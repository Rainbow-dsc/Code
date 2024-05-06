#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int main() {
	cin>>n>>m>>k;
	for(int i=0;i<=n;i++) cout<<(i%m<k);
	return 0;
}

