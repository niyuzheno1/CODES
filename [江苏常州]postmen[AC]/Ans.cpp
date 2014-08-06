#include "mode.h"
const int MN = 500010,MM=2*MN;
int E[MM][3];
int pr[MN] = {0};
int P[MN],tmp[MN] = {0},C[MN];
int k[MM];
int N,M,a,b;
bool vis[MN]  = {0};
vector<int> path;
int newv = -1,u;
int getU(int i,int v)
{
    return (v == E[i][0])?E[i][1]:E[i][0];
}
void dfs(int v)
{
 path.clear();
 path.push_back(v);
 while(v != -1){
  vis[v] = true;
  newv = -1;
  for(;pr[v] < C[v];++pr[v]){
   int i = k[P[v]+pr[v]];
   if(E[i][2] == false){
    u = getU(i,v);
    E[i][2] = true;
    if(vis[u]){
     newv = u;
     while(path.back()!=u){
     printf("%d ",path.back());
     vis[path.back()] = false;
     path.pop_back();
     }
     printf("%d\n",path.back());
    }else{
    newv = u;path.pb(u);
    }
    break;
    }
  }
  if(newv == -1 && path.size() > 1)
   newv = path.back(),path.pop_back();
  v = newv;
 }
 vis[path[0]] = false;

}
int main(int argc, char *argv[])
{
    setIO("sample");
    path.reserve(MN);
    N = gi,M = gi;
    for(int i = 0;i<M;++i)
     E[i][0] = gi,E[i][1] = gi,++C[E[i][0]],++C[E[i][1]];
    P[1] = 0;
    for(int i = 2;i<=N;++i)P[i] = P[i-1]+C[i-1];
    for(int i = 0;i<M;++i)a = E[i][0],b = E[i][1],k[P[a]+tmp[a]]=i,k[P[b]+tmp[b]]=i,++tmp[a],++tmp[b];
    for(int i = 1;i<=N;dfs(i),++i);
    closeIO();
    return EXIT_SUCCESS;
}
