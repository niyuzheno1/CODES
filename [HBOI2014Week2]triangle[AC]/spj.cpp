#include "mode.h"

const double eps =  1e-3;

FILE * a,* b,*c;
double xx,yy,uu,vv;
int T;
int main(int argc, char *argv[])
{
    a =  fopen("sample.ans","r");
    b =  fopen("sample.out","r");
    c =  fopen("sample.in","r");
    freopen("result.txt","w",stdout);
    fscanf(c,"%d",&T);
    while(T--)
    {
     fscanf(a,"%lf%lf",&xx,&yy);
     fscanf(b,"%lf%lf",&uu,&vv);
     if(fabs(((uu-xx)*(1.0/xx))<eps) && fabs(((vv-yy)*(1.0/yy))<eps))
      printf("AC\n");
    }
    fclose(a);fclose(b);fclose(c);
    fclose(stdout);
    return EXIT_SUCCESS;
}
