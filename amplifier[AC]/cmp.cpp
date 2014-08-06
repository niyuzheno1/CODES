#include <cstdlib>
#include <iostream>

using namespace std;
char str[10];
int main(int argc, char *argv[])
{
    int k = 0;
    while(k < 10)
    {
     system("data");
     system("Ans");
     system("Ans2");
     if(system("fc amplifier.out amplifier.ans")==1)
     {
      sprintf(str,"cp amplifier.in amplifier.in%d",k);
      system(str);
      k++;
     }
    }
    return EXIT_SUCCESS;
}
