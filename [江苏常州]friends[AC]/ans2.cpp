#include "mode.h"

string f(const string & s,int o,int ol,int ms){
 bool m = false;
 int or1 = o,mod = ms,i = 0;
 while(i < ol){
  if(s[or1] != s[mod]){
   if(m) return string();
   m = true;
   ++mod;
   }
   else 
    ++or1,++mod,++i;
 }
 return s.substr(o,ol);
}
int main(int argc, char *argv[])
{
    setIO("sample");
    string ff;
    int N;
    cin>>N;cin>>ff;
    int ol = (ff.length()-1)/2;
    const string & pos1 = f(ff,ol+1,ol,0),pos2 = f(ff,0,ol,ol);
    if((pos1.empty() && pos2.empty() )||(ff.length()%2==0))
     cout<<"NOT POSSIBLE"<<endl;
    else if(pos1.empty())
     cout<<pos2<<endl;
    else if(pos2.empty())
     cout<<pos1<<endl;
    else if(pos1 != pos2)
     cout<<"NOT UNIQUE"<<endl;
    else
     cout<<pos1<<endl;
    closeIO();
    return EXIT_SUCCESS;
}
