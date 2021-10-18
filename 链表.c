#include<stdio.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0

//typedef int Elemtype;

typedef struct LNode{
	int data;
	LNode *next;
}LNode,*LinkList;

int InitList(LinkList &L){						//��ʼ�� 
	L=(LNode *)malloc(sizeof(LNode));
	L->next=NULL;
	return OK;
}

int GetLong(LinkList L)				//��ȡ������ 
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

int Insert_H(LNode *H){					//ͷ�巨 
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
void print(LinkList L){							//��ӡ 
	LNode *p;
	p=L->next;
	while(p){
		p=p->next;
		printf("%d  ",p->data);
	}
}

void Insert_T(LinkList &H)		//β�巨 
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

int LNodeSearch(LinkList L,int x){				//1ֵ����    //2��λ 
	//1 ��ֵ���� 
		LNode *P=L;
	int i=0;
	

	while(P!=NULL&&P->data!=x)
	{
		P=P->next;
	 } 
	 if(P)
	{
		printf("���ҵ�\n");
		return OK;
	}
	printf("δ�ҵ�\n");
	return ERROR;
	
	
	
	
	
	//2 ��λ����			//�����в�����ʹ�ø÷������в���
							//��Ϊ�޷�֪�������ȣ�˳������ʺ�ʹ�ô˷��� 
	
//	LNode *P=L->next;
//	int i=0;
//	
//	 for(i=1;i<=x;i++)
//	 {
//	 	P=P->next;
//	 }
//	 if(P)
//	{
//		printf("���ҵ�\ndata=%d\n",P->data);
//		return OK;
//	}
//	printf("δ�ҵ�\n");
//	return ERROR;
}


int DeleteLNode(LinkList &H,int x)
{
	//1 ��λɾ�� 
	int i;
	i=GetLong(H);
	if(x>i)
	{
		printf("�������ݲ��Ϸ�!\n");
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
	
	//2 ��ֵɾ�� 
//	LNode *P=H;
//	if(LNodeSearch(P,x)==ERROR)
//	{
//		printf("�����ֵ���Ϸ�!\n")
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
