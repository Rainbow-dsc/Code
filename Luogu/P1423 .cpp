#include<bits/stdc++.h>
using namespace std;
float s;
int main(){
	cin>>s;
	float p=2,ans=0;
	while(1){
		ans++;
		if(s-p<=0){
			cout<<ans;
			return 0;
		}
		s-=p;
		p*=0.98;
	}
	return 0;
}
