#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const long long mod=100000007;
const double e=2.718281828459045;
const double pi=3.1415926535;
#define CK cout<<"OK\n";
int main(){
	int a95=00,a90=0,a85=0,a80=0;
	freopen("1.txt","r",stdin);
	freopen("output1.txt","w",stdout);
	for(int i=0;i<100;i++){
		double a;
		cin>>a;
		if(a>0.95)a95++;
		if(a>0.90)a90++;
		if(a>0.85)a85++;
		if(a>0.80)a80++,cout<<i+1<<endl;
		
	}
	cout<<a95<<endl<<a90<<endl<<a85<<endl<<a80<<endl;
	return 0;
}
