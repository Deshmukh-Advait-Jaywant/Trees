#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

int node_cnt=0,i=0,j,n,harr[10];
void insert(int );
void display(void );
int delete(void );

int main()
{
	int x,a,ch;
	do{
		printf("enetr 1 for insert");
		printf("enter 2 for delete");
		printf("enter your choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
					printf("\n enter how many elements do you want:");
					scanf("%d",&n);
					for(a=0;a<n;a++)
					{
						printf("\n enter element[%d]:",a+1);
						scanf("%d",&x);
						insert(x);
						printf("\n elements of heap are:");
						display();
					}
					break;
			case 2:
				x=delete();
			printf("\n %d element is deleted from the heap",x);
			display();	
		}	
	}while(ch!=3);
}
void insert(int x)
{
	int temp;
	i=node_cnt;
	if(node_cnt==SIZE)
	{
		printf("\n heap is full");
		return;
	}
	harr[i]=x;
	node_cnt++;
	j=i;
	while((j!=0) && harr[j]<harr[(j-1)/2])
    {
    	temp=harr[j];
    	harr[j]=harr[(j-1)/2];
    	harr[(j-1)/2]=temp;
    	j=(j-1)/2;
	}
	printf("\n %d node is successfully added",x);
}

void display(void )
{
	for(i=0;i<=node_cnt-1;i++)
	{
		printf("\n %4d",harr[i]);
	}
}

int delete()
{
	if(node_cnt==0)
	{
		printf("heap is empty");
		return;
	}
	harr[0]=harr[node_cnt-1];
	node_cnt--;
//	heap(0);
	int swap;
	int largest=0;
	int l=(2*i)+1,r=(2*i)+2;
	while(r<=node_cnt)
	{
		if((l<node_cnt) && harr[l]>harr[largest])
		{
			largest=l;
		}
		if((r<node_cnt) && harr[r]>harr[largest])
		{
			largest=l;
		}
		if(largest!=i)
		{
			swap=harr[i];
			harr[i]=harr[largest];
			harr[largest]=swap;
		}
	}
	
}

