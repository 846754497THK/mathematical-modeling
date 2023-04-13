#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const long long mod=100000007;
const double e=2.718281828459045;
const double pi=3.1415926535;
#define CK cout<<"OK\n";
double sum[10];		//该种疫苗所需时间 
double total;		// 总时间 
double t[10][4];
double quan[10];

void init(){
	memset(sum,0,sizeof(sum));
	memset(t,0,sizeof(t));
	memset(quan,0,sizeof(quan));
	total=0;
	
}

int main(){
	init();	
	freopen("t4_in.txt","r",stdin);
	freopen("t4_out2.txt","w",stdout);
	for(int i=0;i<10;i++)scanf("%lf",&quan[i]);
	for(int i=0;i<10;i++){
		for(int j=0;j<4;j++)scanf("%lf",&t[i][j]);
		sum[i]=max(
			max(
				t[i][3]+t[i][2]+t[i][1]+quan[i]*t[i][0],
				t[i][3]+t[i][2]+quan[i]*t[i][1]+t[i][0]
			),
			max(
				t[i][3]+quan[i]*t[i][2]+t[i][1]+t[i][0],
				quan[i]*t[i][3]+t[i][2]+t[i][1]+t[i][0]
			)
		);
		total+=sum[i];
		printf("%.4lf\n",sum[i]);
	}
	printf("共 %.4lf  分钟\n",total);
	return 0;
}
