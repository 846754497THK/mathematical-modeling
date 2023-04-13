#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
double E[200050];
int cnt[200050];
double N,n,r;
const int repN=100;
double testN,testr;
void init(){
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
const int TOTturn=5;
int main(){
	freopen("需要测试的N和r.txt","r",stdin);
	freopen("不同N和r的测试结果.txt","w",stdout);
	default_random_engine DRE;
	init();
	int num;
	scanf("%d",&num);
for(int i=0;i<num;i++){
	scanf("%lf%lf",&testN,&testr);
	
	N=testN;
	r=testr;
	n=N*r;
	
	printf("N=%.0lf\nr=%.5lf\n",N,r);
	for(int i=1;i<=TOTturn;i++){
		int mina;
		double minE=1e6;
		init();
		for(int a=N/50;a<=N/3;a++){			//改这里可以加速 
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
		//	printf("a= %d   E= %.4lf\n",a,E[a]);
			if(E[a]<minE){
				minE=E[a];
				mina=a;
			}
		}
		printf("%d\t\t%.4lf\n",mina,minE);
	}
	
}
	return 0;
} 
