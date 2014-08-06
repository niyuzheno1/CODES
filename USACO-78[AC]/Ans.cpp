#include <cstdlib>
#include <iostream>
#include <queue>

using namespace std;
int n,k;
struct p
{
  int k,x,y;
  p()
  {
   k=x=y=0;
  }
  p(int a,int b,int c)
  {
   k = a;x = b,y = c;
  }
  bool operator <(p a) const
  {
       if(k == a.k)
        return x > a.x;
       return k < a.k;
  }    
};
int s[100010*2];
int f[100010*2],ans;
priority_queue<p> q;
p Q;
int main(int argc, char *argv[])
{
    scanf("%d%d",&n,&k);
    for(int i = 1;i<=n;i++)
    {
     int x;scanf("%d",&x);s[i] = s[i-1]+x;
    }
    for(int i = n+1;i<=n+k;i++)
     s[i] = s[i-1];
    q.push(p(0,0,1));
    Q = p(s[1],1,1);f[1] = s[1];
    for(int i = 2;i<=n+k;i++)
    {
     p newq = p(0,i,1);
     while(!q.empty() && q.top().y+i-2-q.top().x > k)
      q.pop();
     if(!q.empty()){
      p newqq = q.top();
      newqq.k += s[i-2]-s[q.top().x];
      newqq.x = i-2;
      newqq.y = q.top().y+i-2-q.top().x;
      newq.k = q.top().k+s[i-2]-s[q.top().x]+s[i]-s[i-1];
      q.pop();
     }
     f[i] = newq.k;
     q.push(Q);
     Q = newq;
    }
    for(int i = 1;i<=n+k;i++){
     printf("%d\n",f[i]);
     ans = max(f[i],ans);
    }
    printf("%d",ans);
    system("PAUSE");
    return EXIT_SUCCESS;
}
