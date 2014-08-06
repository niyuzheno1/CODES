#include "mode.h"
#define MN 1000005
int r,c,n,szl1,szl2;
int A[MN],B[MN],C[MN],D[MN];
int st1[MN],ed1[MN],st2[MN],ed2[MN];
int set11[MN*4],set12[MN*4],set21[MN*4],set22[MN*4];;
int vis[MN];
pair<pii,int> list1[MN*4],list2[MN*4];
int find(int * s,int x){
 if(s[x] < 0)  return x;
 return (s[x] = find(s,s[x]));
}
void Union(int * s,int x,int y){
 x = find(s,x);
 y = find(s,y);
 s[x] = y;
}
void insert(int x,int y,int i){
 list1[szl1++] = MP(MP(x,y),i);swap(x,y);
 list2[szl2++] = MP(MP(x,y),i);
}
void build1()
{
     for(int i = 0,j= 0;i<szl1;i=j){
      for(;j<szl1 && list1[i].X.X == list1[j].X.X;++j);
      st1[list1[i].X.X] = i;
      ed1[list1[i].X.X] = j-1;
     }
}
void build2()
{
     for(int i = 0,j=0;i<szl2;i=j){
      for(;j<szl2 && list2[i].X.X == list2[j].X.X;++j);
      st2[list2[i].X.X] = i;
      ed2[list2[i].X.X] = j-1;
     }
}
void clear1()
{
     fill(set11,set11+szl1,-1);
     fill(set12,set12+szl1,-1);
}
void clear2()
{
     fill(set21,set21+szl2,-1);
     fill(set22,set22+szl2,-1);
}
int trans(char ch){
 if(ch == 'L') return 0;
 if(ch == 'R') return 1;
 if(ch == 'U') return 2;
 if(ch == 'D') return 3;
}
int findpos(int x,int y,int d){
 if(d < 2)
 {
   int p = lower_bound(list1+st1[x],list1+ed1[x],MP(MP(x,y),-1))-list1;
   if(d == 0)
    return list1[find(set11,p-1)].X.Y;
   else
    return list1[find(set12,p+1)].X.Y;
 }
 else{
   swap(x,y);
   int p = lower_bound(list2+st2[x],list2+ed2[x],MP(MP(x,y),-1))-list2;
   if(d == 2)
    return list2[find(set21,p-1)].X.Y;
   else
    return list2[find(set22,p+1)].X.Y;
 }
}
int findcolor(int x,int y,int d)
{
     if(d < 2)
     {
          if(d == 0)
          {
           int p = upper_bound(list1+st1[x],list1+ed1[x],MP(MP(x,y),-1)) - list1-1;
           return list1[find(set11,p)].Y;
          }
          else
          {
           int p = lower_bound(list1+st1[x],list1+ed1[x],MP(MP(x,y),-1)) - list1;
           return list1[find(set12,p)].Y;
          }
     }
     else
     {
      swap(x,y);
      if(d == 2)
      {
       int p = upper_bound(list2+st2[x],list2+ed2[x],MP(MP(x,y),-1)) - list2 -1;
       return list2[find(set21,p)].Y;
      }
      else
      {
       int p = lower_bound(list2+st2[x],list2+ed2[x],MP(MP(x,y),-1)) - list2; 
       return list2[find(set22,p)].Y;
      }
     }
}
void remove(int x,int y){
 int p1 = lower_bound(list1+st1[x],list1+ed1[x],MP(MP(x,y),-1))-list1;
 int p2 = lower_bound(list2+st2[y],list2+ed2[y],MP(MP(y,x),-1))-list2;
 Union(set11,find(set11,p1),find(set11,p1)-1);
 Union(set12,find(set12,p1),find(set12,p1)+1);
 Union(set21,find(set21,p2),find(set21,p2)-1);
 Union(set22,find(set22,p2),find(set22,p2)+1);
}
bool candel(int i)
{
 int x1 = A[i],y1 = B[i],x2 = C[i],y2 = D[i];
 if(abs(x1-x2)+abs(y1-y2) <= 1) return 0;
 if(MP(x1,y1) > MP(x2,y2)) {
  swap(x1,x2);swap(y1,y2);
 }
 if(x1 == x2)
  return findpos(x1,y1,trans('R')) == y2;
 if(y1 == y2)
  return findpos(x1,y1,trans('D')) == x2;
 if(y1 < y2)
  return ((findpos(x1,y1,trans('D')) > x2 && findpos(x2,y2,trans('L')) < y1) || (findpos(x1,y1,trans('R')) > y2 && findpos(x2,y2,trans('U'))<x1));
 else
  return ((findpos(x1,y1,trans('D')) > x2 && findpos(x2,y2,trans('R'))>y1)||(findpos(x1,y1,trans('L'))<y2 && findpos(x2,y2,trans('U'))<x1));
}
void del(int i){
 int x1 = A[i],y1 = B[i],x2 = C[i],y2 = D[i];
 if(MP(x1,y1) > MP(x2,y2))
 {
  swap(x1,x2);swap(y1,y2);
 }
 if(x1 == x2)
  printf("%d %d L R\n",x1,y1+1);
 else
 {
  if(y1 == y2)
   printf("%d %d U D\n",x1+1,y1);
  else
  {
   if(y1 < y2){
          if(findpos(x1,y1,trans('D')) > x2 && findpos(x2,y2,trans('L')) < y1)
            printf("%d %d U R\n",x2,y1);
          else
            printf("%d %d L D\n",x1,y2);
   }
   else {
     if(findpos(x1,y1,trans('D')) > x2 && findpos(x2,y2,trans('R')) > y1)
       printf("%d %d U L\n",x2,y1);
     else
       printf("%d %d R D\n",x1,y2);
   }
  }
 }
 remove(x1,y1);
 remove(x2,y2);
}
void run()
{
     scanf("%d%d",&r,&c);
     scanf("%d",&n);
     szl1 = szl2= 0;
     for(int i = 0;i<n;++i){
      scanf("%d%d%d%d",&A[i],&B[i],&C[i],&D[i]);
      insert(A[i],B[i],i);
      insert(C[i],D[i],i);
     }
     for(int i = 1;i<=r;++i){
      list1[szl1++] =MP(MP(i,0),-1);
      list1[szl1++] =MP(MP(i,c+1),-1);
     }
     for(int i = 1;i<=c;++i){
      list2[szl2++] = MP(MP(i,0),-1);
      list2[szl2++] = MP(MP(i,r+1),-1);
     }
     sort(list1,list1+szl1);
     sort(list2,list2+szl2);
     build1();
     build2();
     clear1();
     clear2();
     int k;
     int score = 0;
     scanf("%d",&k);
     for(int i = 0;i<k;++i){
      int x,y;
      char ch1,ch2;
      scanf("%d %d %c %c",&x,&y,&ch1,&ch2);
      int next1 = findcolor(x,y,trans(ch1));
      int next2 = findcolor(x,y,trans(ch2));
      int p =lower_bound(list1+st1[x],list1+ed1[x],MP(MP(x,y),-1))-list1;
      if(list1[find(set11,p)].X.Y == y)
       continue;
      p = lower_bound(list2+st2[y],list2+ed2[y],MP(MP(y,x),-1))-list2;
      if(list2[find(set21,p-1)].X.Y == x)
      continue;
      if(next1 == next2 && next1 != -1 && next2 != -1 && !(A[next1] == x && B[next1]==y) && !(C[next1] == x && D[next1]==y))
      {
       ++score;
       remove(A[next1],B[next1]);
       remove(C[next1],D[next1]);
      }
     }
     printf("%d\n",score);
     clear1();
     clear2();
     printf("%d\n",n);
     int best = 0;
     deque<int> Q;
     for(int i = 0;i<n;++i){
      if(i == 2)
       i = 2;
       if(candel(i))
      {
       Q.pb(i);
       vis[i] = 1;
      }
     }
     while(!Q.empty()){
      int cur = Q.front();
      Q.pop_front();
      ++best;
      del(cur);
      for(int d = 0;d<4;++d){
       int next = findcolor(A[cur],B[cur],d);
       if(next != -1 && ! vis[next] && candel(next))
       {
        Q.pb(next);
        vis[next] = 1;
       }
      }
      for(int d = 0;d<4;++d){
       int next = findcolor(C[cur],D[cur],d);
       if(next != -1 && !vis[next] && candel(next)){
        Q.pb(next);
        vis[next] = 1;
       }
      }
     }
     for(int i = 0;i<n-best;++i)
      printf("1 1 L R\n");
}
int main(int argc, char *argv[])
{
    setIO("sample");
    run();
    closeIO();
    return EXIT_SUCCESS;
}
