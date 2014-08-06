#include "mode.h"
const int MN = 100000;
template <class T>
class BAllocator
{
private:
 static const int BL = 10000;
 union TItem{
 char rt[sizeof(T)];
 TItem * next;
 };
 TItem * pool,*tail;
 TItem * unused;
public:
 BAllocator()
 {
  pool = unused = NULL;
 }
 T* alloc()
 {
 TItem * p;
  if(unused)
  {p = unused;unused = unused->next;}
  else
  {
   if(pool == NULL) pool = new TItem[BL],tail = pool;
   p = tail++;
   if(tail == pool+BL) pool = NULL;
  }
  return (T*)p;
 }
 void de(T * pt)
 {
  TItem * p = (TItem*)pt;
  p->next = unused,unused = p;
 }
};
BAllocator<int> p;
struct edge{int v,u,w,totL;};
struct lct_edge{int w;edge * cirE; edge*getCirE(){return this?this->cirE:NULL;} };
struct lct_message
{
 int headL,midL,tailL;
 lct_edge * firstE,*lastE;
 bool hasCirE;
 void rev()
 {
  swap(firstE,lastE);swap(headL,tailL);
 }
 void coverCirE(edge * e,bool isSingle)
 {
  hasCirE = isSingle?false:e!=NULL;
 }
 friend inline lct_message operator+(const lct_message & lhs,const lct_message & rhs)
 {
  lct_message res;
  /*ÅÐ»·*/
  
  /*ÅÐ³¤¶È*/
  if(lhs.tailL != -1 && rhs.headL != -1)
  {
   int mid = lhs.tailL+lhs.lastE->w+rhs.headL;
   res.headL = lhs.headL;
   res.midL = lhs.midL + rhs.midL + min(mid,lhs.lastE->getCirE()->totL-mid);
   res.tailL = rhs.tailL;
  }
  else if(lhs.tailL != -1)
  {/*=>rhs.headL == -1*/
   res.headL = lhs.headL;
   res.midL = lhs.midL;
   res.tailL = lhs.tailL+lhs.lastE->w+rhs.midL;
  }
  else if(rhs.headL != -1)
  {
   /*=>lhs.tailL == -1
   */
   res.headL = lhs.midL+lhs.lastE->w+rhs.headL;
   res.midL = rhs.midL;
   res.tailL = rhs.tailL;
  }
  else
  {
   /*=>rhs.headL == -1 & lhs.tailL == -1*/
   res.headL = lhs.headL;
   res.tailL = rhs.tailL;
   res.midL = lhs.midL + lhs.lastE->w + rhs.midL;
  }
 }
};
int main(int argc, char *argv[])
{
    setIO("sample");
    
    closeIO();
    return EXIT_SUCCESS;
}
