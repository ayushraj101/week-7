#include<iostream>
using namespace std;

class node {
	public:
	int data;
	node * right;
	node * left;
	node * parent;
	node(int value)
		{
			data = value;
			right = NULL;
			left = NULL;
			parent = NULL;
		}
	};
	
class BiST{
	public:
	node * root;
	BiST()
		{
			root = NULL;
		}
	void insert (int value)
		{
			if(root == NULL)
			root = new node(value);
			else insert2(value, root);
		}
	void insert2(int value, node * current)
		{
			if (value < current -> data)
				{
					if(current -> left == NULL)
					{current -> left = new node(value);
					current -> left -> parent = current;}
					else 
					insert2(value, current -> left);
				}
			else 
				{
					if (current -> right == NULL)
					{current -> right = new node(value);
					current -> right -> parent = current;}
					else insert2(value, current -> right);
				}
		}
	void display2(node* current)
		{
			if(current -> left != NULL)
			{display2(current -> left);}
			cout << current->data<<",";
			if(current -> right != NULL)
			{display2(current -> right);}
		}
	void display()
		{
			if(root == NULL)
				cout<< "The tree is empty\n";
			
			else display2(root);
			cout<<endl;
		}
	node * search(int value)
		{
			node * m = search2(value, root);
			if(m == NULL) 
			{cout<< "THis element is not present in the tree\n";
			return m;}	
			else return search2(value, root); 
		}
	node * search2(int value, node * current)
		{
			if(current->data == value)
			{return current;}
			else if(value < current -> data)
				{
					if (current -> left == NULL)
					return NULL;
					else search2(value, current -> left);
				}
			else
				{
					if(current -> right == NULL)
					return NULL;
					else search2(value, current -> right);
				}
		}
	node * find_min(node *current)
		{
			if(current -> left != NULL) find_min(current -> left);
			if(current -> left == NULL)return current;
		}
	void replace_at_parent(node * temp, node * current)
		{
			
			/* if(temp -> left == NULL and temp -> right == NULL)
			{
				if(current == root ) root = temp;
				if(temp == root ) root = current;
				temp -> left = current -> left;
				temp -> right = current -> right;
				node * par = temp -> parent ; 
				temp -> parent = current -> parent;
				current -> left = NULL;
				current -> left = NULL;
				current -> parent = temp -> parent;
			}
			else if(temp -> left != NULL or temp -> right != NULL)
			{
				if(current == root ) root = temp;
				if(temp == root ) root = current;
				
			}*/
			
			node * lef, * rig, * par;
			lef = temp-> left;
			rig = temp-> right;
			par = temp -> parent;
			temp -> left = current -> left;
			temp -> right = current -> right;
			temp -> parent = current -> parent;
			current -> left = lef;
			current -> right = rig;
			current -> parent = par;
			if(current == root ) root = temp;
			if(temp == root ) root = current;
			}	
	
	};
	

int main()
	{
		BiST t1;
		//for(int i=0; i< 10; i++)
		//{
		//	t1.insert(i);
		//}
		//
		//t1.display();
		//t1.insert(2);
		//t1.insert(26);
		//t1.display();
		t1.insert(7);
		t1.insert(4);
		t1.insert(98);
		t1.insert(1);
		t1.insert(5);
		t1.display();
		t1.replace_at_parent(t1.root, t1.root->right);
		cout<< t1.root-> data<<endl;
		t1.display();
		return 0;
	}	
	
	
	
	
	
	
