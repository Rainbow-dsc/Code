#include <bits/stdc++.h>
#define int long long
using namespace std;
int x,y;
bool check(int p) {
	if((p%4==0&&p%100!=0)||p%400==0) return true;
	else return false;
}
signed main() {
	scanf("%lld%lld",&x,&y);
	int sum=0;
	for(int i=x;i<=y;i++) if(check(i)==true) sum++;
	cout<<sum<<endl;
	for(int i=x;i<=y;i++) if(check(i)==true) cout<<i<<" ";
	return 0;
}

