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

const int Mod=(int)1e9+7;

int n,m;


const int MAX=1000000+10;

int prime[MAX],phi[MAX],K[MAX],mm[MAX];
int q[MAX],top;
vector<int> yueshu[MAX];
map<int,int> S[MAX/10];

void update(int& a,int b)
{
    a+=b;
    if(a>=Mod)
        a-=Mod;
}

LL calc(int n,int m)
{
    int t=K[n];
    if(m==0)
        return 0;
    if(t!=n && n!=1)
        return (n/t) * calc(t,m) % Mod;
    if(S[n].find(m)!=S[n].end())
        return S[n][m];
    int& ans=S[n][m];
    if(n==1)
    {
        int now=m,next,t;
        for(;now>=2;now=next)
        {
            t=m/now;
            next=m/(t+1);
            update(ans,(now-next) * calc(1,t) % Mod);
        }
        return ans=( (LL)m*(m+1)/2-ans + Mod ) % Mod;
    }
    int i;
    REP2(i,0,(int)yueshu[n].size())
    {
        int d=yueshu[n][i];
        update(ans,phi[n/d] * calc(d,m/d)% Mod);
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("sample.in","r",stdin);freopen("output.txt","w",stdout);
#endif
    int i;
    scanf("%d%d",&n,&m);
    mm[1]=phi[1]=K[1]=1;
    for(i=2;i<MAX;++i)
    {
        if(!mm[i])
        {
            mm[i]=i;
            phi[i]=i-1;
            K[i]=i;
            q[++top]=i;
        }
        for(int j=1;j<=top && q[j]*i<MAX;++j)
        {
            int u=q[j]*i;
            mm[u]=q[j];
            phi[u]=phi[i];
            K[u]=K[i];
            if(i%q[j]==0)
            {
                phi[u]*=q[j];
                break;
            }
            phi[u]*=(q[j]-1);
            K[u]*=q[j];
        }
    }
    for(i=1;i<=n;++i)
        for(int j=i;j<=n;j+=i)
            yueshu[j].pb(i);

    int now=0;
    for(i=1;i<MAX;++i)
    {
        update(now,phi[i]);
        S[1][i]=now;
    }

    int ans=0;
    REP(i,1,n)
        update(ans,calc(i,m));
    printf("%d\n",ans);
    return 0;
}
