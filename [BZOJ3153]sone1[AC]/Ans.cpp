#include "mode.h"
#include "data.h"
#define MN 100010
struct info
{
       int mul,plus;
       info():mul(1),plus(0){}
       info(int a,int b):mul(a),plus(b){}
       int ok(){return mul != 1 || plus;}
}nulli;
info operator + (const info & a,const info & b){
      return info(a.mul*b.mul,a.plus*b.mul+b.plus);
}
struct su{
       int maxv,minv;
       int sum,size;
       su(int a = -INF,int b = INF,int c = 0,int d = 0)
              :maxv(a),minv(b),sum(c),size(d)
              {}
       su(int * a):
               maxv(*a),minv(*a),sum(*a),size(1){
               }
};
su operator + (const su & a, const su & b){
 return su(max(a.maxv,b.maxv),min(a.minv,b.minv),a.sum+b.sum,a.size+b.size);
}
int app(int a,const info & b){
 return a*b.mul+b.plus;
}
su operator +(const su & a,const info & b){
 if(!a.size) return a;
 return su(app(a.maxv,b),app(a.minv,b),a.sum*b.mul+b.plus*a.size,a.size);
}
struct node{
       node * ch[4],*p;
       int inner,rev,val;
       info cf,tf;
       su all,cha,tr;
       node():p(0),inner(0),rev(0),val(0){
       CLEAR(ch,0);
       }
       int getpos()
       {
        for(int i = 0;i<4;++i)
         if(p->ch[i] == this)
          return i;
        return 4;
       }
       void setc(node * u,int kind){
        ch[kind] = u;
        if(u) u->p = this;
       }
       int isrt(int kind){
        if(kind)
         return !p || !p->inner || !inner;
        else
         return !p || (getpos()>=2) || inner || p->inner;
       }
       void revit(node * u)
       {
        if(u)
        {
         u->rev ^= 1;
         swap(u->ch[0],u->ch[1]);
        }
       }
       void fc(const info & a){
         cha = cha+a;
         cf = cf + a;
         all = cha+tr;
         val = app(val,a);
       }
       void ft(const info& a,int b){
        tf = tf+a;
        tr = tr+a;
        if(b && !inner) fc(a);
        else all = cha+tr;
       }
       void pd()
       {
            if(rev){
             for(int i = 0;i<2;++i)
              revit(ch[i]);
             rev = 0;
            }
            if(!inner && cf.ok())
            {
             for(int i = 0;i<2;++i)
              if(ch[i])
               ch[i]->fc(cf);
              cf = nulli;
            }
            if(tf.ok()){
              for(int i = 0;i<4;++i)
               if(ch[i])
                ch[i]->ft(tf,i>=2);
              tf = nulli;
            }
       }
       void upd(){
        if(!inner){
          cha = su(&val);
          for(int i = 0;i<2;++i)
           if(ch[i])
            cha = cha + ch[i]->cha;
        }else cha = su();
        tr = su();
        for(int i = 0;i<4;++i)
         if(ch[i])
          tr = tr + (i>=2?ch[i]->all:ch[i]->tr);
        if(!inner) all = cha+tr;
        else all = tr;
       }
       node * get(int kind)
       {
        if(ch[kind])
         ch[kind]->pd();
        return ch[kind];
       }
}tree[MN];

void rotate(node * u,int kind){
 node * fa = u->p;
 int t = u->getpos()&1;
 if(fa->p) fa->p->setc(u,fa->getpos());
 else u->p = 0;
 fa->setc(u->ch[!t+kind],t+kind);
 u->setc(fa,!t+kind);
 fa->upd();
}
void relax_all(node * u,int kind)
{
     if(!u->isrt(kind))
      relax_all(u->p,kind);
     u->pd();
}
void splay(node * u,int kind = 0){
 relax_all(u,kind);
 for(;!u->isrt(kind);rotate(u,kind))
  if(!u->p->isrt(kind))
   rotate(u->getpos()==u->p->getpos()?u->p:u,kind);
 u->upd();
}
node * ffa(node * u){
 splay(u);
 if(!u->p) return 0;
 if(!u->p->inner) return u->p;
 else {
  node * tmp = u->p;
  splay(tmp,2);
  return tmp->p;
 }
}
void add(node * p,node * v){
 p->pd();
 for(int i = 2;i<4;++i)
  if(!p->ch[i]){
  p->setc(v,i);
  return;
  }
 for(;p->ch[2] && p->ch[2]->inner;)
  p=p->get(2);
 node * x = new node;
 x->inner = 1;
 x->setc(p->ch[2],2);
 x->setc(v,3);
 p->setc(x,2);
 splay(x,2);
}
void del(node * u){
 splay(u);
 if(!u->p) return;
 node * p = u->p;
 if(p->inner)
 {
  relax_all(p,2);
  node * tmp = p->p;
  if(tmp){
   tmp->setc(p->get(u->getpos()^1),p->getpos());
   splay(tmp,2);
  }
  delete p ;
 }
 else
  p->setc(0,u->getpos()),splay(p);
 u->p = 0;
}
node * access(node * u){
 node * v = 0;
 if(!u) return 0;
 node * tmp = u;
 while(u){
        splay(u);
        if(u->ch[1]) add(u,u->ch[1]);
        if(v) del(v);
        u->setc(v,1);
        u->upd();
        node * tmp = ffa(u);
        v = u;
        u = tmp;
 }
 splay(tmp);
 return v;
}
node * myffa(node * u){
 access(u);
 u = u->get(0);
 while(u && u->get(1))
  u = u->get(1);
 return u;
}
void bert(node * u){
 access(u);
 u->revit(u);
}
void link(node * u,node * v){
 bert(v);
 add(u,v);
 access(v);
}
void cut(node * u){
 node * p = myffa(u);
 if(p){
  access(p);
  del(u);
  splay(p);
 }
}
node * lca(node * a,node * b){
 access(a);return access(b);
}
#undef ff
#define ff 
void show(node * u){
 /*if(!u||u->inner) return ;
  show(u->ch[0]);
  ff(debug,"%d ",u-tree);
  show(u->ch[1]);*/
}
int n, m;
int a[MN],b[MN];

int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi,m = gi;
    for(int i = 1;i<=n-1;++i) a[i] = gi,b[i] = gi;
    for(int i = 1;i<=n;++i) tree[i].val = gi,tree[i].upd();
    for(int i = 1;i<=n-1;++i)
    {
     int x = a[i],y = b[i];
     link(&tree[x],&tree[y]);
    }
    int rt = gi;
    node * newrt = &tree[rt];
    bert(newrt);
    splay(newrt);
    for(int i = 1;i<=m;++i)
    {
     int ty=gi,x,y;
     if(ty == 0 || ty == 3 || ty == 4 || ty == 5 || ty == 11){
      bert(newrt);
      x = gi;
      node * u = &tree[x];ff(debug,"\n");show(u);
      access(u);
      if(ty == 0 || ty == 5){
       y = gi;
       info a(ty == 5, y);
       u->val = app(u->val,a);
       for(int j = 2;j<4;++j)
        if(u->ch[j]) u->ch[j]->ft(a,1);
       u->upd();
       splay(u);
      }else {
       int ans = u->val;
       node * v;
       for(int i = 2;i<4;++i)
        if((v=u->ch[i])){
         if(ty == 3)
          ans = min(ans,v->all.minv);
         if(ty == 4)
          ans = max(ans,v->all.maxv);
         if(ty == 11)
          ans += v->all.sum;
        }
       printf("%d\n",ans);
      }
     }
      if(ty == 2 || ty == 6 || ty == 7 || ty == 8 || ty == 10){
      x = gi,y = gi;
      node * u = &tree[x];ff(debug,"\n");show(u);
      bert(&tree[x]);
      access(&tree[y]);
      splay(u);
      if(ty == 2 || ty == 6){
       int z = gi;
       u->fc(info(ty==6,z));
      }else{
       int ans = 0;
       if(ty == 7) ans = u->cha.minv;
       else if(ty == 8) ans = u->cha.maxv;
       else if(ty == 10) ans = u->cha.sum;
       printf("%d\n",ans);
      }
      
     }
      if(ty == 1){
       x = gi;
       bert(&tree[x]);newrt = &tree[x];ff(debug,"\n");show(&tree[x]);
      } if(ty == 9){
       x = gi, y= gi;
       swap(x,y);
       bert(newrt);
       node * u = &tree[x];ff(debug,"\n");show(u);
       node * v = &tree[y];
       if(lca(u,v) == v) continue;
       cut(v);
	   link(u,v);
      }
    }
    closeIO();
    return EXIT_SUCCESS;
}
