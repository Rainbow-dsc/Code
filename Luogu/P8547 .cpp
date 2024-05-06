#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[] = {11, 23, 35, 47, 59, 70, 82, 94, 106, 118, 141, 153, 165, 177, 200, 212, 224, 236, 271, 283, 295, 330, 342, 354, 401, 413, 460, 472, 531, 611, 694};
int t, d, ans;
const int day = 31;
int main() {
	cin >> d;
	while (d--) {
		cin >> t;
		if (t < 34) {
			cout << "0\n";
			continue;
		} else if (t <= 60) {
			cout << "1\n";
			continue;
		}
		if (t <= 60 && t >= 34) {
			cout << "1\n";
			continue;
		}
		ans = 1;
		t -= 60;
		ans += t /720 * day;
		t %= 720;
		for (int i = 0; i < 31; i++) {
			if (a[i] <= t) ans++;
			else break;
		}
		cout << ans << "\n";
	}
	return 0;
}
