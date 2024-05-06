#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e2 + 7, M = 2e3 + 7;
long long dp[N][M], ans;
int n, m;
struct product {
    int w, h, a;
    bool operator<(const product &x) const { return a < x.a; }
} products[N];
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> products[i].w >> products[i].h >> products[i].a;
    sort(products + 1, products + n + 1); //按重要值排序
    memset(dp, 0xcf, sizeof dp);
    dp[0][0] = 0; // dp[i][j][k]考虑到第i个物品，选了j个，总价钱k; i滚动数组
    for (int i = 1; i <= n; i++)
        for (int j = i; j >= 1; j--)
            for (int k = m; k >= products[i].w; k--)
                dp[j][k] = max(dp[j][k], dp[j - 1][k - products[i].w] +* products[i].h * (j - 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            ans = max(ans, dp[i][j]);
    cout << ans;
    return 0;
}
