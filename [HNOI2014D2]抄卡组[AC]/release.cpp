#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#define show1D(_type,_array) for(int i = 0;i<=sizeof(_array)/sizeof(_type);++i)\
ff(debug,"%d ",_array[i]);\
ff(debug,"\n");\
\


#define TRA(x,y) for(int x = st[y];~x;x = lk[x].n) if(!lk[x].f)
#define ff fprintf
#define RENEW(x) if(x) delete[] x
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define gi getint()
#define CLEAR(x,y) memset(x,y,sizeof(x))
#define MP make_pair
#define pb push_back
#ifdef WIN32 
#define I64D "%I64d"
#else
#define I64D "%lld"
#endif
#define SIZE(a) a[0]
#define INF  1000000010
using namespace std;
typedef  double ld;
typedef long long int64;
typedef unsigned long long uint64;
typedef pair<int,int> pii;
typedef pair<int64,int64> pll;
FILE * debug;
void setIO(string file = "sample")
{
 #ifndef ONLINE_JUDGE
 string input = file+".in",output = file+".out";freopen(input.c_str(),"r",stdin);freopen(output.c_str(),"w",stdout);debug = fopen("debug.txt","w");
 #endif
}
void closeIO()
{
 #ifndef ONLINE_JUDGE
 fclose(stdin);fclose(stdout);fclose(debug);
 #endif
}
template <class T>
void read(T & x)
{
 char tmp = 0; T flag = 1,ret = 0;while(tmp != '-' && !isdigit(tmp))tmp = getchar();
 if(tmp == '-') flag = -1,tmp=getchar();while(isdigit(tmp)) ret*=10,ret += tmp-'0',tmp = getchar();
 x = flag *ret;
}

int64 getint()
{
     int64 ret;read<int64>(ret);
     return ret;
}

void endline()
{
     ff(debug,"\n");
}

#define MN 11000000
#define MM 100010
#define p 991
typedef long long ll;
typedef unsigned long long ull;
int com,cnt[MM];
int n,m,nowlen,from[MM],to[MM];
ull sum[MN],power[MN];
char str[MN];
ull gethash(int l,int r){
 return sum[r]-sum[l-1]*power[r-l+1];
}
int isstr(char c){
 return isalpha(c)||isdigit(c)||c=='*';
}
void read(){
 n = gi;
 int now = 0,maxlen = 0;
 com = -1;
 for(int i = 1;i<=n;++i){
  cnt[i] = 0;
  bool mark = true;
  cin>>str+now+1;
  from[i] = now+1;
  for(int j = now+1;isstr(str[j]);++j){
   str[++now] = str[j];
   if(str[j] == '*')
    mark = false;
   else
    ++cnt[i]; 
  }
  if(mark) com = i;
  maxlen = max(maxlen,now);
  to[i] = now;
 }
 if(nowlen < maxlen)
  for(int i = nowlen+1;i<=maxlen;++i)
   power[i] = power[i-1]*p;
 for(int i = 1;i<=now;++i)
  sum[i] = sum[i-1]*p+str[i]; 
}
bool check(int a,int b){
     int l = from[b],r = to[b];
     while(from[a] <= to[a] && l <=r && str[from[a]] != '*'){
      if(str[from[a]] != str[l])
       return false;
      ++from[a],++l;
     }
     while(from[a] <= to[a] && l<=r && str[to[a]] != '*')
     {
      if(str[to[a]] != str[r])
       return false;
      --to[a],--r;
     }
     while(from[a] <= to[a]){
       while(str[from[a]] == '*' && from[a] <= to[a])
        ++ from[a];
       if(from[a] > to[a]) break;
       int st = from[a],ed;
       for(ed = st;str[ed] != '*';++ed);
       ull val = gethash(from[a],ed-1);
       int len = ed-st;
       for(int i = l;i<=r+1;++i)
       {
        if(i+len-1>r) return false;
        if(gethash(i,i+len-1)==val){
        l = i+len;
        break;
        }
       }
       from[a] = ed;
     }
     return true;
}
bool check()
{
     if(com != -1){
       for(int i = 1;i<=n;++i){
        if(cnt[i] > cnt[com]) return false; //case 1 length not satisfy
        if(cnt[i] == to[i]-from[i]+1 && (cnt[i] < cnt[com] || gethash(from[i],to[i]) != gethash(from[com],to[com])))
         return false;//case 2 without * string && len satisfy
        if(cnt[i] != to[i]-from[i]+1 && check(i,com)==false)
         return false;//case 3 *string
       }
       return true;
     }else {
      static int prev[MM],next[MM];
      int head = 1,tail = n;
      for(int i = 1;i<=n;++i)
       prev[i] = i-1,next[i] = i+1;
      while(head <= tail){
        char c = 0;
        for(int i = head;i<=tail;i=next[i])
        {
         if(str[from[i]] == '*')
         {
          prev[next[i]] = prev[i],next[prev[i]] = next[i];
          if(i == head )
           head = next[i];
          if(i == tail)
           tail = prev[i];
         }//delete invalid
         else if(c == 0)
          c = str[from[i]];
         else if(c != str[from[i]])
          return false;
         ++from[i];
        }
      }
      head = 1,tail = n;
      for(int i = 1;i<=n;++i)
       prev[i] = i-1,next[i] = i+1;
      while(head <= tail){
       char c = 0;
       for(int i = head;i<=tail;i=next[i])
       {
        if(str[to[i]] == '*'){
         prev[next[i]] = prev[i],next[prev[i]] = next[i];
         if(i == head) head = next[i];
         if(i == tail) tail = prev[i];
        }else if(c == 0)
         c = str[to[i]];
        else if(c != str[to[i]])
         return false;
        --to[i];
       }
      }
     }
     return true;
}
int main(int argc, char *argv[])
{
    setIO("sample");
    power[0] = 1;
    int T = gi;
    while(T--){
     read();
     puts(check()?"Y":"N");
    }
    closeIO();
    return EXIT_SUCCESS;
}
