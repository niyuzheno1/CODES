#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long s64;

const s64 S64_MAX = 9223372036854775807ll;

const int MaxN = 100000;
const int MaxM = 500000;

// getint
inline int getint()
{
    char c;
    while (c = getchar(), ('0' > c || c > '9') && c != '-');
    
	int res = c - '0';
	while (c = getchar(), '0' <= c && c <= '9')
		res = res * 10 + c - '0';
	return res;
}

struct number
{
	s64 id;
	number *lx, *rx;

	int pri;
	number *lc, *rc;
};
number num_pool[MaxM], *num_tail = num_pool;

template <class T>
int cmpT(const T &a, const T &b)
{
	if (a < b)
		return -1;
	else if (a > b)
		return 1;
	else
		return 0;
}
int numcmp(const number *lhs, const number *rhs)
{
	return cmpT(lhs ? lhs->id : 0, rhs ? rhs->id : 0);
}
int numxcmp(const number *lhs, const number *rhs)
{
	if (!lhs && !rhs)
		return 0;
	if (!lhs)
		return -1;
	if (!rhs)
		return 1;
	int c = numcmp(lhs->lx, rhs->lx);
	if (c == 0)
		c = numcmp(lhs->rx, rhs->rx);
	return c;
}

number *treap_root;

number *_treap_ins_p;
s64 _treap_ins_pL, _treap_ins_pR;

void zig(number *&y)
{
	number *x = y->lc;
	y->lc = x->rc;
	x->rc = y;
	y = x;
}
void zag(number *&y)
{
	number *x = y->rc;
	y->rc = x->lc;
	x->lc = y;
	y = x;
}

void _treap_insert(number *&p, s64 pL, s64 pR, number *np)
{
	if (!p)
	{
		_treap_ins_p = p = np;
		np->lc = np->rc = NULL;
	}
	else
	{
		int c = numxcmp(np, p);
		if (c < 0)
		{
			_treap_insert(p->lc, pL, p->id - 1, np);
			if (p->lc->pri < p->pri)
				zig(p);
		}
		else if (c > 0)
		{
			_treap_insert(p->rc, p->id + 1, pR, np);
			if (p->rc->pri < p->pri)
				zag(p);
		}
		else
			_treap_ins_p = p;
	}

	if (p == np)
		_treap_ins_pL = pL, _treap_ins_pR = pR;
}
void _treap_relabel(number *p, s64 pL, s64 pR)
{
	p->id = pL + (pR - pL) / 2;
	if (p->lc)
		_treap_relabel(p->lc, pL, p->id - 1);
	if (p->rc)
		_treap_relabel(p->rc, p->id + 1, pR);
}
number *treap_insert(number *np)
{
	_treap_insert(treap_root, 1, S64_MAX, np);
	if (np == _treap_ins_p)
		_treap_relabel(np, _treap_ins_pL, _treap_ins_pR);
	return _treap_ins_p;
}

int n, m;
number *a[MaxN + 1];
int seg[MaxN * 4 + 1];

int a_max(int i, int j)
{
	return numcmp(a[i], a[j]) >= 0 ? i : j;
}

void seg_update(int p)
{
	seg[p] = a_max(seg[p << 1 | 0], seg[p << 1 | 1]);
}

void seg_build(int p, int pL, int pR)
{
	if (pL == pR)
		seg[p] = pL;
	else
	{
		int pMid = (pL + pR) / 2;
		seg_build(p << 1 | 0, pL, pMid);
		seg_build(p << 1 | 1, pMid + 1, pR);
		seg_update(p);
	}
}
void seg_change(int p, int pL, int pR, int q)
{
	if (pL == pR)
	{
		seg[p] = pL;
		return;
	}

	int pMid = (pL + pR) / 2;
	if (q <= pMid)
		seg_change(p << 1 | 0, pL, pMid, q);
	else
		seg_change(p << 1 | 1, pMid + 1, pR, q);
	seg_update(p);
}
int seg_query(int p, int pL, int pR, int qL, int qR)
{
	if (qL <= pL && pR <= qR)
		return seg[p];

	int pMid = (pL + pR) / 2;
	if (pMid >= qR)
		return seg_query(p << 1 | 0, pL, pMid, qL, qR);
	else if (pMid < qL)
		return seg_query(p << 1 | 1, pMid + 1, pR, qL, qR);
	else
		return a_max(seg_query(p << 1 | 0, pL, pMid, qL, qR), seg_query(p << 1 | 1, pMid + 1, pR, qL, qR));
}

void init()
{
	seg_build(1, 1, n);

	treap_root = NULL;
}
void change(int l, int r, int k)
{
	num_tail->lx = a[l], num_tail->rx = a[r];
	num_tail->pri = rand();
	a[k] = treap_insert(num_tail);
	if (a[k] == num_tail)
		num_tail++;
	seg_change(1, 1, n, k);
}
int query(int l, int r)
{
	return seg_query(1, 1, n, l, r);
}

int main()
{
    freopen("sample.in","r",stdin);
    freopen("sample.out","w",stdout);
	srand(192737);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		a[i] = NULL;

	init();

	while (m--)
	{
		char type;
		while (type = getchar(), type != 'C' && type != 'Q');

		if (type == 'C')
		{
			int l = getint(), r = getint(), k = getint();
			change(l, r, k);
		}
		else if (type == 'Q')
		{
			int l = getint(), r = getint();
			printf("%d\n", query(l, r));
		}
		else
			cerr << "error!" << endl;
	}
    fclose(stdin);fclose(stdout);
	return 0;
}
