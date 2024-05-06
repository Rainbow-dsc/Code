#include <bits/stdc++.h>
using namespace std;
int p1,p2,p3;
string s;
signed main() {
	scanf("%d%d%d",&p1,&p2,&p3);
	cin>>s;
	int len=s.size();
	for(int i=0; i<len; i++) {
		if(s[i]!='-'||(s[i]=='-'&&'0'<=s[i-1]<='9'&&'0'<=s[i+1]<='9'&&s[i-1]<s[i+1])||(s[i]=='-'&&'a'<=s[i-1]<='z'&&'a'<=s[i+1]<='z'&&s[i-1]<=s[i+1])) cout<<s[i];
		else {
			if('0'<=s[i-1]<='9') {
				if(p3!=3) {
					if(p1==1) {
						for(int p=int(s[i-1]-1); p<int(s[i+1]-1); p++) {
							for(int j=1; j<=p2; j++) cout<<char(p);
						}
					}
					if(p1==2) {
						for(int p=int(s[i-1]-1); p<int(s[i+1]-1); p++) {
							for(int j=1; j<=p2; j++) cout<<char(s[i+1]-p+s[i-1]);
						}
					}
				} else {
					for(int p=int(s[i-1]-1); p<int(s[i+1]-1); p++) {
						for(int j=1; j<=p2; j++) cout<<"*";
					}
				}
			}
			if('a'<=s[i-1]<='z') {
				if(p3==1) {
					if(p1==1) {
						for(int p=int(s[i-1]-1); p<int(s[i+1]-1); p++) {
							for(int j=1; j<=p2; j++) cout<<char(p);
						}
					}
					if(p1==2) {
						for(int p=int(s[i-1]-1); p<int(s[i+1]-1); p++) {
							for(int j=1; j<=p2; j++) cout<<char(s[i+1]-p+s[i-1]);
						}
					}
				} 
				if(p3==3){
					for(int p=int(s[i-1]-1); p<int(s[i+1]-1); p++) {
						for(int j=1; j<=p2; j++) cout<<"*";
					}
				}
			}
		}
	}
	return 0;
}

