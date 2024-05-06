#include<bits/stdc++.h>
using namespace std;
int a[1001][1001];
int maxn=-1e9,sum=0;
int n,m;
int main(){
	scanf("%d%d",&n,&m);	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
			sum+=a[i][j];
			maxn=max(maxn,a[i][j]);
		}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			printf("%d ",a[i][j]);
//			sum+=a[i][j];
//			maxn=max(maxn,a[i][j]);
		}
		cout<<endl;
	}
		
//	cout<<max(maxn,sum);
	return 0;
}
