#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const long long mod=100000007;
const double e=2.718281828459045;
const double pi=3.1415926535;
#define CK cout<<"OK\n";
struct Point{
	string name;
	int rank;
	Point(string s="_",int x=0):name(s),rank(x){}
	
}p[100];
double dis[100][100];

int N;

int search_point(string tar){
	int r=-1;
	for(int i=0;i<N;i++){
		if(tar==p[i].name){
			r=i;
			break;
		}
	}
	return r;
}

int main(){
	freopen("distance_out.txt","r",stdin);
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		cin>>p[i].name;
		p[i].rank=i;
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++)scanf("%lf",&dis[i][j]);
	} 
	
	freopen("CON","r",stdin); //切换到从控制台输入
	
	
	string s1,s2;
	while(1){
		cin>>s1;
		if(s1=="end")break;
		cin>>s2;
		int r1,r2;
		r1=search_point(s1);
		r2=search_point(s2);
		if(r1==-1 || r2==-1)printf("输入有误\n");
		else{
			printf("%.1lf\n",dis[r1][r2]/5);
		}
	}
	return 0;
}
