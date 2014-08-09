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
typedef pair<int,int> _reserve_type_1;
typedef pair<int64,int64> pll;
#define pii _reserve_type_1
FILE * debug;
#define setIO _func_2_
void _func_2_(string file = "sample")
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

#define ERROR_FILE_END -1
#define FILEOF(X) func_1_(X)
int func_1_(FILE * X)
{
 int cur = ftell(X);
 fseek(X,0L,SEEK_END);
 int ret  = ftell(X);
 fseek(X,cur,SEEK_SET);
 return ret;
}
class iomgr{
 FILE * A;
 char * rb, * endb;
 int fl;
public:
 void setting(FILE * _A){
	 A = _A;fl = 4194304/*FILEOF(stdin)*/;rb = new char[fl+3];fread(rb,1,fl,stdin);rb[fl] = -1;endb = rb+fl;
 }
 char exgetchar(){
	char ret = *rb; ++rb;
	return ret;
 }
 template <class T>
 void exread(T & x)
 {
  if(rb >= endb) return;
  char tmp = 0; T flag = 1,ret = 0;while(tmp != -1 && tmp != '-' && !isdigit(tmp)) tmp = exgetchar();
  if(tmp == -1) return;
  if(tmp == '-') flag = -1,tmp=exgetchar();while(isdigit(tmp)) ret*=10,ret += tmp-'0',tmp = exgetchar();
  x = flag *ret;
 }
 int64 exgetint()
 {
	int64 ret = ERROR_FILE_END;exread(ret);return ret;
 }
};
iomgr _global_reader_;
#undef setIO
void _func_3_(string file = "sample"){
 _func_2_(file);
 _global_reader_.setting(stdin);
}
#define setIO _func_3_
#undef gi
#define gi _global_reader_.exgetint()
#define gc _global_reader_.exgetchar()

#define MN 10010
int n,m;
#define have(x) if(x != (node * )NULL)
struct node{
       node * ch[4];
       bool rev;
       void setw(node * b){ch[2] = b;}
       void pd(){
        if(rev){
         swap(ch[0],ch[1]);
         if(ch[0]!=(node*)NULL)ch[0]->rev ^= 1;
         if(ch[1]!=(node*)NULL)ch[1]->rev ^= 1;
         rev = 0;
        }
       }
       void mkrt(){
        rev = 1;
        pd();
       }
       void upd(){
       }
       bool fd(node * u){
        return (ch[0]==u)||(ch[1]==u);
       }
       int fdc(node * u){
        return ch[0]==u?0:1;
       }
       bool isrt(){
        return (ch[2] == 0)|| !ch[2]->fd(this);
       }
};
node a[MN];
void rotate(node * x){
 node * y = x->ch[2],* z = y->ch[2];
have(z) z->pd(); have(y) y->pd();  x->pd();
 int d1 = (y->ch[0]==x),d2 = (y->isrt())?(3):(z->ch[1]==y);
 y->ch[!d1] = x->ch[d1];have(y->ch[!d1]) y->ch[!d1]->setw(y);
 x->ch[d1] = y ; y->setw(x);
 if(z != (node*)NULL){z->ch[d2] = x ;} x->setw(z);
 have(y) y->upd();x->upd();have(z) z->upd();
}
void splay(node * x){
 while(!x->isrt()){
  node * y = x->ch[2],*z = y->ch[2];
  if(!y->isrt() && ((y->ch[1]==x) == (z->ch[1]==y)))
   rotate(y);
 rotate(x);
 }
}
node * lm(node * x){
 while(x->ch[0] != (node *)NULL) x = x->ch[0];
 return x;
}
node * access(node * x){
 for(node * pre = 0,*now = x;now;){
  splay(now);now->pd();
  now->ch[1] = pre;
  pre = now;now = now->ch[2];
 }
 splay(x);
 return lm(x);
}
void link(node * x,node * y){
 access(x); x->mkrt();
 x->ch[2] = y;
}
/*void cut(node * x,node * y){
 access(x);x->pd();splay(y);y->pd();
  if(x->ch[2] != y || !y->fd(x))
  {
   access(y);y->pd();
   x->ch[2] = (node * )NULL;
   y->ch[y->fdc(x)] = (node *)NULL;
   return;
  }
 splay(x);x->pd();
 y->ch[2] = (node *) NULL;
 x->ch[x->fdc(y)] = (node * )NULL;
}*/
void cut(node * a,node * b){
 access(a);a->mkrt(); access(b); b->ch[0]->ch[2] = (node*)NULL; b->ch[0] = (node*)NULL;
}

bool query(node * x,node * y){
 x = access(x);y = access(y);
 return (x == y);
}
int times = 0;
int main(int argc, char *argv[])
{
    setIO();
    n = gi,m = gi;
    for(int i = 1;i<=m;++i){
     char opt =  gc;++times;
     while(!((opt<='Z' && opt >= 'A') || opt == -1)) opt = gc;
     int x=gi,y = gi;
     if(opt == 'Q')
            puts(query(a+x,a+y)?"Yes":"No");
     if(opt == 'C')
            link(a+x,a+y);
     if(opt == 'D')
            cut(a+x,a+y);
    }
    closeIO();
    return EXIT_SUCCESS;
}
