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
			if(root == NULL) return NULL;
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
			if(current != NULL)
				{
				if(current -> left != NULL) find_min(current -> left);
				if(current -> left == NULL)return current;
				}
			else return NULL;
		}
	void replace_at_parent(node * d, node * r)
		{
			if(r == NULL) 
			{	
				if(d->parent->right == d)d->parent->right=NULL;
				if(d->parent->left == d)d->parent->left = NULL;
				delete d;
			}
			else{
			if(d != root)
			{
				if(d->parent->left == d) d->parent->left = r;
				else if(d->parent->right == d) d->parent->right = r;
				if(r!= NULL)
				{
					r->parent = d->parent;
				}
			}
			else root = r;
			}
		}
	void delnode(int value)
		{
			node * del = search(value);
			
			if(del != NULL)
				{
					node* temp = NULL;
					if(del -> left != NULL and del-> right != NULL)//for two child
					{
						temp = find_min(del->right);//store the right of del's minimum in a pointer
						replace_at_parent(del, temp);//use replace at parent with the del and new
						temp->left = del-> left;//give the right child
						del->left->parent = temp;//give the right child its parent
						if(del->right != temp)//if it itslf is not the right child 
						{
							temp-> right = del->right;//give it the right child
							del->right->parent = temp;//give that child the parent
						}
						delete del;
					}
					else//else //if no child do nothing
					{
						if(del->left== NULL and del->right == NULL);
						else if(del->left == NULL)//elif no left child 
						{temp=del->right;}//save right child in a temo
						else if (del-> right == NULL)
						{temp=del->left;}//eif no right child save in a temp
						replace_at_parent(del, temp);//then replace with del with the temp
					}
					if(del == root)root = temp; 
					
				}
				else cout<< "Can't delete in an empty tree "<<endl; 
			
		}
	};
	

int main()
	{
		BiST t1;
    t1.insert(4);
    t1.insert(2);
    t1.insert(3);
    t1.insert(1);
    t1.insert(6);
    t1.insert(5);
    t1.insert(7);
    t1.insert(8);
    t1.display();
    if(t1.search(3) != NULL){
        cout << endl << t1.search(3)->data << endl;
    }
    t1.delnode(5);
   	t1.display();
    cout << "Deleting 6" << endl;
   	t1.delnode(6);
    cout << "Deleting 2" << endl;
    t1.delnode(2);
    t1.display();
    t1.delnode(4);
    t1.display();
    t1.delnode(7);
    t1.display();
    t1.delnode(8);
    t1.display();
    t1.delnode(3);
    t1.display();
    t1.delnode(1);
    t1.display();
    t1.delnode(1);
    
} 
