#include<bits/stdc++.h>
using namespace std;
int n,v[60],m[60],c[60],f[410][410],V,M;//n不解释，v是体积，m是质量，c是卡路里 
int main(){
	cin>>V>>M>>n;
	for(int i=1;i<=n;i++){
		cin>>v[i]>>m[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=V;j>=v[i];j--){
			for(int l=M;l>=m[i];l--){
				f[j][l]=max(f[j][l],f[j-v[i]][l-m[i]]+c[i]);//变异的01背包 
			}
		}
	}
	cout<<f[V][M];
	return 0;
}
