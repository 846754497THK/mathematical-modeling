#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const long long mod=1000000007;
const double e=2.718281828459045;
const double pi=3.1415926535;
default_random_engine E;
const double P=0.3;                   //ÕÏ°­±ÈÀý  
int N;
const int A=10,B=10;
uniform_real_distribution<double>xx(0,1);
int ram(){
	if(xx(E)<P)return 1;
	else return 0;
}
int main(){
	N=100000; 							//×ÜÊý 
	freopen("test_20%_100000.txt","w",stdout);
	printf("%d\n",N);
	for(int I=0;I<N;I++){
		for(int j=1;j<B;j++){
			printf("%d ",ram());
		}
		printf("2 \n");
		
		for(int i=1;i<A-1;i++){
			for(int j=0;j<B;j++){
				printf("%d ",ram());
			}
			printf("\n");
		}
		
		printf("3 ");
		for(int j=1;j<B;j++){
			printf("%d ",ram());
		}
		
		printf("\n\n");
	}
	return 0;
}
