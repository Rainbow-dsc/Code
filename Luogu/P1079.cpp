#include<bits/stdc++.h>
using namespace std;
int i,j,lenk;
char k[1010],m[1010],kn[1010],ans[1010];
char c[30][30];
void passchart() {
	int i,j;
	for(i=1; i<=26; i++) c[i][1]=char('a'+i-1);
	for(j=1; j<=26; j++) c[1][j]=char('a'+j-1);
	for(i=2; i<=26; i++) for(j=2; j<=26; j++) c[i][j]=(int(c[1][j]-'a')+int(c[i][1]-'a'))%26+'a';
}
int main() {
	scanf("%s%s",k,m);
	passchart();
	for(i=0; i<strlen(k); i++) if(k[i]<='Z'&&k[i]>='A') k[i]=char(k[i]+32);
	lenk=0;
	for(i=0; i<strlen(m); i++) {
		kn[i]=k[lenk];
		lenk=(lenk+1)%strlen(k);
	}
	for(i=0; i<strlen(m); i++) {
		bool f=0;
		if(m[i]>='A'&&m[i]<='Z') {
			m[i]=char(m[i]+32);
			f=1;
		}
		for(j=1; j<=26; j++) 
			if(c[int(kn[i]-'a'+1)][j] == m[i]) {
				if(f) ans[i]=char(c[1][j]-32);
				else ans[i]=c[1][j];
				break;
			}
	}
	for(i=0; i<strlen(m); i++) cout<<ans[i];
	return 0;
}
