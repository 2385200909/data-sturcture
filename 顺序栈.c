#include<stdio.h>
#include<stdlib.h>

#define Maxsize 2

typedef int status;
typedef int Elemtype;

typedef struct {
	Elemtype data[Maxsize];
	int top;
}SqStack;

bool InitStack(SqStack &S){	//≥ı ºªØ’ª 
	S.top=-1;
	return true;
}

bool StackEmpty(SqStack &S){	//≈–∂œ’ªø’ 
	if(S.top==-1)		
	{
		printf("Stack is NULL");
		return true;
	}
	else
		return false;
} 

bool Push(SqStack &S,int x){	//»Î’ª 
	if(S.top+1==Maxsize)
	{
		printf("Stack is full!\n");
		return false; 
	} 
	S.data[++S.top]=x;
	return true;
}

int Pop(SqStack &S,int &x){	//≥ˆ’ª 
	if(S.top==-1)
	{
		printf("Stack is NULL\n");
		return false;
	}
	x=S.data[S.top--];
	return x;
}

bool Gettop(SqStack &S,int &x){			//∂¡»°’ª∂•‘™Àÿ 
	if(S.top==-1)
	{
		printf("Stack is NULL");
		exit(0);
	}
	x=S.data[S.top];
}

int main(){
	SqStack S;
	int n,x,m;
	if(InitStack(S))
		printf("Init Stack success!");
	else{
		printf("Init Stack error!");
		return 0;
	} 
	printf("How many:");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("«Î ‰»Î’ª÷µ£∫");
		scanf("%d",&x);
		Push(S,x);
	}
	Pop(S,x);
	printf("Pop£∫%d\n",x); 
	Gettop(S,x);
	printf("GetTop: %d\n",x);
	return 0;
} 
