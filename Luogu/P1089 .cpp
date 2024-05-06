#include<bits/stdc++.h>
using namespace std;
int p,c,r,cost,flag=1;
int main(){
	for(int i=1;i<=12;i++){
		p+=300;
		cin>>cost;
		p-=cost;
		if(p<0){
			flag=0;
			c=i;
			break;
		}
		r+=p/100;
		p%=100;
	}
	if(flag==1) {
		p+=r*120;
		cout<<p;
	} else cout<<-c;
	return 0;
}
