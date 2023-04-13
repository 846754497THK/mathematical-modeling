#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const long long mod=100000007;
const double e=2.718281828459045;
const double pi=3.1415926535;
#define CK cout<<"OK\n";
double k[15][400],x1[15][400],x2[15][400];
int n;
int main(){
	freopen("input1.txt","r",stdin);
	freopen("output1.txt","w",stdout);
	n=0;
	for(int i=0;i<=10;i++){
		for(int j=0;j<=300;j++){
			scanf("%lf%lf%lf",&k[i][j],&x1[i][j],&x2[i][j]);
			
		}
	}
	for(int i=0;i<=10;i++){
		for(int j=0;j<=300;j++){
			printf("%.5lf\t",k[i][j]);
			
		}
		printf("\n");
	}
	printf("\n");
	printf("\n");printf("\n");printf("\n");
	for(int i=0;i<=10;i++){
		for(int j=0;j<=300;j++){
			printf("%.5lf\t",x1[i][j]);
			
		}
		printf("\n");
	}
	printf("\n");printf("\n");printf("\n");printf("\n");
	for(int i=0;i<=10;i++){
		for(int j=0;j<=300;j++){
			printf("%.5lf\t",x2[i][j]);
			
		}
		printf("\n");
	}
	return 0; 
}
