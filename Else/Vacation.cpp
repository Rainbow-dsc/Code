#include<bits/stdc++.h>
using namespace std;
int n,a[10005][3],f[10005][3];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i][0]>>a[i][1]>>a[i][2];
	for(int i=1;i<=n;i++){
		f[i][0]=max(f[i-1][1],f[i-1][2])+a[i][0];
		f[i][1]=max(f[i-1][0],f[i-1][2])+a[i][1];
		f[i][2]=max(f[i-1][0],f[i-1][1])+a[i][2];
	}
	cout<<max(max(f[n][0],f[n][1]),f[n][2]);
	return 0;
}
