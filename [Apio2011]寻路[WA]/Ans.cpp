#include "mode.h"
//simple condition+
#define CON1 x,x+xl
#define CON2 y,y+yl
#define MN 2003
struct rect{
     int x1,y1,x2,y2;
}a[MN];
struct edge{
       int n,v,f,o;
};
edge lk[MN*MN*2];
int st[MN];
typedef pair<double,int> pdi;
priority_queue<pdi,vector<pdi>,greater<pdi> > q;
double d[MN*MN];
int x[MN],y[MN],f[MN][MN],xl,yl,top;
void addedge(int x1,int y1,int x2,int y2){
 int s = x1*yl+y1,t = x2*yl+y2,v = abs(x[x2]-x[x1])+abs(y[y2]-y[y1]);
 lk[top].v = t;lk[top].o = v;lk[top].n=st[s];st[s] = top;++top;
 lk[top].v = s;lk[top].o = v;lk[top].n=st[t];st[t] = top;++top;
}
void clear(){
 CLEAR(st,0xff);
 top = 0;
}
void findv(int x,int y,int d){
 int i = y+d;
 for(;i>=0 && i <yl && f[x][i] == -1;i+=d);
  if(i >= 0 && i < yl && f[x][i] == -2) f[x][i] = 1;
}
void findh(int x,int y,int d){
 int i = x+d;
 for(;i>=0 && i < xl && f[i][y]==-1;i+=d);
 if(i >= 0 && i < xl && f[i][y] == -2) f[i][y] = 1;
}
void solve(){
      clear();
 int xs=gi,ys=gi,xt=gi,yt=gi;
 int n = gi;
 for(int i = 0;i<n;++i){
 a[i].x1 = gi;a[i].y1 = gi;a[i].x2 = gi;a[i].y2 = gi;
 if(a[i].x1 > a[i].x2) swap(a[i].x1,a[i].x2);
 if(a[i].y1 > a[i].y2) swap(a[i].y1,a[i].y2);
 x[2*i] = a[i].x1,x[2*i+1] = a[i].x2;
 y[2*i] = a[i].y1,y[2*i+1] = a[i].y2;
 }
 x[2*n] = xs,x[2*n+1] = xt,y[2*n] = ys,y[2*n+1]=yt;
 sort(x,x+2*n+2);xl = unique(x,x+2*n+2)-x;
 sort(y,y+2*n+2);yl = unique(y,y+2*n+2)-y;
 xs = lower_bound(CON1,xs)-x,xt = lower_bound(CON1,xt)-x,ys = lower_bound(CON2,ys)-y,yt = lower_bound(CON2,yt)-y;
 for(int i = 0;i<xl;++i)
  for(int j = 0;j<yl;++j) 
   f[i][j] = -1;
 f[xs][ys] = 0,f[xt][yt] = 0;
 for(int i = 0;i<n;++i){
  int x1 = lower_bound(CON1,a[i].x1)-x,x2 = lower_bound(CON1,a[i].x2)-x;
  int y1 = lower_bound(CON2,a[i].y1)-y,y2 = lower_bound(CON2,a[i].y2)-y;
  a[i].x1 = x1,a[i].x2 = x2,a[i].y1 = y1,a[i].y2 = y2;
  for(int j = x1;j<=x2;++j) f[j][y1] = f[j][y2] = -2;
  for(int j = y1;j<=y2;++j) f[x1][j] = f[x2][j] = -2;
  f[x1][y1] = f[x1][y2] = f[x2][y1] = f[x2][y2]= 2;
 }
 for(int i = 0;i<n;++i){
  findh(a[i].x1,a[i].y1,-1),findv(a[i].x1,a[i].y1,-1);
  findh(a[i].x1,a[i].y2,-1),findv(a[i].x1,a[i].y2,1);
  findh(a[i].x2,a[i].y1,1),findv(a[i].x2,a[i].y1,-1);
  findh(a[i].x2,a[i].y2,1),findv(a[i].x2,a[i].y2,1);
 }
 findh(xs,ys,-1),findh(xs,ys,1),findv(xs,ys,-1),findv(xs,ys,1);
 findh(xt,yt,-1),findh(xt,yt,1),findv(xt,yt,-1),findv(xt,yt,1);
 int flag = 0;
 for(int i = 0;i<xl;++i)
  for(int j = 0,k=-2;j<yl;++j)
   if(f[i][j] > 0 ){
    if(k != -1){
          if(k > -1) addedge(i,k,i,j);
          int tflag = flag;
          if(f[i][j] == 2 && !tflag )flag = 1;
          if(!flag) k = -1;else k = j;
          if(f[i][j] == 2 && tflag) flag = 0;
    }else k = j;
   }else if(!f[i][j]){
    if(k > -1) addedge(i,k,i,j);
    k = j;
   }else if(f[i][j] == -2 && !flag) k = -1;
 flag = 0;
 for(int j = 0;j<yl;++j)
  for(int i = 0,k=-2;i<xl;++i)
   if(f[i][j] > 0){
     if(k != -1){
     if(k  > -1) addedge(k,j,i,j);
     int tflag = flag;
     if(f[i][j] == 2 && !tflag) flag = 1;
     if(!flag) k = -1; else k = i;
     if(f[i][j] == 2 && tflag) flag = 0;
     }else k = i;
   }else if(!f[i][j]) { if(k > -1) addedge(k,j,i,j);k=i;}
   else if(f[i][j] == -2 && !flag ) k = -1;
 for(int i = 0;i<xl*yl;++i) d[i] = 1e30;
 d[xs*yl+ys] = 0;
 q.push(pdi(0,xs*yl+ys));
 while(!q.empty()){
  int u = q.top().Y;
  if(q.top().X != d[u]){q.pop();continue;}
  q.pop();
  TRA(i,u)
   if(d[u]+lk[i].o< d[lk[i].v]){
    d[lk[i].v] = d[u]+lk[i].o;
    if(d[lk[i].v] < d[xt*yl+yt]) q.push(pdi(d[lk[i].v],lk[i].v));
   }
 }
 if(d[xt*yl+yt]>1e20) puts("No Path");
 else printf("%.0lf\n",d[xt*yl+yt]);

}
int main(int argc, char *argv[])
{
    setIO("sample");
    int t = gi;
    while(t--) solve();
    closeIO();
    return EXIT_SUCCESS;
}
