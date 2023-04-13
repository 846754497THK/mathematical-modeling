#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
double f(double x){
	return x*x*x-6*x*x+9*x;
}
int main(){
	double a;
	freopen("T.txt","w",stdout);
	for(a=0;a<5;a+=0.01){
		printf("%.3lf\t",f(a));
	}
	return 0;
} 
