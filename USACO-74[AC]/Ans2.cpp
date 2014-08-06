#include <cstdlib>
#include <iostream>
#include <vector>
#include <set>
#define sqr(x) (x)*(x)
#define X first
#define Y second
using namespace std;
typedef long long int64;
const int64 inf = 1000000000;
typedef vector<int> v;
struct poss
{
 int64 d,c,t,ch;
};
typedef set<poss> se;
bool operator<(poss a,poss b){
  if(a.ch || b.ch)
   return a.t<b.t;
  if(a.d > b.d) return true;
  if(a.d < b.d) return false;
  return a.c<b.c;
}
int n;
v e[50010];
bool vi[50010];
long long d[50010];
long long of[50010];
se * be[50010];
int h(poss a,poss b)
{
 return (a.c-b.c+sqr(a.d)-sqr(b.d))/(2*(b.d-a.d));
}
void up(int64 & c,poss a,poss b)
{
     while((2*(b.d-a.d))*c < (a.c-b.c+sqr(a.d)-sqr(b.d)))
      c++;
}
void dfs(int x)
{
     vi[x] = 1;
     int64 bp = -1;
     int64 asf = 0;
     for(int i = 0;i<e[x].size();i++){
      if(vi[e[x][i]])
       continue;
      d[e[x][i]] = d[x]+1;
      dfs(e[x][i]);
      int64 tadd;
      {    poss w = {0,0,-d[x],true};
           se::iterator wh = be[e[x][i]]->upper_bound(w);
           wh--;
           tadd = sqr(d[x]-wh->d)+wh->c+of[e[x][i]];
      }
      if(bp != -1) bp+= tadd;
      if(be[x] == 0){
       be[x] = be[e[x][i]];
       of[x] = of[e[x][i]];
      } else {
       se * s = be[x],* t = be[e[x][i]];
       int64 os = of[x]+tadd,ot = of[e[x][i]]+asf;
       if(s->size() < t->size())
        swap(s,t),swap(os,ot);
       for(se::iterator it = t->begin();it != t->end();it++){
        poss w = {0,0,it->d-2*d[x],true};
        se::iterator wh = s->upper_bound(w);
        wh--;
        int tp = sqr(it->d+wh->d-2*d[x])+it->c+wh->c+of[x]+of[e[x][i]];
        if(bp == -1 || tp < bp)
         bp = tp;
       }
       for(se::iterator it = t->begin();it != t->end();it++){
          poss p = *it;p.c += ot-os;
          se::iterator w = s->insert(p).X;
          bool kill = 0;
          while (w != s->begin()){
          se::iterator prev = w;prev--;
          if(prev->d == w->d){
           s->erase(w);kill = 1;
           break;
          }
          p.t = h(*w,*prev);up(p.t,*w,*prev);
          s->erase(w);w = s->insert(p).X;
          if(w->t <= prev->t)
            s->erase(prev);
          else
           break;
         }
         if(kill)
          continue;
         if(w == s->begin()){
          p.t = -inf;s->erase(w);w = s->insert(p).X;
         }
         se::iterator next = w;
         next++;
         while(next != s->end()){
          if(next->d == w->d){
            s->erase(next);next = w;next++;
            continue;
          }
          poss n = *next;
          n.t = h(*next,*w);up(n.t,*next,*w);
          if(n.t <= (*w).t){
           s->erase(w);
           break;
          }
          s->erase(n);next = s->insert(n).X;
          se::iterator nnext = next;nnext++;
          if(nnext != s->end() && nnext->t <= next->t){
           s->erase(next);
           next = nnext;
          }
          else
           break;
       }
      }
      be[x] = s;
      of[x] = os;
      delete t;
     }
     asf += tadd;
   }
   if(be[x] == 0){
    be[x] = new se();
    poss p = {d[x],0,-inf,false};
    be[x]->insert(p);
   }
   else if(bp != -1){
    poss p = {d[x],bp-of[x],0,false};
    while(!be[x]->empty()){
    p.t = h(p,*be[x]->rbegin());up(p.t,p,*be[x]->rbegin());
    if(p.t > be[x]->rbegin()->t)
     break;
    be[x]->erase(*(be[x]->rbegin()));
    }
    if(be[x]->empty()) p.t = -inf;
    be[x]->insert(p);
   }
}
int main(int argc, char *argv[])
{
    freopen("solder.in","r",stdin);
    freopen("solder.out","w",stdout);
    scanf("%d",&n);
    for(int i = 0;i<n-1;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    a--,b--;
    e[a].push_back(b);
    e[b].push_back(a);
    }
    dfs(0);
    if(e[0].size() == 1){
     poss w = {0,0,0,true};
     se::iterator wh = be[0]->upper_bound(w);
     wh--;
     printf("%I64d",wh->d*wh->d+wh->c+of[0]);
    }
    else {
      poss p = *(be[0]->rbegin());
      printf("%I64d",p.c+of[0]);
    }
    fclose(stdin);
    fclose(stdout);
    return EXIT_SUCCESS;
}
