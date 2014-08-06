
#include <cstring>
#include <cstdio>

using namespace std;
const int MAXN = 500010;
struct edge{
 int point;
 int data;
 edge * next;
};
struct vertex{
 edge * link;
 vertex(){
  link = NULL;
 }
};
struct queue{
 int data,pos;
};
int max,n,s,a,b,c,dist[MAXN],relax[MAXN],F[MAXN],stack[MAXN],stack2[MAXN],top;
edge * doing[MAXN];
vertex g[MAXN];
queue D[MAXN];
bool mark[MAXN];
void insert(int from,int to,int value){
 edge*temp = new edge;
 (*temp).data = value;
 (*temp).next = g[from].link;
 (*temp).point = to;
 g[from].link = temp;
}
void search(int h){
 mark[h] = 1;
 stack[++top] = h;
 stack2[top] = 0;
 doing[top] = g[h].link;
 while(top){
  if(doing[top] == NULL)
  {
  if(stack2[top] > max)
   max = stack2[top];top--;
  }
  else if(!mark[(*doing[top]).point]){
   mark[(*doing[top]).point] = 1;
   stack[top+1] = (*doing[top]).point;
   stack2[top+1] = stack2[top]+(*doing[top]).data;
   doing[top+1] = g[(*doing[top]).point].link;
   doing[top] = (*doing[top]).next;
   top++;
  }else doing[top] = (*doing[top]).next;
 }
}
void dfs(int h){
 mark[h] = 1;
 doing[++top] = g[h].link;
 stack[top] = h;
 while(top){
  if(doing[top] == NULL)
   top--;
  else if(!mark[(*doing[top]).point]){
   mark[(*doing[top]).point] = 1;
   relax[(*doing[top]).point] = stack[top];
   dist[(*doing[top]).point] = dist[stack[top]]+(*doing[top]).data;
   stack[top+1] = (*doing[top]).point;
   doing[top+1] = g[(*doing[top]).point].link;
   doing[top] = (*doing[top]).next;
   top++;
  }else 
   doing[top] = (*doing[top]).next; 
 }
}
int main(int argc, char *argv[])
{
    #ifndef ONLINE_JUDGE
    freopen("bzoj1999.in","r",stdin);freopen("bzoj1999.out","w",stdout);
    #endif
    scanf("%d%d",&n,&s);
    for(int i = 1;i<=n-1;i++)
    {
     int a,b,c;
     scanf("%d%d%d",&a,&b,&c);
     insert(a,b,c);insert(b,a,c);
    }
    dfs(1);
    int st,ed;
    for(int i = 1;i<=n;i++)
     if(dist[i] > max)
     {
      max = dist[i];
      ed = i;
     }
    memset(mark,0,sizeof(mark));
    memset(dist,0,sizeof(dist));
    dfs(ed);max = 0;
    for(int i = 1;i<=n;i++)
     if(dist[i] > max)
     {
      max = dist[i];
      st = i;
     }
    memset(mark,0,sizeof(mark));
    mark[st] = 1;F[1] = st;
    int num = 1,now = st;
    do{
     now = relax[now];
     mark[now] = 1;
     F[++num]=now;
    }while(now != ed);
    int low = 1,L=0,R=-1,ans=(1<<31)-1;
    for(int i = 1;i<=num;i++){
     while(dist[F[low]]-dist[F[i]]>s)
      low++;
     max = 0;search(F[i]);
     while(L<=R && max >=D[R].data)
      R--;
     D[++R].pos = i;
     D[R].data = max;
     while(D[L].pos < low)
      L++;
     max = D[L].data;
     if(dist[F[i]]>max)
      max = dist[F[i]];
     if(dist[st]-dist[F[low]] > max)
      max = dist[st]-dist[F[low]];
     if(max < ans)
      ans = max;
    }
    printf("%d\n",ans);
    #ifndef ONLINE_JUDGE
    fclose(stdin);fclose(stdout);
    #endif
    return 0;
}
