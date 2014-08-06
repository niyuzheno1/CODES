#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 500000;

int bas[16], com[64][64];
bool okay[maxn];

int code(bool a[4][4]) {
  int r = 0, now = 0;
  for (int i = 0; i < 4; i++) for (int j = i + 1; j < 4; j++) {
    if (a[i][j]) r |= 1 << now;
    now++;
  }
  return r;
}

void decode(int r, bool a[4][4]) {
  int now = 0;
  for (int i = 0; i < 4; i++) a[i][i] = 0;
  for (int i = 0; i < 4; i++) for (int j = i + 1; j < 4; j++) {
    if (r & (1 << now)) a[i][j] = a[j][i] = 1; else a[i][j] = a[j][i] = 0;
    now++;
  }
}

void floyd4(bool a[4][4]) {
  int n = 4;
  for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (a[i][k] && a[k][j]) a[i][j] = 1;  
}

void floyd8(bool a[8][8]) {
  int n = 8;
  for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (a[i][k] && a[k][j]) a[i][j] = 1;  
}

int basic(int t) {
  bool a[4][4] = {0};
  if (t & (1 << 0)) a[0][1] = a[1][0] = 1;
  if (t & (1 << 1)) a[2][3] = a[3][2] = 1;
  if (t & (1 << 2)) a[0][2] = a[2][0] = 1;
  if (t & (1 << 3)) a[1][3] = a[3][1] = 1;
  floyd4(a);
  return code(a);
}

int combine(int lef, int rig) {
  bool a[4][4], b[4][4], c[8][8] = {0}, d[4][4];
  decode(lef, a);
  decode(rig, b);
  for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) {
    if (a[i][j]) {
      c[i][j] = c[j][i] = 1;
    }
    if (b[i][j]) {
      c[i + 4][j + 4] = c[j + 4][i + 4] = 1;
    }
  }
  c[1][4] = c[4][1] = 1;
  c[3][6] = c[6][3] = 1;
  floyd8(c);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      int ni = i, nj = j;
      if (ni % 2 == 1) ni += 4;
      if (nj % 2 == 1) nj += 4;
      d[i][j] = c[ni][nj];
    }
  }
  return code(d);
}

void precalc() {
  for (int i = 0; i < 16; i++) bas[i] = basic(i);
  for (int i = 0; i < 64; i++) for (int j = 0; j < 64; j++) com[i][j] = combine(i, j);
}

struct node {
  int sty, con, l, r;
  node *lef, *rig;
  int connect(int ll, int rr) {
    if (ll == rr) {
      bool a[4][4] = {0};
      a[0][1] = a[2][3] = 1;
      a[1][0] = a[3][2] = 1;
      if (okay[ll]) {
	a[0][2] = a[2][0] = 1;
	a[1][3] = a[3][1] = 1;
      }
      floyd4(a);
      return code(a);
    }
    if (ll <= l && rr >= r) return con;
    int mid = (l + r) / 2;
    if (rr <= mid) return lef->connect(ll, rr);
    if (ll >= mid) return rig->connect(ll, rr);
    int lf = lef->connect(ll, rr);
    int rg = rig->connect(ll, rr);
    return com[lf][rg];
  }
  void modify(int r1, int c1, int r2, int c2, bool open) {
    if (l + 1 == r) {
      int id;
      if (r1 == r2) id = r1; else {
	if (c1 == l) id = 2; else id = 3;
      }
      if (open) sty |= 1 << id; else {
	if (sty & (1 << id)) sty ^= 1 << id;
      }
      con = bas[sty];
    } else {
      int mid = (l + r) / 2;
      if (c2 <= mid) lef->modify(r1, c1, r2, c2, open); 
      if (c1 >= mid) rig->modify(r1, c1, r2, c2, open);
      con = com[lef->con][rig->con];
    }
  }
} tr[maxn];

int m, n, tl;

void build(int l, int r) {
  node *p = &tr[m++];
  p->l = l;
  p->r = r;
  if (l + 1 == r) {
    p->sty = 0;
    p->con = bas[0];
  } else {
    int mid = (l + r) / 2;
    p->lef = tr + m;
    build(l, mid);
    p->rig = tr + m;
    build(mid, r);
  }
}

void solve() {
  char cmd[20];
  bool a[4][4];
  for (int i = 1; i <= n; i++) okay[i] = 0;
  while (scanf("%s", cmd) == 1 && strcmp(cmd, "Exit")) {
    int r1, c1, r2, c2;
    scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
    r1--;
    r2--;
    if (c1 > c2) {
      swap(r1, r2);
      swap(c1, c2);
    }
    if (strcmp(cmd, "Open") == 0) {
      if (c1 == c2) okay[c1] = 1;
      tr[0].modify(r1, c1, r2, c2, 1);
    } else if (strcmp(cmd, "Close") == 0) {
      if (c1 == c2) okay[c1] = 0;
      tr[0].modify(r1, c1, r2, c2, 0);
    } else {
      int g = tr[0].connect(1, c1);
      decode(g, a);         
      bool lll = a[1][3];
      g = tr[0].connect(c2, n);
      decode(g, a);
      bool rrr = a[0][2];
      g = tr[0].connect(c1, c2);
      decode(g, a);
      if (lll) a[0][2] = a[2][0] = 1;
      if (rrr) a[1][3] = a[3][1] = 1;
      floyd4(a);
      int t1 = r1 * 2, t2 = r2 * 2 + 1;
      printf("%s\n", a[t1][t2] ? "Y" : "N");
    }
  }
}

int main() {
	freopen("traffic.in", "r", stdin); 
	freopen("traffic.out", "w", stdout);
	precalc();
    scanf("%d", &n);
    bool flag = 0;
    if (n == 1) {      
      n = 2;
      flag = 1;
    }
    m = 0;
    build(1, n);
    if (flag) {
      tr[0].modify(0, 1, 0, 2, 0);
      tr[0].modify(1, 1, 1, 2, 0);
    }
    solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
