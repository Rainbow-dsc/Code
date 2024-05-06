#include<bits/stdc++.h>
using namespace std;
string b="b",a;
int n;
int main() {
    cin>>n>>a;
    if(a=="b"&&n==1){
    	cout<<0<<endl;
    	return 0;
	}
	for(int i=1;i<=n;i++){
		int p=i%3;
		if(p==0) b='b'+b+'b';
		if(p==1) b='a'+b+'c';
		if(p==2) b='c'+b+'a';
		if(b==a){
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
    return 0;
}

