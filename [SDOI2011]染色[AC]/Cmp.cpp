#include <cstdio>  
#include <cstring>  
#include <algorithm>  
  
using namespace std;  
typedef long long lld;  
const int maxn = 100005;  
#define lson rt<<1, l, mid  
#define rson rt<<1|1, mid+1, r  
struct Edge{  
    int v, next;  
}edge[maxn<<1];  
struct N{  
    int num, l, r;  
}que[maxn<<2];  
int n, m, M, head[maxn], E, tot;  
int top[maxn], Fa[maxn], Dep[maxn], Son[maxn], Siz[maxn];  
int w[maxn], W[maxn], val[maxn], cov[maxn<<2];  
N Up(N L, N R){  
    if (!L.num)return R;  
    if (!R.num)return L;  
    N ans;  
    ans.num = L.num + R.num - (L.r == R.l);  
    ans.l = L.l; ans.r = R.r;  
    return ans;  
}  
void Down(int rt){  
    if (cov[rt] != -1){  
        cov[rt<<1] = cov[rt<<1|1] = cov[rt];  
        que[rt<<1] = que[rt<<1|1] = (N){1, cov[rt], cov[rt]};  
        cov[rt] = -1;  
    }  
}  
void build(int rt, int l, int r){  
    cov[rt] = -1;  
    if (l == r){  
        que[rt] = (N){1, W[l], W[r]};  
        return ;  
    }  
    int mid = r + l >> 1;  
    build(lson); build(rson);  
    que[rt] = Up(que[rt<<1], que[rt<<1|1]);  
}  
void update(int rt, int l, int r, int L, int R, int c){  
    if (l >= L && r <= R){  
        cov[rt] = c;  
        que[rt] = (N){1, c, c};  
        return ;  
    }  
    Down(rt);  
    int mid = r + l >> 1;  
    if (mid >= L)update(lson, L, R, c);  
    if (R > mid) update(rson, L, R, c);  
    que[rt] = Up(que[rt<<1], que[rt<<1|1]);  
}  
N query(int rt, int l, int r, int L, int R){  
    if (l >= L && r <= R){  
        return que[rt];  
    }  
    Down(rt);  
    int mid = r + l >> 1;  
    N res = (N){0, -1, -1};  
    if (mid >= L)res = query(lson, L, R);  
    if (R > mid){  
        if (res.num)return Up(res, query(rson, L, R));  
        else return query(rson, L, R);  
    }  
    return res;  
}  
  
void init(){  
    E = 0; tot = 0; top[1] = 1;  
    memset(head, -1, sizeof(head));  
}  
void add_edge(int u, int v){  
    edge[E].v = v;  
    edge[E].next = head[u];  
    head[u] = E++;  
}  
  
void dfs1(int fa, int u, int d){  
    Fa[u] = fa; Dep[u] = d; Siz[u] = 1; Son[u] = -1;  
    int Max = 0;  
    for (int i = head[u]; i != - 1; i = edge[i].next){  
        int v = edge[i].v;  
        if (v == fa)continue;  
        dfs1(u, v, d + 1);  
        Siz[u] += Siz[v];  
        if (Siz[v] > Max){  
            Max = Siz[v];  
            Son[u] = v;  
        }  
    }  
    return ;  
}  
void dfs2(int fa, int u){  
    w[u] = ++tot; W[tot] = val[u];  
    if (Son[u] == -1)return ;  
    for (int i = head[u]; i != -1; i = edge[i].next){  
        int v = edge[i].v;  
        if (v != Son[u])continue;  
        top[v] = top[u];  
        dfs2(u, v);  
    }  
    for (int i = head[u]; i != -1; i = edge[i].next){  
        int v = edge[i].v;  
        if (v == fa || v == Son[u])continue;  
        top[v] = v;  
        dfs2(u, v);  
    }  
}  
void C(int a, int b, int c){  
    while (top[a] != top[b]){  
        int f1 = top[a], f2 = top[b];  
        if (Dep[f1] >= Dep[f2]){  
            update(1, 1, m, w[f1], w[a], c);  
            a = Fa[f1];  
        }else {  
            update(1, 1, m, w[f2], w[b], c);  
            b = Fa[f2];  
        }  
    }  
    if (Dep[a] >= Dep[b]){  
        update(1, 1, m, w[b], w[a], c);  
    }else {  
        update(1, 1, m, w[a], w[b], c);  
    }  
}  
N Q(int a, int b){  
    N L, R;  
    L = R = (N){0, -1, -1};  
    if (top[a] != top[b]){  
        while (top[a] != top[b]){  
            int f1 = top[a], f2 = top[b];  
            if (Dep[f1] >= Dep[f2]){  
                L = Up(query(1, 1, m, w[f1], w[a]), L);  
                a = Fa[f1];  
            }else {  
                R = Up(query(1, 1, m, w[f2], w[b]), R);  
                b = Fa[f2];  
            }  
        }  
        if (Dep[a] >= Dep[b]){  
            L = Up(query(1, 1, m, w[b], w[a]), L);  
        }else {  
            R = Up(query(1, 1, m, w[a], w[b]), R);  
        }  
        swap(L.l, L.r);  
        return Up(L, R);  
    }else {  
        if (Dep[a] >= Dep[b])return query(1, 1, m, w[b], w[a]);  
        else return query(1, 1, m, w[a], w[b]);  
    }  
}  
  
int main(){  
    freopen("sample.in","r",stdin);
    freopen("sample.out","w",stdout);
    scanf("%d%d", &n, &M);  
    for (int i = 1; i <= n; i++){  
        scanf("%d", &val[i]);  
    }  
    init();  
    for (int i = 1; i < n; i++){  
        int a, b;  
        scanf("%d%d", &a, &b);  
        add_edge(a, b);  
        add_edge(b, a);  
    }  
    dfs1(0, 1, 0);  
    dfs2(0, 1);  
    m = tot;  
    build(1, 1, m);  
    while (M--){  
        char op[2];  
        int a, b, c;  
        scanf("%s%d%d", op, &a, &b);  
        if (op[0] == 'C'){  
            scanf("%d", &c);  
            C(a, b, c);  
        }else {  
            printf("%d\n", Q(a, b).num);  
        }  
    }  
    fclose(stdin);fclose(stdout);
    return 0;  
}  
