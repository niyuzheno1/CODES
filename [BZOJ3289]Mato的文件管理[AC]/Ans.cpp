#include "mode.h"
#include "data.h"
#define MN 50010
struct node{
        int l,r,lp,pos;
        bool operator < (node t) const {
         return lp < t.lp || (lp == t.lp && r < t.r);
        }
}ask[MN];
int num[MN],num2[MN],w[MN],a[MN],key[MN];
int n,q,cnt,ans;
void upd(int x,int v){
 for(int i  =x;i<=cnt;i+=lb(i))
  num[i] += v;
}
int sum(int x){
 int res = 0;
 for(int i = x;i;i-=lb(i))
  res += num[i];
 return res;
}
void upd2(int x,int v){
 for(int i = x;i<=cnt;i+=lb(i))
  num2[i] += v;
}
int sum2(int x){
 int res = 0;
 for(int i = x;i;i-=lb(i))
  res += num2[i];
 return res;
}
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi;
    for(int i = 1;i<=n;a[i]=gi,w[i]=a[i],++i);
    sort(w+1,w+n+1);
    cnt = unique(w+1,w+n+1)-w-1;
    for(int i = 1;i<=n;a[i]=lower_bound(w+1,w+cnt+1,a[i])-w,++i);
    q = gi;
    int len = (int)(sqrt(n)+0.5);
    for(int i = 1;i<=q;++i){
     ask[i].l = gi,ask[i].r=  gi;
     ask[i].lp = (ask[i].l-1)/len+1;
     ask[i].pos = i;
    }
    sort(ask+1,ask+q+1);
    int pl = 1,pr = 0;
    for(int i = 1;i<=q;++i){
     if(pr < ask[i].r){
      for(++pr;pr <= ask[i].r;++pr){
       ans += sum(cnt+1-a[pr]);
       upd(cnt+1-a[pr]+1,1);
       upd2(a[pr]+1,1);
      }
      --pr;
     }else if(pr > ask[i].r){
      for(;pr>ask[i].r;--pr){
       ans -= sum(cnt+1-a[pr]);
       upd(cnt+1-a[pr]+1,-1);
       upd2(a[pr]+1,-1);
      }
     }
     if(pl < ask[i].l){
      for(;pl < ask[i].l;++pl){
       ans -=sum2(a[pl]);
       upd(cnt+1-a[pl]+1,-1);
       upd2(a[pl]+1,-1);}
      }
      else if(pl > ask[i].l){
       for(--pl;pl >= ask[i].l;--pl){
        ans += sum2(a[pl]);
        upd(cnt+1-a[pl]+1,1);
        upd2(a[pl]+1,1);
       }
      ++ pl;
      }
      key[ask[i].pos] = ans;
     }
    
    
    for(int i = 1;i<=q;++i) printf("%d\n",key[i]);
    closeIO();
    return EXIT_SUCCESS;
}
