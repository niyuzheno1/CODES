#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdlib>
using namespace std;
const int maxn = 50010;
struct node {
    int l, r, lp, pos;
    bool operator < (node t) const {
        return lp < t.lp || (lp == t.lp && r < t.r);
    }
}ask[maxn];
int num[maxn], num2[maxn], w[maxn], a[maxn], key[maxn];
int n, q, cnt, ans;
void update(int x, int v) {
    while(x <= cnt) {
        num[x] += v;
        x += x & -x;
    }
    return;
}
int sum(int x) {
    int res = 0;
    while(x) {
        res += num[x];
        x -= x & -x;
    }
    return res;
}
void update2(int x, int v) {
    while(x <= cnt) {
        num2[x] += v;
        x += x & -x;
    }
    return;
}
int sum2(int x) {
    int res = 0;
    while(x) {
        res += num2[x];
        x -= x & -x;
    }
    return res;
}
int main() {
    freopen("sample.in","r",stdin);
    freopen("sample.out","w",stdout);
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) {
        scanf("%d", &a[i]);
        w[i] = a[i];
    }
    sort(w + 1, w + n + 1);
    cnt = unique(w + 1, w + n + 1) - w - 1;
    for(int i = 1; i <= n; i ++) {
        a[i] = lower_bound(w + 1, w + cnt + 1, a[i]) - w;
    }
    scanf("%d", &q);
    int len = (int)(sqrt(n) + 0.5);
    for(int i = 1; i <= q; i ++) {
        scanf("%d%d", &ask[i].l, &ask[i].r);
        ask[i].lp = (ask[i].l - 1) / len + 1;
        ask[i].pos = i;
    }
    sort(ask + 1, ask + q + 1);
    int pl = 1, pr = 0;
    for(int i = 1; i <= q; i ++) {
        if(pr < ask[i].r) {
            for(pr ++; pr <= ask[i].r; pr ++) {
                ans += sum(cnt + 1 - a[pr]);
                update(cnt + 1 - a[pr] + 1, 1);
                update2(a[pr] + 1, 1);
            }
            pr --;
        } else if(pr > ask[i].r) {
            for(; pr > ask[i].r; pr --) {
                ans -= sum(cnt + 1 - a[pr]);
                update(cnt + 1 - a[pr] + 1, -1);
                update2(a[pr] + 1, -1);
            }
        }
        if(pl < ask[i].l) {
            for(; pl < ask[i].l; pl ++) {
                ans -= sum2(a[pl]);
                update(cnt + 1 - a[pl] + 1, -1);
                update2(a[pl] + 1, -1);
            }
        } else if(pl > ask[i].l) {
            for(pl --; pl >= ask[i].l; pl --) {
                ans += sum2(a[pl]);
                update(cnt + 1 - a[pl] + 1, 1);
                update2(a[pl] + 1, 1);
            }
            pl ++;
        }
        key[ask[i].pos] = ans;
    }
    for(int i = 1; i <= q; i ++) printf("%d\n", key[i]);
    fclose(stdin);fclose(stdout);
    return 0;
}
