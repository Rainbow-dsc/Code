#include<bits/stdc++.h>
using namespace std;
int a,n,l,maxn=0,minn=0;
int main(){
	cin>>l>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		int y=l+1-a;
		if(a<l+1-a) swap(a,y);
		if(a>maxn) maxn=a;
		if(l+1-a>minn) minn=l+1-a;
	}
	cout<<minn<<" "<<maxn;
	return 0;
}
