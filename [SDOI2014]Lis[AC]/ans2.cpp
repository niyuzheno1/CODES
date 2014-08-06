/**************************************************************
    Problem: 3532
    User: zhuohan123
    Language: C++
    Result: Accepted
    Time:9472 ms
    Memory:18660 kb
****************************************************************/
 
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxpoint=11000,maxedge=1100000;
const LL inf=~0ULL>>3;
int head[maxpoint],nowhead[maxpoint],pointsize;
struct edge{int to,next;LL c;}g[maxedge];int gnum=1;
void addedge(int from,int to,LL c)
{
    g[++gnum].to=to;g[gnum].c=c;g[gnum].next=head[from];head[from]=gnum;
    g[++gnum].to=from;g[gnum].c=0;g[gnum].next=head[to];head[to]=gnum;
}
int dfsstart,dfsend,dis[maxpoint];
int q[maxpoint],ql,qr;
bool BFS()
{
    for(int i=1;i<=pointsize;i++)nowhead[i]=head[i],dis[i]=0;
    ql=1;qr=0;q[++qr]=dfsend;
    while(ql<=qr)
        for(int now=q[ql++],i=head[now];i;i=g[i].next)
        if(g[i^1].c&&!dis[g[i].to]&&g[i].to!=dfsend)
            dis[q[++qr]=g[i].to]=dis[now]+1;
    return dis[dfsstart];
}
LL DFS(int po,LL delta)
{
    if(po==dfsend)return delta;
    LL nowans=0,tans;
    for(int&i=nowhead[po];i&&delta;i=g[i].next)
        if(g[i].c&&dis[g[i].to]+1==dis[po]&&(tans=DFS(g[i].to,min(delta,g[i].c))))
            g[i].c-=tans,g[i^1].c+=tans,nowans+=tans,delta-=tans;
    return nowans;
}
LL dinic(int start,int end)
{
    dfsstart=start,dfsend=end;
    LL ans=0;
    while(BFS())ans+=DFS(start,inf);
    return ans;
}
int n;
int a[1100],b[1100],f[1100];
struct T
{
    int num,pos;
    friend bool operator<(T A,T B){return A.num<B.num;}
}c[1100];
int oans[1100],ansnum;
int main(int argc, char *argv[])
{
    freopen("sample.in","r",stdin);
    freopen("sample.out","w",stdout);
    int Ti;scanf("%d",&Ti);
    while(Ti--)
    {
        memset(head,0,sizeof head);gnum=1;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)scanf("%d",&b[i]);
        for(int i=1;i<=n;i++)scanf("%d",&c[i].num),c[i].pos=i;
        int maxf=0;
        for(int i=1;i<=n;i++)f[i]=1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<i;j++)
                if(a[j]<a[i])maxf=max(maxf,f[i]=max(f[i],f[j]+1));
        for(int i=1;i<=n;i++)
        {
            addedge(2*i+1,2*i+2,b[i]);
            if(f[i]==1)addedge(1,2*i+1,inf);
            if(f[i]==maxf)addedge(2*i+2,2,inf);
            for(int j=1;j<i;j++)
                if(a[j]<a[i]&&(f[j]+1==f[i]))
                addedge(2*j+2,2*i+1,inf);
        }
        pointsize=2*n+2;
        LL ans=dinic(1,2);
        sort(c+1,c+n+1);
        ansnum=0;
        for(int i=1;i<=n;i++)
        {
            int ne=0,po=c[i].pos;
            for(int j=head[2*po+1];j;j=g[j].next)
                if(g[j].to==2*po+2){ne=j;break ;}
            if(g[ne].c==0)
            {
                dfsstart=2*po+1,dfsend=2*po+2;
                if(!BFS())
                {
                    dinic(2,2*po+2);
                    dinic(2*po+1,1);
                    g[ne^1].c=0;
                    oans[++ansnum]=po;
                }
            }
        }
        sort(oans+1,oans+ansnum+1);
        printf("%lld %d\n",ans,ansnum);
        for(int i=1;i<ansnum;i++)printf("%d ",oans[i]);printf("%d\n",oans[ansnum]);
         
    }
    return 0;
}
