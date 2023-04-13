#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const long long mod=100000007;
const double e=2.718281828459045;
const double pi=3.1415926535;
#define CK cout<<"OK\n";
int ind[50][11];
double ave[50];
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
	freopen("t3_2_in.txt","r",stdin);
	freopen("t3_2_out.txt","w",stdout);
	int r,N;
	scanf("%d",&r);
	for(int i=0;i<r;i++){
		for(int j=1;j<=10;j++)scanf("%d",&ind[i][j]);
		ave[i]=0;
	}
	//CK
	scanf("%d",&N);
	for(int I=0;I<N;I++){	//对于每一组数据 
		for(int i=1;i<=10;i++){
			for(int j=1;j<=4;j++){
				scanf("%lf",&raw[i][j]);
			//	printf("%.1lf\t",raw[i][j]);
			}
		//	printf("\n");
		}
//		CK
		for(int k=0;k<r;k++){	//测试每一种排列 
			for(int i=1;i<=10;i++){
		//		cout<<ind[k][i]<<endl;
				for(int j=1;j<=4;j++){
					aft[ ind[k][i] ][j]=raw[ i ][j];
					
				}
				
			}
			//CK
			double ans=test();
		//	cout<<ans;
			ave[k]+=ans/N;
		}
	}
	double mina=1000;
	int min_ind=0;
	for(int k=0;k<r;k++){
		printf("%.4lf\n",ave[k]);
		if(mina>ave[k]){
			mina=ave[k];
			min_ind=k;
		}
	}
	
	printf("\nmin:%.4lf\n",mina);
	for(int i=1;i<=10;i++){
		printf("%d\t",ind[min_ind][i]);
	}
	
	return 0;
}
