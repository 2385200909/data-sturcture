#include<stdio.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0

//typedef int Elemtype;

typedef struct LNode{
	int data;
	LNode *next;
}LNode,*LinkList;

int InitList(LinkList &L){						//初始化 
	L=(LNode *)malloc(sizeof(LNode));
	L->next=NULL;
	return OK;
}

int GetLong(LinkList L)				//获取链表长度 
{
	LNode *P=L;
	int i;
	while(P!=NULL)
	{
		P=P->next;
		i++;
	 } 
	return i;
}

int Insert_H(LNode *H){					//头插法 
	LNode *P=H;
	LNode *L;
	int x;
	while(x!=9999)
	{
		
		L=(LNode *)malloc(sizeof(LNode));
		L->data=x;
	  	P->next=L;
	 	P=L;	
		 scanf("%d",&x);
	}
	return OK;
}
void print(LinkList L){							//打印 
	LNode *p;
	p=L->next;
	while(p){
		p=p->next;
		printf("%d  ",p->data);
	}
}

void Insert_T(LinkList &H)		//尾插法 
{
	LNode *P=H;
	LNode *L;
	int x;
	while(x!=9999)
	{
		
		L=(LNode *)malloc(sizeof(LNode));
		L->data=x;
	  	P->next=L;
	 	P=L;	
		 scanf("%d",&x);
	}
	P->next=NULL;
	}	

int LNodeSearch(LinkList L,int x){				//1值查找    //2按位 
	//1 按值查找 
		LNode *P=L;
	int i=0;
	

	while(P!=NULL&&P->data!=x)
	{
		P=P->next;
	 } 
	 if(P)
	{
		printf("已找到\n");
		return OK;
	}
	printf("未找到\n");
	return ERROR;
	
	
	
	
	
	//2 按位查找			//链表中不建议使用该方法进行查找
							//因为无法知道链表长度，顺序表中适合使用此方法 
	
//	LNode *P=L->next;
//	int i=0;
//	
//	 for(i=1;i<=x;i++)
//	 {
//	 	P=P->next;
//	 }
//	 if(P)
//	{
//		printf("已找到\ndata=%d\n",P->data);
//		return OK;
//	}
//	printf("未找到\n");
//	return ERROR;
}


int DeleteLNode(LinkList &H,int x)
{
	//1 按位删除 
	int i;
	i=GetLong(H);
	if(x>i)
	{
		printf("输入数据不合法!\n");
		return ERROR;
	}
	LNode *P=H; 
	for(int i=0;i<x;i++)
	{
		P=P->next;
	}
	LNode *S=P->next;
	P->next=S->next;
	free(S);
	return OK;
	
	//2 按值删除 
//	LNode *P=H;
//	if(LNodeSearch(P,x)==ERROR)
//	{
//		printf("输入的值不合法!\n")
//		return ERROR;
//	 } 
//	 while(P->next.data!=x&&P!=NULL)
//	 {
//	 	P=P->next; 
//	 }
//	LNode *S=P->next;
//	P->next=S->next;
//	free(S);
//	return OK;
 } 

int main(){
	int n;
	LNode * H;
	int data;
	InitList(H);
//	
//	H=(LNode *)malloc(sizeof(LNode)); 
//	H->next=NULL;
		if(H)
		printf("Init List sucess!\n");
	else 
		printf("Init fail!");
	printf("Please input:\n");
		Insert_T(H);	
	printf("Input the data witch you want to delete:\n");
	scanf("%d",&data);
	DeleteLNode(H,data);
	print(H);

}
