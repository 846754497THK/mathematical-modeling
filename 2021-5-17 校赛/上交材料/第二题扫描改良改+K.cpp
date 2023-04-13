#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const long long mod=1000000007;
const double e=2.718281828459045;
const double pi=3.1415926535;
#define CK cout<<"OK\n";
// ע�͵���ϸ˵������ֽ˵��1�� 
int T[100][100];			//ʱ�� 
int A,B;
int sta[100][100];			//���ӵ�״̬ -1 ������ 0 ������  
int land[100][100];			//���ӵ���  -1 ������ 0 ���� 1 ������ 
int mas[105][105];			//ԭʼ��Ϣ  0 ��  1 �� 
int truemas[15][15];		//��ʵ��ͼ��Ϣ  0 ��  1 �� 
int mas1[105][105];			//hash��Ϣ  0 ��  1 �� 
int massrate[15][15];	//Ŀ�귽���ڵ�ˮƽ 
int N;				//������ 
int Srate;					//����ˮƽ��S% Ϊ����ʶ����� 
							//massrate �������ֵ�Ͳ���ʶ���� 
const int NANT=100*100+5;	
int ans;
int dx[8]={1,1,0,-1,-1,-1,0,1};
int dy[8]={0,1,1,1,0,-1,-1,-1};

int minf[15][15];			//������� 

// ��Դ����Ҳ�й� 
//int from[100][100];		//��Դ���� 

double K;
// ��Դ����Ҳ�й� 
//int from[100][100];		//��Դ���� 

int X,Y;			//��ǰλ�� 

void init(){
	
	for(int i=0;i<=A+1;i++){
		for(int j=0;j<=B+1;j++){
			T[i][j]=NANT;
			land[i][j]=1;
			mas[i][j]=1;
			truemas[i][j]=1;
			
		}
	}
	
	ans=NANT;
	for(int i=0;i<=A+1;i++){
		for(int j=0;j<=B+1;j++)
			if(i==0 || i==A+1 || j==0 || j==B+1){
				massrate[i][j]=0;
				sta[i][j]=0;
				mas[i][j]=1;
				truemas[i][j]=1;
			}else{
				massrate[i][j]=100;
				sta[i][j]=-1;
			}
	}
	
	for(int i=0;i<100;i++)for(int j=0;j<100;j++)scanf("%d",&mas[i][j]);
	memset(mas1,0,sizeof(mas1));
	//��ϣ
	for(int i=0;i<100;i++){
		int sum=0;
		for(int j=0;j<10;j++)sum+=mas[i][j];

		for(int j=0;j<=90;j++){
			mas1[i][j]=sum;
			sum=sum-mas[i][j]+mas[i][j+10];
		}
	} 
	memset(mas,0,sizeof(mas));
	for(int j=0;j<=90;j++){
		int sum=0;
		for(int i=0;i<10;i++)sum+=mas1[i][j];
		for(int i=0;i<=90;i++){
			mas[i][j]=sum;
			sum=sum-mas1[i][j]+mas1[i+10][j];
		}
	}
	
	//֮��ȡ��mas���� 
	
	//��ʵ��ͼ��Ϣ  0 ��  1 �� 
	
	for(int i=0;i<=9;i++){
		for(int j=0;j<=9;j++){
			printf("%d\t",mas[i*10][j*10]);
		}
		printf("\n");
	}
	printf("\n");
	
}

//ɨ��ɼ���

void SCAN(){
	for(int i=1;i<=10;i++)for(int j=1;j<=10;j++){
		if( massrate[i][j]==0 )continue;
		if( abs(j-Y)<=1 && abs(i-X)<=1 ){
			massrate[i][j]=0;
			continue;
		}
		int di=X-i;
		int dj=Y-j;
		int S=0;	//����ڵ�ˮƽ 
		//���껻�㣺10*10  ->  100-100 
		int I=10*(i-1);
		int J=10*(j-1);
		int XX=10*(X-1);
		int YY=10*(Y-1); 
		
		while( I!=XX || J!=YY ){
			
			I+=di;
			J+=dj;
			if( abs(I-10*(i-1))<10 && abs(J-10*(j-1))<10 )continue;
			if(mas[I][J]>S)S=mas[I][J];
		}
		massrate[i][j]=min(S,massrate[i][j]);
	}
	
	//�ɼ�����ʽת��
	for(int i=1;i<=10;i++){
		for(int j=1;j<=10;j++){
			if(massrate[i][j]<Srate)sta[i][j]=0;
		}
	} 
	
}

void check_eyesight(){
	printf("eyesight_real\n");
	for(int i=1;i<=10;i++){
		for(int j=1;j<=10;j++)printf("%d\t",massrate[i][j]);
		printf("\n");
	}
}

void check_eyesight_01(){
	printf("eyesight_turned\n");
	for(int i=0;i<=11;i++){
		for(int j=0;j<=11;j++)printf("%d\t",sta[i][j]);
		printf("\n");
	}
}

struct node{
	int x;
	int y;
	int t;
	node(int x,int y,int t):x(x),y(y),t(t){}
	friend bool operator<(const node &WW,const node &VV ){
		return WW.t<VV.t;
	}
};

bool check_edge(int x,int y){
	
	for(int turn=0;turn<8;turn++){
		int tx=x+dx[turn];
		int ty=y+dy[turn];
		if( (sta[tx][ty]==-1 && land[tx][ty]==0) || land[tx][ty]==2 ){
			return 1;
		}
	}
	return 0;
}

vector<node> v;							//��Ե������ 

node step(){
	int movement[15][15];
	int reach[15][15];
	bool edge[15][15];
	memset(edge,0,sizeof(edge));
	memset(reach,10005,sizeof(reach));
	memset(movement,-1,sizeof(movement));
	
	v.clear();	
	priority_queue <node> q;				//�������� 
	while(!q.empty())q.pop();
	reach[X][Y]=0;
	movement[X][Y]=-1;
	edge[X][Y]=0;
	
	q.push(node(X,Y,0));
	
	while(!q.empty()){
		node tmp=q.top();
		q.pop();
		
		if(land[tmp.x][tmp.y]==2)continue;							//���յ� 
		
		for(int turn=0;turn<8;turn++){
			int tx=tmp.x+dx[turn];
			int ty=tmp.y+dy[turn];
		//	if(sta[tx][ty]==-1)continue;			//���������� 
			if( land[tx][ty]==1 )continue;
			int tt=tmp.t+1;
			if(reach[tx][ty]>tt){
				reach[tx][ty]=tt;
				q.push(node(tx,ty,tt));
				movement[tx][ty]=turn;
			}
			
			if(edge[tx][ty]==0 && land[tx][ty]!=1 && sta[tx][ty]==0 ){
				if( land[tx][ty]==2 || check_edge(tx,ty) ){		//���� ��Ե�����飬֮��Ҫ��� 
					//movement[tx][ty]=turn;
					v.push_back(node(tx,ty,tt));
					
					edge[tx][ty]=1;
				}
				//����edge 
			}
			//�����Χ����	
		}
	}
	
	//���������� 
	
//	printf("size: %d\n",v.size());
	
//	check_eyesight_01();
	
	/*
	printf("edge\n");
	for(int i=1;i<=10;i++){
		for(int j=1;j<=10;j++){
			if(edge[i][j])printf("1\t");
			else printf("0\t");
		}
		printf("\n");
	}
	
	/*
	printf("movement:\n");
	for(int i=1;i<=10;i++){
		for(int j=1;j<=10;j++){
			printf("%d\t",movement[i][j]);
		}
		printf("\n");
	}
	
	if(sta[1][B]!=-1){				//�ܿ����յ㣬������յ��� 
		v.push_back(node(1,B,0));
		edge[1][B]=1;
	}
	
	
	printf("reach:\n");
	for(int i=1;i<=10;i++){
		for(int j=1;j<=10;j++){
			if(sta[i][j]==-1){
				printf("?\t");
				continue;	
			}
			if(edge[i][j])printf("*");
			if(reach[i][j]>NANT)printf("%d\t",-1);
			else printf("%d\t",reach[i][j]);
			
		}
		printf("\n");
	}
	*/
	
	//�ҵ�����+�ɱ���С�� 
	//�ҵ�����+�ɱ���С�� 
	double judge[15][15];
	memset(judge,0,sizeof(judge));
	int minx,miny;
	double minjudge=10005;
	for(int i=0;i<v.size();i++){
		int tx=v[i].x;
		int ty=v[i].y;
		judge[tx][ty]=reach[tx][ty]+K*minf[tx][ty];
		if(judge[tx][ty]<minjudge){
			minjudge=judge[tx][ty];
			minx=tx;
			miny=ty;
		}
	}
	//�����յ㣺ֱ���յ�
	if(edge[1][B]==1){
		minjudge=0;
		minx=1;
		miny=B;
	} 
	
	/*
	printf("JUDGE:\n");
	for(int i=1;i<=10;i++){
		for(int j=1;j<=10;j++){
			printf("%d\t",judge[i][j]);
		}
		printf("\n");
	}
	*/
	
//	cout<<"min judge : "<<minx<<"  "<<miny<<endl; 
	
	//minx,miny �ǵ�ǰ��Ŀ���
	//����Ŀ��� 
	int targetx=minx,targety=miny,lastx,lasty;
	int backx,backy;
	backx=dx[ movement[targetx][targety] ];
	backy=dy[ movement[targetx][targety] ];
	lastx=targetx-backx;
	lasty=targety-backy;
	while(lastx!=X || lasty!=Y){
		targetx=lastx;
		targety=lasty;
		backx=dx[ movement[targetx][targety] ];
		backy=dy[ movement[targetx][targety] ];
		lastx=targetx-backx;
		lasty=targety-backy;
	}
//	cout<<targetx<<"   "<<targety<<endl; 
	//��ʱ target[x y]������һ����Ŀ�� 
	return node(targetx,targety,0);
}

void land_reshape(){
	for(int i=0;i<=9;i++){
		for(int j=0;j<=9;j++){
			if(mas[i*10][j*10]<Srate)land[i+1][j+1]=0;
			else land[i+1][j+1]=-1;
		}
	}
	land[A][1]=3;
	land[1][B]=2;
}

int main(){
	A=10;
	B=10;
	Srate=50;
	freopen("newscan_in.txt","r",stdin);
	init();
	N=1;			//ͼ�ĸ���
	
	land_reshape();		//��land��Ϣת����10*10 
	
	double Kseq[25]={10,5,3,2.5,2,  1.8,1.6,1.4,1.2,1.1  ,1,0.9,0.8,0.7,0.6  ,0.5,0.4,0.3,0.2,0.1};
				//��Ϣ�ز��� 
	
	for(int i=1;i<=10;i++){
		for(int j=1;j<=10;j++){
			minf[i][j]=max( i-1 , B-j );
		}
	}
	
	//land checked
	/*
	printf("land\n");
	for(int i=1;i<=10;i++){
		for(int j=1;j<=10;j++){
			printf("%d\t",land[i][j]);
		}
		printf("\n");
	}
	
	
	//���������
	X=10,Y=1;
	SCAN();
	check_eyesight();		//��������� 
	
	step();
	//��������� 
	
	
	*/
	K=1.2;
	X=10,Y=1;
	int cnt=0;
	printf("time:  %d  \t\t  [%d][%d]\n",cnt++,A,1);
	while( X!=1 || Y!=B ){					//�������ͼһ��������ͨ 
		//ɨ��ɼ���
		SCAN();
		check_eyesight();	
		printf("\n");
		check_eyesight_01();		
		node NEXT=step();			
		X=NEXT.x;			
		Y=NEXT.y;
		printf("time:  %d  \t\t  [%d][%d]\n",cnt++,X,Y);
			printf("\n");
	}
		//printf("time: %d\t  [%d][%d]\n",cnt++,1,B);
	
	
	return 0;
}
