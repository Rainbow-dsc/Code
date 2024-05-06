#include<bits/stdc++.h>
using namespace std;
int main() {
	int l,r,ans=0;
	cin>>l>>r;
	for(int i=l;i<=r;i++){
		int n=i;
		while(n!=0){
			if(n%10==2) ans++;
			n/=10;
		}
	}
	cout<<ans;
	return 0;
}
