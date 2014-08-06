#include "mode.h"
#define MN 500001
#define MM 2000001
int tail[MN],net[MM],sora[MM],len[MN],f[MN],rt[MN];
int next[MN][27],ans[MN],s1,ss;
char ch[MN];
void dfs(int x)
{
 int ne;
 f[x] = (x==tail[x])?1:0;
 for(int i = x;net[i] != 0;){
  i = net[i],ne = sora[i];
  if(ne == rt[x]) continue;
  dfs(ne);
  f[x]+=f[ne];
 }
 if(f[x] > ans[len[x]]) ans[len[x]] = f[x];
}
void origin(){
 for(int i = 1;i<=s1;++i) tail[i] = i;
 ss = s1;
}
void link(int x,int y)
{
++ss,net[tail[x]] = ss,tail[x] = ss,sora[ss] = y;
}
void init()
{
     int ne,last;
     gets(ch+1);
     int l = strlen(ch+1);ch[0] = 'z'+1;
     next[0][ch[0]-'a']=++s1,rt[s1] = 0,len[s1] = 1,last = s1;
     for(int i  = 1;i<=l;++i){
       ne = ch[i]-'a';++s1;len[s1] = i+1;
       int x;
       for( x = last,last = s1;!next[x][ne]&&x;x = rt[x]) next[x][ne] = s1;
       int y = next[x][ne];
       if(!y){next[x][ne]=s1;continue;}
       if(len[x]+1==len[y])rt[s1] = y;
       else{
        ++s1;len[s1]=len[x]+1;
        for(int j = 0;j<=26;++j) next[s1][j] = next[y][j];
        rt[last] = s1;rt[s1] = rt[y],rt[y] = s1;
        for(;x;x=rt[x]) if(next[x][ne]==y)next[x][ne] = s1;else break;
        if(next[x][ne]==y) next[x][ne]=s1;
       }
     }
     origin();
     for(int i = 1;i<=s1;++i) link(rt[i],i);
     dfs(0);
     for(int i = 1;i<=l;++i) printf("%d\n",ans[i]);
}
int main(int argc, char *argv[])
{
    setIO("sample");
    init();
    closeIO();
    return EXIT_SUCCESS;
}
