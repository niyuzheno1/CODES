#include "mode.h"
#include "debug.h"
#include "ptr.h"
#undef SIZE
int ran(){ 
    static int x=222313214; 
    x+=(x<<2)+1; 
    return x; 
} 
struct node;
typedef ptr<node> pt;
int pcnt;
struct node{ 
    int w,sz; 
    char k; 
    pt l,r; 
    int ref;
    static pt getnew();
}; 
node None;
pt none(&None);
pt node::getnew(){ 
       node * x = new node;
       x->w = ran();
       x->l = none;
       x->r = none;
       x->sz = 1;
       x->ref = 0;
       return pt(x);
} 
#define SIZE(_) (((_)!=none)?(_)->sz:0) 
int M,curid; 
queue<pair<int,node*> > Literbox; 
deque<node*> Roots; 
void giveback(node *p){ 
    Literbox.push(make_pair(curid,p)); 
} 
pt combine(pt p,pt q){ 
    if (p==none || q==none)return (q==none)?p:q; 
    if (p->w<q->w){  
        pt a = p;
        a->sz=p->sz+q->sz;
        a->r=combine(p->r,q);  
        return a; 
    }else{ 
        pt a = q;
        a->sz=p->sz+q->sz;
        a->l=combine(p,q->l);  
        return a; 
    } 
} 
void cutdown(pt p,pt &x,pt &y,int a){ 
    if (a==0)x=none,y=p; 
    else if (a==SIZE(p)){ 
        x=p;y=none; 
    }else{ 
        if (SIZE(p->l)+1<=a){ 
            //x=node::getnew(); 
            x = p; 
            x->sz=a;  
            cutdown(p->r,x->r,y,a-SIZE(p->l)-1); 
            //giveback(p); 
        }else{ 
            //y=node::getnew(); 
            y = p; 
            y->sz=p->sz-a;
            cutdown(p->l,x,y->l,a); 
            //giveback(p); 
        } 
    } 
} 
void treeadd(pt &p,pt q){ 
    if (p == none){ 
        p=q; 
    }else{ 
        if (p->w<q->w){ 
            treeadd(p->r,q); 
            p->sz++; 
        }else{ 
            q->l=p;q->sz=p->sz+1; 
            p=q; 
        } 
    } 
} 

pt now;
void Insert(int i,pt a){ 
   pt x=none,y=none;
   cutdown(now,x,y,i);
   x = combine(x,a);
   x = combine(x,y);
   now = x;
} 
void Delete(int i,int r){ 
    pt x=none,y =none,z =none; 
    cutdown(now,x,y,i); 
    cutdown(y,y,z,r-i+1); 
    x=combine(x,z); 
    now = x;
} 
void Revolve(int a,int b,int c){ 
    pt p=none,q=none,r=none,s=none,w=none; 
    cutdown(now,p,q,a);
    cutdown(q,r,s,b-a+1);
    p = combine(p,s);
    cutdown(p,q,s,c);
    p = combine(q,r);
    p = combine(p,s);
    now = p;
} 
void dfs(pt x,int y){
 if(y == x->l->sz+1)
 {
  printf("%d",x->k);
  return;
 }
 if(y <= x->l->sz)
  dfs(x->l,y);
 else if(y > x->l->sz+1 )
  dfs(x->r,y-(x->l->sz+1));
}
void print(int x){
    dfs(now,x); 
    puts("");
}

int n ;
void init(){
 none->w = INF;
 none->l = none;
 none->r = none;
 none->k = 0;
 none->sz = 0;
 none->ref = 10;
}
int main() 
{ 
    setIO("sample");
    init();
    
    pt r=none; 
    
    scanf("%d%d",&n,&M); 
    DEG_PIN_1_BEGIN
    for (int i=1;i<=n;i++){ 
        pt p=node::getnew(); 
        p->k=gi; 
        treeadd(r,p); 
    } 
    DEG_PIN_1_END
    now = r;
    curid=0; 
    char cmd[10]; 
    while (scanf("%s",cmd)!=EOF){ 
        if (cmd[0]=='I'){ 
            int x; 
            scanf("%d",&x);
            int len =  0; 
            scanf("%d",&len);
            pt nr = none;
            for(int i = 1;i<=len;++i)
            {
             pt p = node::getnew();
             p->k = gi;
             treeadd(nr,p);
            }
            Insert(x,nr);
        }else if (cmd[0]=='D'){ 
            int x,y; 
            scanf("%d%d",&x,&y); 
            Delete(x-1,y-1); 
        }else if (cmd[0]=='P'){ 
            int x;
            scanf("%d",&x);
            print(x); 
        }else if (cmd[0]=='C'){ 
            
            int x,y,z; 
            scanf("%d%d%d",&x,&y,&z); 
            Revolve(x-1,y-1,z); 
            
        } 
       
        
     }
    printf("%d",pcnt);
    return 0; 
} 
