#include <cstdlib>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;
typedef long long int64;
priority_queue<int64,vector<int64>,greater<int64> > q;
map<int64,int> m;
int d[101];
int k,n;
int main(int argc, char *argv[])
{
    freopen("humble.in","r",stdin);
    freopen("humble.out","w",stdout);
    scanf("%d%d",&k,&n);
    for(int i = 1;i<=k;i++){
     int x = 0;
     scanf("%d",&x);
     d[i] = x;
     q.push(x);
    }
    int ans = 0;
    while(n > 0)
    {
      n--;
      ans = q.top();q.pop();
      for(int i =1;i<=k;i++)
      if(!m[ans*d[i]] && ans*d[i] > d[i] && ans*d[i] > ans){
       m[ans*d[i]] = 1;
       q.push(ans*d[i]);
      }
    }
    printf("%d",ans);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
