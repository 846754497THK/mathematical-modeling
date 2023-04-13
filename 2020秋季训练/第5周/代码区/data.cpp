#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
double heat[5000],oil[5000];
const double e=2.718281828;
const double pi=3.1415926535;
double exp(double k){
	return pow(e,k);
}
vector<double>X;
void Nor(double p=0,double d=1,int N=100){
	default_random_engine E;
	int cnt=0;
	double y_lim1,y_lim2;
	double x_lim=3*d;
	y_lim1=(1/(d * (sqrt(2*pi)) ));
	y_lim2=(1/(d * (sqrt(2*pi)) )) * exp(-(x_lim*x_lim) / (2*d*d));
	//在3d外分类随机，提高效率 
	while(cnt<N){
		uniform_int_distribution<unsigned>x_k(0,100);
		if( x_k(E) <99){
			uniform_real_distribution<double>xx(p-x_lim,p+x_lim);
			double x=xx(E);
			double y_up=(1/(d * (sqrt(2*pi)) )) * exp(-( (x-p) * (x-p) ) / (2*d*d));
			uniform_real_distribution<double>y(0,y_lim1);
			if(y(E)<=y_up){
				X.push_back(x);
				cnt++;
			}
		}else{
			uniform_real_distribution<double>xx(p-100*d,p+100*d);
			double x=xx(E);
			double y_up=(1/(d * (sqrt(2*pi)) )) * exp(-( (x-p) * (x-p) ) / (2*d*d));
			uniform_real_distribution<double>y(0,y_lim2);
			if(y(E)<=y_up){
				X.push_back(x);
				cnt++;
			}
		}
	}
}

int main(){
	X.clear();
	Nor(0,1e-5,100);
	
	freopen("input1.txt","r",stdin);
	freopen("output1.txt","w",stdout);
	double sum1=0,sum2=0;
	for(int i=1980;i<=2019;i++){
		scanf("%lf",&heat[i]);
	}
	double k;
	for(int i=1980;i<=1992;i++){
		k=-(5e-6)*(i-1993)+(2e-3)+X[i-1980];
		printf("%.2lf\n",heat[i]/k,k);
		
	}
	
	
	return 0;
} 
