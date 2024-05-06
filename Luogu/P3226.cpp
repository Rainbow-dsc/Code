#include<bits/stdc++.h>
using namespace std;
long long n,m;
int main() {
	cin>>n>>m;
	long long q=0,a=1,jc=1;
	for(long long i=1;i<=n;i++){
		a=i%m*a%m;
		q=q%m+a%m;
		cout<<q%m<<"  "<<jc<<endl;
		jc++;
	}
    return 0;
}
