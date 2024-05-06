#include <bits/stdc++.h>
using namespace std;
long long a[1000010];
int main() {
	long long t;
	cin>>t;
	long long num = 1;
	long long p = 0;
	long long s = 1;
	long long l = 1;
	string v;
	a[1] = 1;
	for(long long i = 1; i<=1000005; i++) {
		if(s>l) {
			num+=1;
			s = 1;
		}
		if(num>p) {
			num = 1;
			p = p+1;
			s = 1;
			stringstream o;
			o<<p;
			o>>v;
			l = v.length();
		}
		a[i]=v[s-1]-'0';
		a[i] += a[i-1];
		s++;
	}
	for(long long i = 1; i<=t; i++) {
		long long x,y;
		scanf("%lld%lld",&x,&y);
		cout<<a[y]-a[x-1]<<"\n";
	}
	return 0;
}
