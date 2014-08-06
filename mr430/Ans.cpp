#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;
int p,k,n;
string s,str;
string h[5100];
int su[5100][5100];

bool fi(int a,int b)
{
 for(int i = 1;i<=n;i++)
  if(h[i].length()-1 <= b-a){
   bool ans = true;
   for(int j = a;j<=a+h[i].length()-1;j++)
    if(s[j] != h[i][j-a])
     ans = false;
   if(ans)
    return ans;
   }
  
  return false; 
}
char inf[101],ouf[101];
int main(int argc, char *argv[])
{
for(int cani = 0;cani<=4;cani++){
    
    memset(su,0,sizeof(su));
    memset(inf,0,sizeof(inf));
    memset(ouf,0,sizeof(ouf));
    sprintf(inf,"mr430.in%d",cani);
    sprintf(ouf,"mr430.ou%d",cani);
    ifstream cin(inf);
    ofstream cout(ouf);
    while(true){
    s = "";
    cin>>p>>k;
    if(cin.eof())
     break;
    for(int i = 1;i<=p;i++)
    {
     cin>>str;
     s+=str;
    }
    cin>>n;
    for(int i = 1;i<=n;i++)
     cin>>h[i];
    if(s.length() < k){ 
     cout<<0<<endl;
     continue;
    }
    for(int i = s.length()-1;i>=0;i--)
     for(int j = i;j<s.length();j++)
      if(fi(i,j))
       su[i][j] = su[i+1][j]+1;
      else
       su[i][j] = su[i+1][j];
    cout<<su[0][s.length()-1]<<endl;
    }
    cin.close();cout.close();
}
    return EXIT_SUCCESS;
}
