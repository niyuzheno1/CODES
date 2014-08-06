#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;
string s;
int top;
struct Node
{
 bool t;

 int c[27];
};
Node t[10010];
int f[265][51][51];
void insert(string s)
{
     int u = 1;
     for(int i = 0;i<s.length();i++)
     {
            
             if(!t[u].c[s[i]-'a'+1])
              t[u].c[s[i]-'a'+1] = ++top;
             u = t[u].c[s[i]-'a'+1];
             
             /*,t[u].m=s*/;
             
     }
	  t[u].t = true;
}
bool find(string s)
{
  int u = 1;
  for(int i = 0;i<s.length();i++)
  {
            
             if(!t[u].c[s[i]-'a'+1])
              return false;
              u = t[u].c[s[i]-'a'+1];
  }
  if(t[u].t)
   return true;
  else
   return false;
}
int dfs(int x,int w,int l)
{
    if(x > s.length())
     return 0;
    if(f[x][w][l])
     return f[x][w][l];
    int ans = 0;
    for(int i = x;i<s.length();i++)
    if(find(s.substr(x,i-x+1)))
    {
     if(w+i-x+1 != 0 && w+i-x+1 <= 50 && l+1 >=3 && (w+i-x+1) % (l+1) == 0)
      ans=max(ans,dfs(i+1,0,0)+1);
     ans = max(ans,dfs(i+1,w+i-x+1,l+1));
    } 
    return f[x][w][l] = ans;
}
char inf[101],ouf[101];
int main(int argc, char *argv[])
{
for(int cani = 0;cani<=4;cani++){
    n = top = 0;s.clear();
    memset(f,0,sizeof(f));
    memset(t,0,sizeof(t));
    memset(inf,0,sizeof(inf));
    memset(ouf,0,sizeof(ouf));
    sprintf(inf,"mr456.in%d",cani);
    sprintf(ouf,"mr456.ou%d",cani);
    freopen(inf,"r",stdin);
    freopen(ouf,"w",stdout);
    top = 1;
    cin>>n;
    for(int i = 1;i<=n;i++)
    {
    cin>>s;
    transform(s.begin(), s.end(), s.begin(), ::tolower); 
    insert(s);
    }
    cin>>s;
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    printf("%d",dfs(0,0,0));
	fclose(stdin);fclose(stdout);
}
    return EXIT_SUCCESS;
}
