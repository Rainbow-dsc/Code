#include <stdio.h>
const int _(100005);
int Root, t, n, opt, y, f[_], Child[_][2], v[_], c[_], s[_];
#define l(p) Child[p][0]
#define r(p) Child[p][1]
#define cp(z) Child[p][z]
#define cu(z) Child[u][z]
#define Sret(z) { Splay(u); return (z); }
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
	int u(f[p]), x(f[u]), q(ChildSide(p));
	cu(q) = cp(q ^ 1);
	f[f[f[cu(q)] = cp(q ^ 1) = u] = p] = x;
	if (x) Child[x][r(x) == u] = p;
	ChangeSize(u);
	ChangeSize(p);
}
inline void Splay(int p) {
	for (int q(p); q = f[p]; Rotate(p))
		if (f[q]) Rotate(p ^ r(f[p]) ^ q ^ r(f[q]) ? p : q);
	Root = p;
}
inline void Insert(int p) {
	if (!Root) {
		t = Root = 1;
		s[1] = c[1] = 1;
		v[1] = p;
		return;
	}
	int u(Root), x(0);
	while (true) {
		if (v[u] == p) {
			++c[u];
			++s[u];
			ChangeSize(x);
			Splay(u);
			return;
		}
		x = u;
		u = cu(v[u] < p);
		if (!u) {
			v[++t] = p;
			c[t] = s[t] = 1;
			f[t] = x;
			Child[x][v[x] < p] = t;
			ChangeSize(x);
			Splay(t);
			return;
		}
	}
}
inline int Rank(int p) {
	int u(Root), x(0), i(0);
	while (++i)
		if (p < v[u]) u = l(u);
		else {
			x += s[l(u)];
			if (i > 1000) Sret(x + 1);
			if (p == v[u]) Sret(x + 1);
			x += c[u];
			u = r(u);
		}
}
inline int Pth(int p) {
	int u(Root);
	while (true)
		if (l(u) && p <= s[l(u)]) u = l(u);
		else {
			p -= c[u] + s[l(u)];
			if (p < 1) Sret(v[u]);
			u = r(u);
		}
}
inline int PreSuc(bool p) {
	int u(p ? r(Root) : l(Root));
	while (p ? l(u) : r(u)) u = p ? l(u) : r(u);
	Sret(u);
}
inline void Delete(int p) {
	Rank(p);
	int u(Root), x;
	if (c[u] > 1) {
		--c[u];
		--s[u];
		return;
	}
	if (!l(u) && !r(u)) {
		Clear(u);
		Root = t = 0;
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
int main() {
	for (scanf("%d", &n); n; --n) {
		scanf("%d%d", &opt, &y);
		if (opt < 2) Insert(y);
		else if (opt < 3) Delete(y);
		else if (opt < 5) {
			printf("%d\n", opt < 4 ? Rank(y) : Pth(y));
		} else {
			Insert(y);
			printf("%d\n", v[PreSuc(opt - 5)]);
			Delete(y);
		}
	}
	return 0;
}
