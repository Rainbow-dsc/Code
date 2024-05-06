#include<bits/stdc++.h>
using namespace std;
int a,n,l,maxn=0,minn=0,x,y,m;
int main(){
	cin>>l>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		x=a;
		y=l+1-a;
		if(x<y) swap(x,y);
		if(x>maxn) maxn=x;
		if(y>minn) minn=y;
	}
	cout<<minn<<" "<<maxn;
	return 0;
}
