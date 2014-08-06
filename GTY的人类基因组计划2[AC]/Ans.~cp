#include "mode.h"
const int MN =  1e5+10,p = 13131,pp = 21313,ppp=756753,pppp=10007;
typedef unsigned long long lld;
set<lld> hash;set<int> s;
typedef set<int>::iterator iter;
lld mp[MN],room[MN];
int size[MN],bel[MN];
int n , m ,  q ; 

void Change(int i,int j)
{
 room[bel[i]] ^= mp[i];
 size[bel[i]]--;
 if(!hash.count(room[bel[i]])) s.insert(bel[i]);else s.erase(bel[i]);
 room[(bel[i] = j)] ^= mp[i];
 ++size[bel[i]];
 if(!hash.count(room[bel[i]]))s.insert(bel[i]); else s.erase(bel[i]);
}

int Qsum(int l,int r)
{
    int ans = 0;
    for(;;){
     iter it = s.lower_bound(l);
     if(it == s.end() || *it>r) break;
     int deb = *it;
     ans += size[*it];
     hash.insert(room[*it]);
     s.erase(it);
    }
    return ans;
}

int main(int argc, char *argv[])
{
    srand(233);
    setIO("sample");
    n = gi; m = gi; q = gi;
    for(int i = 1;i<=n;++i) mp[i] = ((rand())*p+pp*(rand()+ppp))*pppp;
    size[1] = n;
    for(int i = 1;i<=n;++i) room[1] ^= mp[i],bel[i] = 1;
    s.insert(1);
    while(q--)
    {
     char opt[3];scanf("%s",opt);
     if(opt[0] == 'C'){
      int i = gi,j= gi;
      Change(i,j);
     }else {
      int l = gi,r = gi;
      printf("%d\n",Qsum(l,r));
     }
    }
    closeIO();
    return EXIT_SUCCESS;
}
