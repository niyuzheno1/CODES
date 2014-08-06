#include "mode.h"
#define iter iterator
typedef vector<int> vi;
typedef pair<string,string> pss;
map<string,vi> occ;
map<pss,int> ans;
string s;
int main(int argc, char *argv[])
{
    setIO("sample");
    cin>>s;
    int l = s.length();
    for(int i = 0;i<l;++i){
     string tmp("");
     for(int j = 0;j<4 && i+j <l;++j){
     tmp += s[i+j];
     occ[tmp].pb(i);
     }
    }
    int q;
    cin>>q;
    while(q--){
     string a,b;
     cin>>a>>b;
     if(ans[MP(a,b)]) {
      cout<<ans[MP(a,b)]<<endl;
      continue;
     }
     vi va(occ[a]),vb(occ[b]);
     if(va.empty()||vb.empty()){
      ans[MP(a,b)]=-1;
      cout<<"-1"<<endl;
      continue;
     }
     int res = INF;
     vi::iter ia = va.begin(),ib = vb.begin();
     for(;ia!=va.end()&&ib!=vb.end();)
     {
      res = min(res,int(max(a.size()+*ia,b.size()+*ib)-min(*ia,*ib)));
      if(*ia < *ib)++ia;
      else ++ib;
     }
     cout<<res<<endl;
     ans[MP(a,b)] = res;
    }
    closeIO();
    return EXIT_SUCCESS;
}
