#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxA=50050;
double E[maxA];
const double fake_nega=0.0887;
double fakepo[maxA];
double fakene[maxA];
double N,n,r,c,p;
const int repN=100;

int cnt[maxA];
int main(){
	N=40000;
	r=0.0025;
	
	n=N*r;
	default_random_engine DRE;
	memset(E,0,sizeof(E));
	memset(fakepo,0,sizeof(fakepo));
	memset(fakene,0,sizeof(fakene));
	freopen("灰色数据生成生成output.txt","w",stdout);
	
	for(int a=2;2*a<=N;a++){
		p=N/a;
		uniform_int_distribution<unsigned>choose(1,a);
		
		for(int i=0;i<repN;i++){
				double e=0;
				
				for(int i=1;i<=a;i++)cnt[i]=0;
				
				int tot=0;
				while(tot<n){
					int tmp=choose(DRE);
					if(cnt[tmp]<p){
						cnt[tmp]++;
						tot++;
					}
				}
				tot=0;
				for(int i=1;i<=a;i++)if(cnt[i])tot++;
				
				E[a]+=(double)(a+p*tot)/repN;
				fakepo[a]+=(double)(p*tot-n)/N/repN;
				fakene[a]+=(double)(p*tot)*fake_nega/N/repN;
			}
		printf("%d\n%.4lf\n%.10lf\n%.10lf\n\n",a,E[a],fakepo[a],fakene[a]);
	}
	return 0;
}
