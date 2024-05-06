#include <bits/stdc++.h>
#define int long long
#define maxn 100005
//#define mininf -1e18
//#define maxinf 1e18
const int maxinf = LONG_LONG_MAX, mininf = LONG_LONG_MIN;
#define lgn 25
using namespace std;
int n,m,q;
int amax[maxn][lgn],amin[maxn][lgn];//amax表示a数组区间最大值,amin表示a数组区间最小值
int afmx[maxn][lgn],azmn[maxn][lgn];//afmx表示a数组在负数中的最大值,azmn表示a数组在非负数中的最小值(因为有0)
int bmax[maxn][lgn],bmin[maxn][lgn];//bmax表示b数组区间最大值,bmin表示b数组区间最小值
int lg[maxn];
inline bool gmx(int &a, int b) {
	return b > a ? a = b, true : false;
}
signed main() {
	scanf("%lld%lld%lld",&n,&m,&q);

	for(int i=1; i<=n; ++i) {
		int x;
		scanf("%lld",&x);
//		amax[i][0]=amin[i][0]=x;
//        afmx[i][0]=(x<0?x:mininf);
//        azmn[i][0]=(x>=0?x:maxinf);
		amax[i][0]=x;
		amin[i][0]=x;
		if(x<0) afmx[i][0]=x;
		else afmx[i][0]=mininf;
		if(x>=0) azmn[i][0]=x;
		else azmn[i][0]=maxinf;
	}

	for(int i=1; i<=m; ++i) {
		int x;
		scanf("%lld",&x);
		bmax[i][0]=bmin[i][0]=x;
	}

	for(int i=2; i<=max(m,n); ++i) lg[i]=lg[i>>1]+1;

	for(int j=1; j<=lg[n]; ++j) {
		for(int i=1; i+(1<<j)-1<=n; ++i) {
			int pcr=i+(1<<(j-1));
			amax[i][j]=max(amax[i][j-1],amax[pcr][j-1]);
			afmx[i][j]=max(afmx[i][j-1],afmx[pcr][j-1]);
			amin[i][j]=min(amin[i][j-1],amin[pcr][j-1]);
			azmn[i][j]=min(azmn[i][j-1],azmn[pcr][j-1]);
		}
	}

	for(int j=1; j<=lg[m]; ++j) {
		for(int i=1; i+(1<<j)-1<=m; ++i) {
			int pcr=i+(1<<(j-1));
			bmax[i][j]=max(bmax[i][j-1],bmax[pcr][j-1]);
			bmin[i][j]=min(bmin[i][j-1],bmin[pcr][j-1]);
		}
	}

	while(q--) {
		int l1,r1,l2,r2;
		scanf("%lld%lld%lld%lld",&l1,&r1,&l2,&r2);

		int sa=lg[r1-l1+1];
		int sb=lg[r2-l2+1];

		int pcr1=r1-(1<<sa)+1;
		int pcr2=r2-(1<<sb)+1;
//		int sa = lg[r1 - l1 + 1], sb = lg[r2 - l2 + 1];
//        int pcr1 = r1 - (1 << sa) + 1, pcr2 = r2 - (1 << sb) + 1;

		int amaxn=max(amax[l1][sa],amax[pcr1][sa]);
		int aminn=min(amin[l1][sa],amin[pcr1][sa]);

		int afmax=max(afmx[l1][sa],afmx[pcr1][sa]);
		int azmin=min(azmn[l1][sa],azmn[pcr1][sa]);

		int bmaxn=max(bmax[l2][sb],bmax[pcr2][sb]);
		int bminn=min(bmin[l2][sb],bmin[pcr2][sb]);

		int ans=mininf;

		if(amaxn>=0) amaxn*=bminn;
		else amaxn*=bmaxn;
		ans=max(ans,amaxn);
		
		if(aminn>=0) aminn*=bminn;
		else aminn*=bmaxn;
		ans=max(ans,aminn);

//		gmx(ans,amaxn*(amaxn>=0?bminn:bmaxn));
//        gmx(ans,aminn*(aminn>=0?bminn:bmaxn));

		if(afmax!=mininf) {
			if(afmax>=0) afmax*=bminn;
			else afmax*=bmaxn;
			ans=max(ans,afmax);
		}
		
		if(azmin!=maxinf) {
			if(azmin>=0) azmin*=bminn;
			else azmin*=bmaxn;
			ans=max(ans,azmin);
		}

//       if (afmax!=mininf) gmx(ans,afmax*(afmax>=0?bminn:bmaxn));
//       if (azmin!=maxinf) gmx(ans,azmin*(azmin>=0?bminn:bmaxn));

		printf("%lld\n",ans);
	}
	return 0;
}

