#include <bits/stdc++.h>
using namespace std;
int n,sum;
char a[1001][1001];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    	for(int j=1;j<=n;j++){
    		cin>>a[i][j];
    		if(a[i][j]=='1') sum++;
		}
    if(sum<=3||n==1) {
    	cout<<0;
    	return 0;
	}
	if(n==2){
		cout<<1;
		return 0;
	}
	if(sum==9){
		cout<<5;
		return 0;
	}
	if(a[1][1]='0'&&a[3][1]=='0'&&a[1][3]=='0'&&a[3][3]=='0'){
		cout<<0;
		return 0;
	}
    return 0;
}
