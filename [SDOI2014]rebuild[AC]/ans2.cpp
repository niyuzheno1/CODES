#include "mode.h"
using namespace std;

#define for_(it,W) for(__typeof(W.begin())it=W.begin();it!=W.end();++it)

typedef  double LD;

const LD eps = 1e-8;
const int N = 105;

inline int sgn (LD x) { return fabs(x) < eps ? 0 : x > 0 ? 1 : -1; }

LD P[N][N], G[N][N];
int n, nID[N], m;
vector<LD> probs[N][N];

struct DSU
{
	int f[N];
	void init (int n)
	{
		for (int i = 0; i <= n; ++i) f[i] = i;
	}
	int find (int x) { return f[x] == x ? x : (f[x] = find(f[x])); }
	void merge (int x, int y) { f[find(x)] = find(y); }
} dsu;

LD Determinant (LD a[N][N], int n)
{
	LD res = 1;
	for (int i = 1; i <= n; ++i)
	{
		LD cur = 0; int k(i);
		for (int j = i; j <= n; ++j)
			if (fabs(a[j][i]) > cur)
			{ cur = fabs(a[k = j][i]); break; }

		if (sgn(cur) == 0)
			return 0;

		if (k != i) res = -res;

		for (int j = 1; j <= n; ++j)
			swap(a[k][j], a[i][j]);

		res *= a[i][i];

		for (int j = i + 1; j <= n; ++j)
		{
			LD d = -a[j][i] / a[i][i];
			for (int k = 1; k <= n; ++k)
				a[j][k] += d * a[i][k];
		}
	}
	return res;
}

int main ()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#else
	setIO("sample");
#endif
	cin >> n;
	dsu.init(n);

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> G[i][j];

	for (int i = 1; i <= n; ++i)
		for (int j = i; j <= n; ++j)
		{
			assert(G[i][j] == G[j][i]);
			if (sgn(1 - G[i][j]) == 0)
			{
				if (dsu.find(i) == dsu.find(j))
				{
					cout << 0 << endl;
					return 0;
				}
				dsu.merge(i, j);
			}
		}

	fill(nID, nID + 1 + n, 0);
	m = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (! nID[dsu.find(i)])
			nID[dsu.find(i)] = ++m;
	}
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= m; ++j)
		{
			probs[i][j].clear();
		}

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (sgn(1 - G[i][j]) != 0 && (dsu.find(i) != dsu.find(j) || i < j))
				probs[nID[dsu.find(i)]][nID[dsu.find(j)]].push_back(G[i][j]);

	LD base = 1;
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= m; ++j)
		{
			LD p0 = 1, p1 = 0;
			for_(it, probs[i][j])
				p0 *= 1 - *it;

			for_(it, probs[i][j])
				p1 += p0 * *it / (1 - *it);
            ff(debug,"%lf %lf\n",p0,p1);
			if (i == j)
			{
				base *= p0;
				P[i][j] = 0;
			}
			else
			{
				if (i < j)
					base *= p0;

				P[i][j] = p1 / p0;
			}
		}
cout.setf(ios::fixed);
  for (int i = 1; i <= m;printf("\n"),++i)
		for (int j = 1; j <= m; ++j)
		 cout<<setprecision(2)<<P[i][j]<<' ';
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= m; ++j)
		{
			if (i != j)
			{
				P[i][i] += P[i][j];
				P[i][j] = -P[i][j];
			}
		}
	
	base *= Determinant(P, m - 1);
	
	cout << setprecision(20) << base << endl;
	closeIO();
    return 0;
}
