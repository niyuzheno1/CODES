template<class T>
struct ptr{
 T * p;
 ptr(){p = NULL;}
 ptr(T * q){p = q;++p->ref;}
 ptr(const ptr<T> & a) {p = a.p;++p->ref;}
 ~ptr(){
  if(p){ --p->ref;
    if(!p->ref){delete p;}
  }
 }
 T * operator ->() {return p;}
 bool operator == (const ptr<T> & a) const{
  return p == a.p;
 }
 bool operator != (const ptr<T> & a) const {
  return p != a.p;
 }
 ptr<T>& operator = (const ptr<T> & a){
  if(p != a.p && p){
         --p->ref;
         if(!p->ref) {delete p;}
  }
  p = a.p;++p->ref;
 return (*this);
 }
};
