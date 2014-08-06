#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#define rep(i, n) for(int i = 1; i <= n; ++i)
#define debug(x) cout << #x << " = " << x << endl
using namespace std;

const int maxn = 2000 + 10;
const int Mod = 1000000000 + 9;

long long fact[maxn], c[maxn][maxn];

int n, k;
long long f[maxn][maxn];
int a[maxn], b[maxn], r[maxn];

void Init() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; ++i)
		scanf("%d", &b[i]);

	fact[0] = 1;
	rep (i, maxn - 1)
		fact[i] = (long long)(fact[i-1] * i) % Mod;
	for (int i = 0; i < maxn; ++i) {
		c[i][0] = c[i][i] = 1;
		rep(j, i - 1)
			c[i][j] = (c[i-1][j] + c[i-1][j-1]) % Mod;
	}
}
void solve() {
	k = (n - k) / 2 + k;
	sort(a, a + n);
	sort(b, b + n);
	for (int i = 0; i < n; ++i) {
		if (i > 0)
			r[i] = r[i-1];
		while (r[i] < n && b[r[i]] < a[i])
			r[i]++;
	}

	f[0][0] = 1;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j <= i; ++j) {
			if (f[i][j] == 0)
				continue;
			f[i+1][j+1] = (f[i+1][j+1] + (long long)(f[i][j] * max(r[i] - j, 0))) % Mod;
			f[i+1][j] = (f[i+1][j] + f[i][j]) % Mod;
		}
	for (int i = n; i >= 0; --i) {
		f[n][i] = (long long)(f[n][i] * fact[n-i]) % Mod;
		for (int j = i + 1; j <= n; ++j)
			f[n][i] = (f[n][i] - ((long long)(f[n][j]) * c[j][i]) % Mod + Mod) % Mod;
	}

	cout << f[n][k] << endl;
}

int main() {
	freopen("sample.in", "r", stdin);

	Init();
	if ((n - k) & 1)
		cout << 0 << endl;
	else solve();

	return 0;
}
