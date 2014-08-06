#include "mode.h"

#define MN 1010
struct ele
{
       int i,p;
};
struct minmonoqueue{
 ele Q[MN];
 int Width,head,tail;
 void ins(int i ,int p)
 {
       while(tail >= head && (i-Q[tail].i>=Width || p <= Q[tail].p ))
        --tail;
       Q[++tail].p = p;
       Q[tail].i = i;
 }
 int get(int i)
 {
     while(i-Q[head].i>=Width)++head;
     return Q[head].p;
 }
 void init(int W)
 {
  Width = W;
  head = 0;tail = -1;
 }
}MinQ; 
struct maxmonoqueue {
 ele Q[MN];
 int Width,head,tail;
 void ins(int i ,int p)
 {
       while(tail >= head && (i-Q[tail].i>=Width || p >= Q[tail].p ))
        --tail;
       Q[++tail].p = p;
       Q[tail].i = i;
 }
 int get(int i)
 {
     while(i-Q[head].i>=Width)++head;
     return Q[head].p;
 }
 void init(int W)
 {
  Width = W;
  head = 0;tail = -1;
 }
}MaxQ;
int N,M,P,Ans;
int A[MN][MN],B[MN][MN],C[MN][MN];
int main(int argc, char *argv[])
{
    setIO("sample");
    N = gi,M = gi,P = gi;
    for(int i = 1;i<=N;++i)
     for(int j = 1;j<=M;++j) A[i][j] = gi;
    Ans = INF;
    int Amin=0,Amax=0;
    for(int j = 1;j<=M;++j)
    {
     MinQ.init(P);
     MaxQ.init(P);
     for(int i = 1;i<P;++i)
      MinQ.ins(i,A[i][j]),MaxQ.ins(i,A[i][j]);
     for(int i = P;i<=N;++i)
     {
      MinQ.ins(i,A[i][j]),MaxQ.ins(i,A[i][j]);
      int k = i-P+1;
      B[k][j] = MinQ.get(i);
      C[k][j] = MaxQ.get(i);
     }
    }
    for(int i = 1;i+P-1<=N;++i)
    {
     MinQ.init(P);MaxQ.init(P);
     for(int j = 1;j<P;++j) MinQ.ins(j,B[i][j]),MaxQ.ins(j,C[i][j]);
     for(int j = P;j<=M;++j)
     {
     MinQ.ins(j,B[i][j]),MaxQ.ins(j,C[i][j]);
     Amin = MinQ.get(j);
     Amax = MaxQ.get(j);
      Ans = min(Ans,Amax-Amin);
     }
    }
    printf("%d",Ans);
    closeIO();
    return EXIT_SUCCESS;
}
