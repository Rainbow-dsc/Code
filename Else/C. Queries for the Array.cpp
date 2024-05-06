#include<bits/stdc++.h>
using namespace std;
int T,L,R;
int f[200005],fl;
int main(){
	scanf("%d",&T);
	while(T--){
		string a;
		cin>>a;
		memset(f,0,sizeof(f));
		f[0]=f[1]=1;
		fl=0;L=R=0;
		for(int i=0;i<a.length()&&!fl;i++){
			if(a[i]=='+'){
				R++;
				if(f[R-1]==2) f[R]=2;
			}
			else if(a[i]=='-'){
				if(R==0) fl=1;
				f[R--]=0;
				L=min(L,R);
			} 
			else if(a[i]=='1') {
				if(f[R]==2) fl=1;
				L=R;
			}
			else if(a[i]=='0'){
				if(R<2) fl=1;
				else if(L>=R) fl=1;
				f[R]=2;
			}
		}
		if(fl) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
