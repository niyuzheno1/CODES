#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define a2 t[0]
#define b2 t[1]
#define sa p[0]
#define sb p[1]
#define sqr(x) ((x)*(x))%mod
#define ff fprintf
using namespace std;
typedef int ele[2][2];
const int mod = 10301;
FILE * d;
int getint()
{
 int ret = 0;
 bool o = 0;
 char c = 0;
 while(!isdigit(c) && c!='-'){
  c = getchar();
  if(c == EOF)
   return 0;
 }
 if(c == '-')
  c = getchar(),o = 1;
 while(isdigit(c)){
  ret *= 10;
  ret += c-'0';
  c = getchar();
 }
 if(!o)
 return ret;
 else
 return -ret;
}

const int MAXN = 100010;
ele id;
int a[MAXN],b[MAXN];
void inline  che(ele & ans,ele  x,ele  y)
{
 memset(ans,0,sizeof(ans));
  for(int i = 0;i<2;i++)
	   for(int j = 0;j<2;j++)
		 for(int z= 0;z<2;z++)
		  ans[i][j] = (ans[i][j]+x[i][z]*y[z][j])%mod;
}
struct segn
{
  ele flag,dflag;
  int t[2],p[2];
  int ab;
  segn()
  {
   memcpy(flag,id,sizeof(ele)); 
   memset(t,0,sizeof(t));
   memset(p,0,sizeof(p));
   ab = 0;
  }
  void up()
  {
   int lsa = sa,lsb = sb,la2 = a2,lb2 = b2,lab = ab;
   sa = (lsa*flag[0][0]+lsb*flag[0][1])%mod;
   sb = (lsa*flag[1][0]+lsb*flag[1][1])%mod;
   a2 = (la2*sqr(flag[0][0])+lb2*sqr(flag[0][1])+2*(flag[0][0]*flag[0][1])%mod*lab)%mod;
   b2 = (la2*sqr(flag[1][0])+lb2*sqr(flag[1][1])+2*(flag[1][0]*flag[1][1])%mod*lab)%mod;
   ab = (la2*(flag[0][0]*flag[1][0])%mod+lb2*(flag[0][1]*flag[1][1])%mod+lab*((flag[0][1]*flag[1][0]+flag[0][0]*flag[1][1])%mod))%mod;
   che(dflag,flag,dflag);
   memcpy(flag,id,sizeof(ele)); 
  }
  /*void print()
  {
   ff(d,"sa:%d\n",sa);
   ff(d,"sb:%d\n",sb);
   ff(d,"a2:%d\n",a2);
   ff(d,"b2:%d\n",b2);
   ff(d,"ab:%d\n",ab);
   ff(d,"dflag:\n");
   dflag.dpri();
   ff(d,"flag:\n");
   flag.dpri();
  }*/
};
segn t[MAXN*4];
int k;
void init(int x)
{
    k = 1;
    while(k<=x) k<<=1;
}
void updata(int x)
{
  int l = 2*x,r = 2*x+1;
  t[l].up();t[r].up();
  t[x].a2 = (t[l].a2+t[r].a2)%mod;
  t[x].b2 = (t[l].b2+t[r].b2)%mod;
  t[x].ab = (t[l].ab+t[r].ab)%mod;
  t[x].sa = (t[l].sa+t[r].sa)%mod;
  t[x].sb = (t[l].sb+t[r].sb)%mod;
}

void down(int x)
{
 int l = 2*x,r=2*x+1;
 t[x].up();
 che(t[l].flag,t[x].dflag,t[l].flag);
 che(t[r].flag,t[x].dflag,t[r].flag);
 memcpy(t[x].dflag,id,sizeof(ele));
 /*t[x].sb = t[x].sa = t[x].a2 = t[x].b2 = t[x].ab = 0;
 t[x].flag = id;
 t[x].dflag = id;*/
}
void ptol(int x)
{
  int k = 0,y = x>>1;
  while(y)k++,y>>=1;
  for(int i = k;i>=1;i--)
   down(x>>i); 
}
void upd(int x)
{
  while(true)
  {
   x>>=1;
   if(x == 0) break;
   updata(x);
  }
}
void modify(int x)
{
  int l = x+k-1,r = x+k+1;
  ptol(l);ptol(r);
  memcpy(t[l+1].dflag,id,sizeof(ele));
  memcpy(t[l+1].flag,id,sizeof(ele));
  t[l+1].sa = a[x];
  t[l+1].sb = b[x];
  t[l+1].a2 = (a[x]*a[x])%mod;
  t[l+1].b2 = (b[x]*b[x])%mod;
  t[l+1].ab = (a[x]*b[x])%mod;
  upd(l);upd(r);
}
void modifylr(int l,int r,int d)
{
  l = l+k-1;r=r+k+1;
  int ll = l,rr = r;
  ptol(ll);ptol(rr);
  while((l^r)!=1)
  {
   if((l&1)==0)
    for(int i = 0;i<2;i++)
     t[l^1].flag[d][i] = (t[l^1].flag[d][i]+t[l^1].flag[d^1][i])%mod;
   if((r&1)==1)
    for(int i = 0;i<2;i++)
     t[r^1].flag[d][i] = (t[r^1].flag[d][i]+t[r^1].flag[d^1][i])%mod;
   l/=2;r/=2;
  }
  upd(ll);upd(rr);
}
int sum(int l,int r)
{
  int ret = 0;
  l = l+k-1;r = r+k+1;
  int ll = l,rr = r;
  ptol(ll);ptol(rr);
  while((l^r) != 1)
  {
   if((l&1)==0)
   {
    t[l^1].up();
    ret = (ret+t[l^1].ab)%mod;
   }
   if((r&1)==1){
     t[r^1].up();
     ret = (ret+t[r^1].ab)%mod;
   }
   l/=2;r/=2;
  }
  //upd(ll);upd(rr);
  return ret%mod;
}

void mkid()
{
 
 for(int i = 0;i<2;i++)
  id[i][i] = 1;
}

int n,m;
int main(int argc, char *argv[])
{
    freopen("tsinsenD5530.in","r",stdin);freopen("tsinsenD5530.out","w",stdout);
    d = fopen("debug.txt","w");
    mkid();
    n = getint();m=getint();
    for(int i = 1;i<=n;i++){
     a[i] = getint();b[i] = getint();
     a[i] %= mod;b[i] %= mod;
    }
    init(n);
    for(int i = 1;i<=n;i++)
     modify(i);
    for(int i = 1;i<=m;i++)
    {
     int x,y,z;
     x = getint();y = getint();z = getint();
     
     if(x <= 2 && x>=1)
      modifylr(y,z,x-1);
     else
      printf("%d\n",sum(y,z));
    }
    fclose(d);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
