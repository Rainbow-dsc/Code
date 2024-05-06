#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
struct aa{
	int ch,ma,en;
	int sum;
	int bian;
}a[305];
bool cmp(aa x,aa y){
	if(x.sum!=y.sum) return x.sum>y.sum;
	else if(x.sum==y.sum&&x.ch!=y.ch) return x.ch>y.ch;
	else return x.bian<y.bian;
}
signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i].ch,&a[i].ma,&a[i].en);
		a[i].sum=a[i].ch+a[i].ma+a[i].en;
		a[i].bian=i;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=5;i++) printf("%d %d\n",a[i].bian,a[i].sum);
	return 0;
}
