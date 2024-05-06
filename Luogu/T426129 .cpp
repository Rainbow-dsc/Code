#include<bits/stdc++.h>
#define int long long
#define maxn 100005
using namespace std;
signed main(){
	int x,y,z,cnt=0;
	scanf("%lld %lld %lld",&x,&y,&z);
	if(x+y<z) cnt++;
	if(x+z<y) cnt++;
	if(y+z<x) cnt++;
	cout<<cnt;
	return 0;
}
