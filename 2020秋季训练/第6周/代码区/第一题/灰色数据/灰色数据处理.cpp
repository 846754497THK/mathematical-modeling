#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxA=50000;
int a[maxA];
double E[maxA];
double fp[maxA];
double fn[maxA];
int main(){
	int st=2,ed=20000;
	freopen("灰色数据生成生成output.txt","r",stdin);
	
	for(int i=st;i<=ed;i++){
		scanf("%d",&a[i]);
		scanf("%lf%lf%lf",&E[i],&fp[i],&fn[i]);
	}
	freopen("灰色数据处理1.txt","w",stdout);
	for(int i=st;i<=ed;i++){
		printf("%d\n",a[i]);	
	}
	
	freopen("灰色数据处理2.txt","w",stdout);
	for(int i=st;i<=ed;i++){
		printf("%.6lf\n",E[i]);	
	}
	
	freopen("灰色数据处理3.txt","w",stdout);
	for(int i=st;i<=ed;i++){
		printf("%.6lf\n",fp[i]);	
	}

	freopen("灰色数据处理4.txt","w",stdout);
	for(int i=st;i<=ed;i++){
		printf("%.6lf\n",fn[i]);	
	}
	
	return 0;
}
