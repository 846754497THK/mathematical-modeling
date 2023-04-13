#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const long long mod=100000007;
const double e=2.718281828459045;
const double pi=3.1415926535;
#define CK cout<<"OK\n";
int main(){

	freopen("pic_2_in.txt","r",stdin);
	freopen("pic_2_out.txt","w",stdout);
	int n=0;
	double x[1500],y[1500];
	while(~scanf("%lf%lf",&x[n],&y[n])){
		n++;
	}
	int m=n;	//已有数据个数 
	//x0 y0 表示圆心
	double r=4.974273; 
	double x0=1.31628+4.0097;
	double y0=6.30581-2.936216;
	double ix=x[n-1];
	while(ix<=1.31628+4.0097*2){
		ix=ix+0.01;
		x[n]=ix;
		y[n]=sqrt(r*r- (ix-x0)*(ix-x0) )+y0;
		n++;
	}
	while(m>0){
		m--;
		x[n]=x0*2-x[m];
		y[n]=y[m];
		n++;
	}
	for(int i=0;i<n;i++){
		printf("%.6lf\t%.6lf\n",x[i],y[i]);
	}
	return 0;
}
