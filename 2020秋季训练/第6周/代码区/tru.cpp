
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	default_random_engine DRE;
	uniform_int_distribution<unsigned>choose(0,2);
	for(int i=0;i<1000;i++)printf("%d\n",choose(DRE));
	return 0;
}
