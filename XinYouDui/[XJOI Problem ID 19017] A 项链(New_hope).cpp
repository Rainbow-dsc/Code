#include<bits/stdc++.h>
#define int long long
#define _ (int)(5e5 + 4)
using namespace std;

int res,del[_];
struct v {
    int val,pre,ne;
} a[_];
struct p {
    int u,v,sum;
    bool operator < (const p &a)const {
        return sum < a.sum;
    }
};
priority_queue<p> q;
signed main() {
//    freopen("necklace.in","r",stdin);
//    freopen("necklace.out","w",stdout);
	int tid,n,m;
    scanf("%lld %lld %lld",&tid,&n,&m);
	m=n-m;
    for(int i = 1; i <= n; i ++) {
        int p; scanf("%lld",&p);
        a[i] = {p,i - 1,i + 1};
        if(i == 1) a[i].pre = n;
        if(i == n) a[i].ne = 1;
    }
    for(int i = 1; i <= n; i ++) {
        if(i == n) q.push({n,1,a[n].val + a[1].val});
        else q.push({i,i + 1,a[i].val + a[i + 1].val});
    }
    for(int i = 1; i <= m; i++) {
        p fr = q.top(); q.pop();
        if(del[fr.u] || del[fr.v]) {
        	i--;
        	continue;
		}    
		if(a[fr.u].val > a[fr.v].val) {
            a[a[fr.u].pre].ne = fr.v;
            a[fr.v].pre = a[fr.u].pre;
            a[fr.u].pre = a[fr.u].ne = 0; del[fr.u] = 1;
            q.push({a[fr.v].pre,fr.v,a[a[fr.v].pre].val + a[fr.v].val});
        }
        else {
            a[a[fr.v].ne].pre = fr.u;
            a[fr.u].ne = a[fr.v].ne;
            a[fr.v].pre = a[fr.v].ne = 0; del[fr.v] = 1;
            q.push({fr.u,a[fr.u].ne,a[fr.u].val + a[a[fr.u].ne].val});
        } 
    }
    while(del[q.top().u] || del[q.top().v]) q.pop();
    printf("%lld",q.top().sum);
    return 0;
}
