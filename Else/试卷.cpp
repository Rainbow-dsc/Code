#include<bits/stdc++.h>
using namespace std;
struct aa{
	string s;
	int f;
}a[10];
int zf;
int sumc,summ,sume,sums;
int main() {
	cin>>zf;
	for(int i=1;i<=3;i++){
		cin>>a[i].s>>a[i].f;
		if(a[i].s[0]=='C') sumc++;
		if(a[i].s[0]=='M') summ++;
		if(a[i].s[0]=='E') sume++;
		if(a[i].s[0]=='S') sums++;
	}
	int p=zf-a[1].f-a[2].f-a[3].f;
	if(sumc==0) cout<<"Chinese"<<" "<<p;
	if(summ==0) cout<<"Math"<<" "<<p;
	if(sume==0) cout<<"English"<<" "<<p;
	if(sums==0) cout<<"Science"<<" "<<p;
    return 0;
}
