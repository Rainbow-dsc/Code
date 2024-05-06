#include <bits/stdc++.h>
using namespace std;
const int N = 11000000;
int a[N];
bool used[N];
int len;// 目标长度
int n;// 小木棍数量
// cnt: 还剩cnt根原木棍待拼
// cur: 当前拼出的长度
// 准备尝试用第i个小木棍
bool dfs(int cnt, int cur, int i) {// cnt: 还剩cnt根原木棍待拼;cur: 当前拼出的长度;准备尝试用第i个小木棍
    if (!cnt) return true;
    // 已经拼好一根原木棍，从第1个小木棍重新开始拼下一根原木棍
    if (cur == len) return dfs(cnt - 1, 0, 1);
    // 记录上一次尝试错误的长度，避免重复踩坑
    int failed = 0;
    for (register int j = i; j <= n; j++) {
        if (used[j] || a[j] == failed || cur + a[j] > len) continue;
        used[j] = true;
        if (dfs(cnt, cur + a[j], j + 1)) return true;
        used[j] = false;
        failed = a[j];
        // 剪枝  52  511
        // 如果当前是从0开始拼或者刚好拼成一根原木棍，但仍然没有最终拼成功
        // 那之后这里只能提前使用更短的木棍来拼，当前这根小木棍要放到更后面使用，更不可能成功
        if (!cur || cur + a[j] == len) return false;
    }
    return false;
}
int main() {
    int sum=0;
    scanf("%d",&n);
    for (register int i=1; i<=n; i++) {
        scanf("%d",a+i);
        sum += a[i];
    }
    sort(a+1,a+n+1,greater<int>());
    // (sum / 2, sum]之间不需要尝试
    for ( len=a[1];len<=sum/2;len++) {
        // 不能凑整
        if (sum%len) continue;
        memset(used, 0, sizeof(used));
        // 需要拼出cnt根原木棒
        if (dfs(sum / len, 0, 1)) {
            printf("%d", len);
            return 0;
        }
    }
    // 一根原木棍
    printf("%d", sum);
    return 0;
}
