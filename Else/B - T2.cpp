#include <iostream>
#include <iomanip>
#include <cstdio>
#include <stdio.h>
#include <string>
#include <cstring>
#include <istream>
#include <ostream>
#include <map>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <time.h>
#include <ctime>
#include <stdlib.h>
#include <cstdlib>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
//#define int long long
#define maxn 10005
using namespace std;
int T;
int a[maxn];
priority_queue <int> C;
signed main() {
	scanf("%d",&T);
	while(T--) {
		int m,n;
		scanf("%d %d",&m,&n);
		for(int i=1; i<=n; i++) {
			scanf("%d",&a[i]);
			C.push(a[i]);
		}
		for(int i=1; i<m; i++) {
			for(int j=1; j<=n; j++) a[j]=C.top(),C.pop();
			for(int j=1; j<=n; j++) {
				int x;
				scanf("%d",&x);
				for(int k=1; k<=n; k++) {
					if(C.size()>=n) {
						if(C.top()>a[k]+x) C.pop(),C.push(a[k]+x);
					}
					else C.push(a[k]+x);
				}
			}
		}
		for(int i=1; i<=n; i++) a[i]=C.top(),C.pop();
		for(int i=n; i>=1; i--) printf("%d ",a[i]);
		puts("");
	}
	return 0;
}
