#include<bits/stdc++.h>
using namespace std;
/**
 * %4==0 ������
 * %4==1��3 ��Ҫ��%4==0 ���
 * %4==2 ������ˣ��������,��ǰ��һ����һ��λ����Ҫ�����������
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
