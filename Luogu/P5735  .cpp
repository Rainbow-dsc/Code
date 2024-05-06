#include<bits/stdc++.h>
using namespace std;
float x,y,xq,y2,x2,yy;
float dis(float a,float b,float c,float d){
	return sqrt((a-c)*(a-c)+(b-d)*(b-d));
}
int main(){
	cin>>x>>y>>xq>>y2>>x2>>yy;;
	float p=dis(x,y,xq,y2);
	float c=dis(xq,y2,x2,yy);
	float r=dis(x2,yy,x,y);
	printf("%.2lf",p+c+r);
	return 0;
}
