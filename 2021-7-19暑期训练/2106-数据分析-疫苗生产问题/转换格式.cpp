#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("Trans_in.txt","r",stdin);
	freopen("Trans_out.txt","w",stdout);
	double a[55];
	for(int J=0;J<40;J++){
		for(int i=0;i<50;i++){
			cin>>a[i];
			printf("%.4lf\t",a[i]);
		}
		printf("\n");
	}
	return 0;
}
