/*
��� P3388 ��ģ�塿��㣨���
*/
#include <bits/stdc++.h>
using namespace std;
int n, m;  // n������ m������
int dfn[100001], low[100001], inde, res;
// dfn����¼ÿ�����ʱ���
// low���ܲ��������׵�����С�ı�ţ�inde��ʱ�����res��������
bool vis[100001], flag[100001];  // flag: �� vis������Ƿ��ظ�
vector<int> edge[100001];        // ��ͼ�õ�

void Tarjan(int u, int father) {  // u ��ǰ��ı�ţ�father �Լ��ְֵı��
	vis[u] = true;                  // ���
	low[u] = dfn[u] = ++inde;  // ����ʱ���
	int child = 0;             // ÿһ�����������
	for (auto v : edge[u]) {   // ���������������ھ� ��C++11��

		if (!vis[v]) {
			child++;                       // ����һ������
			Tarjan(v, u);                  // ����
			low[u] = min(low[u], low[v]);  // �����ܵ�����С�ڵ���
			if (father != u && low[v] >= dfn[u] && !flag[u])  // ��Ҫ����
				// ��������Լ����Ҳ�ͨ�����׷��ص���С����ϸ���Ҫ�󣬲���û�б���ǹ�
				// Ҫ��Ϊ��ɾ�˸���������ȥ�ˣ���Ϊ�����������
			{
				flag[u] = true;
				res++;  // ��¼��
			}
		} else if (v != father) low[u] = min(low[u], dfn[v]);  // �������㲻���Լ��������ܵ�����С�ڵ���
	}
	if (father == u && child >= 2 && !flag[u]) {  // ��Ҫ���룬�Լ��Ļ���Ҫ 2 �����Ӳſ���
		flag[u] = true;
		res++;  // ��¼��
	}
}

int main() {
	cin >> n >> m;                  // ��������
	for (int i = 1; i <= m; i++) {  // ע����Ǵ� 1 ��ʼ��
		int x, y;
		cin >> x >> y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}                             // ʹ�� vector ��ͼ
	for (int i = 1; i <= n; i++)  // ��Ϊ Tarjan ͼ��һ����ͨ
		if (!vis[i]) {
			inde = 0;      // ʱ�����ʼΪ 0
			Tarjan(i, i);  // �ӵ� i ���㿪ʼ������Ϊ�Լ�
		}
	cout << res << endl;
	for (int i = 1; i <= n; i++) if (flag[i]) cout << i << " ";  // ������
	return 0;
}

