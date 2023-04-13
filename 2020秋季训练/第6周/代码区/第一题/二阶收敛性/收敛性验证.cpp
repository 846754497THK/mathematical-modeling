#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//取N=40000 n=40  a=1200进行验证 
double N,n,r;
int repN;
int cnt[20050];
const int NUM=10000;
double E[NUM+500];
double test[NUM+500];
void init(){
	N=40000;
	r=0.001;
	repN=NUM;
	n=N*r;
	memset(E,0,sizeof(E));
	E[0]=0;
}

int main(){
	init();
	freopen("收敛性验证.txt","w",stdout);
	default_random_engine DRE;
	int a=1200;
	uniform_int_distribution<unsigned>choose(0,a);
	double p=N/a;
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
			test[i]=(double)(a+p*tot);
			E[i+1]=(E[i]*i+test[i])/(i+1);
			printf("%.4lf\n",E[i+1]);
	}
	return 0;
}
