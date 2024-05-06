#include<bits/stdc++.h>
#define maxn 100
#define int long long
using namespace std;
int T; 
int cnt1[maxn],cnt2[maxn];
signed main(){
	scanf("%lld",&T);
	while(T--) {
		memset(cnt1,0,sizeof(cnt1));
		memset(cnt2,0,sizeof(cnt2));
		bool flag=true,flagg=true;
		int n,k;
		scanf("%lld%lld",&n,&k);
		string s,s1;
		cin>>s>>s1;
		for(int i=0;i<n;i++) cnt1[s[i]-'a'+1]++;
		for(int i=0;i<n;i++) cnt2[s1[i]-'a'+1]++;
		for(int i=1;i<=26;i++) {
			if(cnt1[i]!=cnt2[i]) {
				cout<<"NO"<<endl;
				flag=false;
				break;
			}
		}
		for(int i=0;i<n&&flag==true;i++) {
			if(i+k>=n&&i<k) {
				if(s1[i]!=s[i]) {
					cout<<"NO"<<endl;
					flagg=false;
					break;
				}
			}
		}
		if(flagg==true&&flag==true) cout<<"YES"<<endl;
	}
	return 0;
}

