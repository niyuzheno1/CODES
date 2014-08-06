#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#define ha 257
#define hb 1000007
using namespace std;
const char t[] = "Begin the Escape execution at the Break of Dawn";
int f[256];
int g[256];
map<char,int> m;

struct llk
{
       int x;
       char str[76];
};
int st[1000007];
llk lk[1000007];
int tot;
void add(char * a,long long x)
{
 tot++;
 lk[tot].x = st[x];
 memcpy(lk[tot].str,a,sizeof(lk[tot].str));
 st[x] = tot;
}
bool find(char * a,long long x)
{
 for(int i = st[x];i != -1;i = lk[i].x)
  if(strcmp(a,lk[i].str) == 0)
    return true;
 return false;
}
void getp(char *x,vector<int> * p)
{
     for(int i = 0;i<strlen(x);i++)
      if(m[x[i]] != 0)
       p[m[x[i]]].push_back(i);
}
void swap(char * a,int x,int y,int z)
{
    char s[76];
    memset(s,0,sizeof(s));
    for(int i = 0;i<x;i++)
     s[i] = a[i];
    int u = x;
    for(int i = y+1;i<z;i++)
     s[u] = a[i],u++;
    for(int i = x+1;i<y;i++)
     s[u] = a[i],u++;
    for(int i = z+1;i<strlen(a);i++)
     s[u] = a[i],u++;
    memcpy(a,s,sizeof(s));
}

char str[76];
long long hash(char * a)
{
    long long ans = 0;
    for(int i = 0;i<strlen(a);i++)
     ans = ((ans)%hb*(ha)%hb+a[i])%hb;
    return ans;
}
bool cut(char * a,vector<int> * b)
{
     int lena =  strlen(a);int lenb = strlen(t);
     for(int i = 0;i<(b[1].size()==0?lena:b[1][0]) && i<lenb;i++)
      if(a[i] != t[i] || a[i]=='W' || a[i]=='O')
       return true;
     int tp = lenb-1;
     for(int i = lena-1;i>(b[3].size()==0?0:b[3][b[3].size()-1]) && tp>=0;i--,tp--)
      if(a[i] != t[tp]  || a[i]=='C' || a[i]=='O')
       return true;
     return false;
}
bool ans = 0;
void dfs(char * a)
{
     char tmp[76];
     memcpy(tmp,a,sizeof(tmp));
     int ht = hash(a);
     if(find(tmp,ht))
      return;
     if(strcmp(a,t) == 0)
     {
      ans = 1;
      return;
     }
     vector<int> p[4];
     getp(a,p);
     add(tmp,ht);
     if(cut(a,p) == 1)
      return;
     for(int i = 0;i<p[1].size();i++)
      for(int j = 0;j<p[2].size();j++)
       for(int k = 0;k<p[3].size();k++)
        if(p[1][i] < p[2][j] && p[2][j] < p[3][k])
        {
         char tmp2[76];
         memcpy(tmp2,tmp,sizeof(tmp2));
         swap(tmp2,p[1][i],p[2][j],p[3][k]);
         dfs(tmp2);
        }
     return;
}
void cx(int * a,const char * b)
{
     for(int i = 0;i<strlen(b);i++)
      a[b[i]]++;
}
bool cp()
{
     for(char i = 'A';i<='z';i++)
     if(i != 'C' && i != 'W' && i != 'O'){
      if(g[i] > f[i])
       return false;
      else if(g[i] < f[i])
       return false;
     }
     return true;
}
int main(int argc, char *argv[])
{
    freopen("cryptcow.in","r",stdin);
    freopen("cryptcow.out","w",stdout);
    memset(st,-1,sizeof(st));
    m['C'] = 1;m['O'] = 2;m['W'] = 3;
    gets(str);
    cx(f,t);
    cx(g,str);
    if(cp() && (strlen(str)-strlen(t))%3 == 0)
    {
     dfs(str);
     if(ans)
      printf("Yes\n");
     else
      printf("No\n");
    }
    else
     printf("No\n");
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
