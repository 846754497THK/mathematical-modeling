#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const long long mod=100000007;
const double e=2.718281828459045;
const double pi=3.1415926535;
#define CK cout<<"OK\n";
double q[11];
double sum[11];
int main(){
	freopen("t5_2_in.txt","r",stdin);
	freopen("t5_2_out.txt","w",stdout);
	double a[11][5];
	for(int i=1;i<=10;i++)scanf("%lf",&q[i]);
	for(int i=1;i<=10;i++){
		for(int j=1;j<=4;j++)scanf("%lf",&a[i][j]);
	}
	for(int j=1;j<=4;j++){
		for(int i=1;i<=10;i++){
			sum[j]+=q[i]*a[i][j];
		}
		printf("第 %d 个工位剩余时间： %.4lf\n",j,96000-sum[j]);
	}
	return 0;
}
