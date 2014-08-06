#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <map>
#include <vector>
using namespace std;
int n;
vector<int> s;
int l[1010],r[1010],c[1010];
int m[1010];
int cmp(int x,int y)
{
 if(r[x] > r[y])
  return false;
 else
  return true;
 
}
int main(int argc, char *argv[])
{
    freopen("sequence.in","r",stdin);
    freopen("sequence.out","w",stdout);
    
    int ans = 0;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
     scanf("%d%d%d",&l[i],&r[i],&c[i]);
    for(int i = 1;i<=n;i++)
     s.push_back(i);
    sort(s.begin(),s.end(),cmp);
    for(int i = 0;i<n;i++)
    {
     int cnt = 0;
     for(int j = l[s[i]];j<=r[s[i]];j++)
      if(m[j] == 1)
       cnt++;
     for(int j = r[s[i]];j>=l[s[i]];j--)
     {
      if(cnt >= c[s[i]])
       break;
      if(!m[j])
      {
       m[j] = 1;
       ans++;
       cnt++;
      }
     }
    }
    printf("%d\n",ans);
    fclose(stdin);
    fclose(stdout);
    return EXIT_SUCCESS;
}
