#include<iostream>
#define N 5
using namespace std;

//////////////////////����һ�����뺯��/////////////////////////////

int input(double array[N][N])
{
// double array[N][N];
int i,j;
for (i=0;i<N;i++)
for (j=0;j<N;j++)
cin>>array[i][j];
return 0;
}

///////////////////////һ����ú���////////////////////////////////

void vary(double array[N][N]) //�任��������
{
int row1,row2,col;
//row1��ʾ�У�row2��ʾ��row1�Ļ����ϵ���һ�У�col��ʾ��Ӧ����
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
//////////////////////////������///////////////////////////////////
int main()
{
double a[N][N];
cout<<"\n\n";
cout<<"\t\t\t\t������һ�� "<<N<<" ά����"<<endl;
input(a);
vary(a);
for(int i=0;i<N;i++) //�任�����
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
