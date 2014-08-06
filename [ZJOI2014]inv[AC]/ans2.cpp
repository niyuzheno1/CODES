#include <set>
#include <map>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define MaxN 200010
#define eps 1e-6

using namespace std;

struct Counter{
	long double sigma[2], sqrsigma[2], sigmaxy;
}cnt[MaxN], Now, ccnt[MaxN];

struct Point {
	double x, y;
}poi[MaxN];

Counter operator - (Counter a, Counter b) {
	a.sigma[0] -= b.sigma[0]; a.sigma[1] -= b.sigma[1];
	a.sqrsigma[0] -= b.sqrsigma[0]; a.sqrsigma[1] -= b.sqrsigma[1];
	a.sigmaxy -= b.sigmaxy; return a;
}

Counter operator + (Counter a, Counter b) {
	a.sigma[0] += b.sigma[0]; a.sigma[1] += b.sigma[1];
	a.sqrsigma[0] += b.sqrsigma[0]; a.sqrsigma[1] += b.sqrsigma[1];
	a.sigmaxy += b.sigmaxy; return a;
}

int N, M, Q, m0, head[MaxN], prep[MaxN], v[MaxN], seed = 2333, fa[MaxN][20], dep[MaxN], cou[MaxN], cir[MaxN], cTotal, To[MaxN];
bool vis[MaxN], iscir[MaxN];

long double sinn, coss, oo = 1e5, Ans;

long double sqr(long double x) {
	return x * x;
}

long double Min(long double a, long double b) {
	return a < b ? a : b;
}

void AddEdge(int a, int b) {
	++m0; v[m0] = b; prep[m0] = head[a]; head[a] = m0;
}

void Dfs(int now) {
	vis[now] = 1;
	for(int i = head[now]; i; i = prep[i])
		if((!vis[v[i]]) && (!iscir[v[i]])) {
			cnt[v[i]].sigma[0] += cnt[now].sigma[0]; cnt[v[i]].sigma[1] += cnt[now].sigma[1];
			cnt[v[i]].sqrsigma[0] += cnt[now].sqrsigma[0]; cnt[v[i]].sqrsigma[1] += cnt[now].sqrsigma[1];
			cnt[v[i]].sigmaxy += cnt[now].sigmaxy;
			fa[v[i]][0] = now; dep[v[i]] = dep[now] + 1;
			Dfs(v[i]);
		}
}

void Search_Circle(int now) {
	cir[++cTotal] = now;
	To[now] = cTotal;
	vis[now] = 1;
	iscir[now] = 1;
	for(int i = head[now]; i; i = prep[i])
		if(!vis[v[i]])
			Search_Circle(v[i]);
}

int Que[MaxN], Qhead, Qtail;

void Bfs() {
	int i;
	Qhead = 1;
	for(i = 1; i <= N; ++i)
		if(cou[i] == 1)
			Que[++Qtail] = i;
	for( ; Qhead <= Qtail; ++Qhead) {
		vis[Que[Qhead]] = 1;
		for(i = head[Que[Qhead]]; i; i = prep[i]) {
			--cou[v[i]];
			if(cou[v[i]] == 1)
				Que[++Qtail] = v[i];
		}
	}
	for(i = 1; i <= N; ++i)
		if(!vis[i]) {
			Search_Circle(i);
			break;
		}
	memset(vis, 0, sizeof(vis));
	for(i = 1; i <= cTotal; ++i) {
		dep[cir[i]] = 1;
		fa[cir[i]][0] = cir[i];
		Dfs(cir[i]);
		ccnt[i] = ccnt[i - 1] + cnt[cir[i]];
	}
}

int LCA(int l, int r) {
	if(dep[l] < dep[r])
		swap(l, r);
	int d = dep[l] - dep[r], i;
	for(i = 0; d; d >>= 1, ++i)
		if(d & 1)
			l = fa[l][i];
	if(l == r)
		return l;
	for(i = 19; i >= 0; --i)
		if(fa[l][i] != fa[r][i]) {
			l = fa[l][i]; r = fa[r][i];
		}
	return fa[l][0];
}

long double Calc(long double k, long double tot) {
	return (k * k * (Now.sqrsigma[0] - sqr(Now.sigma[0]) / tot)
	      - 2.0 * k * (Now.sigmaxy - Now.sigma[0] * Now.sigma[1] / tot)
	      + (Now.sqrsigma[1] - sqr(Now.sigma[1]) / tot)
		  )
		  / (k * k + 1.0);
}

void GetAns(long double tot) {
	if(tot <= 2) {
		Ans = 0;
		return ;
	}
	long double A = (Now.sqrsigma[0] - sqr(Now.sigma[0]) / tot), B = - 2.0 * (Now.sigmaxy - Now.sigma[0] * Now.sigma[1] / tot),
	C = (Now.sqrsigma[1] - sqr(Now.sigma[1]) / tot);
	long double tA = 1, tB = -(A + C), tC = A * C - sqr(B) / 4.0;
	Ans = Min(Ans, (- tB - sqrt(sqr(tB) - 4.0 * tA * tC + 3 * eps)) / 2.0);
}

int main() {
	freopen("sample.in", "r", stdin);
	freopen("inv.out", "w", stdout);
	int i, j, a1, b1;
	sinn = sin(seed); coss = cos(seed);
	scanf("%d%d", &N, &M);
	for(i = 1; i <= N; ++i) {
		//cin >> poi[i].x >> poi[i].y;
		scanf("%lf%lf", &poi[i].x, &poi[i].y);
		long double nx = poi[i].x * coss - poi[i].y * sinn,
			   ny = poi[i].x * sinn + poi[i].y * coss;
		poi[i].x = nx; poi[i].y = ny;
		cnt[i].sigma[0] = nx; cnt[i].sigma[1] = ny; cnt[i].sqrsigma[0] = sqr(nx); cnt[i].sqrsigma[1] = sqr(ny);
		cnt[i].sigmaxy = nx * ny; 
	}
	for(i = 1; i <= M; ++i) {
		scanf("%d%d", &a1, &b1);
		AddEdge(a1, b1); AddEdge(b1, a1); ++cou[a1]; ++cou[b1];
	}
	if(M == N - 1) {
		dep[1] = 1;
		fa[1][0] = 1;
		Dfs(1);
	}
	else {
		Bfs();
	}
	for(j = 1; j <= 19; ++j)
		for(i = 1; i <= N; ++i)
			fa[i][j] = fa[fa[i][j - 1]][j - 1];
	scanf("%d", &Q);
	for(i = 1; i <= Q; ++i) {
		scanf("%d%d", &a1, &b1);
		Ans = 1e8;
		if(fa[a1][19] == fa[b1][19]) {
			int L = LCA(a1, b1);
			Now = cnt[a1] + cnt[b1] - cnt[L] - (fa[L][0] == L ? cnt[0] : cnt[fa[L][0]]);
			GetAns(dep[a1] + dep[b1] - 2 * dep[L] + 1);
			double pA = fabs(Ans + eps);
			printf("%.5lf\n", pA);
		}
		else {
			int ta = fa[a1][19], tb = fa[b1][19];
			if(To[ta] > To[tb]) swap(ta, tb);
			Now = cnt[a1] + cnt[b1] + ccnt[To[tb]] - ccnt[To[ta]] - cnt[tb];
			GetAns(dep[a1] + dep[b1] + To[tb] - To[ta] - 1);
			Now = cnt[a1] + cnt[b1] + ccnt[cTotal] - ccnt[To[tb]] + ccnt[To[ta]] - cnt[ta];
			GetAns(dep[a1] + dep[b1] + cTotal - To[tb] + To[ta] - 1);
			double pA = fabs(Ans);
			printf("%.5lf\n", pA);
		}
	}
	//while(1);
	return 0;
}
