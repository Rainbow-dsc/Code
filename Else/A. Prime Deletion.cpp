#include <bits/stdc++.h>
using namespace std;
int T,a[100]; 
bool ifprime[100];
string s;
void pcr(){
	ifprime[2]=true;
	for(int i=3;i<=100;i++) {
		bool flag=false;
		for(int j=2;j<=sqrt(i);j++) {
			if(i%j==0) {
				flag=true;
				continue;
			}
		}
		if(flag==false) ifprime[i]=true;
	}
}
signed main() {
	scanf("%d",&T);
	memset(ifprime,false,sizeof(ifprime));
	pcr();
	while(T--) {
		bool flag=false;
		cin>>s;
		for(int i=0;i<s.size();i++) a[s[i]-'0']=i; 
		for(int i=0;i<s.size()-1&&flag==false;i++) {
			for(int j=i+1;j<s.size()&&flag==false;j++) {
				int num=int(s[i]-'0')*10+int(s[j]-'0');
				if(ifprime[num]==true) {
					printf("%d\n",num);
					flag=true;
				}
			}
		}
		if(flag=false) printf("-1\n");
	}
	return 0;
}

