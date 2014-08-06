#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
typedef long long ll;
using namespace std;
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

const ll N=20001,mo=1000000007;
struct info{
    ll t,num,s;
    info(const ll a=0,const ll b=0,const ll c=0):
        t(a),num(b),s(c){}
}im[N];
struct inas{
    ll bo,x,y;
    inas(const ll a=0,const ll b=0,const ll c=0):
        bo(a),x(b),y(c){}
}ask[N];
ll n,m,f[N][13][2],sum[N][13],change[N];
char ch;
inline bool cmp(info a,info b){ return a.num<b.num; }
void makechange(){
    sort(im+1,im+n+1,cmp);
    for (ll i=1;i<=n;i++) change[im[i].t]=i;
}
void push(ll x,ll y,ll z){
    ll now=im[x+1].s,nex=x+1,ney,nez,free;
    for (ll i=0;i<10;i++)
    if ((now>>i)&1){
        if (i<y) ney=y,nez=z^((now>>y)&1),free=i;
        if (i>y) ney=i,nez=sum[x][i],free=y;
        if (i==y) ney=i,nez=z,free=i;
        f[nex][ney][nez]=(f[nex][ney][nez]+(f[x][y][z]<<free)%mo)%mo;
    }
}
void makef(ll t){
    for (ll i=t-1;i<n;i++){
        for (ll j=0;j<10;j++){
            f[i+1][j][0]=f[i+1][j][1]=0;
            sum[i+1][j]=sum[i][j]^((im[i+1].s>>j)&1);
        }
        for (ll j=0;j<10;j++)
        for (ll k=0;k<=1;k++)
        if (f[i][j][k]) push(i,j,k);
    }
}
void print(ll t){
    ll res=0;
    for (ll i=9;i>=0;i--){
        res=(res+f[n][i][(t>>i)&1])%mo;
        if (sum[n][i]!=((t>>i)&1)) break;
    }
    printf("%I64d\n",res);
}
int main(){
    setIO("sample");
    scanf("%I64d%I64d",&n,&m);
    for (ll x,i=1;i<=n;i++){
        scanf("%I64d",&x);
        im[i]=info(i,0,x+1);
    }
    for (ll i=1,x,y;i<=m;i++){
        scanf("\n%c",&ch);
        if (ch=='2'){
            scanf("%I64d",&x);
            ask[i]=inas(0,x,0);
        }else{
            scanf("%I64d%I64d",&x,&y);
            ask[i]=inas(1,x+1,y+1);
            ++im[x+1].num;
        }
    }
    makechange();
    f[0][0][0]=1;
    makef(1);
    for (ll i=1;i<=m;i++)
    if (ask[i].bo){
        ll now=change[ask[i].x];
        im[now].s=ask[i].y;
        makef(now);
    }else print(ask[i].x);
    closeIO();
}
