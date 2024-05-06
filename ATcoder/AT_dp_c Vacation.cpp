#include<bits/stdc++.h>
#define maxn 100001
using namespace std;
int n;
struct aa{
	int aaa,b,c;
}a[maxn];
int f[maxn][10];
signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i].aaa,&a[i].b,&a[i].c);
	for(int i=1;i<=n;i++) {
		f[i][1]=max(f[i-1][2],f[i-1][3])+a[i].aaa;
		f[i][2]=max(f[i-1][1],f[i-1][3])+a[i].b;
		f[i][3]=max(f[i-1][1],f[i-1][2])+a[i].c;
	}
	printf("%d",max(f[n][1],max(f[n][2],f[n][3])));
	return 0;
}
