#include<stdio.h>
#include<stdlib.h>

#define Maxsize 100

typedef struct{
	int data[Maxsize];
	int length;
}SqList;

void InitList(SqList &L);				//��ʼ�� 
void Setnum(SqList &L,int n,int i);		//���ó�ʼֵ 
void PrintSq(SqList L);					//��ӡ���Ա� 
bool ListInsert(SqList &L,int i,int e);	//���� 
bool ListDelete(SqList &L,int i,int &e);//ɾ�� 
int LocateElem(SqList L,int e);			//���� 


int main(){
	SqList S;
	InitList(S);
	int t,j;
	for(int i=0;i<10;i++)
	{
		Setnum(S,i,i);
		}
	PrintSq(S);
//	printf("��������룺");
//	scanf("%d%d",&t,&e);
//	ListInsert(S,t,e); 

//	printf("������ɾ����");
//	scanf("%d",&t);
//	ListDelete(S,t,j);
//	printf("��ɾ����%d\n",j); 

	printf("��������ң�");
	scanf("%d",&t);
	if(LocateElem(S,t)!=0){
		printf("���ҵ�,�ڵ�%d��λ��\n",LocateElem(S,t));
	}
	else
		printf("δ�ҵ�"); 
	PrintSq(S);
	
	return 0;
}


void InitList(SqList &L){
	for(int j=0;j<Maxsize;j++)
		L.data[j]=0;
	L.length=0;
}

void Setnum(SqList &L,int n,int i){           
	L.data[n]=i;
	L.length++;
}

void PrintSq(SqList L){
	for(int i=0;i<L.length;i++)
		printf("L.data[%d]=%d\n",i,L.data[i]);
}

bool ListInsert(SqList &L,int i,int e){
	if(i<1||i>L.length)
		return false;
	for(int j=L.length;j>=i-1;j--){
		L.data[j+1]=L.data[j];
	}
	L.data[i-1]=e;
	L.length++;
	return true;
} 

bool ListDelete(SqList &L,int i,int &e){
	if(i<i||i>L.length)
		return false;
	L.data[i-1]=e;
	for(int j=i-1;j<L.length+1;j++)
	{
		L.data[j]=L.data[j+1];
	}
	L.length--;
}

int LocateElem(SqList L,int e){
	for(int i=0;i<L.length;i++){
		if(L.data[i]==e)
			return i+1;
	}
	return 0;
}
