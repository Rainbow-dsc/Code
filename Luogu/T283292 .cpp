#include<bits/stdc++.h>
typedef unsigned __int128 LLL;
LLL read() {
	LLL x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
void out(LLL x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) out(x / 10);
	putchar(x % 10 + '0');
}
LLL xxqz_sqrt(LLL n) {
	LLL left = 1, right = n;
	LLL mid;
l:
	if(right-left<=1)
		return left;
	mid = (left + right)/2;
	if(mid*mid > n) {
		right=mid;
		goto l;
	}
	if(mid*mid < n) {
		left=mid;
		goto l;
	}
	return mid;
}
int main() {
	LLL n;
	n=read();
	out(xxqz_sqrt(n));
	return 0;
}
