#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,s;
int a[1005][1005];
signed main(){
    scanf("%lld%lld",&n,&m);
    scanf("%lld",&s);
    memset(a,0,sizeof(a));
    for(int i=1;i<=s;i++){
    	string p,c,z,q,d,w;
    	int shu,rp;
    	cin>>p>>c;
    	int hp=p[0]-'A'+1;
    	int lenp=p.size();
    	if(lenp==2) rp=p[1]-'0';
    	else rp=(p[1]-'0')*10+(p[2]-'0');
    	if(c[0]=='i'){
    		scanf("%lld",&shu);
    		a[hp][rp]=shu;
		}
    	if(c[0]=='a') {
    		cin>>z>>q;
    		int rz,rq;
    		int hz=z[0]-'A'+1;
    		int lenz=z.size();
    		if(lenz==2) rz=z[1]-'0';
    		else rz=(z[1]-'0')*10+(z[2]-'0');
    		int hq=q[0]-'A'+1;
    		int lenq=q.size();
    		if(lenq==2) rq=q[1]-'0';
			else rq=(q[1]-'0')*10+(q[2]-'0'); 
			int sum=0,g=0;
			for(int i=rz;i<=rq;i++)
				for(int j=hz;j<=hq;j++)
					sum+=a[i][j];
			a[hp][rp]=sum/(rq-rz+1)*(hq-hz+1);
		}
		if(c[0]=='s') {
			int rd,rw,sum=0;
    		cin>>d>>w;
    		int hd=d[0]-'A'+1;
    		int lend=d.size();
    		if(lend==2) rd=d[1]-'0';
    		else rd=(d[1]-'0')*10+(d[2]-'0');
    		int hw=w[0]-'A'+1;
    		int lenw=w.size();
    		if(lenw==2) rw=w[1]-'0';
			else rw=(w[1]-'0')*10+(w[2]-'0'); 
			for(int i=rd;i<=rw;i++)
				for(int j=hd;j<=hw;j++)
					sum+=a[i][j];
			a[hp][rp]=sum;
		}
		if(c[0]=='o') printf("%lld\n",a[hp][rp]);
	}
    return 0;
}
