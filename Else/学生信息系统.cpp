#include<bits/stdc++.h>
using namespace std;
struct ren {
	string xm,dh,em,cs,jd,mph;
}a[1000001];
int main() {
	string tmp;
	int n,m;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].xm>>a[i].dh>>a[i].em>>a[i].cs>>a[i].jd>>a[i].mph;
	cin>>m;
	for(int k=1; k<=m; k++) {
		cin>>tmp;
		bool b=true;
		for(int i=1; i<=n; i++)
			if(a[i].xm==tmp) {
				cout<<a[i].xm<<" "<<a[i].dh<<" "<<a[i].em<<" "<<a[i].cs<<" "<<a[i].jd<<" "<<a[i].mph<<endl;
				b=false;
				break;
			}
		if(b) cout<<"not found"<<endl;;
	}
	return 0;
}
