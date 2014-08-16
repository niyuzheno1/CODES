#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    clock_t st,ed;
    st = clock();
    system("ans4");
    ed = clock();
    printf("%.7f\n",double(ed-st)/CLOCKS_PER_SEC);
    st = clock();
    system("ans2");
    ed = clock();
    printf("%.7f\n",double(ed-st)/CLOCKS_PER_SEC);
    system("PAUSE");
    return EXIT_SUCCESS;
}
