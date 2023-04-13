#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const long long mod=100000007;
const double e=2.718281828459045;
const double pi=3.1415926535;
#define CK cout<<"OK\n";
int ind[11];
double ans[6050];
double raw[11][5];
double aft[11][5];
double et[11][5];		//结束时间 

double test(){
	//et[i][j]表示第i阶段 第j种疫苗的结束时间。
	for(int i=0;i<=10;i++)et[i][0]=0;
	for(int j=1;j<=4;j++)et[0][j]=0;
	for(int i=1;i<=10;i++){
		for(int j=1;j<=4;j++){
			et[i][j]=aft[i][j] + max( et[i][j-1] , et[i-1][j] );
		}
	}
	return et[10][4];
}

int main(){
	memset(ans,0,sizeof(ans));
	freopen("t3_3_in.txt","r",stdin);
	freopen("t3_3_out.txt","w",stdout);
	int r,N;
	for(int j=1;j<=10;j++)scanf("%d",&ind[j]);

	//CK
	scanf("%d",&N);
	for(int I=0;I<N;I++){	//对于每一组数据 
		for(int i=1;i<=10;i++){
			for(int j=1;j<=4;j++){
				scanf("%lf",&raw[i][j]);
			}
		}
		for(int i=1;i<=10;i++){
			for(int j=1;j<=4;j++){
				aft[ ind[i] ][j]=raw[ i ][j];
			}
		}
		ans[I]=test();
		printf("%.4lf\n",ans[I]);
	}
	
	
	return 0;
}
