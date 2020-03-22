//题目描述：一颗二叉树，将从根结点到指定结点的路径上的结点一次入栈
//2015 966 三.2




#include <iostream>
#include <stack>
#include <algorithm>
#include <stdio.h>

using namespace std;

typedef struct node
{
    char data;
    node *left,*right;
}node;

node* Create1(node* root)  //先根建树
{
	char ch = getchar();
	getchar();
	if (ch == '#')
	{
		root = NULL;
		return (root);
	}

	else
	{
		root = new node;
		root->data = ch;
		root->left = Create1(root->left);
		root->right = Create1(root->right);
		return (root);
	}
}//Create1 先序 递归

void previs(node* root)
{
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    previs(root->left);
    previs(root->right);
}

stack <node*> search1(node *root,char p,int n)
{
    bool vis[n+1];
    fill(vis,vis+n+1,0);
    stack <node*> st;
    st.push(root);
    while(!st.empty())
    {
        node *temp=st.top();
        if(temp->data==p)
            break;
        else if((temp->left==NULL&&temp->right==NULL)||vis[temp->data-'0']==1)  //如果是叶子结点或已经标记过，出栈
            st.pop();
        else //标记该结点并将右左孩子入栈
        {
            vis[temp->data-'0']=1;
            if(temp->right!=NULL&&vis[temp->right->data-'0']==0)
            {
                st.push(temp->right);
            }
            if(temp->left!=NULL&&vis[temp->left->data-'0']==0)
            {
                st.push(temp->left);
            }
        }
    }
    return st;
}

int main()
{
    node *root=Create1(root);
    stack <node*> st=search1(root,'5',7);
    while(!st.empty())
    {
        cout<<st.top()->data<<" ";
        st.pop();
    }
    return 0;
}
