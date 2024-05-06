#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define int long long
struct Node{
    int c,s;
}node,top;
bool operator <(Node a,Node b){return a.c<b.c;}
int n,ans;
priority_queue<Node> q;
signed main(){
    scanf("%lld",&n);
    for(int i=0;i<n;i++){
        scanf("%lld%lld",&node.c,&node.s);
        q.push(node);
    }
    while(!q.empty()){
        bool f=0;
        top=q.top();
        q.pop();
        while(!q.empty()&&q.top().c==top.c){
            node=q.top();
            q.pop();
            top.s+=node.s;
        }
        // cout<<top.c<<" "<<top.s<<endl;
        while(top.c%2==0){
            f=1;
            top.c>>=1;
            top.s<<=1;
        }
        if(!f){
            while(top.s){
                if(top.s%2) ans++;
                top.s>>=1;
            }
        }
        else q.push(top);
    }
    printf("%lld\n",ans);
    return 0;
}
