#include <cstdlib>
#include <iostream>
#include <map>
#define X first
#define Y second
using namespace std;
const int inf = 27;
typedef map<int,int> mp;
mp f[inf];
int n;
int a[inf];
char str[110];
int main(int argc, char *argv[])
{
    freopen("font.in","r",stdin);
    freopen("font.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
     scanf("%s",&str);
     for(int j = 0;j<strlen(str);j++)
      a[i] = a[i] | (1<<(str[j]-'a'));
    }
    f[1][0] = 1;
    for(int i = 1;i<=n;i++)
     for(mp::iterator it = f[i].begin();it != f[i].end();it++){
      f[i+1][(*it).X] += (*it).second;
      f[i+1][(*it).X|a[i]] += (*it).second;
     }
    printf("%d",f[n+1][67108863]);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
