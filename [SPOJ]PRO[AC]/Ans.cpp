#include "mode.h"
#include "data.h"

const int MN = 1000010;
int lef[MN*4],rig[MN*4],tot;
int64 cnt[MN*4];
#define LEF(_t) lef[_t]
#define RIG(_t) rig[_t]

int build(TREE)
{
 if(_t == 0 ) _t = ++tot;
 if(_l == _r) return _t;
 M;LEF(_t) = build(LEFT);RIG(_t) = build(RIGHT);
 return _t;
}
void mkc(TREE,int x)
{
 ++cnt[_t];if(_l == _r) return;
 M;
 if(x<=mid) 
 mkc(LEFT,x); 
 else 
 mkc(RIGHT,x);
}
int64 delmin(TREE)
{
  --cnt[_t];
  if(_l == _r) return _l;
  M;
  if(cnt[LEF(_t)]>0)return delmin(LEFT);
  else if(cnt[RIG(_t)]>0)return delmin(RIGHT);
  return 0;
}
int64 delmax(TREE)
{
 --cnt[_t];
 if(_l == _r) return _r;
 M;
 if(cnt[RIG(_t)]>0)return delmax(RIGHT);
 else if(cnt[LEF(_t)]>0)return delmax(LEFT);
 return 0;
}
int main(int argc, char *argv[])
{
    tot = 1;
    setIO("sample");
    int64 n = gi;
    build(1,1,MN-10);
    int64 ans = 0;
    for(int64 i = 1;i<=n;++i)
    {
     int64 k = gi;
     for(int64 j = 1,u=0;j<=k;++j)
      u = gi,mkc(1,1,MN-10,u);
     int64 fx = delmin(1,1,MN-10);
     int64 fy = delmax(1,1,MN-10);
     ans += fy-fx;
    }
    printf(I64D,ans);
    closeIO();
    return EXIT_SUCCESS;
}
