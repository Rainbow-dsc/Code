#include<bits/stdc++.h>
#define _ (int)(4e5 + 4)
#define ll long long
using namespace std;
struct p { int x, y; };
const ll inf = 1e18 + 4;
int n;
p a[_], tp[_];
inline ll pw(int x) { return (ll)x * x; }
inline ll dis(p i, p j) { return pw(i.x - j.x) + pw(i.y - j.y); }
ll Div(int l, int r) {
    if(l >= r) return inf;
    if(r - l == 1) return dis(a[l],a[r]); 
    int mid = (l + r) >> 1; 
    ll d1 = Div(l, mid), d2 = Div(mid, r), d3 = min(d1, d2);
    int c = 0;
    for(int i = l; i <= r; i ++) if(pw(a[i].x - a[mid].x) < d3) tp[++c] = a[i];
    sort(tp + 1, tp + 1 + c, [](p a, p b) { return a.y < b.y; });
    for(int i = 1; i <= c; i ++) for(int j = i+1; j <= c && pw(tp[i].y - tp[j].y) < d3; j ++) d3 = min(d3, dis(tp[i], tp[j]));
    return d3;
}
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d %d",&a[i].x, &a[i].y);
    sort(a + 1, a + 1 + n, [](p a, p b) { return a.x < b.x; });
    printf("%lld", Div(1, n));
    return 0;
}
