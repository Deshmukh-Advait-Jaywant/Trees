#include<stdio.h>
#include<stdlib.h>
struct avl_node
{
	int data;
	struct avl_node *left;
	struct avl_node *right;
	int height;
};
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
struct avl_node *root=NULL;
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
	//update heights of parent nodes
	tp->height=1+max(height(tp->left),height(tp->right));
	//update balance factor of parent
	int bal=getbal(tp);
	//check for balance factor whether it is greater than 1 or less than -1 and apply suitable rotation
	if(bal>1&&x<tp->left->data)
	{
		//right rotation
		return(rightrotation(tp));
	}
	if(bal>1&&x>tp->left->data)
	{
		//left-right rotation
		tp->left=leftrotaion(tp->left);
		return(rightrotation(tp));
	}
	if(bal<-1&&x>tp->right->data)
	{
		return(leftrotaion(tp));
	}
	if(bal<-1&&x<tp->right->data)
	{
		tp->right=rightrotation(tp->right);
		return(leftrotaion(tp));
	}
//	return tp;
}
struct avl_node *leftrotaion(struct avl_node *tp)
{
	struct avl_node *tb,*ty;
	tb=tp->right;//initialization
	ty=tb->left;//initialization
	
	tb->left=tp;
	tp->right=ty;
	//update heights of nodes
	tp->height=max(height(tp->left),height(tp->right));
	tpb->height=max(height(tpb->left),height(tpb->right));
	return (tb);
	
}
struct avl_node *rightrotation(struct avl_node *tp)
{
	struct avl_node *tpb,*tpy;
	//initialize pointers
	tpb=tp->left;
	tpy=tpb->right;
	//do right rotation
	tpb->right=tp;
	tp->left=tpy;
	//update heights of nodes
	tp->height=max(height(tp->left),height(tp->right));
	tpb->height=max(height(tpb->left),height(tpb->right));
	return (tpb);
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
int max(int x,int y)
{
	if(x>y)
	{
		return x;
	}
	else
	{
		return y;
	}
}
int height(struct avl_node *tp)
{
	if(tp==NULL)
	{
		return 0;
	}
	else
	{
		return(tp->height);
	}
}
int getbal(struct avl_node *tp)
{
	if(tp==NULL)
	{
		return 0;
	}
	else
	{
		return(height(tp->left)-height(tp->right));
	}
}
int main()
{
	int x,n,i;
	/*read integers and insert into BST*/
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
	return(0);
}
