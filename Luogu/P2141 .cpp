#include<bits/stdc++.h>
using namespace std;
int n,a[1000001];
int ans;
int main() {
	cin>>n;
	for(int i=1; i<=n; i++) scanf("%d",&a[i]);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(a[i]!=a[j]) {
				int sum=a[i]+a[j];
				for(int k=1; k<=n; k++){
					if(a[k]==sum){
						ans++;
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
