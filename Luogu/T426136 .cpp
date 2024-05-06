#include<bits/stdc++.h>
#define int long long
#define maxn 100005
using namespace std;
int n,q,cnt1=0,cnt2=0;
string s1,s2;
signed main(){
	cin>>n>>q>>s1>>s2;
	for(int i=0;i<s2.size();i++) if(s2[i]=='1') cnt1^=1; else cnt2^=1; 
	if(cnt1) reverse(s1.begin(),s1.end());
	if(cnt2) for(int i=0;i<s1.size();i++) {
		if(s1[i]=='1') s1[i]='0';
		else s1[i]='1';
	}
	cout<<s1;
	return 0;
}

