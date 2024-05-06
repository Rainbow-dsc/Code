#include<bits/stdc++.h>
using namespace std;
int n;
string a,b,op,x;
deque<string>d;
map<string,bool>in;
int main(){
	scanf("%d",&n);
	while(n--){
		cin>>op;
		if(op[0]=='s'){
			if(a!="") d.push_back(a);
			if(b!="") d.push_back(b);
			if(d.empty()) printf("Error\n");
			else {
				a=b="";
				if(!d.empty()) a=d.front(),d.pop_front();
				if(!d.empty()) b=d.front(),d.pop_front();
				printf("%s %s\n",a.c_str(),b.c_str());
			}
		}
		else if(op[0]=='a') {
			cin>>x;
			if(!in[x]) {
				in[x]=1;
				d.push_back(x);
				printf("OK\n");
			}
			else printf("Error\n");
		}
		else {
			cin>>x;
			if(in[x]&&a!=x&&b!=x) {
				in[x]=0;
				d.erase(find(d.begin(),d.end(),x));
				printf("OK\n");
			}
			else printf("Error\n");
		}
	}
    return 0;
}
