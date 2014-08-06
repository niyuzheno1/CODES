#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXBLOCK = 10100;

struct edge
{
 int v,u,w,l;
};
struct lct_edge
{
 int w;
 edge * cir;
};
struct lct_msg
{
 int p[3];
 lct_edge *q[2];
 bool cir;
 void rev()
 {
  lct_edge * tmp = q[0];q[0] = q[1];q[1] = tmp;
  int tp = p[0];p[0] = p[2];p[2] = tp;
 }
 void co(edge * e,bool is)
 {
  cir = is?false:(e != NULL);
 }
 friend inline lct_msg operator+(const lct_msg & l,const lct_msg & r)
 {
  lct_msg res;
  res.q[0] = l.q[0],res.q[1] = r.q[1];
  lct_edge * e = l.q[1];
  res.cir = l.cir||e->cir||r.cir;
  if(l.p[2] != -1 && r.p[0] != -1)
  {
     res.p[0] = l.p[0];
     res.p[2] = r.p[2];
     int trL = l.p[2] + e->w + r.p[0];
     res.p[1] = l.p[1]+r.p[1]+min(trL,e->cir->l-trL);
  }
  else if(l.p[2] != -1)
  {
     res.p[0] = l.p[0];
     res.p[2] = r.p[1]+e->w+l.p[2];
     res.p[1] = l.p[1];
  }
  else if(r.p[0] != -1)
  {
     res.p[0] = l.p[1]+e->w+r.p[0];
     res.p[2] = r.p[2];
     res.p[1] = r.p[1];
  }
  else
  {
      res.p[0] = l.p[0];
      res.p[2] = r.p[2];
      res.p[1] = l.p[1]+e->w+r.p[1];
  }
  return res;
 }
};
int main(int argc, char *argv[])
{
    system("PAUSE");
    return EXIT_SUCCESS;
}
