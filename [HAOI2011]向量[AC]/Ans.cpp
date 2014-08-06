#include <cstdio>
#include <string>
using namespace std;
typedef long long LL;
LL c;
void setIO(string file)
{
 #ifndef ONLINE_JUDGE
 string input = file+".in",output = file+".out";freopen(input.c_str(),"r",stdin);freopen(output.c_str(),"w",stdout);
 #endif
}
void closeIO()
{
 #ifndef ONLINE_JUDGE
 fclose(stdin);fclose(stdout);
 #endif
}
LL check(LL x,LL y)
{
 if((x%c==0) && (y%c==0))
  return 1;
 else
  return 0;
}
LL gcd(LL x,LL y)
{
 if(y == 0)
  return x;
 else
  return gcd(y,x%y);
}
int main(int argc, char *argv[])
{
    setIO("vector");
    LL t;
    scanf("%lld",&t);
    while(t--)
    {
     LL a,b,x,y;
     scanf("%lld%lld%lld%lld",&a,&b,&x,&y);
     c = gcd(a,b)*2;
     if(check(x,y) || check(x-a,y-b) || check(x-b,y-a) || check(x-a-b,y-a-b))
      puts("Y");
     else
      puts("N");
    }
    closeIO();
    return 0;
}
