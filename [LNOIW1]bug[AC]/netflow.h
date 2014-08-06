#undef TRA //undefine TRA in mode.h
#define TRA(x,y) for(int x = st[y];x;x=lk[x].n)
#define FIND(x,y) for(int & x = cur[y];x;x=lk[x].n)
#define PRE(x,y) for(int x = pre[y];x;x=pre[lk[x^1].v])
#define GAP(x) if((--num[d[x]]) == 0) break; 
#define BAL(x) lk[x].c-lk[x].f
#define INC(x) ++num[d[x]]
struct _nedge{int n,f,v,c;};
struct _cedge{int n,f,v,c,w;};
