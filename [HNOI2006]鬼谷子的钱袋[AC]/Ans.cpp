#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;
int n;
int main(int argc, char *argv[])
{
    cin>>n;
    cout<<int(log(n)/log(2))+1<<endl;
    return EXIT_SUCCESS;
}
