#include <stdio.h>
#include <string.h>
#define maxn 100000
#define maxh 200003
#define maxH 1000000003LL

int ind[maxn], next[maxn * 2], to[maxn * 2], p;
int n;
int used[maxn];
int f;
int stack[maxn], sp;

int hash[maxh], hashans[maxh], hp;
int hashlib[maxh][3];
long long h1[maxn], h2[maxn];

long long hash2[maxh];

int addhash (int *data) {
    long long c = 123456;
    for (int i = 0; i < 3; i ++)
        c = c * 47 ^ data[i];
    c = c * 47 % maxh;
    while (hash[c] != -1 && (hashlib[c][0] != data[0] || hashlib[c][1] !=
data[1] || hashlib[c][2] != data[2])) {
        c ++;
        if (c == maxh)
            c = 0;
        }
    if (hash[c] == -1) {
        hashlib[c][0] = data[0];
        hashlib[c][1] = data[1];
        hashlib[c][2] = data[2];
        hash[c] = hp ++;
        }
    return hash[c];
    }

int add2 (long long x, int i) {
    long long c = x % maxh;
    c = c * 47 % maxh;
    while (hash2[c] != -1 && hash2[c] != x) {
        c ++;
        if (c == maxh)
            c = 0;
        }
    if (hash2[c] == -1) {
        hash2[c] = x;
        hash[c] = i;
        return -1;
        }
    else
        return hash[c];
    }

int test (int a, int b) {
    for (int i = 0; i < sp; i ++)
        if (stack[i + a >= sp? i + a - sp: i + a] != stack[i + b >= sp? i
+ b -
sp: i + b])
            return 0;
    return 1;    
    }

int dfs2 (int x, int dad) {

    int lib[3], lp = 0;
    
    for (int i = ind[x]; i != -1; i = next[i])
        if (to[i] != dad && !used[to[i]])
            lib[lp ++] = dfs2(to[i], x);
    if (dad == -1)
        lib[lp ++] = maxh - 2;
    while (lp < 3)
        lib[lp ++] = maxh - 1;
    for (int i = 0; i < 3; i ++)
        for (int j = 0; j < 2; j ++)
            if (lib[j] > lib[j + 1])
                lib[j] ^= lib[j + 1] ^= lib[j] ^= lib[j + 1];
    lp = addhash(lib);
    int ans = 0;
    for (int i = 0; i < 3; i ++)
        if (lib[i] != maxh - 1 && lib[i] != maxh - 2 && (i == 0
|| lib[i] !=
lib[i-1]))
            ans += hashans[lib[i]];
    if (lib[2] == maxh - 1)
        ans ++;
    hashans[lp] = ans;
    return lp;
    }

void dfs (int x, int dad) {
    if (f)
        return;
    if (used[x] != 0xFEFEFEFE) {
        f = 1;
        sp = 0;
        dad = to[dad];
        stack[sp ++] = dad;
        while (dad != x) {
            dad = used[dad];
            stack[sp ++] = dad;
            }
        return;
        }
    used[x] = dad == -1? -1 : to[dad];
    for (int i = ind[x]; i != -1; i = next[i])
        if (i != dad)
            dfs(to[i], i^1);
    }

int main () {
    int i, a, b, c;
    
    //freopen("cowmstr.in", "r", stdin);
    //freopen("cowmstr.out", "w", stdout);
    
    scanf("%d",&n);
    p = 0;
    memset(ind, -1, sizeof(ind));
    for (i = 0; i < n; i ++) {
        scanf("%d%d",&a,&b);
        a --;
        b --;
        
        next[p] = ind[a];
        to[p] = b;
        ind[a] = p ++;

        next[p] = ind[b];
        to[p] = a;
        ind[b] = p ++;
        }
    
    memset(used, -2, sizeof(used));
    f = 0;
    sp = 0;
    dfs(0, -1);
    
    memset(used, 0, sizeof(used));
    for (i = 0; i < sp; i ++)
        used[stack[i]] = 1;

/*
    for (i = 0; i < sp; i ++)
        printf("%d\n",stack[i]);
    fflush(stdout);
*/
    
    memset(hash, -1, sizeof(hash));
    hp = 0;
    for (i = 0; i < sp; i ++)
        stack[i] = dfs2(stack[i], -1);
    
    long long big = 1;
    h1[0] = 0;
    for (i = sp - 1; i >= 0; i --) {
        h1[0] = (h1[0] * 147804523 + stack[i]) % maxH;
        big = big * 147804523 % maxH;
        }
    for (i = sp - 1; i > 0; i --)
        h1[i] = (h1[(i + 1) % sp] * 147804523 % maxH + stack[i] + maxH - big *
stack[i] % maxH) % maxH;
    
    h2[0] = 0;
    for (i = 1; i < sp; i ++)
        h2[0] = (h2[0] * 147804523 + stack[i]) % maxH;
    h2[0] = (h2[0] * 147804523 + stack[0]) % maxH;
    for (i = 1; i < sp; i ++)
        h2[i] = (h2[i - 1] * 147804523 % maxH + stack[i] + maxH - big *
stack[i] % maxH) % maxH;
    
    memset(hash2, -1, sizeof(hash2));
    a = -1;
    for (i = 0; a == -1 && i < sp; i ++)
        if ((b = add2(h1[i], i)) != -1)
            if (test(b, i))
                a = i - b;
    if (a == -1)
        a = sp;
    
    b = 0;
    c = 0;
    for (i = 0; i < sp; i ++) {
        if (h1[i] == h2[i]) {
            b |= 1;
            c = i;
            }
        if (h1[i] == h2[(i + 1) % sp] && !(b&1)) {
            b |= 2;
            c = (i + 1) % sp;
            }
        }
    if (b & 1)
        a = a / 2 + 1;
    else
        if (b & 2)
            a = a / 2;
    int ans = 0;

    for (i = 0; i < a; i ++)
        ans += hashans[stack[(i + c) % sp]];
    
    printf("%d\n", ans);

    return 0;
    }
