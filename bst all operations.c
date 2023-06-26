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
void inorder();
int search();
void deleted();
void main()
{
	int n,ch,i,total,val,key,x;
	do
	{
	printf("\n1.insert");
	printf("\n2.search");
	printf("\n3.delete leaf node");
	printf("\n4.exit");
	printf("\nenter your choice");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("enter total number of elements");
			scanf("%d",&total);
			for(i=0;i<total;i++)
			{
				printf("\nenter a number : ");
				scanf("%d",&n);
				insert(n);
			}
			inorder(root);
			break;
		case 2:
			printf("\nenter the element to search : ");
			scanf("%d",&key);
			val=search(key);
			if(val==1)
			{
				printf("\nPRENSENT");
			}
			else
			{
				printf("\nNOT PRESENT");
			}
			break;
		case 3:
			printf("enter the number to be deleted : ");
			scanf("%d",&x);
			deleted(x);
			inorder(root);
			break;
		case 4:
			exit(0);
			break;
	}
	}while(ch!=4);
}
void insert(int n)
{
	struct tnode *tp,*lp,*lpp;
	tp=(struct tnode *)malloc(sizeof(struct tnode));
	if(tp==NULL)
	{
		printf("tree is full");
	}
	tp->data=n;
	tp->left=NULL;
	tp->right=NULL;
	if(root==NULL)
	{
		root=tp;
		return;
	}
	else
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
int search(int key)
{
	struct tnode *tp;
	tp=root;
	while(tp!=NULL)
	{
		if(key==tp->data)
		{
			return 1;
		}
		 else if(tp->data<key)
		{
			tp=tp->right;
		}
		else
		{
			tp=tp->left;
		}
	}
	if(tp!=NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void inorder(struct tnode *tp)
{
	if(tp!=NULL)
	{
		inorder(tp->left);
		printf("%4d",tp->data);
		inorder(tp->right);
	}
}
void deleted(int x)
{
	struct tnode *tp,*pp,*mp,*pmp;
	tp=root;
	pp=NULL;
	while(tp->data!=x && tp!=NULL)
	{
		pp=tp;
		if(x<tp->data)
		{
			tp=tp->left;
		}
		else
		{
			tp=tp->right;
		}
	}
	if(tp->left==NULL && tp->right==NULL)
	{
		printf("*111_________________");
		if(tp==pp->left)
		{
			pp->left=NULL;
			free(tp);
		}
		else
		{
			pp->right=NULL;
			free(tp);
		}
	}
	else if(tp->left==NULL || tp->right==NULL)
	{
		printf("************222");
		if(tp=pp->left)
		{
			printf("************333");
			if(tp->left!=NULL)
			{
				printf("************444");
				pp->left=tp->left;
				free(tp);
			}
			else
			{
				printf("************555");
				pp->left=tp->right;
				free(tp);
			}
		}
		else
		{
			if(tp->left!=NULL)
			{
				pp->right=tp->left;
				free(tp);
			}
			else
			{
				pp->right=tp->right;
				free(tp);
			}
		}
	}
	else
	{
		mp=tp->left;
		while(mp->left!=NULL)
		{
			pmp=mp;
			mp=mp->right;
		}                                                                                                                        
		tp->data=mp->data;
		pmp->right=NULL;
		free(mp);
	}

}
