/*#include <cstdlib>
#include <iostream>
#include <map>

using namespace std;
const int inf = 0x7f7f7f7f;
map<int,int> f;
int n,m;
int s[36];
int a[596],b[596];
int main(int argc, char *argv[])
{
    freopen("lights.in","r",stdin);
    freopen("lights.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;i++)
     s[i-1] = 1<<(i-1);
    for(int i = 1;i<=m;i++){
     scanf("%d%d",&a[i],&b[i]);
     a[i]--;b[i]--;
    }
    for(int i = 1;i<=m;i++){
     s[a[i]] ^= (1<<b[i]);
     s[b[i]] ^= (1<<a[i]);
    }
    int r = (1<<n)-1;
    int r1 = (1<<(n/2))-1;
    int r2 = r-r1;
    
    for(int i = 0;i<=r1;i++)
    {
     int st = 0,ct = 0;
     for(int j = 0;j<n/2;j++)
      if((i & (1<<j)) != 0)
       st ^= s[j],ct++;
      if(f.count(st) == 0 || f[st] > ct)
       f[st] = ct;
    }
    int ans =inf;
    for(int i = r1+1;i<=r;i++)
    {
     int st = 0,ct = 0;
     for(int j = n/2;j<n;j++)
      if((i & (1<<j)) != 0)
       st ^= s[j],ct++;
     if(f.count(r^st) != 0)
     ans = min(ans,f[r^st]+ct);
    }
    printf("%d\n",ans);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
*/
#include <cstdio>
#include <algorithm>
using namespace std;

FILE *in = fopen ("lights.in", "r"), *out = fopen ("lights.out", "w");

const int MAXN = 40, MAX2P = 132000;

int N, M, P, Q, best = MAXN;
long long toggle [MAXN];
pair <long long, int> half [MAX2P];

int main () {
    fscanf (in, "%d %d", &N, &M);
    P = N / 2;
    Q = N - P;

    for (int i = 0; i < N; i++)
        toggle [i] = 1LL << i;

    for (int i = 0, a, b; i < M; i++) {
        fscanf (in, "%d %d", &a, &b); a--; b--;
        toggle [a] |= 1LL << b;
        toggle [b] |= 1LL << a;
    }

    for (int m = 0; m < 1 << P; m++)
        for (int i = 0; i < P; i++)
            if (m & 1 << i) {
                half [m].first ^= toggle [i];
                half [m].second++;
            }

    sort (half, half + (1 << P));

    for (int m = 0; m < 1 << Q; m++) {
        long long mask = 0;

        for (int i = 0; i < Q; i++)
            if (m & 1 << i)
                mask ^= toggle [i + P];

        int pos = lower_bound (half, half + (1 << P),
                       make_pair (((1LL << N) - 1) ^ mask, 0)) - half;

        if ((half [pos].first ^ mask) == (1LL << N) - 1)
            best = min (best, half [pos].second + __builtin_popcount (m));
    }

    fprintf (out, "%d\n", best);
    return 0;
}
