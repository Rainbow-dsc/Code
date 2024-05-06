#include <bits/stdc++.h>
using namespace std;
long long n,k;
double a[1000001],b[1000001];
int main(){
    cin>>n>>k;
    long long p=0,q=0;
    for(long long i=1;i<=n;i++){
    	if(i%k==0) {
    		p++;
			a[p]=i;
		}
		else {
			q++;
			b[q]=i;
		}
	}
//	for(int i=1;i<=p;i++) cout<<a[i]<<" ";
//	cout<<endl;
//	for(int i=1;i<=q;i++) cout<<b[i]<<" ";
//	cout<<endl;
	double sum1=0;
	double sum2=0;
	for(long long i=1;i<=p;i++) sum1+=a[i];
	for(long long i=1;i<=q;i++) sum2+=b[i];
	printf("%.1lf %.1lf",sum1/p,sum2/q);
    return 0;
}
