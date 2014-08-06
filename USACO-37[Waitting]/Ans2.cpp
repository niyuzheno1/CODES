#include <cstdlib>
#include <iostream>

using namespace std;
int n,m;
int sum,best,mw,w;
int r[52],l[1024];
int s[1024],in[1024];
void dfs(int rr,int i1)
{
 if(rr == 1){
  for(int i = i1;i<=n;i++)
   if(r[i] >= l[1])
   {
    printf("%d\n",best);
    fclose(stdout);
    exit(0);
   }
  return;
 }
 for(int i =i1;i<=n;i++)
  if(r[i] >= l[rr]){
       int ow = w;
       r[i] -= l[rr];
       if(r[i] < l[1] && w+r[i]>mw)
       {
        r[i] += l[rr];
       continue;
       }
       if(r[i] < l[1])
        w += r[i];
       if(l[rr-1] == r[rr])
        dfs(rr-1,i);
       else
        dfs(rr-1,in[rr-1]);
       r[i]+=l[rr];
       w = ow;
  }
}

int main(int argc, char *argv[])
{
    freopen("fence.in","r",stdin);
    freopen("fence.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
    {
     scanf("%d",&r[i]);
     sum+=r[i];
    }
    scanf("%d",&m);
    for(int i = 1;i<=m;i++)
     scanf("%d",&l[i]);
    sort(r+1,r+1+n);
    sort(l+1,l+1+m);
    int tmp = 1;
    while(true)
    {
     if(s[tmp-1]+l[tmp] > sum)
      break;
     s[tmp] = s[tmp-1]+l[tmp];
     tmp++;
    }
    m = min(m,tmp);
    int t = 1;
    for(int i = 1;i<=m;i++)
    {
     while(r[t] < l[i] && r[t] != 0)
      t++;
     if(r[t] == 0){
      m = i;
      break;
     }
     in[i] = t;
    }
    if(m == 0)
    {
     printf("0\n");
     fclose(stdout);
     return 0;
    }
    for(int i = m;i>=1;i--){
     w = 0;
     mw = sum-s[i];
     best = i;
     dfs(i,in[i]);
    }
    fclose(stdin);
    fclose(stdout);
    return EXIT_SUCCESS;
}
