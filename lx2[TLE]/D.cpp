#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <windows.h>
using namespace std;
const string a[]
={
  "",
  "01",
  "02",
  "03",
  "04",
  "05",
  "06",
  "07",
  "08",
  "09",
  "10",
  "11",
  "12"    
};
const string b[]
={
 "",
 "a",
 "b",
 "c",
 "d",
 "e",
 "f"
};
BOOL ret;
string in,ans;
WIN32_FIND_DATA fdt;
int main(int argc, char *argv[])
{
    for(int i = 1;i<=12;i++)
     for(int j = 1;j<=6;j++){
     in = "data\\";
     ans = "data\\";
     in+=a[i];in+='.';in+=b[j];in+='.';in+="in";
     ans+=a[i];ans+='.';ans+=b[j];ans+='.';ans+="out";
     HANDLE hFile = FindFirstFile(in.c_str(), &fdt);
     if (hFile == INVALID_HANDLE_VALUE)
      continue;
     else
      FindClose(hFile);
     printf(in.c_str());
     printf("\n");
     printf(ans.c_str());
     printf("\n");
     CopyFile(in.c_str(),"alliances.in",ret);
     if(ret)
      continue;
     CopyFile(ans.c_str(),"alliances.ans",ret);
     if(ret)
      continue;
     system("Ans.exe");
     system("check.exe alliances.in alliances.out alliances.ans");
     DeleteFile("alliances.in");
     DeleteFile("alliances.ans");
     system("PAUSE");
    }
    return EXIT_SUCCESS;
}
