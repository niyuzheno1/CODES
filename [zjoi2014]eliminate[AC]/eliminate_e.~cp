/* 
 * 2014-02-24  Token  <token@token-HP-ENVY-14-SPECTRE-Notebook-PC>

 * 
 */
#include <cstdio>
#include <cstring>
#include <cctype>
#include <climits>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdarg>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <exception>
#include <stdexcept>
#include <memory>
#include <locale>
#include <bitset>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>
#include <string>
#include <complex>
#include <valarray>

using namespace std;

template <class T> inline T checkmin(T &a, T b)
{
	return (a < b) ? a : a = b;
}

template <class T> inline T checkmax(T &a, T b)
{
	return (a > b) ? a : a = b;
}

template <class T> T GCD(T a, T b)
{
	if (a < 0)
		return GCD(- a, b);
	if (b < 0)
		return GCD(a, - b);
	return (a == 0) ? b : GCD(b % a, a);
}

template <class T> T LCM(T a, T b)
{
	if (a < 0)
		return LCM(- a, b);
	if (b < 0)
		return LCM(a, - b);
	return (a == 0 || b == 0) ? 0 : a / GCD(a, b) * b;
}

template <class T> T ExtGCD(T a, T b, T &x, T &y)
{
	if (a < 0)
	{
		T c = ExtGCD(- a, b, x, y);
		x = - x;
		return c;
	}
	if (b < 0)
	{
		T c = ExtGCD(a, - b, x, y);
		y = - y;
		return c;
	}
	if (a == 0)
	{
		x = 0, y = 1;
		return b;
	}
	else
	{
		T c = ExtGCD(b % a, a, y, x);
		x -= b / a * y;
		return c;
	}
}

template <class T> inline T sqr(T X)
{
	return X * X;
}

#define tr(i, x) for (typeof(x.begin()) i = x.begin(); i != x.end(); ++ i)
#define rep(i, n) for (int i = 0; i < n; ++ i)
#define pii pair <int, int>
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define ll long long
#define cmplxd complex <long double>
#define pi 3.14159265358979323846264338327950288

namespace Poor
{
	const int MaxiN = 1000005;
	
	int Row, Col, N, SzL1, SzL2;
	int A[MaxiN], B[MaxiN], C[MaxiN], D[MaxiN];
	int Start1[MaxiN], End1[MaxiN], Start2[MaxiN], End2[MaxiN];
	int Set11[MaxiN * 4], Set12[MaxiN * 4], Set21[MaxiN * 4], Set22[MaxiN * 4];
	bool Vis[MaxiN];
	pair <pii, int> List1[MaxiN * 4], List2[MaxiN * 4];
	
	int Find(int *S, int X)
	{
		if (S[X] < 0)
			return X;
		return (S[X] = Find(S, S[X]));
	}
	
	void Union(int *S, int X, int Y)
	{
		X = Find(S, X);
		Y = Find(S, Y);
		S[X] = Y;
	}
	
	void Insert(int X, int Y, int i)
	{
		List1[SzL1 ++] = mp(mp(X, Y), i);
		List2[SzL2 ++] = mp(mp(Y, X), i);
	}
	
	void Build1()
	{
		for (int i = 0, j = 0; i < SzL1; i = j)
		{
			for (; j < SzL1 && List1[i].x.x == List1[j].x.x; ++ j);
			Start1[List1[i].x.x] = i;
			End1[List1[i].x.x] = j - 1;
		}
	}
	
	void Build2()
	{
		for (int i = 0, j = 0; i < SzL2; i = j)
		{
			for (; j < SzL2 && List2[i].x.x == List2[j].x.x; ++ j);
			Start2[List2[i].x.x] = i;
			End2[List2[i].x.x] = j - 1;
		}
	}
	
	void Clear1()
	{
		fill(Set11, Set11 + SzL1, - 1);
		fill(Set12, Set12 + SzL1, - 1);
	}
	
	void Clear2()
	{
		fill(Set21, Set21 + SzL2, - 1);
		fill(Set22, Set22 + SzL2, - 1);
	}
	
	int Trans(char Ch)
	{
		if (Ch == 'L')
			return 0;
		if (Ch == 'R')
			return 1;
		if (Ch == 'U')
			return 2;
		if (Ch == 'D')
			return 3;
		return -1;
	}
	
	
	int FindPos(int X, int Y, int D)
	{
		if (D < 2)
		{
			int P = lower_bound(List1 + Start1[X], List1 + End1[X], mp(mp(X, Y), - 1)) - List1;
			if (D == 0)
				return List1[Find(Set11, P - 1)].x.y;
			else
				return List1[Find(Set12, P + 1)].x.y;
		}
		else
		{
			int P = lower_bound(List2 + Start2[Y], List2 + End2[Y], mp(mp(Y, X), - 1)) - List2;
			if (D == 2)
				return List2[Find(Set21, P - 1)].x.y;
			else
				return List2[Find(Set22, P + 1)].x.y;
		}
	}
	
	int FindColor(int X, int Y, int D)
	{
		if (D < 2)
		{
			if (D == 0)
			{
				int P = upper_bound(List1 + Start1[X], List1 + End1[X], mp(mp(X, Y), - 1)) - List1 - 1;
				return List1[Find(Set11, P)].y;
			}
			else
			{
				int P = lower_bound(List1 + Start1[X], List1 + End1[X], mp(mp(X, Y), - 1)) - List1;
				return List1[Find(Set12, P)].y;
			}
		}
		else
		{
			if (D == 2)
			{
				int P = upper_bound(List2 + Start2[Y], List2 + End2[Y], mp(mp(Y, X), - 1)) - List2 - 1;
				return List2[Find(Set21, P)].y;
			}
			else
			{
				int P = lower_bound(List2 + Start2[Y], List2 + End2[Y], mp(mp(Y, X), - 1)) - List2;
				return List2[Find(Set22, P)].y;
			}
		}
	}
	
	void Remove(int X, int Y)
	{
		int P1 = lower_bound(List1 + Start1[X], List1 + End1[X], mp(mp(X, Y), - 1)) - List1;
		int P2 = lower_bound(List2 + Start2[Y], List2 + End2[Y], mp(mp(Y, X), - 1)) - List2;
		Union(Set11, Find(Set11, P1), Find(Set11, P1) - 1);
		Union(Set12, Find(Set12, P1), Find(Set12, P1) + 1);
		Union(Set21, Find(Set21, P2), Find(Set21, P2) - 1);
		Union(Set22, Find(Set22, P2), Find(Set22, P2) + 1);
	}
	
	bool CanDel(int i)
	{
		int X1 = A[i], Y1 = B[i], X2 = C[i], Y2 = D[i];
		if (abs(X1 - X2) + abs(Y1 - Y2) <= 1)
			return 0;
		if (mp(X1, Y1) > mp(X2, Y2))
		{
			swap(X1, X2);
			swap(Y1, Y2);
		}
		if (X1 == X2)
			return FindPos(X1, Y1, Trans('R')) == Y2;
		if (Y1 == Y2)
			return FindPos(X1, Y1, Trans('D')) == X2;
		if (Y1 < Y2)
			return (FindPos(X1, Y1, Trans('D')) > X2 && FindPos(X2, Y2, Trans('L')) < Y1) || (FindPos(X1, Y1, Trans('R')) > Y2 && FindPos(X2, Y2, Trans('U')) < X1);
		else
			return (FindPos(X1, Y1, Trans('D')) > X2 && FindPos(X2, Y2, Trans('R')) > Y1) || (FindPos(X1, Y1, Trans('L')) < Y2 && FindPos(X2, Y2, Trans('U')) < X1);
	}
	
	void Del(int i)
	{
		int X1 = A[i], Y1 = B[i], X2 = C[i], Y2 = D[i];
		if (mp(X1, Y1) > mp(X2, Y2))
		{
			swap(X1, X2);
			swap(Y1, Y2);
		}
		if (X1 == X2)
			printf("%d %d L R\n", X1, Y1 + 1);
		else
		{
			if (Y1 == Y2)
				printf("%d %d U D\n", X1 + 1, Y1);
			else
			{
				if (Y1 < Y2)
				{
					if (FindPos(X1, Y1, Trans('D')) > X2 && FindPos(X2, Y2, Trans('L')) < Y1)
						printf("%d %d U R\n", X2, Y1);
					else
						printf("%d %d L D\n", X1, Y2);
				}
				else
				{
					if (FindPos(X1, Y1, Trans('D')) > X2 && FindPos(X2, Y2, Trans('R')) > Y1)
						printf("%d %d U L\n", X2, Y1);
					else
						printf("%d %d R D\n", X1, Y2);
				}
			}
		}
		Remove(X1, Y1);
		Remove(X2, Y2);
	}
	
	void Run(FILE *fi, FILE *fo, FILE *fa)
	{
		if (!fi)
		{
			FILE *fss = fopen("hp_eval.score", "w");
			fprintf(fss, "Fatal: Input!\n0\n");
			fclose(fss);
			return;
		}
		if (!fo)
		{
			FILE *fss = fopen("hp_eval.score", "w");
			fprintf(fss, "Fatal: Output!\n0\n");
			fclose(fss);
			return;
		}
		if (!fa)
		{
			FILE *fss = fopen("hp_eval.score", "w");
			fprintf(fss, "Fatal: Answer!\n0\n");
			fclose(fss);
			return;
		}
		fscanf(fi, "%d%d", &Row, &Col);
		fscanf(fi, "%d", &N);
		SzL1 = SzL2 = 0;
		rep (i, N)
		{
			fscanf(fi, "%d%d%d%d", A + i, B + i, C + i, D + i);
			Insert(A[i], B[i], i);
			Insert(C[i], D[i], i);
		}
		for (int i = 1; i <= Row; ++ i)
		{
			List1[SzL1 ++] = mp(mp(i, 0), - 1);
			List1[SzL1 ++] = mp(mp(i, Col + 1), - 1);
		}
		for (int i = 1; i <= Col; ++ i)
		{
			List2[SzL2 ++] = mp(mp(i, 0), - 1);
			List2[SzL2 ++] = mp(mp(i, Row + 1), - 1);
		}
		sort(List1, List1 + SzL1);
		sort(List2, List2 + SzL2);
		Build1();
		Build2();
		Clear1();
		Clear2();
		int K;
		int Score = 0;
		fscanf(fi, "%d", &K);
		rep (i, K)
		{
			int X, Y;
			char Ch1, Ch2;
			fscanf(fi, "%d %d %c %c", &X, &Y, &Ch1, &Ch2);
			int Next1 = FindColor(X, Y, Trans(Ch1));
			int Next2 = FindColor(X, Y, Trans(Ch2));
			int P = lower_bound(List1 + Start1[X], List1 + End1[X], mp(mp(X, Y), - 1)) - List1;

			if (List1[Find(Set11, P)].x.y == Y)
			{
				continue;
			}

			P = lower_bound(List2 + Start2[Y], List2 + End2[Y], mp(mp(Y, X), - 1)) - List2;

			if (List2[Find(Set21, P - 1)].x.y == X)
			{
				continue;
			}
			if (Next1 == Next2 && Next1 != - 1 && Next2 != - 1 && !(A[Next1] == X && B[Next1] == Y) && !(C[Next1] == X && D[Next1] == Y))
			{
				++ Score;
				Remove(A[Next1], B[Next1]);
				Remove(C[Next1], D[Next1]);
			}
		}
		int CS1, CS2;
		fscanf(fa, "%d %d", &CS1, &CS2);
		int HisScore = - 1;
		if (fscanf(fo, "%d", &HisScore) != 1)
		{
			FILE *fs = fopen("hp_eval.score", "w");
			fprintf(fs, "Incorrect Format!\n0\n");
			fclose(fs);
			return;
		}
		if (CS1 != HisScore)
		{
			FILE *fs = fopen("hp_eval.score", "w");
			fprintf(fs, "Wrong Score!\n0\n");
			fclose(fs);
			return;
		}
		if (fscanf(fo, "%d", &K) != 1)
		{
			FILE *fs = fopen("hp_eval.score", "w");
			fprintf(fs, "Incorrect Format!\n0\n");
			fclose(fs);
			return;
		}
		if (K < 0 || K > 1000000)
		{
			FILE *fs = fopen("hp_eval.score", "w");
			fprintf(fs, "Invalid Output!\n0\n");
			fclose(fs);
			return;
		}
		rep (i, K)
		{
			int X, Y;
			char Ch1, Ch2;
			if (fscanf(fo, "%d %d %c %c", &X, &Y, &Ch1, &Ch2) != 4)
			{
				FILE *fs = fopen("hp_eval.score", "w");
				fprintf(fs, "Incorrect Format!\n0\n");
				fclose(fs);
				return;
			}
			if (X <= 0 || X > Row || Y < 0 || Y > Col || Trans(Ch1) == - 1 || Trans(Ch2) == - 1)
			{
				FILE *fs = fopen("hp_eval.score", "w");
				fprintf(fs, "Invalid Command!\n0\n");
				fclose(fs);
				return;
			}
			int Next1 = FindColor(X, Y, Trans(Ch1));
			int Next2 = FindColor(X, Y, Trans(Ch2));
			

			int P = lower_bound(List1 + Start1[X], List1 + End1[X], mp(mp(X, Y), - 1)) - List1;

			if (List1[Find(Set11, P)].x.y == Y)
			{
				continue;
			}

			P = lower_bound(List2 + Start2[Y], List2 + End2[Y], mp(mp(Y, X), - 1)) - List2;

			if (List2[Find(Set21, P - 1)].x.y == X)
			{
				continue;
			}
			
			if (Next1 == Next2 && Next1 != - 1 && Next2 != - 1 && !(A[Next1] == X && B[Next1] == Y) && !(C[Next1] == X && D[Next1] == Y))
			{
				++ Score;
				Remove(A[Next1], B[Next1]);
				Remove(C[Next1], D[Next1]);
			}
		}
		if (Score != CS2)
		{
			FILE *fs = fopen("hp_eval.score", "w");
			fprintf(fs, "Not Optimal Method!\n0\n");
			fclose(fs);
			return;
		}
		FILE *fs = fopen("hp_eval.score", "w");
		fprintf(fs, "Good!\n10\n");
		fclose(fs);
	}
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		printf("usage: ./eliminate_e <in> <out> <ans>\nThe score will be in 'hp_eval.score'\n");
		FILE *fs = fopen("hp_eval.score", "w");
		fprintf(fs, "argc=%d\n10\n", argc);
		fclose(fs);
		return 1;
	}
	FILE *fi = fopen(argv[1], "r"), *fo = fopen(argv[2], "r"), *fa = fopen(argv[3], "r");
	Poor::Run(fi, fo, fa);
	fclose(fi), fclose(fo), fclose(fa);
	return 0;
}



