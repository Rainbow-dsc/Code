#include<bits/stdc++.h>
using namespace std;
int n,m;
int w[1001],v[1001],f[100001];
int main(){
	cin>>m>>n;
	for(int i=1;i<=n;i++){
		cin>>v[i]>>w[i];
		w[i]*=v[i];
	}
	for(int i=1;i<=n;i++){
        for(int j=m;j>=v[i];j--){
        	if(j>=v[i]) f[j]=max(f[j],f[j-v[i]]+w[i]);
        }
    }
    cout<<f[m];
	return 0;
}

