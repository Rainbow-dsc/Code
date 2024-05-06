#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
int main()
{
	/*
	数据类型：int、float、double 、long long 、char 
	字符串定义：
				char a[100]={"iloveyou"}
				char a[100]="iloveyou";
	cin>>a;			cin不能把含有空格的字符串全部输入
	scanf("%s",a); 不能把含有空格的字符串全部输入
	gets(a);		输入字符串 
	puts(a);		输出字符串
	strlen(a);		求字符串的长度
	strcmp(a,b);	按照ascii值表比较，A(65) a(97),a>b==1,a<b==-1,a==b==0
	strcat(a,b);	拼接-->a能够容纳a+b的总长度  loveyou
	strcpy(a,b);	把b复制到a-->a能够容纳b的长度 
	*/
//	int a=6;
//	cin>>a;
//	float a=6.0;
//	cin>>a;
//	char a='6';
//	cin>>a;
//	int a[100];//整型数组 
//	for(int i=0;i<10;i++)
//	{
//		cin>>a[i];
//	}
//	float a[100]={1.2,1.3,……};//浮点型数组 
//	for(int i=0;i<10;i++)	//给数组赋值，要遍历输入，对下标操作 
//	{
//		cin>>a[i];
//	}
//	char a[100]={'6','5','78'……}; //字符型数组
//	for(int i=0;i<10;i++)	//给数组赋值，要遍历输入，对下标操作 
//	{
//		cin>>a[i];
//	}	
	char a[100];
	char b[100]; //定义字符串 
//	cin>>a;		//cin不能把含有空格的字符串全部输入
//	scanf("%s",a); //不能把含有空格的字符串全部输入
	gets(a);	//love
	gets(b);	//lover	 
	cout<<strlen(a)<<endl;	//4
	cout<<strcmp(a,b);		//b大得负一 
	puts(strcat(a,b));		//lovelover 
	strcpy(a,b);		
	puts(a);				//lover 
	puts(b);				//lover 
	return 0;
}

