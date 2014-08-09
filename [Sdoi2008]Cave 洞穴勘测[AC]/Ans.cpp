#include "mode.h"
#define SSPLAY
#include "data.h"
const int N = 10100;
struct lct{
       int ch[N][3],sz[N],w[N];
       inline void update(int x)
       {
        sz[x] = sz[ch[x][L]]+sz[ch[x][R]]+w[x]+1;
       }
       inline bool isrt(int x){
        return (ch[x][F] == 0 || (ch[ch[x][F]][L]!=x&&ch[ch[x][F]][R]!=x));
       }
       void rotate(int x)
       {
        int y = ch[x][F],z = ch[y][F],d1 = (ch[y][0]==x),d2 = (ch[z][1] == y) ,d3 = isrt(y);
        ch[y][!d1] = ch[x][d1],ch[ch[y][!d1]][F]= y;
        ch[x][d1] = y;ch[y][F]=x;
        if(!d3) ch[z][d2]= x;
        ch[x][F]=z;
        update(y);update(x);
       }
       void splay(int x)
       {
        while(!isrt(x))
        {
         int y = ch[x][F];
         if(!isrt(y)){
         int z = ch[y][F];
         int d1 = ((ch[z][0]==y)==(ch[y][0]==x));
         if(d1) rotate(y);
         }
         rotate(x);
        }
        update(x);
       }
       void access(int rt){
        for(int x = rt,y = 0;x;x=ch[x][F]){
         splay(x);
         //modify
         ch[x][R]= y;
         update(y=x);
        }
       }
       void link(int x,int y)
       {
        access(y);
        splay(x);
        ch[x][F]=y;
        ch[y][R]=x;
        update(y);
       }
       void cut(int x,int y)
       {
        access(x);splay(x);splay(y);
        ch[ch[y][L]][F] = ch[y][F];
        ch[y][F] = 0;
        ch[y][L] = 0;
       }
       int lmost(int x)
       {
        while(ch[x][L]) x=  ch[x][L];
        return x;
       }
       int upmost(int x)
       {
        while(ch[x][F]) x= ch[x][F];
        return x;
       }
       bool isconnect(int x,int y)
       {
        int u = upmost(x),v = upmost(y);
        if(u == v) return true;
        else return false;
       }
};
lct t;
int main(int argc, char *argv[])
{
    setIO("sample");
    int n , m;
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=m;++i)
    {
     char opt[5];scanf("%s",opt);
     int x,y;scanf("%d%d",&x,&y);
     if(opt[0] == 'Q')
      if(t.isconnect(x,y))
       printf("Yes\n");
      else
       printf("No\n");
     if(opt[0] == 'C')
      t.link(x,y);
     if(opt[0] == 'D')
      t.cut(x,y);
    }
    closeIO();
    return EXIT_SUCCESS;
}
