#include<bits/stdc++.h>
#define int long long
#define maxn 1005
using namespace std;
int T;
struct aa{
	int x,y,z;
}a[maxn];
bool vis[maxn];
int n,h,r;
bool flag=false;
double dis(aa cr,int i){
    double dis;
    dis=sqrt((cr.x-a[i].x)*(cr.x-a[i].x)+(cr.y-a[i].y)*(cr.y-a[i].y)+(cr.z-a[i].z)*(cr.z-a[i].z));
    return dis;
}
queue <aa> Q;
void bfs() {
	memset(vis,false,sizeof(vis));
	flag=false;	
	while(!Q.empty()){
		aa pc=Q.front();
		Q.pop();
		if(pc.z+r>=h) {
			cout<<"Yes"<<endl;
			flag=true;
			break;
		}
		for(int i=1;i<=n;i++) {
			if(!vis[i]) {
				if(dis(pc,i)<=2*r) {
					vis[i]=1;
					Q.push(a[i]);
				}
			}
		}
	}
}
signed main(){
	scanf("%lld",&T);
	while(T--) {
		while(!Q.empty()) Q.pop();
		scanf("%lld %lld %lld",&n,&h,&r);
		for(int i=1;i<=n;i++) {
			scanf("%lld %lld %lld",&a[i].x,&a[i].y,&a[i].z);
			if(abs(a[i].z)<=r) Q.push(a[i]);
		}
		bfs();
		if(!flag) cout<<"No"<<endl;
	}
	return 0;
}

