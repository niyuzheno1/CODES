#include "mode.h"

const int MN = 65;
int L[MN*MN],R[MN*MN],U[MN*MN],D[MN*MN];
int S[MN] = {0};
int nCol[MN*MN];
int n,w;
int best = INF;

void init()
{
 n = gi,w = gi;
 for(int i = 0;i<=n;++i)
  L[i] = i-1,R[i] = i+1,U[i] = D[i] = i;
 L[0] = n;R[n] = 0;
 int cnt = n+1;
 int li;
 for(int i = 1;i<=w;++i)
 {
  li = gi;
  int head = cnt,tail = cnt;
  for(int j = 1;j<=li;++j)
  {
  int c=  gi;
  ++S[c];nCol[cnt] = c;
  U[D[c]] = cnt;
  D[cnt] = D[c];
  U[cnt] = c;
  D[c] = cnt;
  L[cnt] = tail;R[tail] = cnt;
  R[cnt] = head;L[head] = cnt;
  tail = cnt;
  ++cnt;
  }
 }
}

void Remove(int x)
{
 for(int i = D[x];i!=x;i=D[i])
 {
  L[R[i]] = L[i];
  R[L[i]] = R[i];
  --S[nCol[i]];
 }
}

void Resume(int x)
{
 for(int i = U[x];i!=x;i=U[i])
 {
 L[R[i]] = R[L[i]] = i;
 ++S[nCol[i]];
 }
}

int Hash()
{
 int ans = 0;
 bool hash[MN] = {0};
 for(int c = R[0];c != 0 ; c=R[c])
  if(!hash[c])
  {
   hash[c] = 1;
   ++ans;
   for(int i = D[c];i != c;i=D[i])
    for(int j = R[i];j!= i; j =R[j])
     hash[nCol[j]] = 1;
  }
 return ans;
}

void dfs(int ans)
{
 if(ans + Hash() >= best) return ;
 if(R[0] == 0)
 {
  best= ans;
  return;
 }
 int c,minnum = INF ;
 for(int i = R[0];i!=0;i=R[i])
 {
  if(S[i] == 0) return;
  if(S[i] < minnum)
   minnum = S[i],c=i;
 }
 for(int i = U[c];i!=c;i=U[i])
 {
 Remove(i);
 for(int j = R[i];j != i;j=R[j])Remove(j);
 dfs(ans+1);
 for(int j = L[i];j != i;j=L[j])Resume(j);
 Resume(i);
 }
}

int main(int argc, char *argv[])
{
    setIO("sample");
    init();
    dfs(0);
    printf("%d\n",best);
    closeIO();
    return EXIT_SUCCESS;
}
