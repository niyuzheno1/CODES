#include <cstdlib>
#include <iostream>

using namespace std;
class Ccircle
{
public:
 int len;
 Ccircle()
 {
  memset(&a,0,sizeof(a));
  a[0]  = 1;
  len = 0;
 }
 long long  a[101];
 long long  & operator [] (int row)
 {
  return a[row];
 }

 void operator =(Ccircle ca)
 {
  len = ca.len;
  for(int i = 0;i<=ca.len;i++)
   a[i] = ca[i];
 }
};

Ccircle func[100];
int a[51][2];
int tot;
int b[51][51];
int cirtot[51];
int visit[51],fast[51];
long long factorial;
int n;
Ccircle t1;
long long mod(long long x,long long y)
{
    if(x>=y)
     x %= y;
    return x<0?x+y:x;
}
long long extend_gcd(long long a,long long b,long long & x,long long & y)
{
    if(b==0)
    {
     x = 1;
     y = 0;
     return a;
    }
    long long reval = extend_gcd(b,a%b,x,y);
    long long t = x;
    x = y;
    y = t-(a/b)*x;
    return reval;//返回值很重要
}
long long suanniyuan(long long a,long long n)
{
  //就像我们所知道的 a^(n-1) = 1 (mod n) 所以很容易求解逆元
  if(n<= 0)
   return -1;
  long long d,x,y;
  d = extend_gcd(a,n,x,y);
  if(d != 1)
   return -1;
  return mod(x,n);
}
long long gc(long long x)
{
 return x % 1000000007; 
}
Ccircle operator *(Ccircle & a,Ccircle & b)
{
       Ccircle temp;
       temp[0] = 0;
       temp.len = 0;
       for(int i = 0;i<=a.len;i++)
        for(int j = 0;j<=b.len;j++){
         temp[i+j] += gc(gc(a[i])*gc(b[j]));
		 temp[i+j] = gc(temp[i+j]);
		}
	   temp.len = a.len+b.len;
       return temp;
}
void init()
{
 func[1][0]  = 1;
 func[1].len = 0;
 func[2][0]  = 1;
 func[2][1]  = 2;
 func[2].len = 1;
 for(int i = 3;i<=50;i++)
 {
  long long flag = 1;
  if(i% 2== 0){
   flag = 2; 
   func[i][i/2] = 2;
   for(int j = (i-1)/2;j>=1;j--)
   {
   func[i][j] = gc(gc(func[i-1][j])*gc(i))/gc(flag);
   flag+=2;
   flag = gc(flag);
   }
   func[i].len = i/2;
  }
  else{
   for(int j = (i-1)/2;j>=1;j--)
   {
    func[i][j] = gc(gc(func[i-1][j])*gc(i))/gc(flag);
    flag+=2;
    flag = gc(flag);
   }
   func[i].len = (i-1)/2;
  }
  func[i][0] = func[i-1][0];
 }
}
void getcir(int x,int f)
{
 if(visit[x])
  return;
 cirtot[f]++;
 b[f][cirtot[f]] = x;
 visit[x] = 1;
 getcir(fast[a[x][1]],f);
}

void muilt(int x)
{
 t1 = t1*func[x];
}
long long ans1 = 0;

int main(int argc, char *argv[])
{
    init(); 

    factorial = 1;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
     scanf("%d",&a[i][0]),factorial *= i,fast[a[i][0]] = i;
	 factorial = gc(factorial);
	}
    for(int i = 1;i<=n;i++)
     scanf("%d",&a[i][1]);
    for(int i = 1;i<=n;i++)
     if(!visit[i])
     {
      tot++;
      getcir(i,tot);
     }
    for(int i = 1;i<=tot;i++)
     muilt(cirtot[i]);
	long long flag = 1;
    for(int i = 0;i<=t1.len;i++)
	{
	 ans1 = gc(gc(ans1)+gc(gc(t1[i])*gc(factorial*suanniyuan(flag,1000000007))));
	 flag= flag*2;
	 flag = gc(flag);
	 }
	printf("%lld",ans1);
    system("PAUSE");
    return EXIT_SUCCESS;
}
