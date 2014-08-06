//algorithm.h
template<class type,type Mod>
inline type & add(type & a,const type & b,const type & c)
{
    a = b+c;
    if(a>=Mod) a-= Mod;
    return a;
}

template<class type,type Mod>
inline type &sub(type & a,const type &b,const type & c)
{
   a= b-c;
   if(a<0) a+=Mod;
   return a;
}

template<class type,type Mod>
inline type &mut(type & a,const type & b,const type & c)
{
   a = ((b%Mod)*(c%Mod))%Mod;
   return a;
}
#ifdef DIVONMOD
template<class type,type Mod>
inline type &div(type & a,const type & b,const type & c)
{
   type u = 0,v = 0;
   type d = exgcd(a,Mod,u,v);
   a = ((b%Mod)*(d%Mod))%Mod;
   return a;
}
#endif
template<class type>
inline type & up(type & u, type v)
{
       if(v > u) u = v;
       return u;
}
template<class type>
inline type & dn(type & u, type v)
{
       if(v < u) u = v;
       return u;
}
