#include<iostream>
using namespace std;
struct matrix
{
	int n,m;//���������������
	int a[20][20];//a[i][j]��������i�е�j�е��� 
	matrix()//���캯�� 
	{
		n=m=0;
		memset(a,0,sizeof(a));
	}
};
matrix operator*(const matrix &m1,const matrix &m2)//����m1*m2
{//O(n^3)
	matrix m3;//�������m3��
	m3.n = m1.n;
	m3.m = m2.m;
	for (int i=1;i<=m3.n;i++)
		for (int j=1;j<=m3.m;j++)//�����������е�i�е�j�е���
			for (int k=1;k<=m1.m;k++)
				m3.a[i][j] += m1.a[i][k] * m2.a[k][j];
				
	return m3;
}

matrix ksm(const matrix x,int y)//����x��y�η�
{
	matrix ans;
	ans.n=ans.m=x.n;
	for (int i=1;i<=ans.n;i++)
		ans.a[i][i]=1;
	
	while (y)
	{
		if (y%2==1) ans=ans*x;
		x=x*x;
		y=y/2;
	}
	return ans;
}

int main()
{
	for (int i=1;i<=5;i++)
	{
		matrix m;
	}
}
