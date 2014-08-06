#include "mode.h"
#define MK 320
const int modd = 10301;
inline int sub(int x,int y)
{
    x-=y;
    while(x < 0) x+=modd;
    return x;
}
inline int add(int x,int y)
{
    x+=y;
    while(x > modd) x-=modd;
    return x;
}
inline int fmod(int x)
{
       while(x > modd) x-= modd;
       while(x < 0) x+= modd;
       return x;
}
inline int mut(int x,int y)
{
       x = (x*y)%modd;
       return x;
}
int len,n,m,num;
class kuai{
  public: int * a,*b;
   int c[5];
   int a2,ab,b2;
   void resize()
   {
    a = new int[len+2]; b = new int[len+2];
    a2 = 0 ,ab = 0,b2 = 0;
    for(int i = 0;i<=len+1;++i)
     a[i] = b[i] = 0;
    c[0] = c[3] = 1;
   }
   void pd()
   {
    for(int i = 0;i<=len+1;++i)
    {
     a2 = sub(a2,mut(a[i],a[i]));
     ab = sub(ab,mut(a[i],b[i]));
     b2 = sub(b2,mut(b[i],b[i]));
     int tmpa = add(mut(a[i],c[0]),mut(b[i],c[1]));
     int tmpb = add(mut(a[i],c[2]),mut(c[3],b[i]));
     a[i] = tmpa;b[i] = tmpb;
     a2 = add(a2,mut(a[i],a[i]));
     ab = add(ab,mut(a[i],b[i]));
     b2 = add(b2,mut(b[i],b[i]));
    } c[0] = 1,c[1] = 0 ,c[2] = 0,c[3] = 1;
   }
   int upd()
   {
    int tmp=0;
    tmp = mut(mut(c[0],c[2]),a2);//tmp = ((c[0]*c[2])%modd*a2)%modd;
    tmp = add(tmp,mut(add(mut(c[1],c[2]),mut(c[0],c[3])),ab)); //tmp = (tmp+((add(c[1]*c[2],c[0]*c[3]))*ab)%modd)%modd;
    tmp = add(tmp,mut(mut(c[1],c[3]),b2));//tmp = (tmp+(((c[1]*c[3])%modd)*b2)%modd)%modd;
    return tmp;
   }
   int change(int x)
   {
    if(x == 1)
    {
     c[0] = add(c[0],c[2]);
     c[1] = add(c[1],c[3]);
    }
    else
    {
     c[2] = add(c[0],c[2]);
     c[3] = add(c[1],c[3]);
    }
   }
   void getup()
   {
    for(int i = 0;i<=len+1;++i)
    {
     a2 = add(a2,mut(a[i],a[i]));
     ab = add(ab,mut(a[i],b[i]));
     b2 = add(b2,mut(b[i],b[i]));
    }
   }
   void rebuild(int l,int r,int opt)
   {
    for(int i = l;i<=r;++i)
    {
     a2 = sub(a2,mut(a[i],a[i]));
     ab = sub(ab,mut(a[i],b[i]));
     b2 = sub(b2,mut(b[i],b[i]));
     if(opt == 1)
      a[i] = add(a[i],b[i]);
     else
      b[i] = add(a[i],b[i]);
     a2 = add(a2,mut(a[i],a[i]));
     ab = add(ab,mut(a[i],b[i]));
     b2 = add(b2,mut(b[i],b[i]));
    }
   }
};
kuai a[MK];
pii getpos(int x)
{
    return MP(x/len,x%len);
}
void setIO2(string file = "sample")
{
 #ifndef ONLINE_JUDGE
 string input = file+".in",output = file+".ans";freopen(input.c_str(),"r",stdin);freopen(output.c_str(),"w",stdout);debug = fopen("debug.txt","w");
 #endif
}
int main(int argc, char *argv[])
{
    setIO2("tsinsenD5530");
    n= gi,m =gi;
    len = int(sqrt(n))+1;
    num = n/len+1;
    for(int i = 0;i<=num;++i) a[i].resize();
    for(int i = 1;i<=n;++i)
    {
     pii tmp = getpos(i);
     a[tmp.X].a[tmp.Y] = gi%modd;
     a[tmp.X].b[tmp.Y] = gi%modd;
    }
    for(int i = 0;i<=num;++i) a[i].getup();
    int times = 0;
    for(int i = 1;i<=m;++i)
    {
     clock_t start,end;
     start = clock();
     int opt,x,y;
     scanf("%d%d%d",&opt,&x,&y);//int opt = gi,x = gi,y=gi;
     if(opt == 1)
     {
      pii tmp1 = getpos(x);
      pii tmp2 = getpos(y);
      if(tmp1.X == tmp2.X){
       a[tmp1.X].pd();
       a[tmp1.X].rebuild(tmp1.Y,tmp2.Y,opt);
      }
      else{
       a[tmp1.X].pd();
       a[tmp2.X].pd();
       a[tmp1.X].rebuild(tmp1.Y,len-1,opt);
       a[tmp2.X].rebuild(0,tmp2.Y,opt);
       for(int i = tmp1.X+1;i<tmp2.X;++i)
        a[i].change(opt);
      }
     }
     if(opt == 2)
     {
      pii tmp1 = getpos(x);
      pii tmp2 = getpos(y);
      if(tmp1.X == tmp2.X){
       a[tmp1.X].pd();
       a[tmp1.X].rebuild(tmp1.Y,tmp2.Y,opt);
      }
      else{
       a[tmp1.X].pd();
       a[tmp2.X].pd();
       a[tmp1.X].rebuild(tmp1.Y,len-1,opt);
       a[tmp2.X].rebuild(0,tmp2.Y,opt);
       for(int i = tmp1.X+1;i<tmp2.X;++i)
        a[i].change(opt);
      }
     }
     if(opt == 3)
     {
      if(times == 4)
      times=4; 
      int ret = 0;
      pii tmp1 = getpos(x);
      pii tmp2 = getpos(y);
      if(tmp1.X == tmp2.X){
       a[tmp1.X].pd();
       for(int i = tmp1.Y;i<=tmp2.Y;++i)
        ret = add(ret,mut(a[tmp1.X].a[i],a[tmp1.X].b[i]));
      }else{
       a[tmp1.X].pd();
       a[tmp2.X].pd();
       for(int i = tmp1.Y;i<len;++i)
        ret = add(ret,mut(a[tmp1.X].a[i],a[tmp1.X].b[i]));
       for(int i = 0;i<=tmp2.Y;++i)
        ret = add(ret,(mut(a[tmp2.X].a[i],a[tmp2.X].b[i])));
       for(int i = tmp1.X+1;i<tmp2.X;++i)
        ret = add(ret,a[i].upd());
      }
      ++times;
      printf("%d\n",ret);
     }
     end = clock();
     double duration = (double)(end - start) / CLOCKS_PER_SEC;
     ff(debug,"%f\n",duration);
    }
    closeIO();
    return EXIT_SUCCESS;
}
