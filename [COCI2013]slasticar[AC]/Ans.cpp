#include "mode.h"
#include "data.h"
#undef INF
#define MN 100100
#define MM 100100
#define ML 100100
#define MND 262150
#define offset 131072
const int INF = ~0U>>1;
struct fenwick{
 int n,a[MN];
 fenwick()
 {
  n = MN-1;
  CLEAR(a,0);
 }
 void add(int idx){
  ++idx;
  for(int x = idx;x<=n;x+=lb(x)) ++a[x];
 }
 int get(int l,int r){
  int ret =0;
  for(;l>0;l-=lb(l)) ret -=a[l];
  for(;r>0;r-=lb(r)) ret += a[r];
  return ret;
 }
};
int n,m;
char s[MN],w[ML];
int id[18][MN];
int sa[MN],pos[MN];
int mm[18][MN];
int ans[MM];
vector<pii> bb[MM];
pii found[MM];
fenwick F;
struct tournament{
 int tree[MND];
 int from,to;
 void init_tree(){
  for(int i = 0;i<n;++i) tree[offset+i] = sa[i];
  for(int i = offset/2;i>0;i/=2)
   for(int j = i;j<2*i;++j)
     tree[j] = min(tree[2*j],tree[2*j+1]);
 }
 int get_min(int t,int lo,int hi){
    if(lo >= to || hi <= from) return INF;
    if(lo >= from && hi <= to) return tree[t];
    int mid = (lo+hi)/2;
    return min(get_min(2*t,lo,mid),get_min(2*t+1,mid,hi));
 }
 int get_min(int l,int r){
  from = l,to = r;
  return get_min(1,0,offset);
 }
}T;
struct cmp{
  int p;
  cmp(int _p):p(_p) {}
  bool operator ()(const int & a,const int & b){
    if(id[p][a] != id[p][b]) return id[p][a] < id[p][b];
    if(p== 0) return 0;
    int na = a+(1<<(p-1)),nb = b+(1<<(p-1));
    if(na >= n || nb >= n) return a > b;
    return id[p][na] < id[p][nb];
  }
};
void SA(){
  for(int i = 0;i<n;++i) sa[i] = i;
  for(int i = 0;i<n;++i) id[0][i]=s[i]-'0';
  cmp C(0);
  sort(sa,sa+n,C);
  int curr = 0;
  for(int p = 1;p<=17;++p){
   for(int i = 0;i<n;++i){
    if(i != 0 && C(sa[i-1],sa[i])) ++ curr;
    id[p][sa[i]] = curr;
   }
   C.p = p;
   sort(sa,sa+n,C);
  }
  for(int i = 0;i<n;++i) pos[sa[i]] = i;
}
pii find(int l,int r,int p,char d){
 pii ret;
 int lo=l,hi=r,mid;
 while(lo < hi){
  mid = (lo+hi)/2;
  int x = sa[mid]+p;
  if(x < n && s[x] >= d) hi = mid;
  else lo = mid+1;
 }
 ret.X = lo;
 lo = l,hi = r;
 while(lo < hi){
  mid = (lo+hi)/2;
  int x = sa[mid]+p;
  if(x >= n || s[x] <= d) lo = mid+1;
  else hi = mid;
 }
 ret.Y = lo;
 return ret;
}
int main(int argc, char *argv[])
{
    setIO("sample");
    scanf("%d",&n);
    scanf("%s",s);
    SA();
    T.init_tree();
    scanf("%d",&m);
    for(int i = 0;i<m;++i){
     scanf("%s",w);
     bb[i].resize(strlen(w));
     pii curr(0,n);
     for(int j = 0;w[j] != '\0';++j){
     curr = find(curr.X,curr.Y,j,w[j]);
     bb[i][j] = curr;
     }
     if(curr.X == curr.Y) found[i] = MP(n-1,i);
     else found[i] = MP(T.get_min(curr.X,curr.Y),i);
    }
    sort(found,found+m);
    int prev = 0;
    for(int i = 0;i<m;++i){
     int idx = found[i].Y;
     while(prev <= found[i].X) 
      F.add(pos[prev++]);
     ans[idx]+=prev;
     for(int j = 0;j<bb[idx].size();++j)
      ans[idx] += F.get(bb[idx][j].X,bb[idx][j].Y);
     if(bb[idx].back().X != bb[idx].back().Y) -- ans[idx];
    }
    for(int i = 0;i<m;++i) 
     printf("%d\n",ans[i]);
    closeIO();
    return EXIT_SUCCESS;
}
