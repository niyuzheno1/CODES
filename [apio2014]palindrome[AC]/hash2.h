template<class _key,class _val,int S1,int S2,int S3>
struct hash
{
 public:
  static const int HM = S1;
  static const int PN = S2;
  static const int MN = S3;
  struct node{
   _key key;
   _val val[MN+1];
   node*ne;
  };
  node * pool,*tail;
  node ** h;
  hash()
  {
   pool = new node[PN];
   h = new node*[HM];
   tail = pool;
   fill(h,h+HM,(node*)NULL);
  }
  node * begin()
  {
   return pool;
  }
  node * end()
  {
   return tail;
  }
  void clear()
  {
   for(node * i = pool;i!= tail;++i)h[i->key%HM]=NULL;
   tail = pool;
  }
  _val *operator[](const _key & sta)
  {
   int id = sta%HM;
   for(node * p = h[id];p;p=p->ne)
    if(p->key == sta)
     return p->val;
   node * p = tail++;
   p->key = sta;
   fill(p->val,p->val+MN+1,0);
   p->ne = h[id],h[id] = p;
   return p->val;
  }
  void swap(hash & b)
  {
   std::swap(pool,b.pool);
   std::swap(tail,b.tail);
   std::swap(h,b.h);
  }
};
