/*
��Ч�ʵ�ð��(���ڵ��������ıȽϣ������������ֱ�ǰ�������ҪС���򽻻���������)
���� -------------- �ڲ��Ƚ�����
���ݽṹ ---------- ����
���ʱ�临�Ӷ� ---- O(n^2)
����ʱ�临�Ӷ� ---- ��������ڲ�ѭ����һ������ʱ,ʹ��һ���������ʾ������Ҫ�����Ŀ���,���԰�����ʱ�临�ӶȽ��͵�O(n)
ƽ��ʱ�临�Ӷ� ---- O(n^2)
���踨���ռ� ------ O(1)
�ȶ��� ------------ �ȶ�
*/

#include<iostream> 
using namespace std;
void bubble_sort(int a[],int n)  
{
	int flag;
	for(int i=0;i<n-1;i++)			//��������
	{
		flag=0;
		for(int j=0;j<n-1-i;j++)	//����ÿһ�ֵĴ���
		{
			if(a[j]>a[j+1])
			{
//				temp=s[j];
//				s[j]=s[j+1];
//				s[j+1]=temp;
				swap(a[j],a[j+1]);			
				flag=1;
			}
		}
		if(flag==0)
		break;
	}
}

int main()
{
	int s[10],*p,temp,flag;
	p=s;
	for(int i=0;i<10;i++)
	{
		cin>>*(p++);
	}
	bubble_sort(s,10);
	p=s;
	for(int i=0;i<10;i++)
	{
		cout<<*(p++)<<" ";
	} 
	return 0; 
}
