#include "mode.h"
const int maxn = 210000;
struct node {node *l, *r; int bh, kind, xx, xd, yx, yd;} g[maxn], *root;
struct poin {int x, y;} a[maxn];   //1-->y  0-->x
int tot, i, n, bh[maxn], px, py, pk, pbh[maxn], m;
long long d[25];

int comy(int p, int q) {return a[p].y < a[q].y;}

int comx(int p, int q) {return a[p].x < a[q].x;}

void up(int &a, int b) {if (b > a) a = b;}

void dw(int &a, int b) {if (b < a) a = b;}

node *build(int l, int r, int k)
{
      node *p = &g[++tot];
     sort(bh + l, bh + r + 1, k ? comy : comx);
       int mid = (l + r) >> 1;
    p->bh = bh[mid], p->kind = k;
      p->xx = p->xd = a[bh[mid]].x;
      p->yx = p->yd = a[bh[mid]].y;
      if (l < mid) 
    {
                p->l = build(l, mid - 1, !k);
             up(p->xd, p->l->xd); dw(p->xx, p->l->xx);
              up(p->yd, p->l->yd); dw(p->yx, p->l->yx);
      }
        if (r > mid) 
    {
                p->r = build(mid + 1, r, !k);
             up(p->xd, p->r->xd); dw(p->xx, p->r->xx);
              up(p->yd, p->r->yd); dw(p->yx, p->r->yx);
      }
        return p;
}

long long dist(int x, int y) {return 1LL * x * x + 1LL * y * y;}

void updata(int x)
{
  long long mid = dist(px - a[x].x, py - a[x].y);
  for (int j = 1; j <= pk; ++j)
             if (mid > d[j] || ((mid == d[j]) && pbh[j] > x))
           {
                        for (int k = pk; k > j; --k)
                              d[k] = d[k - 1], pbh[k] = pbh[k - 1];
                    d[j] = mid, pbh[j] = x;
                  return ;
         }
}

void answer(node *p, int k)
{
   if (!p || dist(max(abs(px - p->xx), abs(px - p->xd)), max(abs(py - p->yx), abs(py - p->yd))) < d[pk]) return;
 updata(p->bh);
    if (k ? (a[p->bh].y < py || ((a[p->bh].y == py) && a[p->bh].x < px)) : (a[p->bh].x < px || ((a[p->bh].x == px) && a[p->bh].y < py)))  
            answer(p->l, !k), answer(p->r, !k);
        else answer(p->r, !k), answer(p->l, !k);
}

int main()
{
      setIO("sample");
       scanf("%d", &n);
 for (i = 1; i <= n; bh[i] = i, ++i)
               scanf("%d%d", &a[i].x, &a[i].y);
 root = build(1, n, 0);
   for (scanf("%d", &m); m; --m)
    {
                scanf("%d%d%d", &px, &py, &pk);
          memset(d, -1, sizeof(d));
                answer(root, 0);
         printf("%d\n", pbh[pk]);
 }
 closeIO();
        return 0;
}
