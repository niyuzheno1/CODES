#include "mode.h"

using namespace std;

int main(int argc, char *argv[])
{
    while(true)
    {
    system("data");
    system("brute");
    system("cp sample.out sample.ans");
    clock_t start, finish;
    double duration;
    start = clock();
    system("ans");
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf( "%f seconds\n", duration );
    system("fc sample.out sample.ans");
    }
    return EXIT_SUCCESS;
}
