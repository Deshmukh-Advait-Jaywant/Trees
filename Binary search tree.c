#include<stdio.h>
#include<stdlib.h>
struct tnode
{
	int data;
	struct tnode *left;
	struct tnode *right;
};
struct tnode *root=NULL;
void insert();
void In_ordertraversal(struct tnode *tp);
void pre_ordertraversal(struct tnode *tp);
void post_ordertraversal(struct tnode *tp);
int search(int );
int deleted();
int main()
{   
    int n,ch,x,key,r;
    do
    {
    printf("\n|---------------------------------------  |\n");
	printf("|               MENU                      |\n");
	printf("|---------------------------------------  |\n");
	printf("|enter 1 for insert operation             |\n");
    printf("|enter 2 for inorder traversal operation  |\n");
    printf("|enter 3 for postorder traversal operation|\n");
    printf("|enter 4 for preorder traversal operation |\n");
    printf("|enter 5 for search operation		  |\n");
    printf("|enter 6 for delete operation		  |\n");
	printf("|enter 7 for exit operation               |\n");
	printf("|---------------------------------------  |\n"); 
    printf("Enter your choice:");
    scanf("%d",&n);
    switch(n)
    {
    case 1:
	    printf("\nEnter the value:\n");
		scanf("%d",&x);
		insert(x);
		printf("\n...The value is inserted...\n");
	    break;
   case 2:
		In_ordertraversal(root);
		break;
	case 3:
		pre_ordertraversal(root);
		break;
	case 4:
		post_ordertraversal(root);
		break;
	case 5:
		printf("\nenter the key value : ");
		scanf("%d",&key);
		r=search(key);
		printf("%d***********",r);
		if(r==1)
		{
			printf("\nelement found");
		}
		else
		{
			printf("\nelement not found");
		}
		break;
	case 6:
		deleted();
		break;
	case 7:
		printf("\n...Program is going to be stopped...\n");
		break;
    }
    }while(ch!=7);
}
int search(int key)
{
	struct tnode *tp;
	tp=root;//start searching from root
	while(tp!=NULL)
	{
		if(key==tp->data)
		{
			return 1;
		}
		else if(key<tp->data)//move to left child
		{
			tp=tp->left;
		}
		else//move to right child
		{
			tp=tp->right;
		}
	}
	if(tp!=NULL)
	{
		return 1;
	}
	else
	{
		return (0);
	}
}
void pre_ordertraversal(struct tnode *tp)
{
	if(tp!=NULL)
	{
		printf("%4d",tp->data);
		pre_ordertraversal(tp->left);
		pre_ordertraversal(tp->right);
	}
}
void post_ordertraversal(struct tnode *tp)
{
	if(tp!=NULL)
	{
		post_ordertraversal(tp->left);
		post_ordertraversal(tp->right);
		printf("%4d",tp->data);
	}
}
void insert(int x)
{
	struct tnode *tp,*lp,*lpp;
	tp=(struct tnode*)malloc(sizeof(struct tnode));
	if(tp==NULL)
	{
		printf("\n...BST is FULL...\n");
		return;
	}
	tp->data=x;
	tp->left=NULL;
	tp->right=NULL;
	if(root==NULL)  //BST is empty
	{
		root=tp;   //Add NewNode(NN) as root
		return;
	}
	else //BST is not empty
	{
		lp=root;
		lpp=NULL;
		while(lp!=NULL)
		{
			lpp=lp;
			if(tp->data<lp->data)
			{
				lp=lp->left;
			}
			else
			{
				lp=lp->right;
			}
		}
		//Add NN to lpp as left or right Child
		if(tp->data<lpp->data)
		{
			lpp->left=tp;
		}
		else
		{
			lpp->right=tp;
		}
	}
}
void In_ordertraversal(struct tnode *tp)
{
	if(tp!=NULL)
	{
		In_ordertraversal(tp->left);
		printf("%4d",tp->data);
		In_ordertraversal(tp->right);
	}		
}

