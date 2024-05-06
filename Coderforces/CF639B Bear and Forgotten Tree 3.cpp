//#pragma GCC optimize(2)
#include<bits/stdc++.h>
//#define int long long
using namespace std;
int n,d,h;
signed main(){
	scanf("%d %d %d",&n,&d,&h);
	if(h*2<d) {
		cout<<-1;
		return 0;
	}
	if(d==1&&h==1&&n>2) {
		cout<<-1;
		return 0;
	}
	for(int i=2;i<=h+1;i++) printf("%d %d\n",i-1,i);
	for(int i=h+2;i<=d+1;i++) {
		if(i==h+2) printf("%d %d\n",1,i);
		else printf("%d %d\n",i-1,i);
	}
	for(int i=d+2;i<=n;i++) {
		if(d==h) printf("%d %d\n",2,i);
		else printf("%d %d\n",1,i);
	}
    return 0;
}
//10 3 3
//3  1 1
