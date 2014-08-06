#include "mode.h"
#undef INF
#define MN 200010
#define INF 1000000000

 #define MS 524288
 struct node
 {
  int l,r,mid;
  pair<int,int> val;
 };
 node a[MS];
 void upd(int i)
 {
  a[i].val = min(a[i*2].val,a[i*2+1].val);
 }
 void build(int i,int bg,int ed,pair<int,int> * d)
 {
  a[i].l = bg;a[i].r = ed;a[i].mid = (bg+ed)/2;
  if(bg == ed) {a[i].val = d[bg];return;}
  build(i*2,bg,a[i].mid,d);build(i*2+1,a[i].mid+1,ed,d);
  upd(i);
 }
 pair<int,int> query(int i,int bg,int ed)
 {
  if(bg <= a[i].l && a[i].r <= ed) return a[i].val;
  if(ed <= a[i].mid) return query(i*2,bg,ed);
  if(a[i].mid < bg) return query(i*2+1,bg,ed);
  return min(query(i*2,bg,ed),query(i*2+1,bg,ed));
 }
 void change(int i,int pl,pair<int,int> val)
 {
  if(a[i].l == a[i].r) {
            a[i].val = val;
            return;
 }
  if(pl<=a[i].mid)change(i*2,pl,val);else change(i*2+1,pl,val);
  upd(i);
 }

typedef vector<pii> vp;
typedef vector<int> vi;
vp qlist[MN];
vi lis[MN];
int len[MN],cur[MN],dl[MN],final[MN];

 pii d[MN];
 void init(int n)
 {
  for(int i =1;i<=n;++i)
   if(cur[i] == len[i]) d[i] =MP(INF,0);
   else d[i] = qlist[i][cur[i]];
  build(1,1,n,d);
 }
 int bk;
 void query2(int l,int r,int rval)
 {
  if(l>r) return;
  while(1)
  {
   pair<int,int> val = query(1,l,r);
   if(val.X == 49)
			 val.X = 49;
   if(val.X > r)break;
   int i = dl[val.Y];
   if(i == 2) 
   i =2;
   while(cur[i]<len[i] && qlist[i][cur[i]].X <= r)
   {
    if(qlist[i][cur[i]].Y == 2)
     bk = 2;
    final[qlist[i][cur[i]].Y] = rval;
    ++cur[i];
   }
   if(cur[i] == len[i])
    change(1,i,MP(INF,0));
   else
    change(1,i,qlist[i][cur[i]]);
  }
 }

int main(int argc, char *argv[])
{
    setIO("sample");
    int n,qa; n = gi,qa = gi;
    for(int i = 0;i<=200001;++i)lis[i].pb(0);
    for(int i = 1;i<=n;++i)
    {
     int x = gi;lis[x].pb(i);
    }
    for(int i = 0;i<=200001;++i)lis[i].pb(n+1);
    for(int i = 1;i<=qa;++i)
    {
     int l=gi,r=gi;
     dl[i] = l;
     qlist[l].pb(MP(r,i));
    }
    for(int i = 1;i<=n;++i)
     sort(qlist[i].begin(),qlist[i].end());
    for(int i = 1;i<=n;++i)
     len[i]=qlist[i].size(),cur[i] = 0;
    init(n);
    for(int i = 0;i<=200001;++i)
     for(int k = 0;k<lis[i].size()-2;++k)
     query2(lis[i][k]+1,lis[i][k+1]-1,i);
    for(int i = 1;i<=qa;++i)
     printf("%d\n",final[i]);
    closeIO();
    return EXIT_SUCCESS;
}
