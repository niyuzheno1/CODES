#include<iostream>
#define N 5
using namespace std;

//////////////////////定义一个输入函数/////////////////////////////

int input(double array[N][N])
{
// double array[N][N];
int i,j;
for (i=0;i<N;i++)
for (j=0;j<N;j++)
cin>>array[i][j];
return 0;
}

///////////////////////一个变幻函数////////////////////////////////

void vary(double array[N][N]) //变换成上三角
{
int row1,row2,col;
//row1表示行，row2表示在row1的基础上的下一行，col表示相应的列
double m;
for(row1=0;row1<N;row1++)
{
for(row2=row1+1;row2<N;row2++)
{ 
m=array[row2][row1]/array[row1][row1];
for(col=row1;col<N;col++)
{
array[row2][col]=array[row2][col]-array[row1][col]*m;
} 
}
}
}
//////////////////////////主函数///////////////////////////////////
int main()
{
double a[N][N];
cout<<"\n\n";
cout<<"\t\t\t\t请输入一个 "<<N<<" 维矩阵"<<endl;
input(a);
vary(a);
for(int i=0;i<N;i++) //变换后输出
{
for(int j=0;j<N;j++)
{
cout<<a[i][j]<<" ";
// printf("%d",a[i][j]);
}
cout<<endl;
}
system("PAUSE");
}
