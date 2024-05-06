#include <bits/stdc++.h>
#define maxn 1100006
#define l(p) Child[p][0]
#define r(p) Child[p][1]
#define cp(z) Child[p][z]
#define cu(z) Child[u][z]
#define Sret(z) { Splay(u); return (z); }
using namespace std;
int Root,t,n,m,o,l,y,z;
int f[maxn],Child[maxn][2],v[maxn],c[maxn],s[maxn];
inline void ChangeSize(int p) {
	s[p] = s[l(p)] + s[r(p)] + c[p];
}
inline bool ChildSide(int p) {
	return p == r(f[p]);
}
inline void Clear(int p) {
	l(p) = r(p) = f[p] = v[p] = c[p] = s[p] = 0;
}
inline void Rotate(int p) {
	int u = f[p], x = f[u], q = ChildSide(p);
	cu(q) = cp(q ^ 1);
	if (cp(q ^ 1)) f[cp(q ^ 1)] = u;
	cp(q ^ 1) = u;
	f[u] = p;
	f[p] = x;
	if (x) Child[x][u == r(x)] = p;
	ChangeSize(p);
	ChangeSize(u);
}
inline void Splay(int p) {
	for (int q = f[p]; q = f[p], q; Rotate(p))
		if (f[q]) Rotate(ChildSide(p) == ChildSide(q) ? q : p);
	Root = p;
}
inline void Insert(int p) {
	if (!Root) {
		v[++t] = p;
		++c[Root = t];
		++s[t];
		return;
	}
	int u = Root, x = 0;
	while (true) {
		if (v[u] == p) {
			++c[u];
			ChangeSize(u);
			ChangeSize(x);
			Splay(u);
			return;
		}
		x = u;
		u = cu(v[u] < p);
		if (!u) {
			v[++t] = p;
			++c[t];
			f[t] = x;
			Child[x][v[x] < p] = t;
			++s[t];
			ChangeSize(x);
			Splay(t);
			return;
		}
	}
}
inline int Rank(int p) {
	int u = Root, x = 0;
	while (true)
		if (p < v[u]) u = l(u);
		else {
			x += s[l(u)];
			if (p == v[u]) Sret(x + 1);
			x += c[u];
			u = r(u);
		}
}
inline int Pth(int p) {
	int u = Root;
	while (true)
		if (l(u) && p <= s[l(u)]) u = l(u);
		else {
			p -= c[u] + s[l(u)];
			if (p < 1) Sret(v[u]);
			u = r(u);
		}
}
inline int PreSuc(bool p) {
	int u = p ? r(Root) : l(Root);
	while (p ? l(u) : r(u)) u = p ? l(u) : r(u);
	Sret(u);
}
inline void Delete(int p) {
	Rank(p);
	int u = Root, x;
	if (c[u] > 1) {
		--c[u];
		--s[u];
		return;
	}
	if (!l(u) && !r(u)) {
		Clear(u);
		Root = 0;
		return;
	}
	if (!l(u)) {
		f[Root = r(u)] = 0;
		Clear(u);
		return;
	}
	if (!r(u)) {
		f[Root = l(u)] = 0;
		Clear(u);
		return;
	}
	f[r(u)] = x = PreSuc(false);
	r(x) = r(u);
	Clear(u);
}
inline int Read() {
	char c = getchar();
	int p = 0;
	while (c < '0' || c > '9') c = getchar();
	while (c > 47 && c < 58) p = (p << 3) + (p << 1) + c - 48, c = getchar();
	return p;
}
int main() {
	n = Read(), m = Read();
	for (int i = 1; i <= n; ++i) y = Read(), Insert(y);
	while (m--) {
		o = Read(), y = Read() ^ l;
		if (o < 2) Insert(y);
		else if (o < 3) Delete(y);
		else if (o < 4) {
			Insert(y);
			l = Rank(y);
			Delete(y);
		} else if (o < 5) l = Pth(y);
		else {
			Insert(y);
			l = v[PreSuc(o - 5)];
			Delete(y);
		}
		if (o > 2 && l) z ^= l;
	}
	printf("%d\n", z);
	return 0;
}
