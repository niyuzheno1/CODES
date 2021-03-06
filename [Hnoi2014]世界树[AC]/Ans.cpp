#include "mode.h"
const int MN = 300010;
int occur[MN],seq[MN],top;
int n,father[MN],dep[MN],F[MN][20],size[MN];
int nEdge = 1,to[MN*2],next[MN*2],start[MN];
void ae(int a,int b)
{
 ++nEdge,to[nEdge] = b,next[nEdge] = start[a],start[a] = nEdge;
}
void read()
{
 n = gi;
 for(int i = 2,a,b;i<=n;++i)
  a = gi,b = gi,ae(a,b),ae(b,a);
 dep[1] = 1;
}
int LCA(int a,int b)
{
 if(dep[a] < dep[b])
  swap(a,b);
 for(int i = 18;i>=0;--i)
  if(dep[F[a][i]] >= dep[b]) a = F[a][i];
 if(a == b)
  return a;
 for(int i = 18;i>=0;--i)
  if(F[a][i] != F[b][i])
   a = F[a][i],b = F[b][i];
 return F[a][0];
}
int Find(int p,int d)
{
 for(int i = 18;i>=0&&dep[p]>d;--i)
  if(dep[F[p][i]] >= d)
   p = F[p][i];
 return p;
}
void DFS(int p)
{
 seq[++top] = p,occur[p] = top,size[p]= 1;
 for(int i = start[p];i;i=next[i])
  if(to[i] != father[p])
  {
   int q = to[i];
   dep[q] = dep[p]+1;
   father[q] = p,F[q][0] = p;
   for(int j =0 ;F[F[q][j]][j];++j)
    F[q][j+1] = F[F[q][j]][j];
   DFS(q),size[p] += size[q]; 
  }
}
int cmp(int a,int b)
{
    return occur[a]<occur[b];
}
void Query()
{
     static int stack[MN];
     static int ask[MN],tree[MN],val[MN],ans[MN],in[MN],tmp[MN];
     static pair<int,int> near[MN];
     int m = gi;
     for(int T = 1;T<=m;++T)
     {
      int tn=gi,tot,top = 0;
      for(int i = 1;i<=tn;++i)
      {
       ask[i] = gi;
       near[ask[i]] = MP(0,ask[i]);
       ans[ask[i]] = 0;
       tmp[i] = ask[i];
       tree[i] = ask[i];
      }
      sort(ask+1,ask+1+tn,cmp);
      tot = tn;
      for(int j = 1;j<=tn;++j)
      {
       int p = ask[j];
       if(top == 0)
        stack[++top] = p,father[p] = 0;
       else
       {
        int x = LCA(stack[top],p);
        father[p] = x;
        while(dep[stack[top]]>dep[x])
        {
         if(dep[stack[top-1]]<=dep[x])
          father[stack[top]] = x;
         --top;
        }
        if(stack[top] != x)
        {
         father[x] = stack[top];
         stack[++top] = x,near[x] =MP(1<<30,0);
         tree[++tot] = x;
        }
        stack[++top] = p;
       }
      }
      sort(tree+1,tree+tot+1,cmp);
      for(int i = 1;i<=tot;++i)
      {
       int p = tree[i];
       val[p] = size[p];
       if(i>1)
        in[p] = dep[p]-dep[father[p]];
      }
      for(int i = tot;i>1;--i)
      {
       int p = tree[i],fa = father[p];
       near[fa] = min(near[fa],MP(near[p].X+in[p],near[p].Y));
      }
      for(int i = 2;i<=tot;++i)
      {
       int p = tree[i],fa = father[p];
       near[p] = min(near[p],MP(near[fa].X+in[p],near[fa].Y));
      }
      for(int i = 1;i<=tot;++i)
      {
       int p = tree[i],fa = father[p],sum = size[Find(p,dep[fa]+1)]-size[p];
       if(fa == 0)
        ans[near[p].Y] += n-size[p];
       else
       {
        val[fa] -= sum+size[p];
        if(near[p].Y == near[fa].Y)
         ans[near[p].Y] += sum;
        else
        {
         int dis = (dep[p]-dep[fa]+near[fa].X-near[p].X)/2,x;
         if(dis + near[p].X == dep[p]-dep[fa]-dis+near[fa].X && near[fa].Y < near[p].Y)
          -- dis;
         x = Find(p,dep[p]-dis);
         ans[near[p].Y] += size[x]-size[p];
         ans[near[fa].Y] += sum-size[x]+size[p];
        }
       }
      }
     for(int i = 1;i<=tot;++i)
      ans[near[tree[i]].Y] += val[tree[i]];
     for(int i = 1;i<=tn;++i)
      printf("%d ",ans[tmp[i]]);
     printf("\n");
     }
}
int main(int argc, char *argv[])
{
    setIO("sample");
    read();
    DFS(1);
    Query();
    closeIO();
    return EXIT_SUCCESS;
}
