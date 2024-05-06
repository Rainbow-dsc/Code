#include<bits/stdc++.h>
#define int long long
#define maxn 25005
#define maxm 65540
using namespace std;
int S,T,n,x,y,beg,cnt=0;
int a[maxn],b[maxn],tot[maxm];
bool ans[maxm];
int txor[maxm],tor[maxm];
bool cmp(int x,int y) { return x>y; }
signed main(){
	scanf("%lld %lld",&S,&T);
	while(T--) {
		memset(ans,0,sizeof(ans));
		memset(tot,0,sizeof(tot));
		memset(txor,0,sizeof(txor));
		memset(tor,0,sizeof(tor));
		cnt=0;
		scanf("%lld %lld %lld",&n,&x,&y);
		for(int i=1;i<=n;i++) {
			 scanf("%lld",&a[i]);
			if(i==1) beg=a[i];
			tot[a[i]]++;
			if(tot[a[i]]==1) cnt++,b[cnt]=a[i];
		}
		sort(b+1,b+cnt+1,cmp);
		for(int i=1;i<=cnt;i++) {
			if(b[i]==beg) {
				if(tot[b[i]]%2==1) {
					if(x>=(tot[b[i]]-1)) x-=(tot[b[i]]-1),txor[b[i]]+=(tot[b[i]]-1);
					else {
						txor[b[i]]+=x,x=0;
						tor[b[i]]=tot[b[i]]-x-1,y-=(tot[b[i]]-x-1);
					}
					ans[b[i]]=true;
				} else {
					if(y>=1) {
						if(x>=(tot[b[i]]-2)) {
							x-=(tot[b[i]]-2),txor[b[i]]=(tot[b[i]]-2);
							y--,tor[b[i]]=1;
						} else {
							txor[b[i]]=x,tor[b[i]]=(tot[b[i]]-x-1);
							x=0,y-=(tor[b[i]]);
						}
						ans[b[i]]=true;
					} else {
						txor[b[i]]=tot[b[i]]-1;
						x-=(tot[b[i]]-1);
					}
				}
			} else {
				if(tot[b[i]]%2==1) {
					if(x>=tot[b[i]]) {
						x-=tot[b[i]];
						txor[b[i]]+=tot[b[i]];
					} else {
						txor[b[i]]+=x;
						x=0;
						tor[b[i]]=tot[b[i]]-x;
						y-=(tot[b[i]]-x);
					}
					ans[b[i]]=true;
				} else {
					if(y>=1) {
						if(x>=tot[b[i]]-1) {
							x-=(tot[b[i]]-1);
							txor[b[i]]=(tot[b[i]]-1);
							y--;
							tor[b[i]]=1;
						} else {
							txor[b[i]]=x;
							tor[b[i]]=tot[b[i]]-x;
							x=0;
							y-=(tor[b[i]]);
						}
						ans[b[i]]=true;
					} else txor[b[i]]=tot[b[i]],x-=tot[b[i]];
				}
			}	
		}
		bool flag=false;
		for(int i=65537; i>=0; i--) {
			if(ans[i]==true) flag=true;
			if(flag==true) cout<<ans[i];
		}
		if(flag==false) cout<<0<<endl;
		else cout<<endl;
		for(int i=2; i<=n; i++) {
			if(txor[a[i]]>=1) cout<<"^",txor[a[i]]--;
			else cout<<"|",tor[a[i]]--;
		}
		cout<<endl;
	}
	return 0;
}
