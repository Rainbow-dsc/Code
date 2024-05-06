#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#define MXN 50007
using namespace std;
std::vector<int> v[MXN];
std::vector<int> w[MXN];

int fa[MXN][31], cost[MXN][31], dep[MXN];
int n, m;
int a, b, c;

// dfs������Ϊ lca �㷨��׼������������������dfs ��ʼ�ڵ�����ĸ��׽ڵ㡣
void dfs(int root, int fno) {
	// ��ʼ������ 2^0 = 1 �����Ⱦ������ĸ��׽ڵ㣬dep Ҳ�ȸ��׽ڵ�� 1��
	fa[root][0] = fno;
	dep[root] = dep[fa[root][0]] + 1;
	// ��ʼ�������������Ƚڵ㣺�� 2^i �����Ƚڵ��ǵ� 2^(i-1) �����Ƚڵ�ĵ�
	// 2^(i-1) �����Ƚڵ㡣
	for (int i = 1; i < 31; ++i) {
		fa[root][i] = fa[fa[root][i - 1]][i - 1];
		cost[root][i] = cost[fa[root][i - 1]][i - 1] + cost[root][i - 1];
	}
	// �����ӽڵ������� dfs��
	int sz = v[root].size();
	for (int i = 0; i < sz; ++i) {
		if (v[root][i] == fno) continue;
		cost[v[root][i]][0] = w[root][i];
		dfs(v[root][i], root);
	}
}

// lca���ñ����㷨��ȡ x �� y �� lca �ڵ㡣
int lca(int x, int y) {
	// �� y �� x �
	if (dep[x] > dep[y]) swap(x, y);
	// �� y �� x ��һ����ȡ�
	int tmp = dep[y] - dep[x], ans = 0;
	for (int j = 0; tmp; ++j, tmp >>= 1)
		if (tmp & 1) ans += cost[y][j], y = fa[y][j];
	// ������ʱ�� y = x����ô x��y �Ͷ��������Լ������ȡ�
	if (y == x) return ans;
	// ��Ȼ�Ļ����ҵ���һ�������������ȵ������㡣
	for (int j = 30; j >= 0 && y != x; --j) {
		if (fa[x][j] != fa[y][j]) {
			ans += cost[x][j] + cost[y][j];
			x = fa[x][j];
			y = fa[y][j];
		}
	}
	// ���ؽ����
	ans += cost[x][0] + cost[y][0];
	return ans;
}

int main() {
	// ��ʼ����ʾ���ȵ����� fa������ cost ����� dep��
	memset(fa, 0, sizeof(fa));
	memset(cost, 0, sizeof(cost));
	memset(dep, 0, sizeof(dep));
	// ���������ڵ���һ���� n ����
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		scanf("%d %d %d", &a, &b, &c);
		++a, ++b;
		v[a].push_back(b);
		v[b].push_back(a);
		w[a].push_back(c);
		w[b].push_back(c);
	}
	// Ϊ�˼��� lca ��ʹ�� dfs��
	dfs(1, 0);
	// ��ѯ m �Σ�ÿһ�β��������ڵ�� lca �㡣
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d %d", &a, &b);
		++a, ++b;
		printf("%d\n", lca(a, b));
	}
	return 0;
}

