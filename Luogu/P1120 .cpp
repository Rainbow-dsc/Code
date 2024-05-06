#include <bits/stdc++.h>
using namespace std;
const int N = 11000000;
int a[N];
bool used[N];
int len;// Ŀ�곤��
int n;// Сľ������
// cnt: ��ʣcnt��ԭľ����ƴ
// cur: ��ǰƴ���ĳ���
// ׼�������õ�i��Сľ��
bool dfs(int cnt, int cur, int i) {// cnt: ��ʣcnt��ԭľ����ƴ;cur: ��ǰƴ���ĳ���;׼�������õ�i��Сľ��
    if (!cnt) return true;
    // �Ѿ�ƴ��һ��ԭľ�����ӵ�1��Сľ�����¿�ʼƴ��һ��ԭľ��
    if (cur == len) return dfs(cnt - 1, 0, 1);
    // ��¼��һ�γ��Դ���ĳ��ȣ������ظ��ȿ�
    int failed = 0;
    for (register int j = i; j <= n; j++) {
        if (used[j] || a[j] == failed || cur + a[j] > len) continue;
        used[j] = true;
        if (dfs(cnt, cur + a[j], j + 1)) return true;
        used[j] = false;
        failed = a[j];
        // ��֦  52  511
        // �����ǰ�Ǵ�0��ʼƴ���߸պ�ƴ��һ��ԭľ��������Ȼû������ƴ�ɹ�
        // ��֮������ֻ����ǰʹ�ø��̵�ľ����ƴ����ǰ���Сľ��Ҫ�ŵ�������ʹ�ã��������ܳɹ�
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
    // (sum / 2, sum]֮�䲻��Ҫ����
    for ( len=a[1];len<=sum/2;len++) {
        // ���ܴ���
        if (sum%len) continue;
        memset(used, 0, sizeof(used));
        // ��Ҫƴ��cnt��ԭľ��
        if (dfs(sum / len, 0, 1)) {
            printf("%d", len);
            return 0;
        }
    }
    // һ��ԭľ��
    printf("%d", sum);
    return 0;
}
