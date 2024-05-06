#include<bits/stdc++.h>
using namespace std;
int n,k=1;
int main(){
	cin>>n;
	int sum=n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=sum;j++){
			if(k<10){
				printf("%d",0);
				printf("%d",k);
			}
			else printf("%d",k);
			k++;
		}
		cout<<endl;
		sum--;
	}
	return 0;
}
