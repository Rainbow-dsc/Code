// #pragma GCC optimize(2)
#include<bits/stdc++.h>
//#define int long long
#define maxn 3000005
using namespace std;
int T;
int get_num(char x) {
	if(x<='Z'&&x>='A') return x-'A';
	if(x<='9'&&x>='0') return x-'0'+52;
	if(x<='z'&&x>='a') return x-'a'+26;
}
struct Trie {
	int ans[maxn];
	int nxt[maxn][70],cnt;
	void init() {
		for(int i=0;i<=cnt;++i){
			ans[i]=0;
			for(int j=0;j<=69;++j) nxt[i][j]=0;
		}
		cnt=0;
	}
	void insert(string s) {
		int p=0,len=s.size();
		for(int i=0; i<len; i++) {
			int now=get_num(s[i]);
			if(!nxt[p][now]) nxt[p][now]=++cnt;
			p=nxt[p][now];
			ans[p]++;
		}
	}
	int find(string s) {
		int p=0,len=s.size();
		for(int i=0; i<len; i++) {
			int now=get_num(s[i]);
			if(!nxt[p][now]) return 0;
			p=nxt[p][now];
		}
		return ans[p];
	}
}Tre;
signed main() {
	scanf("%lld",&T);
	while(T--) {
		int n,q;
		scanf("%lld %lld",&n,&q);
		Tre.init();
		for(int i=1; i<=n; i++) {
			string s;
			cin>>s;
			Tre.insert(s);
		}
		for(int i=1; i<=q; i++) {
			string s;
			cin>>s;
			printf("%lld\n",Tre.find(s));
		}
	}
	return 0;
}
