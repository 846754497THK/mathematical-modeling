#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const long long mod=1000000007;
const double e=2.718281828459045;
const double pi=3.1415926535;
#define CK cout<<"OK\n";
int land[100][100];			//�ؿ�״̬ 0�յأ�1�ϰ���2�յ㣬3���
int T[100][100];			//ʱ�� 
int A,B;
int sta[100][100];			//���ӵ�״̬ -1 ������ 0 ������  
int minf[15][15];			//������� 
int N;				//������ 
const int NANT=100*100+5;	
int ans;
int dx[8]={1,1,0,-1,-1,-1,0,1};
int dy[8]={0,1,1,1,0,-1,-1,-1};
// ��Դ����Ҳ�й� 
//int from[100][100];		//��Դ���� 
int X,Y;			//��ǰλ�� 

void init(){
	ans=NANT;
	for(int i=0;i<=A+1;i++){
		for(int j=0;j<=B+1;j++){
			T[i][j]=NANT;
			land[i][j]=1;
		}
	}
	for(int i=1;i<=10;i++)for(int j=1;j<=10;j++)scanf("%d",&land[i][j]);
	
	for(int i=1;i<=A;i++)for(int j=1;j<=B;j++){
		sta[i][j]=-1;
	}
	
	
	X=A;
	Y=1;
	sta[X][Y]=0;
}

void checkmap(){
	for(int i=0;i<=A+1;i++){
		for(int j=0;j<=B+1;j++)printf("%d ",land[i][j]);
		printf("\n");
	}

}

//ɨ��ɼ���

void SCAN(){
	sta[X][Y]=0;
	double d,h;
		
	//�������
	 
	//�������ϵ�h�����µ�h�����ڱ���ֱ����h=1�����ĵ�һ�е�bug
	int Hup=1,Hdown=1;
	while( land[X-Hup][Y]!=1 )Hup++;
	while( land[X+Hdown][Y]!=1 )Hdown++;
	
	int Hright=4,Hleft=1;	// �����������h 

	//����ɨ�裺����
	//������� 
	
	d=0;
	h=Hup;
	for(int py=Y+1;py<=B;py++){
		sta[X][py]=0;					//��Ǳ���Ϊ��֪ 
		int h1=0,d1=py-Y;			//h1Ϊ��ǰ�߶Ȳd1Ϊ��ǰ������� 
		
		while( land[X-h1][py]!=1 ){		//������һ�е��谭��� 
			h1++;						//ֱ����������������е��ϰ��߶� 
		}
		
		int ph=1;
		while( h*d1-ph*d>0 && X-ph>0 ){
			if(ph<h-1)sta[X-ph][py]=0;			//����ǰ����谭�ߣ�������û���ϰ����������� 
			else{
				if(land[X-ph][py]!=1)sta[X-ph][py]=0;
				else{
					sta[X-ph][py]=0;
					if( land[X-ph][py-1]!=1 && land[X-ph-1][py-1]==1 )sta[X-ph-1][py]=0; 		//������� 
					break;
				}
			} 
			ph++;
		}
		
		if( h*d1-d*h1>0 ){
			h=h1;
			d=d1;
		}
		
		if(land[X][py]==1){
			Hright=py-Y;
			break;
		}
	}
	
	//����ɨ�裺����
	//������� 
	d=0;
	h=Hdown;
	for(int py=Y+1;py<=B;py++){
		sta[X][py]=0;					//��Ǳ���Ϊ��֪ 
		int h1=0,d1=py-Y;			//h1Ϊ��ǰ�߶Ȳd1Ϊ��ǰ������� 
		
		while( land[X+h1][py]!=1 ){		//������һ�е��谭��� 
			h1++;						//ֱ����������������е��ϰ��߶� 
			
		}
		
		int ph=1;
		while( h*d1-ph*d>0 && X+ph<=A ){
			if(ph<h-1)sta[X+ph][py]=0;			//����ǰ����谭�ߣ�������û���ϰ����������� 
			else{
				if(land[X+ph][py]!=1)sta[X+ph][py]=0;
				else{
					sta[X+ph][py]=0;
					if( land[X+ph][py-1]!=1 && land[X+ph+1][py-1]==1 )sta[X+ph+1][py]=0; 		//������� 
					break;
				}
			}
			ph++;
		}
		
		if( h*d1-d*h1>0 ){
			h=h1;
			d=d1;
		}
		
		if(land[X][py]==1)break;
	}
	//����ɨ�裺����
	//�������	
	d=0;
	h=Hup;
	for(int py=Y-1;py>=0;py--){
		sta[X][py]=0;					//��Ǳ���Ϊ��֪ 
		int h1=0,d1=Y-py;			//h1Ϊ��ǰ�߶Ȳd1Ϊ��ǰ������� 
		
		while( land[X-h1][py]!=1 ){		//������һ�е��谭��� 
			h1++;						//ֱ����������������е��ϰ��߶� 
		}
		
		int ph=1;
		while( h*d1-ph*d>0 && X-ph>0 ){
			if(ph<h-1)sta[X-ph][py]=0;			//����ǰ����谭�ߣ�������û���ϰ����������� 
			else{
				if(land[X-ph][py]!=1)sta[X-ph][py]=0;
				else{
					sta[X-ph][py]=0;
					if( land[X-ph][py+1]!=1 && land[X-ph-1][py+1]==1 )sta[X-ph-1][py]=0; 		//������� 
					break;
				}
			} 
			ph++;
		}
		
		if( h*d1-d*h1>0 ){
			h=h1;
			d=d1;
		}
		
		if(land[X][py]==1){
			Hleft=Y-py;
			break;	
		}
	}
	
	//����ɨ�裺����
	//�������	
	d=0;
	h=Hdown;
	for(int py=Y-1;py>=1;py--){
		sta[X][py]=0;					//��Ǳ���Ϊ��֪ 
		int h1=0,d1=Y-py;			//h1Ϊ��ǰ�߶Ȳd1Ϊ��ǰ������� 
		
		while( land[X+h1][py]!=1 ){		//������һ�е��谭��� 
			h1++;						//ֱ����������������е��ϰ��߶� 
		}
		
		int ph=1;
		while( h*d1-ph*d>0 && X+ph<=A ){
			if(ph<h-1)sta[X+ph][py]=0;			//����ǰ����谭�ߣ�������û���ϰ����������� 
			else{
				if(land[X+ph][py]!=1)sta[X+ph][py]=0;
				else{
					sta[X+ph][py]=0;
					if( land[X+ph][py+1]!=1 && land[X+ph+1][py+1]==1 )sta[X+ph+1][py]=0; 		//������� 
					break;
				}
			}
			ph++;
		}
		
		if( h*d1-d*h1>0 ){
			h=h1;
			d=d1;
		}
		
		if(land[X][py]==1)break;
	}
	
	//������
	
	//����ɨ�裺����
	
	d=0;
	h=Hright;
	
	for(int px=X-1;px>=1;px--){
		sta[px][Y]=0;					//��Ǳ���Ϊ��֪ 
		int h1=0,d1=X-px;				//h1Ϊ��ǰ�߶Ȳd1Ϊ��ǰ�������
		while( land[px][Y+h1]!=1 )h1++;	//������һ�е��谭��� 
	//	cout<<h1<<endl;
		
		int ph=1;
		while( h*d1-ph*d>0 && Y+ph<=B ){
			if(ph<h-1)sta[px][Y+ph]=0;
			else{
				if( land[px][Y+ph]!=1 )sta[px][Y+ph]=0;
				else{
					sta[px][Y+ph]=0;
					if( land[px+1][Y+ph]!=1 && land[px+1][Y+ph+1]==1 )sta[px][Y+ph+1]=0;
					break;
				}
			}
			ph++;
		}
		
		if( h*d1-d*h1>0 ){
			h=h1;
			d=d1;
		}
		
		if( land[px][Y]==1 )break;
	}
	
	//����ɨ�裺����
	
	d=0;
	h=Hright;
	
	for(int px=X+1;px<=A;px++){
		sta[px][Y]=0;					//��Ǳ���Ϊ��֪ 
		int h1=0,d1=px-X;				//h1Ϊ��ǰ�߶Ȳd1Ϊ��ǰ�������
		while( land[px][Y+h1]!=1 )h1++;	//������һ�е��谭��� 
	//	cout<<h1<<endl;
		
		int ph=1;
		while( h*d1-ph*d>0 && Y+ph<=B ){
			if(ph<h-1)sta[px][Y+ph]=0;
			else{
				if( land[px][Y+ph]!=1 )sta[px][Y+ph]=0;
				else{
					sta[px][Y+ph]=0;
					if( land[px-1][Y+ph]!=1 && land[px-1][Y+ph+1]==1 )sta[px][Y+ph+1]=0;
					break;
				}
			}
			ph++;
		}
		
		if( h*d1-d*h1>0 ){
			h=h1;
			d=d1;
		}
		
		if( land[px][Y]==1 )break;
	}
	
	//����ɨ�裺����
	
	d=0;
	h=Hleft;
	
	for(int px=X-1;px>=1;px--){
		sta[px][Y]=0;					//��Ǳ���Ϊ��֪ 
		int h1=0,d1=X-px;				//h1Ϊ��ǰ�߶Ȳd1Ϊ��ǰ�������
		while( land[px][Y-h1]!=1 )h1++;	//������һ�е��谭��� 
	//	cout<<h1<<endl;
		
		int ph=1;
		while( h*d1-ph*d>0 && Y-ph>=1 ){
			if(ph<h-1)sta[px][Y-ph]=0;
			else{
				if( land[px][Y-ph]!=1 )sta[px][Y-ph]=0;
				else{
					sta[px][Y-ph]=0;
					if( land[px+1][Y-ph]!=1 && land[px+1][Y-ph-1]==1 )sta[px][Y-ph-1]=0;
					break;
				}
			}
			ph++;
		}
		
		if( h*d1-d*h1>0 ){
			h=h1;
			d=d1;
		}
		
		if( land[px][Y]==1 )break;
	}
	
	//����ɨ�裺���� 
	
		d=0;
	h=Hleft;
	
	for(int px=X+1;px<=A;px++){
		sta[px][Y]=0;					//��Ǳ���Ϊ��֪ 
		int h1=0,d1=px-X;				//h1Ϊ��ǰ�߶Ȳd1Ϊ��ǰ�������
		while( land[px][Y-h1]!=1 )h1++;	//������һ�е��谭��� 
	//	cout<<h1<<endl;
		
		int ph=1;
		while( h*d1-ph*d>0 && Y-ph>=1 ){
			if(ph<h-1)sta[px][Y-ph]=0;
			else{
				if( land[px][Y-ph]!=1 )sta[px][Y-ph]=0;
				else{
					sta[px][Y-ph]=0;
					if( land[px-1][Y-ph]!=1 && land[px-1][Y-ph-1]==1 )sta[px][Y-ph-1]=0;
					break;
				}
			}
			ph++;
		}
		
		if( h*d1-d*h1>0 ){
			h=h1;
			d=d1;
		}
		
		if( land[px][Y]==1 )break;
	}
	 
}

void check_eyesight(){
	printf("��ʱ�Ŀɼ���\n");
	for(int i=1;i<=A;i++){
		for(int j=1;j<=B;j++)printf("%d\t",sta[i][j]);
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

node step(){
	int movement[15][15];
	int reach[15][15];
	bool edge[15][15];
	memset(edge,0,sizeof(edge));
	memset(reach,10005,sizeof(reach));
	memset(movement,-1,sizeof(movement));
	

	
	vector<node> v;							//��Ե������ 
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
	
	/*
	printf("size: %d\n",v.size());
	
	
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
	*/
	if(sta[1][B]!=-1){				//�ܿ����յ㣬������յ��� 
		v.push_back(node(1,B,0));
		edge[1][B]=1;
	}
	
	/*
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
	int judge[15][15];
	memset(judge,0,sizeof(judge));
	int minx,miny,minjudge=10005;
	for(int i=0;i<v.size();i++){
		int tx=v[i].x;
		int ty=v[i].y;
		judge[tx][ty]=reach[tx][ty]+minf[tx][ty];
		if(judge[tx][ty]<minjudge){
			minjudge=judge[tx][ty];
			minx=tx;
			miny=ty;
		}
	}
	/*
	printf("JUDGE:\n");
	for(int i=1;i<=10;i++){
		for(int j=1;j<=10;j++){
			printf("%d\t",judge[i][j]);
		}
		printf("\n");
	}
	
	cout<<minx<<"  "<<miny<<endl; 
	*/
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



int main(){
	A=10;
	B=10;
	freopen("test3.txt","r",stdin);
	scanf("%d",&N);
	
	for(int i=1;i<=10;i++){
		for(int j=1;j<=10;j++){
			minf[i][j]=max( i-1 , B-j );
		//	printf("%d\t",minf[i][j]);
		}
//		printf("\n");
	}
	/*
	//���������
	init();
	X=4,Y=6;
	SCAN();
	check_eyesight();
	step();
	*/
	//��������� 
	
	int cnt=0;
	for(int I=0;I<N;I++){
		init();
		cnt=0;
		printf("time:  %d  \t\t  [%d][%d]\n",cnt++,A,1);
		while( X!=1 || Y!=B ){					//�������ͼһ��������ͨ 
			//ɨ��ɼ���
			SCAN();
			//check_eyesight();
			node NEXT=step();
			X=NEXT.x;
			Y=NEXT.y;
			printf("time:  %d  \t\t  [%d][%d]\n",cnt++,X,Y);
			
		}
		//printf("time: %d\t  [%d][%d]\n",cnt++,1,B);
		
	}
	
	
	return 0;
}
