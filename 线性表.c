#include<stdio.h>
#include<stdlib.h>

#define Maxsize 100

typedef struct{
	int data[Maxsize];
	int length;
}SqList;

void InitList(SqList &L);				//初始化 
void Setnum(SqList &L,int n,int i);		//设置初始值 
void PrintSq(SqList L);					//打印线性表 
bool ListInsert(SqList &L,int i,int e);	//插入 
bool ListDelete(SqList &L,int i,int &e);//删除 
int LocateElem(SqList L,int e);			//查找 


int main(){
	SqList S;
	InitList(S);
	int t,j;
	for(int i=0;i<10;i++)
	{
		Setnum(S,i,i);
		}
	PrintSq(S);
//	printf("请输入插入：");
//	scanf("%d%d",&t,&e);
//	ListInsert(S,t,e); 

//	printf("请输入删除：");
//	scanf("%d",&t);
//	ListDelete(S,t,j);
//	printf("已删除：%d\n",j); 

	printf("请输入查找：");
	scanf("%d",&t);
	if(LocateElem(S,t)!=0){
		printf("已找到,在第%d个位置\n",LocateElem(S,t));
	}
	else
		printf("未找到"); 
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
