#include<bits/stdc++.h>
#define int long long
#define maxn 1000005
using namespace std;
int ans,cnt,n,step;
char first[maxn],last[maxn];
void ck(char x,char y) {
	if(x==y)return;
	if(x=='R'&&y=='P') {
		ans++;
		return;
	}
	if(x=='R'&&y=='S') {
		cnt++;
		return;
	}
	if(x=='P'&&y=='R') {
		cnt++;
		return;
	}
	if(x=='P'&&y=='S') {
		ans++;
		return;
	}
	if(x=='S'&&y=='R') {
		ans++;
		return;
	}
	if(x=='S'&&y=='P') {
		cnt++;
		return;
	}
}
int gcd(int x,int y) {
	int maxnn=max(x,y);
	for(int i=maxnn; i<=x*y; i+=maxnn)
		if(i%x==0&&i%y==0)
			return i;
	return 0;
}
signed main() {
	scanf("%lld",&n);
	scanf("%s",first+1);
	scanf("%s",last+1);
	int len1=strlen(first+1);
	int len2=strlen(last+1);
	int m=gcd(len1,len2);
	for(int i=len1+1; i<=m; i++) {
		first[i]=first[++step];
		if(step==len1)step=0;
	}
	step=0;
	for(int i=len2+1; i<=m; i++) {
		last[i]=last[++step];
		if(step==len2)step=0;
	}
	for(int i=1; i<=m; i++) ck(first[i],last[i]);
	int size=n/m;
	n%=m;
	ans*=size;
	cnt*=size;
	for(int i=1; i<=n; i++) ck(first[i],last[i]);
	printf("%lld %lld\n",ans,cnt);
	return 0;
}
