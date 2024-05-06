#include<bits/stdc++.h>
using namespace std;
/**
 * %4==0 整除，
 * %4==1或3 需要和%4==0 配对
 * %4==2 两个相乘，可以配对,但前后一定有一个位置需要和其他数相乘
 **/
int T, n, a, cnt[4];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--) {
        cnt[0] = cnt[1] = cnt[2] = cnt[3] = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a;
            cnt[a % 4]++;
        }
        if (cnt[1] + cnt[3] + (cnt[2] > 0) <= cnt[0] + 1)
            cout << "Yes" << '\n';
        else
            cout << "No" << '\n';
    }
    return 0;
}
