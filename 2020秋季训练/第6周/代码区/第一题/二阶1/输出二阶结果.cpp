#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
double E[40500];
int cnt[20050];
double N,n,r;
int repN;
void init(){
	N=40000;
	r=0.1;
	repN=100;
	n=N*r;
	memset(E,0,sizeof(E));
}
double qsm(double x,ll ex){
	double ans=1;
	double tmp=x;
	while(ex){
		if(ex&1)ans*=tmp;
		tmp*=tmp;
		ex>>=1;
	}
	return ans;
}
double comb(int A,int B){
	double ans=1;
	for(int i=1;i<=A;i++){
		ans=ans*(B-i+1)/i;
	}
	return ans;
}
int main(){
	init();
	freopen("output1.txt","w",stdout);
	default_random_engine DRE;
	int mina;
	double minE=1e6;
	for(int a=6000;a<20000;a++){
		double p=N/a;
		uniform_int_distribution<unsigned>choose(0,a);
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
		}
		printf("a= %d   E= %.4lf\n",a,E[a]);
		if(E[a]<minE){
			minE=E[a];
			mina=a;
		}
	}
	printf("%d\t\t%.4lf\n",mina,minE);
	return 0;
} 
