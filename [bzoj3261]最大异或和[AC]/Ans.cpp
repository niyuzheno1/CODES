#include "mode.h"
const int MN = 1010,MD = 24;
struct NODE
{
 NODE * C[3];
 int sum;
 NODE(){L = R = 0,sum = 0;}
 NODE(NODE * _L,NODE * _R,int _x){L = _L,R = _R,sum = _x;}
};
int n,a[MN],b[MN],m;
NODE * root[MN];
int newget(NODE * x,NODE * y)
{
    if(y == NULL && x == NULL) return  0;//case 1
    if(y == NULL ) return -x->sum;//case 2
    if(x == NULL ) return y->sum; // case 3
    return y->sum-x->sum;
}
NODE * inc(NODE * x,int y,int z)
{
     if(y < 0) return NULL;
     if(x == NULL) x = new NODE(),x->sum = 1;
     else {
          NODE * _x = new NODE(x->L,x->R,x->sum+1);
          x = _x;
     }
     if(y == 0) return x;
     int t = (z&(1<<(y-1)))?1:0;
     if(t) x->R = inc(x->R,y-1,z);
     else x->L = inc(x->L,y-1,z);
     return x;
}
int query(int l,int r,int z)
{
   NODE * ll = root[l-1],*rr = root[r];
   int y = MD;
   int ans =  0;
   while(y > 0)
   {
    NODE * nll = NULL,*nlr = NULL,*nrl = NULL,*nrr = NULL;
    if(ll != NULL) nll = ll->L,nlr = ll->R;
    if(rr != NULL) nrl = rr->L,nrr = rr->R; 
    int d1 = newget(nll,nrl),d2 = newget(nlr,nrr);
    if(((z)&(1<<(y-1))) == 0)
    {
     if(d2)
      ll = nlr,rr = nrr,ans = (ans|(1<<(y-1)));
     else
      ll = nll,rr = nrl;
    }
    else
    {
     if(d1)
      ll = nll,rr = nrl,ans = (ans|(1<<(y-1)));
     else
      ll = nlr,rr = nrr;
    }
    --y;
   }
   return ans;
}
/*void show(int bits,NODE * x)
{
 if(x == NULL) return;
 show(0,x->L);
 ff(debug,"%d  SLF:%d L:%d R:%d sum:%d\n",bits,x,x->L,x->R,x->sum);
 show(1,x->R);
}*/
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi,m = gi;++n;
    root[1] = inc(NULL,MD,a[1]);
    for(int i = 2;i<=n;++i) 
     a[i] = gi,b[i]=b[i-1]^a[i],root[i] = inc(root[i-1],MD,b[i]);
    
    for(int i = 1;i<=m;++i)
    {
     char tr = 0;while(tr != 'A' && tr != 'Q') tr = getchar();
     if(tr == 'A')
     {
      ++n;a[n] = gi;b[n]=b[n-1]^a[n];root[n] = inc(root[n-1],MD,b[n]);
     }
     else
     {
      int l = gi,r = gi,x = gi;
      printf("%d\n",query(l,r,x^b[n]));
     }
    }
    closeIO();
    return EXIT_SUCCESS;
}
