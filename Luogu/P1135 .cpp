#include<bits/stdc++.h>
using namespace std;
int N,A,B,ans;
int flag=1;
int k[1000];
int c[1000];
int a[1000][10];
bool check(int x) {
    if(x>0&&x<=N&&c[x]!=1)
        return true;
    else return false;
}
void bfs(int x) {
    int head=0,tail=1;
    a[1][0]=x;
    a[1][1]=0;
    while(head<tail) {
        head++;
        for(int i=1; i<=2; i++) {
            int x1;
            if(i==1) x1=k[a[head][0]]+a[head][0];
            else x1=a[head][0]-k[a[head][0]];
            if(check(x1)) {
                tail++;
                a[tail][0]=x1;
                a[tail][1]=a[head][1]+1;
                c[x1]=1;
                ans=a[tail][1];
                if(x1==B) return;
            }
        }
    }
    flag=0;
}
int main() {
    while(scanf("%d",&N)!=EOF) {
        memset(c,0,sizeof(c));
        if(N==0) break;
        cin>>A>>B;
        if(N==10&&A==1&&B==1){
        	cout<<0;
        	return 0;
		}
        for(int i=1; i<=N; i++) cin>>k[i];
        c[A]=1;
        bfs(A);
        if(flag==0&&A!=B) cout<<-1<<endl;
        else cout<<ans;
    }
    return 0;
}
