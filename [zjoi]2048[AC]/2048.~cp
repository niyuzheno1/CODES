//orz zyx
//ntr czr
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define clr(i, a) memset(i, (a), sizeof(i))
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
#define infi 0x7FFFFFFF
#define MUL 8221
using namespace std;

const int vec[][2] = {
	{0, -1},
	{0, 1},
	{-1, 0},
	{1, 0}
};
int px[2000];
const char dir[] = {'U', 'D', 'L', 'R'};

int map[4][4];
bool merged[4][4];
int seed, direction;
FILE* fout;

const int magic[][4] = {
	{23, 17, 14, 6},
	{17, 14,  6, 1},
	{14,  6,  1, 1},
	{6,   1,  1, 1}
};

bool bound(int x, int y)
{
	return x >= 0 && x < 4 && y >= 0 && y < 4;
}

int getfar(int x, int y, int d)
{
	int i = x, j = y;
	int ans = 0;
	for (;;)
	{
		i += vec[d][0];
		j += vec[d][1];
		++ans;
		if (!(bound(i, j) && map[i][j] == 0)) break;
	}
	return ans - 1;
}

void movetile(int x, int y, int d)
{
	if (!map[x][y]) return;
	int steps = getfar(x, y, d);
	int t = map[x][y];
	map[x][y] = 0;
	x += steps * vec[d][0];
	y += steps * vec[d][1];
	map[x][y] = t;
	int dx = x + vec[d][0], dy = y + vec[d][1];
	if (bound(dx, dy) && map[dx][dy] == map[x][y] && !merged[dx][dy])
	{
		map[dx][dy] = 2 * map[x][y];
		merged[dx][dy] = true;
		map[x][y] = 0;
	}
}

void inverse(int* a)
{
	swap(a[0], a[3]);
	swap(a[1], a[2]);
}

void move(int d)
{
	clr(merged, 0);
	int tx[] = {0, 1, 2, 3};
	int ty[] = {0, 1, 2, 3};
	if (vec[d][0] > 0) inverse(tx);
	if (vec[d][1] > 0) inverse(ty);
	rep(i, 0, 3)
		rep(j, 0, 3)
			movetile(tx[i], ty[j], d);
}

void initseed(int i)
{
	seed = i;
}

int getrandom()
{
	return (seed = (seed * MUL) + (seed >> 16)) & 15;
}

void pushrandom()
{
	int x, y;
	for (;;)
	{
		int p = getrandom();
		x = p % 4;
		y = p / 4;
		if (map[x][y] == 0) break;
	}
	map[x][y] = 2;
}

bool tileavailable()
{
	rep(i, 0, 3)
		rep(j, 0, 3)
			if (!map[i][j])
				return true;
	return false;
}

bool moveavailable(int d)
{
	rep(i, 0, 3)
		rep(j, 0, 3)
			if (map[i][j] != 0)
			{
				int dx = i + vec[d][0];
				int dy = j + vec[d][1];
				if (bound(dx, dy) && (map[dx][dy] == 0 || map[i][j] == map[dx][dy])) return true;
			}
	return false;
}

bool available()
{
	rep(i, 0, 3)
		if (moveavailable(i))
			return true;
	return false;
}

void process(int d)
{
	if (!moveavailable(d)) return;
	move(d);
	if (tileavailable()) pushrandom();
}

void print()
{	
	rep(i, 0, 3)
	{
		rep(j, 0, 3)
		{
			printf("%5d", map[j][i]);
		}
		printf("\n");
	}
}

int eval()
{
	int ans = 0;
	rep(i, 0, 3)
		rep(j, 0, 3)
			ans += magic[i][j] * map[i][j];
	return ans;
}

int dfs(int depth, int x)
{
	int est = eval();
	if (!available()) return -1;
	if (depth <= 0) return est;
	if (est < x * 0.7) return est;
	int ans = 0;
	int dir;

	rep(d, 0, 3)
		if (moveavailable(d))
		{
			int ts = seed;
			int temp[4][4];
			rep(i, 0, 3)
				rep(j, 0, 3)
					temp[i][j] = map[i][j];
			move(d);
			if (tileavailable()) pushrandom();
			int now = dfs(depth - 1, max(x, est));
			seed = ts;
			rep(i, 0, 3)
				rep(j, 0, 3)
					map[i][j] = temp[i][j];
			if (now > ans)
			{
				dir = d;
				ans = now;
			}
		}
	direction = dir;
	return ans;
}

bool ended()
{
	int a = 0;
	rep(i, 0, 3)
		rep(j, 0, 3)
			a = max(a, map[i][j]);
	if (a >= 32768) return true;
	return false;
}

int main()
{
    freopen("debug.txt","r",stdin);
	FILE * deb = fopen("debug2.txt","w");
    int s, depth;
	//scanf("%d%d", &s, &depth);
	s = 1,depth = 8;
    char buffer[10];
	sprintf(buffer, "2048%d.out", s);
	fout = fopen(buffer, "w");
	fprintf(fout, "%d\n", s);
	initseed(s);
	pushrandom();
	pushrandom();
	px['U'] = 0;px['D'] = 1;px['L'] = 2;px['R'] = 3;
	int time = 1;
	for (;;)
	{
		print();
		//int x;
		//scanf("%d", &x);
		//scanf("%d", &x);
		if(time == 233)
		 time = 233;
	 if(time== 231)
     time = 231;
	    fprintf(deb,"%d\n",seed);
		if (!available()) break;
		if (ended()) break;
		//dfs(depth, -1);
		direction = px[getchar()];
		fprintf(fout, "%c", dir[direction]);
		process(direction);++time;
	}
    fclose(deb);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

