#include<bits/stdc++.h>
using namespace std;
int n,m,s;
struct node {
	int a,b,x1,y1,x2,y2;
	node() {
		a=1;
		b=0;
	}
} a[101][27];
char c1[10],c2[10],c3[10],c4[10];
int turn(char *c) {
	int l=strlen(c);
	int t=0;
	for (int i=1; i<l; i++)
		t=t*10+c[i]-48;
	return t;
}
int js(int x, int y) {
	if (a[x][y].a==1) return a[x][y].b;
	int sum=0;
	for (int i=a[x][y].x1; i<=a[x][y].x2; i++)
		for (int j=a[x][y].y1; j<=a[x][y].y2; j++)
			sum+=js(i,j);
	if (a[x][y].a==2) return sum;
	return sum/((a[x][y].x2-a[x][y].x1+1)*(a[x][y].y2-a[x][y].y1+1));
}
int main() {
	scanf("%d%d%d",&m,&n,&s);
	for (int i=1; i<=s; i++) {
		scanf("%s%s",c1,c2);
		int x=turn(c1),y=c1[0]-64;
		if (c2[0]=='o') {
			printf("%d\n",js(x,y));
			continue;
		}
		if (c2[0]=='i') {
			int k;
			scanf("%d",&k);
			a[x][y].a=1;
			a[x][y].b=k;
			continue;
		}
		scanf("%s%s",c3,c4);
		a[x][y].x1=turn(c3);
		a[x][y].x2=turn(c4);
		a[x][y].y1=c3[0]-64;
		a[x][y].y2=c4[0]-64;
		if (c2[0]=='s') a[x][y].a=2;
		else a[x][y].a=3;
	}
	return 0;
}
