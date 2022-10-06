#include<iostream>
#include<queue>
using namespace std;

class Node{
	public:
		int data;
		Node* left;
		Node* right;
		Node(int d)
		{
			this->data=d;
			this->left=NULL;
			this->right=NULL;
		}
		
};

Node* insertToBST(Node* root,int d)
{
	if(root==NULL)
	{
		root=new Node(d);
		return root;
	}
	if(d>root->data)
	{
		root->right=insertToBST(root->right,d);
	}
	else
	{
		root->left=insertToBST(root->left,d);
	}
	return root;
}

void inOrder(Node* root)
{
	if(root==NULL)
	{
		return;
	}
	inOrder(root->left);
	cout<< root->data <<" ";
	inOrder(root->right);
}

void preOrder(Node* root)
{
	if(root==NULL)
	{
		return;
	}
	cout<< root->data <<" ";
	preOrder(root->left);
	preOrder(root->right);
}

void postorder(Node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root-> data << " ";

}

void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) { 
            //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) { 
                //queue still has some child ndoes
                q.push(NULL);
            }  
        }
        else{
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }
}

void takeInput(Node* &root)
{
	int data;
	cin>>data;
	while(data!=-1){
		root=insertToBST(root,data);
		cin>>data;
	}
}

Node* minValue(Node* root)
{
	Node* temp=root;
	while(temp->left!=NULL)
	{
			temp=temp->left;
	}
	return temp;
}

Node* maxValue(Node* root)
{
	Node* temp=root;
	while(temp->right!=NULL)
	{
			temp=temp->right;
	}
	return temp;
}

Node* deleteBST(Node* root,int val)
{
	//base case
	if(root==NULL)
	{
		return root;
	}
	if(root->data==val)
	{
		//0 child
		if(root->left==NULL && root->right==NULL)
		{
			delete root;
			return NULL;
		}
		//1 child left part
		if(root->left!=NULL && root->right==NULL)
		{
			Node* temp=root->left;
			delete root;
			return temp;
		}
		//1 child right part
		if(root->left==NULL && root->right!=NULL)
		{
			Node* temp=root->right;
			delete root;
			return temp;
		}
		//2 child
		if(root->left!=NULL && root->right!=NULL)
		{
			int mini=minValue(root->right)->data;
			root->data=mini;
			root->right=deleteBST(root->right,mini);
			return root;
		}
	}
	else if(root->data >val)
	{
		root->left=deleteBST(root->left,val);
		return root;
	}
	else
	{
		root->right=deleteBST(root->right,val);
		return root;
	}
}


int main()
{
	Node* root=NULL;
	cout<<"Enter data for BST"<<endl;
	takeInput(root);
	cout<<"----Printing BST----"<<endl;
	levelOrderTraversal(root);
	cout<<endl<<"Printing Inorder"<<endl;
	inOrder(root);
	cout<<endl<<"Printing PreOrder"<<endl;
	preOrder(root);
	cout<<endl<<"Printing PostOrder"<<endl;
	postorder(root);
	cout<<endl;
	cout<<"Minimum value of tree "<<minValue(root)->data <<endl;
	cout<<"Maximum value of tree "<<maxValue(root)->data <<endl;
	deleteBST(root,30);
	cout<<"----Printing BST----"<<endl;
	levelOrderTraversal(root);
	cout<<endl<<"Printing Inorder"<<endl;
	inOrder(root);
	return 0;
}
