#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;

const ll inf = 1ll << 58;
const int maxn = 20005;
const int maxm = 50005;
const int maxq = 50005;
const int logn = 35;

struct edge{
       int x, y;
       ll v, z;
}e[maxm], tmp[maxm * logn], *cur = tmp, *sorte;
struct query{
       int num;
       ll val;
}ask[maxq], tmp2[maxq * logn], *now = tmp2;
int n, m, q, trans[maxn], id[maxm], fa[maxn];
ll res[maxq];
bool able[maxm];

bool cmp(int a, int b){
    return sorte[a].v < sorte[b].v;
}
int F(int x){ 
    return fa[x] == x ? x : fa[x] = F(fa[x]);
}
bool merge(int x, int y){
    x = F(x), y = F(y);
    if (x != y){
          fa[x] = y;
          return true;
    }else return false;
}
#define md (l + r >> 1)
void solve(int l, int r, int n, int m, edge* e, ll added){
    if (l == r){
        for (int i = 1; i <= n; i ++) fa[i] = i;
        e[ask[l].num].z = ask[l].val;
        
        for (int i = 1; i <= m; i ++){
            e[i].v = e[i].z;
            id[i] = i;
        }
        sorte = e;
        sort(id + 1, id + 1 + m, cmp);
        for (int i = 1; i <= m; i ++)
            if (merge(e[id[i]].x, e[id[i]].y)) 
               added += e[id[i]].v;
        res[l] = added;
        return ;
    }
    
    //reduce edges
    for (int i = 1; i <= m; i ++) e[i].v = e[i].z, able[i] = false;
    for (int i = l; i <= r; i ++) e[ask[i].num].v = inf, able[ask[i].num] = true;
    for (int i = 1; i <= m; i ++) id[i] = i;
    sorte = e;
    sort(id + 1, id + 1 + m, cmp);
    for (int i = 1; i <= n; i ++) fa[i] = i;
    for (int i = 1; i <= m; i ++) 
        able[id[i]] |= merge(e[id[i]].x, e[id[i]].y);
    
    int mm = 0;
    edge* nxe = cur;
    for (int i = 1; i <= m; i ++)
        if (able[i]){
             trans[i] = ++ mm;
             nxe[mm] = e[i];
         }
    for (int i = l; i <= r; i ++) ask[i].num = trans[ask[i].num];
    
    cur += mm;
    
    //reduce vertices
    for (int i = 1; i <= mm; i ++) nxe[i].v = nxe[i].z, able[i] = false;
    for (int i = l; i <= r; i ++) nxe[ask[i].num].v = - inf;
    for (int i = 1; i <= mm; i ++) id[i] = i;
    sorte = nxe;
    sort(id + 1, id + 1 + mm, cmp);
    for (int i = 1; i <= n; i ++) fa[i] = i;
    for (int i = 1; i <= mm; i ++)
        if (merge(nxe[id[i]].x, nxe[id[i]].y) && nxe[id[i]].v != -inf) 
            able[id[i]] = true, added += nxe[id[i]].v;
    
    int nn = 0;
    for (int i = 1; i <= n; i ++) fa[i] = i;
    for (int i = 1; i <= mm; i ++) 
        if (able[i]) merge(nxe[i].x, nxe[i].y);
        
    for (int i = 1; i <= n; i ++) 
       if (fa[i] == i) id[i] = ++ nn;
    for (int i = 1; i <= n; i ++) 
        id[i] = id[F(i)];
    for (int i = 1; i <= mm; i ++)
            nxe[i].x = id[nxe[i].x], nxe[i].y = id[nxe[i].y];
    
    query *tmpstore = now;
    for (int i = l; i <= md; i ++) tmpstore[i - l] = ask[i];
    now += (md - l + 1);
    
    solve(l, md, nn, mm, nxe, added);
    
    for (int i = l; i <= md; i ++) ask[i] = tmpstore[i - l];
    now -= (md - l + 1);
    
    for (int i = l; i <= md; i ++)
        nxe[ask[i].num].z = ask[i].val;
    solve(md + 1, r, nn, mm, nxe, added);
    
    cur -= mm;
} 
int main(){
    freopen("sample.in","r",stdin);
    freopen("sample.out","w",stdout);
    scanf("%d%d%d",&n,&m,&q);
    for (int i = 1; i <=  m; i ++) 
       scanf("%d%d%lld",&e[i].x,&e[i].y,&e[i].z), e[i].v = e[i].z;
    for (int i = 1; i <= q; i ++)
        scanf("%d%lld",&ask[i].num, &ask[i].val);
    solve(1, q, n, m, e, 0);
    for (int i = 1; i <= q; i ++) printf("%lld\n",res[i]);
    fclose(stdin);fclose(stdout);
    return 0;
}
