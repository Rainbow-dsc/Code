#include<bits/stdc++.h>
using namespace std;
int n,ans=INT_MAX;
char a[20][20],b[20][20],e[20];
int sx1[17],sy1[17],sx2[17],sy2[17];
int c[17];
int used1[17][17],used2[17][17];
int d(char x) {
	if(x>='0'&&x<='9') {
		return x-'0';
	} else {
		return x-'A'+10;
	}
}
bool f(int c,int x1,int y1) {
	for(int i=1; i<=n*n; i++) {
		for(int j=1; j<=n*n; j++) {
			b[i][j]=a[i][j];
		}
	}
	while(c--) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				a[x1+i-1][y1+j-1]=b[x1+n-j][i-1+y1];
			}
		}
		if(c!=0) {
			for(int i=1; i<=n*n; i++) {
				for(int j=1; j<=n*n; j++) {
					b[i][j]=a[i][j];
				}
			}
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(used1[x1+i-1][d(a[x1+i-1][y1+j-1])]) {
				return 0;
			} else {
				used1[x1+i-1][d(a[x1+i-1][y1+j-1])]=1;
			}
			if(used2[y1+j-1][d(a[x1+i-1][y1+j-1])]) {
				return 0;
			} else {
				used2[y1+j-1][d(a[x1+i-1][y1+j-1])]=1;
			}
		}
	}
	return 1;
}
bool check() {
	bool used[17];
	for(int i=1; i<=n*n; i++) {
		memset(used,0,sizeof(used));
		for(int j=1; j<=n*n; j++) {
			if(0<=d(a[i][j])<n*n) {
				if(used[d(a[i][j])]) {
					return 0;
				}
				used[d(a[i][j])]=1;
			} else {
				puts("-1");
				exit(0);
			}
		}
	}
	for(int j=1; j<=n*n; j++) {
		memset(used,0,sizeof(used));
		for(int i=1; i<=n*n; i++) {
			if(0<=d(a[i][j])<n*n) {
				if(used[d(a[i][j])]) {
					return 0;
				}
				used[d(a[i][j])]=1;
			} else {
				puts("-1");
				exit(0);
			}
		}
	}
	return 1;
}
void dfs(int nx) {
	if(nx==n*n+1) {
		if(check()) {
			int cnt=0;
			for(int i=1; i<=n*n; i++) {
				cnt+=c[i];
			}
			if(ans>cnt) {
				ans=cnt;
				for(int i=1; i<=nx; i++) {
					e[i]=c[i];
				}
			}
		}
		return ;
	}
	for(int i=0; i<=3; i++) {
		char y[20][20];
		for(int j=1; j<=n*n; j++) {
			for(int k=1; k<=n*n; k++) {
				y[j][k]=a[j][k];
			}
		}
		bool flag=f((3-i+1)%4,sx1[nx],sy1[nx]);
		if(!flag) {
			int x1=sx1[nx],y1=sy1[nx];
			for(int j=1; j<=n; j++) {
				for(int k=1; k<=n; k++) {
					used1[x1+j-1][d(a[x1+j-1][y1+k-1])]=0;
					used2[y1+k-1][d(a[x1+j-1][y1+k-1])]=0;
					a[x1+j-1][y1+k-1]=y[x1+j-1][y1+k-1];
				}
			}
			continue;
		}
		c[nx]=i;
		dfs(nx+1);
		c[nx]=0;
		int x1=sx1[nx],y1=sy1[nx];
		for(int j=1; j<=n; j++) {
			for(int k=1; k<=n; k++) {
				used1[x1+j-1][d(a[x1+j-1][y1+k-1])]=0;
				used2[y1+k-1][d(a[x1+j-1][y1+k-1])]=0;
				a[x1+j-1][y1+k-1]=y[x1+j-1][y1+k-1];
			}
		}
	}
}
int main() {
	scanf("%d",&n);
	for(int i=1; i<=n*n; i++) {
		scanf("%s",a[i]+1);
	}
	for(int i=1; i<=n*n; i++) {
		sx1[i]=n*((i-1)/n)+1,sy1[i]=n*((i-1)%n)+1;
	}
	dfs(1);
	if(ans!=INT_MAX) {
		printf("%d\n",ans);
		for(int i=1; i<=n*n; i++) {
			while(e[i]--) {
				printf("%d %d\n",(i-1)/n+1,(i-1)%n+1);
			}
		}
		return 0;
	}
	puts("-1");
	return 0;
}
