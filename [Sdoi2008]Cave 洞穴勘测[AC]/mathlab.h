#include <complex>
#define PI 3.1415926535897932384626433832795
template <class T>
bool isprime(T x)
{
     if(x == 1) return false;
     for(T i = 2;i*i<=x;i++) if(x % i == 0) return false;
     return true;
}

template <class T>
T gcd(T a,T b)
{
       if(b == 0) return a;
       return gcd(b,a%b);
}
