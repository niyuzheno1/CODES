#include "mode.h"

const int MN = 2010;
int test,n;
char s[MN];
int top[MN],temp[MN],sa[MN],rank[MN],height[MN];
void Make()
{
 CLEAR(top,0);
 int m = n<256?256:n;
 for(int i = 0;i<n;++i) ++top[rank[i]=s[i]&0xff];
 for(int i = 1;i<m;++i) top[i] += top[i-1];
 for(int i = 0;i<n;++i) sa[--top[rank[i]]] = i;
 for(int len = 1;len<n;len*=2)
 {
 int j;
  for(int i = 0;i<n;++i)
  {
  j = sa[i]-len;
  if(j < 0) j+= n;
  temp[top[rank[j]]++] = j;
  }
  sa[temp[top[0]=0]]=j=0;
  for(int i = 1;i<n;++i)
  {
   if(rank[temp[i]] != rank[temp[i-1]] || rank[temp[i]+len] != rank[temp[i-1]+len])
    top[++j] = i;
   sa[temp[i]] = j;
  }
  memcpy(rank,sa,sizeof(sa));
  memcpy(sa,temp,sizeof(sa));
  if(j>n-1) break;
 }
}

void Lcp()
{
 int i,k;
 for(int j = rank[height[i=k=0]];i<n-1;++i,++k)
  while(k >= 0 && s[i] != s[sa[j-1]+k])
   height[j] = k--,j=rank[sa[j]+1];
}

void Solve()
{
 int sum = n-sa[1]-1;
  for(int i = 2;i<n;++i)
   sum += n-sa[i]-1-height[i];
 printf("%d\n",sum);
}

int main(int argc, char *argv[])
{
    setIO("sample");
    int test = gi;
    while(test--)
    {
     scanf("%s",s);
     n = strlen(s);
     s[n++] = '$';
     Make();Lcp();Solve();
    }
    closeIO();
    return EXIT_SUCCESS;
}
