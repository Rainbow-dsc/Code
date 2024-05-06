#include<bits/stdc++.h>
using namespace std;
int t,h[10001],s[10001];
char a;
signed main(){
	scanf("%d",&t);
	while(t--){
		memset(h,0,sizeof(h));
		memset(s,0,sizeof(s));
		for(int i=1;i<=8;i++)
			for(int j=1;j<=8;j++){
				cin>>a;
				if(a=='R') h[i]++;
				else s[j]++;
			}
		for(int i=1;i<=8;i++) {
			if(h[i]==8) {
				printf("R\n");
				break;
			}
			if(s[i]==8) {
				printf("B\n");
				break;
			}
		}
	}
	return 0;
}
