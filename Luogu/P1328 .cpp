#include<bits/stdc++.h>
#define int long long
#define maxn 205
using namespace std;
int win[5][5]= {{0,0,1,1,0},{1,0,0,1,0},{0,1,0,0,1},{0,0,1,0,1},{1,1,0,0,0}};
int n,na,nb,suma,sumb; 
int a[maxn],b[maxn];
signed main(){
	scanf("%lld%lld%lld",&n,&na,&nb);
	for(int i=0;i<na;i++) scanf("%lld",&a[i]);
	for(int i=0;i<nb;i++) scanf("%lld",&b[i]);
	for(int i=0;i<=n-1;i++) suma+=win[a[i%na]][b[i%nb]];
	for(int i=0;i<=n-1;i++) sumb+=win[b[i%nb]][a[i%na]];
	printf("%lld %lld",suma,sumb);
	return 0;
}
