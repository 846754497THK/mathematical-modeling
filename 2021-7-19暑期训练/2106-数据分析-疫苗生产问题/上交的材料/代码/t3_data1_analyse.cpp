#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const long long mod=100000007;
const double e=2.718281828459045;
const double pi=3.1415926535;
#define CK cout<<"OK\n";
int a[200];
int main(){
	int N=0;
	freopen("t3_data1_out.txt","r",stdin);
	freopen("t3_data1_analyse.txt","w",stdout);
	double t;
	memset(a,0,sizeof(a));
	while(~scanf("%lf",&t)){
		if(t<177)t=177;
		if(t>191)t=191;
		int s=t;
	//	cout<<s<<endl;
		a[s]++;
	}
	for(int i=177;i<=191;i++){
		printf("%d\n",a[i]);
	}
	return 0;
} 
