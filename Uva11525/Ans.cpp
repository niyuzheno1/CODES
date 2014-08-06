#include <cstdlib>
#include <iostream>

using namespace std;
struct Tr
{
	int C[50010],N;
	int lowbit(int x){return x&(-x);}
	int add(int v,int x){ 
         while(v <= N) 
         C[v] += x,v+=lowbit(v);
        }
	void init()
	{
	for(int i = 0;i<=N;i++)
		C[i] = lowbit(i);
	}
	int sum(int v){
           int ret = 0;
          while(v > 0)  
           ret += C[v],v-=lowbit(v);
         }
	int GA(int x)
	{
	int mid;
	 for(int l = 1,r = N; l < R;)
	 {
	 mid = (l+r)/2;
	 int delta = sum(mid-1) - sum(mid-2);
	 if(delta > x)
	   R = mid;
	 else
	   L = mid;
	 }
	return mid;
	}
};
Tr t;
int test;
int main(int argc, char *argv[])
{
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	scanf("%d",&test);
    while(test--){
	int k,u;
	scanf("%d",&k);
	t.N = k;
	t.init();
	while(k--){
	scanf("%d",&u);
        k-1 == 0?printf("%d",t.GA(u)) : printf("%d ",t.GA(u)) ;
	}
    }
	fclose(stdin);
	fclose(stdout);
    return EXIT_SUCCESS;
}
