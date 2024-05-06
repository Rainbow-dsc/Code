#include<iostream>
#include<cstring>
using namespace std;
struct stu
{
	char name[30];
	char sex[30];
	int age;
}s[5];
int main()
{
	strcpy(s1.name,"赵");
	strcpy(s2.name,"陶");
	strcpy(s3.name,"吕");
	strcpy(s4.name,"董");
	strcpy(s1.sex,"男");
	strcpy(s2.sex,"男");
	strcpy(s3.sex,"男");
	strcpy(s4.sex,"男");
	s1.age=12; 
	s2.age=12;
	s3.age=12;
	s4.age=12;
	cout<<s1.name<<"的个人信息：";
	cout<<"性别为："<<s1.sex;
	cout<<"年龄为："<<s1.age;
	cout<<s2.name<<"的个人信息："<<endl;
	cout<<"性别为："<<s2.sex;
	cout<<"年龄为："<<s2.age;
	cout<<s3.name<<"的个人信息："<<endl;
	cout<<"性别为："<<s3.sex;
	cout<<"年龄为："<<s3.age;
	cout<<s4.name<<"的个人信息："<<endl;
	cout<<"性别为："<<s4.sex;
	cout<<"年龄为："<<s4.age;
	return 0;
}


