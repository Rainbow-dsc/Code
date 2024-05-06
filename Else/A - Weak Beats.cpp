#include <bits/stdc++.h>
#define int long long
using namespace std;
string s;
signed main() {
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(i%2==1&&s[i]=='1') {
			cout<<"No";
			return 0;
		} 
	}
	cout<<"Yes";
	return 0;
}

