#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
int main()
{
	/*
	�������ͣ�int��float��double ��long long ��char 
	�ַ������壺
				char a[100]={"iloveyou"}
				char a[100]="iloveyou";
	cin>>a;			cin���ܰѺ��пո���ַ���ȫ������
	scanf("%s",a); ���ܰѺ��пո���ַ���ȫ������
	gets(a);		�����ַ��� 
	puts(a);		����ַ���
	strlen(a);		���ַ����ĳ���
	strcmp(a,b);	����asciiֵ��Ƚϣ�A(65) a(97),a>b==1,a<b==-1,a==b==0
	strcat(a,b);	ƴ��-->a�ܹ�����a+b���ܳ���  loveyou
	strcpy(a,b);	��b���Ƶ�a-->a�ܹ�����b�ĳ��� 
	*/
//	int a=6;
//	cin>>a;
//	float a=6.0;
//	cin>>a;
//	char a='6';
//	cin>>a;
//	int a[100];//�������� 
//	for(int i=0;i<10;i++)
//	{
//		cin>>a[i];
//	}
//	float a[100]={1.2,1.3,����};//���������� 
//	for(int i=0;i<10;i++)	//�����鸳ֵ��Ҫ�������룬���±���� 
//	{
//		cin>>a[i];
//	}
//	char a[100]={'6','5','78'����}; //�ַ�������
//	for(int i=0;i<10;i++)	//�����鸳ֵ��Ҫ�������룬���±���� 
//	{
//		cin>>a[i];
//	}	
	char a[100];
	char b[100]; //�����ַ��� 
//	cin>>a;		//cin���ܰѺ��пո���ַ���ȫ������
//	scanf("%s",a); //���ܰѺ��пո���ַ���ȫ������
	gets(a);	//love
	gets(b);	//lover	 
	cout<<strlen(a)<<endl;	//4
	cout<<strcmp(a,b);		//b��ø�һ 
	puts(strcat(a,b));		//lovelover 
	strcpy(a,b);		
	puts(a);				//lover 
	puts(b);				//lover 
	return 0;
}

