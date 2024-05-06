/*
高效率的冒泡(相邻的两个数的比较，如果后面的数字比前面的数字要小，则交换两个数字)
分类 -------------- 内部比较排序
数据结构 ---------- 数组
最差时间复杂度 ---- O(n^2)
最优时间复杂度 ---- 如果能在内部循环第一次运行时,使用一个旗标来表示有无需要交换的可能,可以把最优时间复杂度降低到O(n)
平均时间复杂度 ---- O(n^2)
所需辅助空间 ------ O(1)
稳定性 ------------ 稳定
*/

#include<iostream> 
using namespace std;
void bubble_sort(int a[],int n)  
{
	int flag;
	for(int i=0;i<n-1;i++)			//控制轮数
	{
		flag=0;
		for(int j=0;j<n-1-i;j++)	//控制每一轮的次数
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
