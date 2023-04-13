#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
double a[5520][105];	//预处理后的数据
double ans[5520][105];	//answer 
int main(){
	memset(ans,0,sizeof(ans));
	freopen("Autocorrelation_coefficient_in.txt","r",stdin);
	freopen("Autocorrelation_coefficient_out.txt","w",stdout);
	int tar[16]={4,7,11,17,20,21,23,41,47,57,65,71,72,73,76,96};
	//编号从1开始 
	for(int i=1;i<=5519;i++){
		for(int j=1;j<=100;j++)scanf("%lf",&a[i][j]);
	}
	//读入数据	
	for(int J=1;J<=100;J++){
	
		//处理第J列数据
		int c=1;
		double sum=0,y=0;
		//sum 用于计算前c个和，以便求平均数 
		for(;c<=15;c++){
			sum+=a[c][J];
		} 
		
		//从十六开始 
		for(;c<=5519;c++){
			sum+=a[c][J];
			y=sum/c;
			//求出分母上的var*c
			double deno=0;
			for(int i=1;i<=c;i++){
				deno+=( a[i][J] - y )*( a[i][J] - y );
			} 
			
			for(int k=1;k<=15;k++){
				double tmp=0;
				//tmp保留当前k延迟条件下的自相关系数
				for(int i=1;i<=c-k;i++){
					tmp+=(a[i][J]-y)*(a[i+k][J]-y)/deno;
				}
				ans[c][J]+=tmp/15;
			}
		}
	}
	for(int i=1;i<=5519;i++){
		for(int j=1;j<=100;j++){
			printf("%.10lf\t",ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}
