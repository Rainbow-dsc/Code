#include<bits/stdc++.h>
using namespace std;
int n,k,a[1000001],qx1[1000001],qx2[1000001];
void minn(){
	int h=0,t=1;
	for(int i=1;i<=n;i++){
		while(h<=t&&qx1[h]+k<=i) h++;
		while(h<=t&&a[i]<a[qx1[t]]) t--;
		qx1[++t]=i;
		if(i>=k) printf("%d ",a[qx1[h]]);
	}
	cout<<endl;
}
void maxn(){
	int h=0,t=1;
	for(int i=1;i<=n;i++){
		while(h<=t&&qx2[h]+k<=i) h++;
		while(h<=t&&a[i]>a[qx2[t]]) t--;
		qx2[++t]=i;
		if(i>=k) printf("%d ",a[qx2[h]]);
	}
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	minn();
	maxn();
	return 0;
}
