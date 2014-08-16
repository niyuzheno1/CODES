inline int get(int * h,int * p,int i,int len){
 int res = h[i+len-1];
 if(i > 0) res -= h[i-1]*p[len];
 return res;
}
inline int lcp(char * s,int * hl,int * p,const pii & a,const pii & b){
 int l = 0,r = min(a.Y,b.Y)+1;//[,)
 if(get(hl,p,a.X,r-1) == get(hl,p,b.X,r-1)) return r-1;
 if(s[a.X] != s[a.X]) return 0;
 while(r-l > 1){
  int mid = ((l+r)>>1);
  if(get(hl,p,a.X,mid) == get(hl,p,b.X,mid))
   l = mid;
  else
   r = mid;
 }
 return l;
}
struct cmpSA{
        int * hl,*p;
        char * s;
        bool operator() (const pii & a,const pii & b)
        {
         int mlen = min(a.Y,b.Y);
         int l = lcp(s,hl,p,a,b);
         if(l == mlen) return a.Y < b.Y;
         return s[a.X+l] < s[b.X + l];
        }
        int slcp(const pii & a,const pii & b){return lcp(s,hl,p,a,b);}
};
