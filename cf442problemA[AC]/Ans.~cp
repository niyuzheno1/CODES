#include "mode.h"

int n,p,ans,c[6][6],a[15],b[15];char s[6];

int chg(char x) { return x=='R'?0:x=='G'?1:x=='B'?2:x=='Y'?3:4;}

int main(int argc, char *argv[])
{
    setIO("sample");ans=INF,p=0;
    n = gi;
    for(int i = 0;i<n;++i) scanf("%s",s),++c[chg(*s)][s[1]-49];
   for(int i = 0;i<1<<10;++i){
     int cnt = 0,flag = 1;
     for(int j = 0;j<10;++j) cnt += a[j]=i>>j&1;
      CLEAR(b,0);
     for(int i = 0;i<5;++i) 
      for(int j = 0;j<5;++j)
       if(c[i][j])
        if(a[i] && a[j+5]) ;
        else if(a[j+5]) ++b[j+5];
        else if(a[i]) ++b[i];
        else ++b[10];
      for(int j = 0;j<11;++j) if(b[j]>1)flag = 0;
        if(flag) 
        ans = min(ans,cnt);
    }
    printf("%d\n",ans);
    closeIO();
    return EXIT_SUCCESS;
}
