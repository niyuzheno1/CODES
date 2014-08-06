#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
const int MAXLEN = 11;
int n;
struct node
{
 node *ch[2],*fa;
 char a[MAXLEN];
 int size,w;
 node(char c[],int _w)
  : size(1),w(_w)
 {memcpy(a,c,sizeof(a));ch[0] = ch[1] = NULL;}
 node(char c[],node * _fa,int _w)
  : w(_w),size(1)
  {memcpy(a,c,sizeof(a));fa = _fa;ch[0] = ch[1] = NULL;}
  void updata()
  {
   size = 1;
   if(ch[0] != NULL)size += ch[0]->size;
   if(ch[1] != NULL)size += ch[1]->size;
  }
}*root = NULL;
char s[MAXLEN];
void rotate(node * & x,int i)
{
 node * y = x->ch[i^1];x->ch[i^1]=y->ch[i];
 if(x->ch[i^1])
  x->ch[i^1]->fa=x;
 y->ch[i] = x;
 y->fa = x->fa;
 x->fa = y;
 x->updata();y->updata();
 if(y->fa)
 {
  if(y->fa->ch[0] == x) y->fa->ch[0] = y;
  else y->fa->ch[1] = y;
 }
 x = y;
}
map <string,node*>  h;
void insert(node *&x,int w)
{
 if(x == NULL){x=new node(s,w);x->fa = NULL;h[string(s)]=x;return;}
 int i = w<=x->w;
 if(x->ch[i] == NULL)
 { x->ch[i] = new node(s,x,w);h[string(s)] = x->ch[i];x->updata(); return;}
 else
 insert(x->ch[i],w);
 x->updata();
 if(rand()%(x->size) < 1)rotate(x,i^1);
 if(x->fa == NULL)root = x;
}
void del(node * & x)
{
 while(1)
 {
  if(x->ch[0]) { rotate(x,1);if(x->fa==NULL)root = x;x=x->ch[1];}
  else if(x->ch[1]){rotate(x,0);if(x->fa==NULL)root = x;x=x->ch[0];}
  else
   break;
 }
 if(x->fa)
 {
  node*p=x->fa;
  int i = p->ch[1]==x;
  p->ch[i] = NULL;
  while(p) p->size--,p=p->fa;
 }
 if(root == x)
  root = NULL;
 delete(x);
}
void find_kth(node *& x,int k)
{
 int ls = x->ch[0]!=NULL?x->ch[0]->size:0;
 int rs = x->size-1-ls;
 if(ls >= k) find_kth(x->ch[0],k);
 else if(ls + 1 == k)memcpy(s,x->a,sizeof(s));
 else find_kth(x->ch[1],k-ls-1);
}
int count(node * x)
{
 int ans = 1;
 ans+=(x->ch[0] != NULL)?x->ch[0]->size:0;
 while(x)
 {
  node * y = x->fa;
  if(y == NULL) return ans;
  if(y->ch[1] == x) ans++,ans+=(y->ch[0])?y->ch[0]->size:0;
  x = x->fa;
 }
 return ans;
}

int main(int argc, char *argv[])
{
    #ifndef ONLINE_JUDGE
    freopen("bzoj1056.in","r",stdin);freopen("bzoj1056.out","w",stdout);
    #endif
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
    {
     int w;char c;
     scanf("%c",&c);
     switch(c)
     {
      case '+':
           {
            scanf("%s %d\n",s,&w);
            if(h.find(s) == h.end())
             insert(root,w);
            else
             del(h[s]),insert(root,w);
            break;
           }
      case '?':
           {
            scanf("%s\n",s);
            if(!isupper(s[0]))
            {
             w = strtol(s,0,10);
             int tot = min(root->size,w+9);
             for(int j = w;j<=tot;j++)
             {
              find_kth(root,j);
              printf("%s",s);
              if(j < tot)
               printf(" ");
              else
               puts("");
             }
            }
            else
             printf("%d\n",count(h[s]));
           }
           
     }
    }
    
    #ifndef ONLINE_JUDGE
    fclose(stdin);fclose(stdout);
    #endif
    return EXIT_SUCCESS;
}
