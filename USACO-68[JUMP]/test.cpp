#include <cstdlib>
#include <iostream>

using namespace std;
typedef long long int64;
int64 x[6];
int main(int argc, char *argv[])
{
    x[3] = 1;
    x[0] = 0;
    x[1] = 0;
    x[2] = 0;
    x[4] = 0;
    x[5] = 0;
    x[3] = int64(int64(x[3])<<(int64(63)));
    x[4] = x[3];
    x[3] = 1;
    x[3] = int64(int64(x[3])<<(int64(63)));
    printf("%I64d",x[3]);
    system("PAUSE");
    return EXIT_SUCCESS;
}
