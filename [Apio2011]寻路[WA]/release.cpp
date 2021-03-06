#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define show1D(_type,_array) for(int i = 0;i<=sizeof(_array)/sizeof(_type);++i)\
ff(debug,"%d ",_array[i]);\
ff(debug,"\n");\
\


#define TRA(x,y) for(int x = st[y];~x;x = lk[x].n) if(!lk[x].f)
#define ff fprintf
#define RENEW(x) if(x) delete[] x
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define gi getint()
#define CLEAR(x,y) memset(x,y,sizeof(x))
#define MP make_pair
#define pb push_back
#ifdef WIN32 
#define I64D "%I64d"
#else
#define I64D "%lld"
#endif
#define SIZE(a) a[0]
#define INF  1000000010
using namespace std;
typedef  double ld;
typedef long long int64;
typedef unsigned long long uint64;
typedef pair<int,int> pii;
typedef pair<int64,int64> pll;
FILE * debug;
void setIO(string file)
{
 #ifndef ONLINE_JUDGE
 string input = file+".in",output = file+".out";freopen(input.c_str(),"r",stdin);freopen(output.c_str(),"w",stdout);debug = fopen("debug.txt","w");
 #endif
}
void closeIO()
{
 #ifndef ONLINE_JUDGE
 fclose(stdin);fclose(stdout);fclose(debug);
 #endif
}
template <class T>
void read(T & x)
{
 char tmp = 0; T flag = 1,ret = 0;while(tmp != '-' && !isdigit(tmp))tmp = getchar();
 if(tmp == '-') flag = -1,tmp=getchar();while(isdigit(tmp)) ret*=10,ret += tmp-'0',tmp = getchar();
 x = flag *ret;
}

int64 getint()
{
     int64 ret;read<int64>(ret);
     return ret;
}

void endline()
{
     ff(debug,"\n");
}

#define MU 20100
#define MW 1000010
#define MN 4010
struct rec{int x,y,z;}ver[MU];
struct line{int xa,ya,xb,yb,z;}seg[4][MU],hol[MU];
struct tree{int l,r,dat,cov;}t[MU*4];
int A[MU],B[MU],s[4],v[MN][MN],go[MW],edge[MW],next[MW],head[MU],vis[MU];
int64 d[MU];
int n,m,N,M,tot,q,l,x,y,T,sx,sy,ex,ey;
void addver(int x,int y,int i)
{
     ver[++m].x = x,ver[m].y = y,ver[m].z = i;
}
void addseg(int xa,int ya,int xb,int yb,int i,int k)
{
     seg[k][++s[k]].xa = xa,seg[k][s[k]].ya = ya,seg[k][s[k]].xb = xb,seg[k][s[k]].yb = yb,seg[k][s[k]].z = i;
}


bool cmp(rec a,rec b){return a.z < b.z;}
bool cmp1(rec a,rec b){return a.x < b.x;}
bool cmp2(rec a,rec b){return a.x > b.x;}
bool cmp3(rec a,rec b){return a.y < b.y;}
bool cmp4(rec a,rec b){return a.y > b.y;}
bool comp1(line a,line b){return a.xa < b.xa;}
bool comp2(line a,line b){return a.xa > b.xa;}
bool comp3(line a,line b){return a.ya < b.ya;}
bool comp4(line a,line b){return a.ya > b.ya;}
inline int padx(int x) {return lower_bound(A+1,A+1+N,x)-A;}
inline int pady(int y) {return lower_bound(B+1,B+1+M,y)-B;}

void init()
{
     int a[MU],b[MU],na = 0,nb = 0,xa,ya,xb,yb;
     sx=gi,sy=gi,ex=gi,ey=gi;
     a[++na]=sx,a[++na]=ex,b[++nb]=sy,b[++nb]=ey;
     m=N=M=tot=0;CLEAR(s,0);CLEAR(head,0);
     n = gi;addver(sx,sy,0);addver(ex,ey,n+1);
     for(int i = 1;i<=n;++i)
     {
      xa = gi,ya = gi,xb = gi,yb = gi;if(xa > xb) swap(xa,xb); if(ya>yb) swap(ya,yb);
      addver(xa,ya,i);addver(xa,yb,i);addver(xb,ya,i);addver(xb,yb,i);
      addseg(xa,ya,xa,yb,i,0);addseg(xb,ya,xb,yb,i,1);
      addseg(xa,ya,xb,ya,i,2);addseg(xa,yb,xb,yb,i,3);
      hol[i].xa = xa,hol[i].ya = ya,hol[i].xb = xb,hol[i].yb = yb;
      a[++na] = xa,a[++na]=xb,b[++nb]=ya,b[++nb]=yb;
     }
     sort(a+1,a+1+na);sort(b+1,b+1+nb);
     for(int i = 1;i<=na;++i) if(i == 1 || a[i] != a[i-1]) A[++N] = a[i];
     for(int i = 1;i<=nb;++i) if(i == 1 || b[i] != b[i-1]) B[++M] = b[i];
     for(int i = 1;i<=N;++i) for(int j = 1;j<=M;++j) v[i][j] = 0;
     for(int i = 1;i<=m;++i) v[padx(ver[i].x)][pady(ver[i].y)] = i;
     q = m;
}

void build(int p,int l,int r)
{
     t[p].l = l,t[p].r = r,t[p].dat=t[p].cov = 0;
     if(l == r) return;
     int mid = ((l+r)/2);
     build(p*2,l,mid);build(p*2+1,mid+1,r);
}

inline void spread(int p)
{
 if(t[p].cov) t[p*2].dat = t[p*2+1].dat=t[p*2].cov=t[p*2+1].cov=t[p].cov,t[p].cov=0;      
}

int ask(int p,int x)
{
    if(t[p].l==t[p].r)return t[p].dat;
    spread(p);
    int mid = (t[p].l+t[p].r)/2;
    if(x <= mid) return ask(p*2,x);else return ask(p*2+1,x);
}

void change(int p,int l,int r,int c)
{
     if(l <= t[p].l && r>=t[p].r){t[p].dat = t[p].cov = c;return;}
     spread(p);
     int mid = (t[p].l+t[p].r)/2;
     if(l <= mid) change(p*2,l,r,c);
     if(r > mid) change(p*2+1,l,r,c);
}

rec pos(int k,line s)
{
    rec p;
    if(k < 2) p.x = s.ya,p.y = s.yb,p.z= s.xa; else p.x = s.xa,p.y = s.xb,p.z = s.ya;
    return p;
}

rec fall(int i,int k,int s){
 rec p ; p.z = i;
 if(k == 0) p.x = hol[i].xb,p.y = s;else if(k==1) p.x = hol[i].xa,p.y = s;
 else if(k==2) p.x = s,p.y = hol[i].yb; else p.x = s,p.y=hol[i].ya;
 return p;
}
bool pre(int k,int a,int b){
 return ((k&1)?(a>=b):(a<=b));
}
void add(int x,int y,int z){
 if(x == y) return;
 go[++tot] = y,edge[tot] = z,next[tot] = head[x],head[x] = tot;
 go[++tot] = x,edge[tot] = z,next[tot] = head[y],head[y] = tot;
}

bool sameside(rec a,rec b,line c){
 return a.x==c.xa&&b.x==c.xa||a.x==c.xb&&b.x==c.xb||a.y==c.ya&&b.y==c.ya||a.y==c.yb&&b.y==c.yb;
}
void cross(int k,rec p){
     int go = ask(1,k<2?pady(p.y):padx(p.x));
     if(!go) return;
     rec po = fall(go,k,k<2?p.y:p.x);
     x = padx(po.x),y=pady(po.y);
     if(!v[x][y]) ++q,ver[q] = po,v[x][y] = q;
     
    add(v[padx(p.x)][pady(p.y)],v[x][y],k<2?abs(p.x-po.x):abs(p.y-po.y));

}

void calc(int N,int k){
 rec now,p;
 build(1,1,N);
 int j = 0,i=0;
 for(i = j=1;i<=s[k];++i){
       now = pos(k,seg[k][i]);
       for(;j<=m&&pre(k,k<2?ver[j].x:ver[j].y,now.z);++j) cross(k,ver[j]);
       if(k<2) x=pady(now.x),y=pady(now.y);
       else x = padx(now.x),y=padx(now.y);
       change(1,x,y,seg[k][i].z);
 }
 for(;j<=m;++j) cross(k,ver[j]);
}

void solve()
{
     sort(ver+1,ver+1+m,cmp1);
     sort(seg[0]+1,seg[0]+s[0]+1,comp1);
     calc(M,0);
     sort(ver+1,ver+1+m,cmp2);
     sort(seg[1]+1,seg[1]+s[1]+1,comp2);
     calc(M,1);
     sort(ver+1,ver+1+m,cmp3);
     sort(seg[2]+1,seg[2]+s[2]+1,comp3);
     calc(N,2);
     sort(ver+1,ver+1+m,cmp4);
     sort(seg[3]+1,seg[3]+s[3]+1,comp4);
     calc(N,3);
     sort(ver+1,ver+q+1,cmp);
     int j,k,l;
     for(int i = 1;i<=q;i=j)
     {
      for(j = i;j<=q && ver[i].z == ver[j].z;++j);
       for(k = i;k<j;++k)
        for(l = k+1;l<j;++l)
         if(sameside(ver[k],ver[l],hol[ver[i].z]))
         {
           x =v[padx(ver[k].x)][pady(ver[k].y)];
           y =v[padx(ver[l].x)][pady(ver[l].y)];
           if(x > 2 && y > 2)
            add(x,y,abs(ver[k].x-ver[l].x)+abs(ver[k].y-ver[l].y));
                        
         }
     }
     if(sx == ex)
     {
           int i;
           for(i = 1;i<=n;++i)
            if(sx > hol[i].xa && sx < hol[i].xb && sy < hol[i].yb && ey > hol[i].ya) break;
           if(i>n) add(1,2,ey-sy);
     }
     if(sy == ey)
     {
         int i;
         for(i = 1;i<=n;++i)
          if(sy > hol[i].ya && sy < hol[i].yb && sx < hol[i].xb && ex > hol[i].xa) break;
         if(i > n) add(1,2,ex-sx);
     }
}


void spfa()
{
     queue<int> q;
     CLEAR(d,0x3f);CLEAR(vis,0);
     q.push(1),vis[1] = 1,d[1] = 0;
     while(!q.empty())
     {
       x= q.front();q.pop();vis[x] =0;
       for(int i = head[x];i;i=next[i])
        if(d[y = go[i]] > d[x] + edge[i])
        {
         d[y] = d[x]+edge[i];
         if(!vis[y]) q.push(y),vis[y] =1;
        }
     }
}

int main()
{
    setIO("sample");
    T = gi;
    while(T--)
    {
    init();
    solve();
    spfa();
    if(d[2] == d[0]) puts("No Path");
    else printf("%d\n",d[2]);
    }
    closeIO();
    return 0;
}
