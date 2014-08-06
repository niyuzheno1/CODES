#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define gi getint()
using namespace std;
const int MAXN = 1058576,MAXM =  400;
int n,m,len,tot;
int getint()
{
 char c = 0;int ret = 0;
 while(!isdigit(c))c = getchar();
 while(isdigit(c)){ret *= 10;ret += (c-'0');c = getchar();}
 return ret;
}
struct trie
{
 int n[27];
 bool w;
};
trie t[MAXM];
char s[MAXN];
int f[2][MAXM];
void getstr()
{
 len = 0;
 char c = 0;
 while(c <'a' || c > 'z') c = getchar();
 while(c <='z' && c >= 'a')
 {len++;s[len] = c;c=getchar();}
}
void setIO(string file)
{
 #ifndef ONLINE_JUDGE
 string input = file+".in",output = file+".out";freopen(input.c_str(),"r",stdin);freopen(output.c_str(),"w",stdout);
 #endif
}
void closeIO()
{
 #ifndef ONLINE_JUDGE
 fclose(stdin);fclose(stdout);
 #endif
}
void update(int & x,int y)
{
 x = max(x,y);
}
int DP()
{
 memset(f,0,sizeof(f));
 int x = 0;
 f[0][1] = 1;
 int ans = 1;
 for(int i = 1;i<=len;i++)
 {
 memset(f[x^1],0,sizeof(f[x^1]));
 bool flag = 1;
  for(int j = 1;j<=tot;j++)
   if(f[x][j] && t[j].n[s[i]-'a'])
   {
    flag = 0;
    int nxt = t[j].n[s[i]-'a'];
    update(f[x^1][nxt],f[x][j]+1);
    if(t[nxt].w){
     ans = max(ans,f[x^1][nxt]);
     update(f[x^1][1],f[x][j]+1); 
    }
   }
 x=x^1;
 if(flag)
  break;
 }
 return ans;
}
int main(int argc, char *argv[])
{
    setIO("LL");
    n = gi;m = gi;
    tot = 1;
    for(int i = 1;i<=n;i++)
    {
     getstr();
     int u =  1;
     for(int j = 1;j<=len;j++){
      if(!t[u].n[s[j]-'a'])
      {
       tot++;
       t[u].n[s[j]-'a'] = tot;
      }
      u = t[u].n[s[j]-'a'];
      if(j == len)
       t[u].w = 1;
     }
    }
    for(int i = 1;i<=m;i++)
    {
     getstr();
     printf("%d\n",DP()-1);
    }
    closeIO();
    return EXIT_SUCCESS;
}
