#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<fstream>
#include<map>
#include<ctime>
#include<set>
#include<queue>
#include<cmath>
#include<vector>
#include<bitset>
#include<functional>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define REP(i,l,r) for((i)=(l);(i)<=(r);++(i))
#define REP2(i,l,r) for((i)=(l);(i)!=(r);++(i))
using namespace std;
 
typedef long long LL;
typedef double ld;
 
const int INF=2000000000;
const int MAX=100000+10;
 
struct Info
{
    //����ʵ����̫����
    int mul,plus;
    Info():mul(1),plus(0){}
    Info(int a,int b):mul(a),plus(b){}
    int ok(){return mul!=1 || plus;}
}emptyInfo;
 
Info operator + (const Info& a,const Info& b)
{
    return Info(a.mul*b.mul,a.plus*b.mul+b.plus);
}
 
struct Sum
{
    int max_val,min_val;
    int sum,size;
 
    Sum(int a,int b,int c,int d):max_val(a),min_val(b),sum(c),size(d){}
 
    Sum():max_val(-INF),min_val(INF),sum(0),size(0){}
 
    Sum(int a):max_val(a),min_val(a),sum(a),size(1){}
};
 
Sum operator + (const Sum& a,const Sum& b)
{
    return Sum( max(a.max_val,b.max_val),min(a.min_val,b.min_val),a.sum+b.sum,a.size+b.size);
}
 
int app(int a,const Info& b)
{
    return a*b.mul+b.plus;
}
 
Sum operator + (const Sum& a,const Info& b)
{
    if(!a.size)
        return a;
    return Sum(app(a.max_val,b),app(a.min_val,b),a.sum*b.mul+b.plus*a.size,a.size);
}
//����ԭ�������û�ܸ��ǵ�����ǵ��³�������
 
struct Node
{
    Node* ch[4],*p;
    int inner,rev,val;
    Info chainflag,treeflag;
    Sum all,chain,tree;
    //all=chain+tree
    //tree�в��������е���Ϣ
 
    Node():p(0),inner(0),rev(0),val(0)
    {
        memset(ch,0,sizeof ch);
    }
 
    int getPos()
    {
        int i;
        REP2(i,0,4)
            if(p->ch[i]==this)
                return i;
        return 4;
    }
 
    void setc(Node* u,int Kind)
    {
        ch[Kind]=u;
        if(u)
            u->p=this;
    }
 
    int isRoot(int Kind)
    {
        if(Kind)
            return !p || !p->inner || !inner;
        else return !p || (getPos()>=2) || inner || p->inner;
    }
 
    void revit(Node* u)//ֻ�����ϵĽڵ�Ż�rev
    {
        if(u)
        {
            u->rev^=1;
            swap(u->ch[0],u->ch[1]);
        }
    }
 
    //treeflag �������Լ���������ȫ���øı�
    //chainflag �Լ��������ĸı�
 
    void flagChain(const Info& a)
    {
        chain=chain+a;
        chainflag=chainflag+a;
        all=chain+tree;
        val=app(val,a);
    }
 
    void flagTree(const Info& a,int xubian)
    {
        treeflag=treeflag+a;
        tree=tree+a;
        if(xubian && !inner)
            flagChain(a);
        else all=chain+tree;
    }
 
    void pushdown()
    {
        int i;
        if(rev)
        {
            REP2(i,0,2)
                revit(ch[i]);
            rev=0;
        }
        if(!inner && chainflag.ok())
        {
            REP2(i,0,2)
                if(ch[i])
                    ch[i]->flagChain(chainflag);
            chainflag=emptyInfo;
        }
        if(treeflag.ok())
        {
            REP2(i,0,4)
                if(ch[i])
                    ch[i]->flagTree(treeflag,i>=2);
            treeflag=emptyInfo;
        }
    }
 
    void update()
    {
        int i;
        if(!inner)
        {
            chain=Sum(val);
            REP2(i,0,2)
                if(ch[i])
                    chain=chain+ch[i]->chain;
        }
        else chain=Sum();
        tree=Sum();
        REP2(i,0,4)
            if(ch[i])
                tree=tree+(i>=2?ch[i]->all:ch[i]->tree);
        if(!inner)
            all=chain+tree;
        else all=tree;
    }
 
    Node* get(int Kind)
    {
        if(ch[Kind])
            ch[Kind]->pushdown();
        return ch[Kind];
    }
}tree[MAX];
 
void rotate(Node* u,int Kind)
{
    Node* fa=u->p;
    int T=u->getPos()&1;
 
    if(fa->p)
        fa->p->setc(u,fa->getPos());
    else u->p=0;
 
    fa->setc(u->ch[!T+Kind],T+Kind);
    u->setc(fa,!T+Kind);
 
    fa->update();
}
 
void relax_all(Node* u,int Kind)
{
    if(!u->isRoot(Kind))
        relax_all(u->p,Kind);
    u->pushdown();
}
 
void Splay(Node* u,int Kind=0)
{
    relax_all(u,Kind);
    for(;!u->isRoot(Kind);rotate(u,Kind))
        if(!u->p->isRoot(Kind))
            rotate(u->getPos()==u->p->getPos()?u->p:u,Kind);
    u->update();
}
 
Node* findfather(Node* u)//��ߵĸ���
{
    Splay(u);
    if(!u->p)
        return 0;
    if(!u->p->inner)
        return u->p;
    else
    {
        Node* tmp=u->p;
        Splay(tmp,2);
        return tmp->p;
    }
}
 
void add(Node* p,Node* v)//��v����p���������ⲿ�Ĵ𰸣������ڲ��ı��һ��Ҫ�´��� 
{
    int i;
    p->pushdown();
    REP2(i,2,4)
        if(!p->ch[i])
        {
            p->setc(v,i);
            return;
        }
    for(;p->ch[2] && p->ch[2]->inner;)
        p=p->get(2);
    Node* x=new Node;
    x->inner=1;
    x->setc(p->ch[2],2);
    x->setc(v,3);
    p->setc(x,2);
    Splay(x,2);//�����update�ˣ�����Ӧ���ǲ����б���˵�
}
 
void del(Node* u)//����������ڲ��ı��ʲô��
{
    Splay(u);
    if(!u->p)
        return;
    Node* p=u->p;
    if(p->inner)
    {
        relax_all(p,2);
        Node* tmp=p->p;
        if(tmp)
        {
            tmp->setc(p->get( u->getPos()^1 ),p->getPos());
            Splay(tmp,2);
        }
        delete p;
    }
    else
    {
        p->setc(0,u->getPos());
        Splay(p);
    }
    u->p=0;
}
 
Node* access(Node* u)//��������еı��
{
    Node* v=0;
    if(!u)
        return 0;
    Node* tmp=u;
    while(u)
    {
        Splay(u);
        if(u->ch[1])
            add(u,u->ch[1]);
        if(v)
            del(v);
        u->setc(v,1);
        u->update();
        Node* tmp=findfather(u);
        v=u;
        u=tmp;
    }
    Splay(tmp);
    return v;
}
 
Node* Myfindfather(Node* u)//�ҵ��Լ������ϵĸ���
{
    access(u);
    u=u->get(0);
    while(u && u->get(1))
        u=u->get(1);
    return u;
}
 
void beRoot(Node* u)
{
    access(u);
    u->revit(u);
}
 
void Link(Node* u,Node* v)
{
    beRoot(v);
    add(u,v);
    access(v);
}
 
void Cut(Node* u)
{
    Node* p=Myfindfather(u);
    if(p)
    {
        access(p);
        del(u);
        Splay(p);
    }
}
 
Node* LCA(Node* a,Node* b)
{
    access(a);
    return access(b);
}
 
int n,m;
int a[MAX],b[MAX];
 
void show(Node* u)
{
    if(!u || u->inner)
        return;
    show(u->ch[0]);
    printf("%d ",u-tree);
    show(u->ch[1]);
}
 
int main()
{
#ifndef ONLINE_JUDGE
    freopen("sample.in","r",stdin);freopen("output.txt","w",stdout);
#endif
    int i;
    scanf("%d%d",&n,&m);
    REP(i,1,n-1)
        scanf("%d%d",a+i,b+i);
    REP(i,1,n)
    {
        scanf("%d",&tree[i].val);
        tree[i].update();
    }
    REP(i,1,n-1)
    {
        int x=a[i];
        int y=b[i];
        Link(tree+x,tree+y);
    }
    int Root;
    scanf("%d",&Root);
    Node* nowRoot=tree+Root;
    beRoot(nowRoot);
    Splay(nowRoot);
    REP(i,1,m)
    {
        int type,x,y;
        scanf("%d",&type);
        if(type==0 || type==3 || type==4 || type==5 || type==11)//�������
        {
            beRoot(nowRoot);
            scanf("%d",&x);
            Node* u=tree+x;printf("\n"),show(u);
            access(u);
            if(type==0 || type==5)
            {
                scanf("%d",&y);
                Info a(type==5,y);
                u->val=app( u->val ,a );
                int j;
                REP2(j,2,4)
                    if(u->ch[j])
                        u->ch[j]->flagTree(a,1);
                u->update();
                Splay(u);
            }
            else
            {
                int ans=u->val;
                int j;
                Node* v;
                REP2(j,2,4)
                    if((v=u->ch[j]))
                    {
                        if(type==3)
                            ans=min(ans,v->all.min_val);
                        else if(type==4)
                            ans=max(ans,v->all.max_val);
                        else ans+=v->all.sum;
                    }
                printf("%d\n",ans);
            }
        }
        else if(type==2 || type==6 || type==7 || type==8 || type==10)//�����
        {
            scanf("%d%d",&x,&y);
            Node* u=tree+x;printf("\n"),show(u);
            beRoot(tree+x);
            access(tree+y);
            Splay(u);
            if(type==2 || type==6)
            {
                int z;
                scanf("%d",&z);
                u->flagChain( Info(type==6,z) );
            }
            else
            {
                int ans=0;
                if(type==7)
                    ans=u->chain.min_val;
                else if(type==8)
                    ans=u->chain.max_val;
                else ans=u->chain.sum;
                printf("%d\n",ans);
            }
        }
        else if(type==1)//����
        {
            scanf("%d",&x);printf("\n"),show(&tree[x]);
            beRoot(nowRoot=tree+x);
        }
        else if(type==9)//������
        {
            scanf("%d%d",&x,&y);
            swap(x,y);
            beRoot(nowRoot);
            Node* X=tree+x;printf("\n"),show(X);
            Node* Y=tree+y;
            if(LCA(X,Y)==Y)
                continue;
            Cut(Y);
            Link(X,Y);
        }
    }
    return 0;
}
