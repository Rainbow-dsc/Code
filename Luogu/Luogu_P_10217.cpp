#include<bits/stdc++.h>
#define int long long
#define ld long double
#define _ (int)(1e6 + 4)
using namespace std;

const int inf = 1e18 + 4;
int T, n;
int K, X, Y, m;
int x[_], y[_];

void cal(int A, int B, int C, int D, int &u, int &d){
    if(B == D) {
        if(C - A < 0) u = -inf;
        return;
    }
    if(B - D > 0) u = min(u,(int)floor((ld)(C - A)/(B - D)));
    else d = max(d,(int)ceil((ld)(C - A)/(B - D)));
}
int solve(){
    m = inf;
    int sx(0),sy(0);
    for(int i(1); i <= n; i ++) sx+=x[i], sy+=y[i];
    int tmpx(-X),tmpy(-Y);
    if (!tmpx && !tmpy) return 0;
    for (int i(1); i <= n; i ++) {
        tmpx+=x[i], tmpy += y[i];
        int u=inf,d=0;
        cal(tmpx + tmpy, sx + sy, K*i, K*n, u, d);
        cal(tmpx - tmpy, sx - sy, K*i, K*n, u, d);
        cal(-tmpx + tmpy, -sx + sy, K*i, K*n, u, d);
        cal(-tmpx - tmpy, -sx - sy, K*i, K*n, u, d);
        if(u >= d) m = min(m, d*n + i);
    }
    return (m == inf ? -1 : m);
}
signed main(){
    cin >> T;
    while(T --){
        cin >> n >> K >> X >> Y;
        for(int i(1); i <= n; i ++)  cin >> x[i] >> y[i];
        cout << solve() << "\n";
  }
  return 0;
}