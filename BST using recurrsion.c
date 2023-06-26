#include<stdio.h>
#include<stdlib.h>
struct avl_node
{
	int data;
	struct avl_node *left;
	struct avl_node *right;
	//int height;
};
struct avl_node *root=NULL;
//create node
struct avl_node *create_node(int x)
{
	struct avl_node *tp;
	tp=(struct avl_node *)malloc(sizeof(struct avl_node));
	tp->data=x;
	tp->left=NULL;
	tp->right=NULL;
	return(tp);
}
//definition of insert function
struct avl_node *insert(struct avl_node *tp,int x)
{
	//check for empty tree
	if(tp==NULL)
	{
		return(create_node(x));
	}
	//insert new node st proper position
	if(x<tp->data)
	{
		tp->left=insert(tp->left,x);
	}
	else
	{
		tp->right=insert(tp->right,x);
	}
	return tp;
}
//definition of inorder() function
void inorder(struct avl_node *tp)
{
	if(tp!=NULL)
	{
		inorder(tp->left);
		printf("%4d",tp->data);
		inorder(tp->right);
	}
}
int main()
{
	int x,n,i;
	/*read integers and insert into BST*/
	do
	{
		printf("1.enter elements");
		printf("2.delete elements");
		printf("enter your choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("enter number of data");
				scanf("%d",&n);
				printf("enter all the value");
				for(i=0;i<=n;i++)
				{
					printf("enter %d integer",i);
					scanf("%d",&x);
					root=insert(root,x);
					printf("\nthe nodes in bst are :\n");
					inorder(root);
				}
				break;
			case 2:
				printf("enter a number to be deleted");
				scanf("%d",&key);
				
				
		}
	}while(ch!=3);
	return(0);
}
