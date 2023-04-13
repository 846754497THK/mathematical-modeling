#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const long long mod=100000007;
const double e=2.718281828459045;
const double pi=3.1415926535;
#define CK cout<<"OK\n";
double t[11][5];
double minT;	//记录最短时间 
vector<int>v;		//记录当前的序列 
vector<int>minV;	//记录最小时间所对应的序列 
bool u[11];	//是否可以用：可用1，已用0 
int tmp;

void init(){
	minV.clear();
	v.clear();
	minT=45000;
	for(int i=0;i<=10;i++)u[i]=1;
	tmp=0;
}

double test(){
	double et[5][11];
	//et[i][j]表示第i阶段 第j种疫苗的结束时间。
	for(int j=0;j<=10;j++)et[0][j]=0;
	for(int i=1;i<=4;i++)et[i][0]=0;
	for(int i=1;i<=4;i++){
		for(int j=1;j<=10;j++){
			et[i][j]=t[ v[j-1] ][i] + max( et[i][j-1] , et[i-1][j] );
		}
	}
	return et[4][10];
}

void OUT(vector<int>tmpv){
	for(int i=0;i<tmpv.size();i++){
		printf("%d ",tmpv[i]);
	}
	printf("\n");
}

void DO(){
	if(v.size()==10){
		double currentT=test();
		if(currentT<minT){
			minT=currentT;
			minV=v;
		}
		tmp++;
		//OUT(v);
		//tmp为测试用数据 
		
		return;
	}
	for(int i=1;i<=10;i++){
		if(u[i]){
			u[i]=0;
			v.push_back(i);
			DO();
			v.pop_back();
			u[i]=1;
		}
	}
}

int main(){
	freopen("t3_data1_in.txt","r",stdin);
	freopen("t3_data1_out_check_result.txt","w",stdout);
	int SS;
	scanf("%d",&SS);
	for(int I=0;I<30;I++){
		init();
		for(int i=1;i<=10;i++)for(int j=1;j<=4;j++)scanf("%lf",&t[i][j]);
		DO();
		printf("%.4lf\n",minT);
		OUT(minV);
	}
	return 0;
}
