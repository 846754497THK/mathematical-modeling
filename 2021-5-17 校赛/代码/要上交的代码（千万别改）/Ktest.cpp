#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const long long mod=1000000007;
const double e=2.718281828459045;
const double pi=3.1415926535;
#define CK cout<<"OK\n";
double a[1050];
int N;
double k[25];
int nk;
double kans[25][1050];
int main(){
	freopen("ktest.txt","r",stdin);
	freopen("ktest_answer.txt","w",stdout);
	N=1000;
	nk=20;
	double minsum=10;
	int mink=0;
	for(int i=0;i<N;i++){
		scanf("%lf",&a[i]);
	}
	for(int j=0;j<20;j++){
		double sum=0;
		scanf("%lf",&k[j]);
		for(int i=0;i<N;i++){
			scanf("%lf",&kans[j][i]);
			sum+=kans[j][i]/a[i];
		}
		sum/=1000;
		if(sum<minsum){
			minsum=sum;
			mink=j;
		}
		printf("K= %.2lf\t\tave=%.4lf\n",k[j],sum);
		
	}
	printf("\nmin: k=%.2lf\t\tave=%.4lf\n",k[mink],minsum);
	return 0;
} 
