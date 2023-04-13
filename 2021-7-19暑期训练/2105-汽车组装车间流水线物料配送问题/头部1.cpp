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
int cnt;

void init(){
	cnt=0;
	for(int i=0;i<100;i++){
		p[i].name="_";
		p[i].rank=-1;
	}
	for(int i=0;i<100;i++){
		for(int j=0;j<100;j++)dis[i][j]=1000000;
	}
}

int search_point(string tar){
	int r=-1;
	for(int i=0;i<cnt;i++){
		if(tar==p[i].name){
			r=i;
			break;
		}
	}
	return r;
}

int main(){
	freopen("distance_in.txt","r",stdin);
	freopen("Í·²¿1.txt","w",stdout);	
	int N;
	init();
	scanf("%d",&N);
	
	
	for(int i=0;i<N;i++){
		string s1,s2;
		double tmp;
		cin>>s1>>s2>>tmp;
		
		int r1,r2;
		r1=search_point(s1);
		if(r1==-1){
			p[cnt].rank=cnt;
			p[cnt].name=s1;
			r1=cnt;
			cnt++;
		}
		r2=search_point(s2);
		if(r2==-1){
			p[cnt].rank=cnt;
			p[cnt].name=s2;
			r2=cnt;
			cnt++;
		}
		
		dis[r1][r2]=tmp;
		dis[r2][r1]=tmp;
		
	}
	
	
	for(int i=0;i<cnt;i++)for(int j=0;j<cnt;j++)for(int k=0;k<cnt;k++)
		if(dis[j][k]>dis[j][i]+dis[i][k]){
			dis[j][k]=dis[j][i]+dis[i][k];
			dis[k][j]=dis[j][i]+dis[i][k];
	}
	
	printf("\n");
	for(int i=0;i<cnt;i++){
		for(int j=0;j<cnt;j++)printf("%.1lf,",dis[i][j]);
		printf("\n");
	}
	
	return  0;
}
