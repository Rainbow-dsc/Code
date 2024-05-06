#include<bits/stdc++.h>
using namespace std;
int n,t;
struct aa{
	int s,e;
}a[25005];
bool cmp(aa x,aa y){
	return x.s<y.s;
}
bool bj[25005];
int main(){
	memset(bj,false,sizeof(bj));
	scanf("%d%d",&n,&t);
	for(int i=1;i<=t;i++) scanf("%d%d",&a[i].s,&a[i].e);
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
		for(int j=a[i].s;j<=a[i].e;j++)
			bj[j]=true;
	int sum=0;
	for(int i=1;i<=n;i++){
		if(bj[i]==true) sum++;
	}
	if(sum<=n) {
		cout<<-1;
		return 0;
	}
	else {
		cout<<n;
		return 0;
	}
    return 0;
}
