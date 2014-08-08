const ld PI = acos(-1.0);
struct cx{
       ld a,b;
       cx(ld _a=0.0,ld _b = 0.0):a(_a),b(_b){}
       friend cx operator + (const cx & x, const cx & y){
        return cx(x.a+y.a,x.b+y.b);
       }
       friend cx operator - (const cx & x, const cx & y){
        return cx(x.a-y.a,x.b-y.b);
       }
       friend cx operator * (const cx & x, const cx & y){
        return cx(x.a*y.a-x.b*y.b,x.a*y.b+x.b*y.a);
       }
};
void fft(cx p[],int n,int oper){
  for(int i = 1,j=0;i<n-1;++i){
    for(int s = n;j^=s>>=1,~j & s;);
    if(i < j) swap(p[i],p[j]);
  }
  cx up0;
  for(int d = 0;(1<<d)<n;++d){
   int m = 1<<d,m2 = m*2;
   double p0 = PI/m*oper;
   up0 = cx(cos(p0),sin(p0));
    for(int i = 0 ;i<n;i+=m2){
     cx u = 1;
     for(int j = 0;j<m;++j){
      cx & p1 = p[i+j+m],&p2 = p[i+j];
      cx t = u * p1;p1 = p2 - t;p2 = p2 + t;
      u = u * up0;
     }
    }
  }
}
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
