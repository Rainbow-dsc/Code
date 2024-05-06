#include<bits/stdc++.h>
using namespace std;
int n,sum;
bool m[10010];
int a[10010];
int main() {
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		m[a[i]]=1;
	}
	for(int j=1; j<=n; j++) {
		for(int o=j+1; o<=n; o++) {
			int t=a[j]+a[o];
			if(m[t]) {
				sum++;
				m[t]=0;
			}
		}
	}
	cout<<sum;
	return 0;
}
