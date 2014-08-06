#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib> 
#include<algorithm>
#include<map>
using namespace std;

#define mk make_pair
#define rep(i, s, t) for (int i = (s); i <= (t); ++i)
#define REP(i, n) rep(i, 1, n)
typedef pair<int, int> PII;
typedef long long LL;
const int MAX_M = 555555, MAX_N = 111111;
struct edge{
    int x, y, w;
    bool operator < (const edge &b) const{
        return w < b.w;
    }
}e[MAX_M];
struct node{
    node *c[2]; LL s;
}tn[111111 * 20], *rt[MAX_N], *nul;
int g[MAX_N << 1], nxt[MAX_N << 1], c[MAX_N << 1], nm;
int ff[MAX_N << 1], fa[MAX_N << 1][18], mm, bg[MAX_N << 1], ed[MAX_N << 1];
int tot, n, m, q, N, Altria;
int b[MAX_N], v[MAX_N], df[MAX_N << 1];
int rev[MAX_N];
long long lstans = 0;
int S; 

void decode(int &x, int &y){
	x = x ^ (lstans & S);
	y = y ^ (lstans & S);
}

int find(int x){
    return ff[x] == x ? x : ff[x] = find(ff[x]);
}

void add(int x, int y){
    g[nm] = y; nxt[nm] = c[x]; c[x] = nm; nm++;
}
/*
void dfs(int x){
    if (x <= Altria) ++mm, rev[mm] = x, bg[x] = ed[x] = mm;
    else bg[x] = n, ed[x] = 0;
    for (; ~c[x]; c[x] = nxt[c[x]]){
        if (g[c[x]] == fa[x][0]) continue;
        fa[g[c[x]]][0] = x;
        dfs(g[c[x]]);
        ed[x] = ed[g[c[x]]];
        bg[x] = min(bg[x], bg[g[c[x]]]);
    }
}
*/

int sk[MAX_N], stack[MAX_N], top;

void new_node(int x){
    if (x <= Altria) ++mm, rev[mm] = x, bg[x] = ed[x] = mm;
    else bg[x] = n, ed[x] = 0;
}

void dfs(int x){
	stack[top = 1] = x;
	sk[1] = c[x];
	new_node(x);
	while (top){
		if (sk[top] == -1){
            bg[stack[top - 1]] = min(bg[stack[top - 1]], bg[stack[top]]);
			ed[stack[top - 1]] = ed[stack[top]];
			top--;
		}
		else{
			int j = g[sk[top]], i = stack[top];
			sk[top] = nxt[sk[top]];
			if (fa[i][0] != j){
				fa[j][0] = i;
				new_node(j);
				stack[++top] = j;
				sk[top] = c[j];
			}
		}
	}
}

void build(node* &x, node *y, int l, int r, int v){
    x = tn + (++tot);
    x->c[0] = y->c[0], x->c[1] = y->c[1], x->s = y->s;
    x->s += b[v];
    if (l == r) return;
    int mid = (l + r) >> 1;
    if (v <= mid) build(x->c[0], y->c[0], l, mid, v);
    else build(x->c[1], y->c[1], mid + 1, r, v);
}

LL  query(node *x, node *y, int l, int r, int v){
    if (l == r) return x->s - y->s;
    int mid = (l + r) >> 1;
    if (v <= mid) return query(x->c[0], y->c[0], l, mid, v);
          else return query(x->c[1], y->c[1], mid + 1, r, v) + x->c[0]->s - y->c[0]->s;
}

LL  ask(int l, int r, LL v){
    if (v < 1) return 0;
    int av;
    if (v >= b[N]) av = N;
    else{
         int v2 = lower_bound(b + 1, b + 1 + N, v + 1) - b;
         av = v2 - 1;
    }
    return query(rt[r], rt[l - 1], 1, N, av);
}

inline int getint(){
       int x = 0; char c = getchar();
       while (!(c >= '0' && c <= '9')) c = getchar();
       while (c >= '0' && c <= '9'){
             x = x * 10 + c - '0';
             c = getchar();
       }
       return x;
}

int main(){
    freopen("sample.in", "r", stdin);
    freopen("sample.out", "w", stdout);
    memset(c, -1, sizeof c);
    scanf("%d%d%d%d", &n, &m, &q, &S);
    
    REP(i, n) scanf("%d", &v[i]), b[i] = v[i];
    sort(b + 1, b + 1 + n);
    N = unique(b + 1, b + 1 + n) - b - 1;
    REP(i, n) v[i] = lower_bound(b + 1, b + 1 + N, v[i]) - b;

    REP(i, m) scanf("%d%d%d", &e[i].x, &e[i].y, &e[i].w);
    sort(e + 1, e + 1 + m);
    REP(i, n) ff[i] = i;
    Altria = n; 
    REP(i, m){
        int a = find(e[i].x), b = find(e[i].y);
        if (a != b){
            ++n;
            add(n, a); add(n, b);
            ff[b] = ff[a] = n;
            ff[n] = n;
            df[n] = e[i].w;
        }
    }
    REP(i, n) find(i);
    REP(i, n) if (ff[i] == i) dfs(i);
    REP(k, 17) REP(x, n)
           fa[x][k] = fa[fa[x][k - 1]][k - 1];
    nul = tn;
    nul->c[0] = nul->c[1] = tn;
    rt[0] = nul;
    REP(i, mm) build(rt[i], rt[i - 1], 1, N, v[rev[i]]);
    
    double tt = 0, tt2 = 0, tt3 = 0;
    int ff = 0, ff2 = 0;
    int cc = 0;
    while (q--){
        ++cc;
        if(cc == 3) 
         cc =  3;
        int v, k;
        scanf("%d%d", &v, &k);
        decode(v, k);
        for (int j = 17; j >= 0; --j)
            if (fa[v][j] && df[fa[v][j]] <= k) v = fa[v][j];
        int l = bg[v], r = ed[v];
        LL now;
        /*for (now = 1; ; now++){
            LL s = ask(l, r, now);
            LL s2 = ask(l, r, now - 1);
            bool t = s - s2;
            if (t)
               now = s;
            else if (s == now - 1)
                    break;
                 else now = s;
        }*/
        for (now = 1; ; now++){
            LL s = ask(l, r, now);
            if (s == now - 1) break;
            else now = s;
        }
        printf("%I64d\n", now);
        lstans = now; 
    }
}
