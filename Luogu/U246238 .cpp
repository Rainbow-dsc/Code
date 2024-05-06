#include <bits/stdc++.h>
using namespace std;
long long d,t;
int main(){
	cin>>d;
    for(long long i=1;i<=d;i++){
    	cin>>t;
    	long long p=t%720;
    	if(p>=0&&p<=33) cout<<0<<endl;
    	if(p>=34&&p<=70) cout<<1<<endl;
    	if(p>=71&&p<=82) cout<<2<<endl;
    	if(p>=83&&p<=94) cout<<3<<endl;
    	if(p>=95&&p<=106) cout<<4<<endl;
    	if(p>=107&&p<=118) cout<<5<<endl;
    	if(p>=119&&p<=129) cout<<6<<endl;
    	if(p>=130&&p<=141) cout<<7<<endl;
    	if(p>=142&&p<=153) cout<<8<<endl;
    	if(p>=154&&p<=165) cout<<9<<endl;
    	if(p>=166&&p<=177) cout<<10<<endl;
    	if(p>=178&&p<=200) cout<<11<<endl;
    	if(p>=201&&p<=212) cout<<12<<endl;
    	if(p>=213&&p<=224) cout<<13<<endl;
    	if(p>=225&&p<=236) cout<<14<<endl;
    	if(p>=237&&p<=259) cout<<15<<endl;
    	if(p>=260&&p<=271) cout<<16<<endl;
    	if(p>=272&&p<=283) cout<<17<<endl;
    	if(p>=284&&p<=295) cout<<18<<endl;
    	if(p>=296&&p<=330) cout<<19<<endl;
    	if(p>=331&&p<=342) cout<<20<<endl;
    	if(p>=343&&p<=354) cout<<21<<endl;
    	if(p>=355&&p<=389) cout<<22<<endl;
    	if(p>=390&&p<=401) cout<<23<<endl;
    	if(p>=402&&p<=460) cout<<24<<endl;
    	if(p>=461&&p<=472) cout<<25<<endl;
    	if(p>=473&&p<=519) cout<<26<<endl;
    	if(p>=520&&p<=531) cout<<27<<endl;
    	if(p>=532&&p<=590) cout<<28<<endl;
    	if(p>=591&&p<=670) cout<<29<<endl;
    	if(p>=671&&p<=719) cout<<30<<endl;
	}
    return 0;
}
