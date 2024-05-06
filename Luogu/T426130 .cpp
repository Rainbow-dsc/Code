#include<bits/stdc++.h>
#define int long long
#define maxn 100005
using namespace std;
double a,b,c,d,e,x,y;
signed main(){
	cin>>a>>b>>c>>d>>e>>x>>y;
	double ans1=a*x+b*y;
	double ans2=c*y;
	double ans3=d*y+e;
	if(ans1>=max(ans2,ans3)) printf("1 %.2lf",ans1);
	if(ans2>max(ans1,ans3)) printf("2 %.2lf",ans2);
	if(ans3>max(ans2,ans1)) printf("3 %.2lf",ans3);
	return 0;
}

