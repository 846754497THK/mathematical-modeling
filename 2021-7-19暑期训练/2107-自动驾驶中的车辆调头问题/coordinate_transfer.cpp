#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const long long mod=100000007;
const double e=2.718281828459045;
const double pi=3.1415926535;
#define CK cout<<"OK\n";
int main(){
	freopen("coordinate_transfer_in.txt","r",stdin);
	freopen("coordinate_transfer_out.txt","w",stdout);
	double x[100],y[100];
	double ax[100],ay[100];
	int n=0;
	double k=15.624/27.3244;
	double dx=2.998806,dy=0.220528;
	while(~scanf("%lf%lf",&x[n],&y[n])){
		x[n]-=dx;
		y[n]-=dy;
		n++;
	}
	for(int i=0;i<n;i++){
		double a=k*k+1;
		double b=-2*x[i]-2*k*y[i];
		double c=x[i]*x[i]+y[i]*y[i];
		double xi=-b/2/a;
		ax[i]=-sqrt(
			max(a*xi*xi+b*xi+c,0.0)
		)+15;
		
		a=1+1/k/k;
		b=2/k*y[i]-2*x[i];
		c=x[i]*x[i]+y[i]*y[i];
		xi=-b/2/a;
		ay[i]=sqrt(
			max(a*xi*xi+b*xi+c,0.0)
		);
	}
	for(int i=0;i<n;i++){
		printf("%.7lf\t%.7lf\n",ax[i],ay[i]);
	}
	return 0;
}
