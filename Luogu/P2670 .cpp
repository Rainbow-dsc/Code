#include<bits/stdc++.h>
using namespace std;
char a[1001][1001]; 
int n,m;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
		for(int j=1;j<=m;j++) 
			cin>>a[i][j];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int t=0;
			if(a[i-1][j]=='*') t++;
			if(a[i][j-1]=='*') t++;
			if(a[i+1][j]=='*') t++;
			if(a[i][j+1]=='*') t++;
			if(a[i-1][j-1]=='*') t++;
			if(a[i+1][j+1]=='*') t++;
			if(a[i-1][j+1]=='*') t++;
			if(a[i+1][j-1]=='*') t++;
			if(a[i][j]=='?') a[i][j]=t+48;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) cout<<a[i][j];
		cout<<endl;
	}
	return 0;
}
