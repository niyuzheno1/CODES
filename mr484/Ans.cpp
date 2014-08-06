#include <cstdio>
#include <algorithm>
#include <cstring>
 
using namespace std; 
 
#define MAXN 100010
#define lowbit(x)((-x)&x)
#define MAXM 1000010
#define MAXV 35000000
#define L(t) T[t].left
#define R(t) T[t].right
#define S(t) T[t].sum
 
struct node {
    int left,right,sum;
    node () {
        left=right=0;
    }
} T[MAXV];
 
int bit[MAXN],M=0,sgt[MAXN];
 
void bit_init(int l,int r,int t) {
    S(t)=0;
    if (l<r) bit_init(l,(l+r)>>1,L(t)=++M),bit_init(((l+r)>>1)+1,r,R(t)=++M);
}
 
void Add(int l,int r,int v,int w,int u,int t) {
    S(t)=S(u)+w;
    if (l==r) return ;
    int mid=(l+r)>>1;
    if (v<=mid) {
        R(t)=R(u);
        Add(l,mid,v,w,L(u),L(t)=++M);
    } else {
        L(t)=L(u);
        Add(mid+1,r,v,w,R(u),R(t)=++M);
    }
}
 
int Sum(int ll,int rr,int l,int r,int t) {
    if (ll==l&&rr==r) return S(t);
    int mid=(ll+rr)>>1;
    if (r<=mid) return Sum(ll,mid,l,r,L(t));
    if (l>mid) return Sum(mid+1,rr,l,r,R(t));
    return Sum(ll,mid,l,mid,L(t))+Sum(mid+1,rr,mid+1,r,R(t));
}
 
struct saver {
    int v,t;
} b[MAXN];
 
bool cmp(saver x,saver y) {
    return x.v<y.v||(x.v==y.v&&x.t<y.t);
}
 
struct qtype {
    qtype *next;
    int l,r,a,b,t;
} *head[MAXN];
 
void Insert(int l,int r,int A,int B,int t) {
    qtype *p=new(qtype);
    p->next=head[l],p->l=l,p->r=r,p->a=A,p->b=B,p->t=t;
    head[l]=p;
}
 
int a[MAXN],n,m,ans[MAXM][2],query[MAXM][4],next[MAXN];
 
void bit_add(int x,int y,int z) {
    for (int i=x;i<=n;i+=lowbit(i)) {
        int v=++M;
        Add(1,n,y,z,bit[i],v);
        bit[i]=v;
    }
}
 
int bit_sum(int x,int A,int B) {
    int rec=0;
    for (int i=x;i;i-=lowbit(i)) rec+=Sum(1,n,A,B,bit[i]);
    return rec;
}
 
int main() {
    scanf("%d%d",&n,&m);
    for (int i=0;i++<n;) scanf("%d",&a[i]),b[i].v=a[i],b[i].t=i;
    sort(b+1,b+n+1,cmp);
    bit_init(1,n,sgt[0]=bit[0]=++M);
    for (int i=0;i++<n;) Add(1,n,a[i],1,sgt[i-1],sgt[i]=++M);
    memset(head,0,sizeof(head));
    for (int i=0;i++<m;) {
        scanf("%d%d%d%d",&query[i][0],&query[i][1],&query[i][2],&query[i][3]);
        ans[i][0]=Sum(1,n,query[i][2],query[i][3],sgt[query[i][1]])-Sum(1,n,query[i][2],query[i][3],sgt[query[i][0]-1]);
        Insert(query[i][0],query[i][1],query[i][2],query[i][3],i);
    }
    for (int i=0;i++<n;) bit[i]=bit[0];
    b[0].v=-1;
    memset(next,0,sizeof(next));
    for (int i=0;i++<n;) {
        if (b[i].v!=b[i-1].v) {
            bit_add(b[i].t,b[i].v,1);
        } else next[b[i-1].t]=b[i].t;
    }
    for (int i=0;i++<n;) {
        for (qtype *p=head[i];p;p=p->next) {
            ans[p->t][1]=bit_sum(p->r,p->a,p->b);
        }
        bit_add(i,a[i],-1);
        if (next[i]) bit_add(next[i],a[i],1);
    }
    for (int i=0;i++<m;) printf("%d %d\n",ans[i][0],ans[i][1]);
    return 0 ;
}
