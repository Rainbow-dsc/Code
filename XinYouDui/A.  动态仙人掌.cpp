#include<bits/stdc++.h>
using namespace std;
char s[200];
int tong[10];
vector <int> mp[200],nmp[200];
bool vis[200];
struct point {
	int x;
	string s;
};
int main() {
	int n;
	cin>>n;
	scanf("%s",s+1);
	for(int i=n; i>=0; --i) {
		for(int j=0; j<=9; ++j) {
			if(!tong[j]) nmp[i].push_back(j);
			if(tong[j]) mp[i].push_back(tong[j]);
		}
		tong[s[i]-'0']=i;
	}
	queue <point> q;
	point node;
	node.s="",node.x=0;
	q.push(node);
	while(!q.empty()) {
		node=q.front();
		q.pop();
		if(vis[node.x]) continue;
		vis[node.x]=1;
		for(int i=0; i<nmp[node.x].size(); ++i) {
			int to=nmp[node.x][i];
			cout<<node.s+char(to+'0');
			exit(0);
		}
		for(int i=0; i<mp[node.x].size(); ++i) {
			int to=mp[node.x][i];
			if(s[to]=='0'&&node.x==0) continue;
			point newnode;
			newnode.x=to;
			newnode.s=node.s+s[to];
			q.push(newnode);
		}
	}
	return 0;
}
