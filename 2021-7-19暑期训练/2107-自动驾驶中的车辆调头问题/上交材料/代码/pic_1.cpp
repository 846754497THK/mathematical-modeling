#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const long long mod=100000007;
const double e=2.718281828459045;
const double pi=3.1415926535;
#define CK cout<<"OK\n";
int main(){
	
	freopen("pic_1_in.txt","r",stdin);
	freopen("pic_1_out.txt","w",stdout);
	double a[100],b[100];
	int n=0;
	while(~scanf("%lf%lf",&a[n],&b[n])){
		n++;
	}
	for(int i=0;i<n;i++){
		printf("%.5lf,",a[i]);
	}
	printf("\n");
	for(int i=0;i<n;i++){
		printf("%.5lf,",b[i]);
	}
	printf("\n");
	return 0;
}
