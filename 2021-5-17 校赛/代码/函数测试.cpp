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
	for(int j=0;j<=B+1;j++){
		T[0][j]=NANT;
		T[A+1][j]=NANT;
		land[0][j]=1;
		land[A+1][j]=1;
	}
	for(int i=1;i<=A+1;i++){
		T[i][0]=NANT;
		T[i][B+1]=NANT;
		land[i][0]=1;
		land[i][B+1]=1;
		for(int j=1;j<=B;j++)scanf("%d",&land[i][j]),T[i][j]=NANT;
	}
	
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
	for(int i=0;i<=A+1;i++){
		for(int j=0;j<=B+1;j++)printf("%d ",T[i][j]);
		printf("\n");
	}
}

void check_eyesight(){
	for(int i=0;i<=A+1;i++){
		for(int j=0;j<=B+1;j++)printf("%d\t",sta[i][j]);
		printf("\n");
	}
}

//ɨ��ɼ���
void SCAN(){
	
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
int main(){
	A=10;
	B=10;
	freopen("test2.txt","r",stdin);
	scanf("%d",&N);
	
	init();
	checkmap();
	X=7,Y=6;
//	check_eyesight();
	SCAN();
	check_eyesight();
	return 0;
}
