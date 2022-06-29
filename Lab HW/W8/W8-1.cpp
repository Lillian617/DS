/* Binary tree (L：left, V：visiting, R：right)
    二元樹實作
*/
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<queue>

using namespace std;

class Node
{
public:
	int level, data;
	Node *left, *right;
};

class Tree
{
public:
	Tree()
	{
		root = NULL;
	}
	int insert(Node *n)
	{
		insert(&root, n, 1);
	}
	void inorder(Node* root) //中序追蹤 (L -> V -> R)
	{
	    if(root){                                                     // if root != NULL
            inorder(root -> left);                                    // using recursion to the leftmost
            cout << root -> data << " " << root -> level << endl;    // print visiting node's data
            inorder(root -> right);                                  // R
	    }
	}
	void preorder(Node* root) //前序追蹤 (V -> L -> R)
	{
	    if(root){
            cout << root -> data << " " << root -> level << endl; // V
            preorder(root -> left);                               // L
            preorder(root -> right);                             // R
	    }
	}
	void postorder(Node* root) //後序追蹤 (L -> R -> V)
	{
	    if(root){
            postorder(root -> left);
            postorder(root -> right);
            cout << root -> data << " " << root -> level << endl;
	    }
	}
	void levelorder() //first layer (left -> right) -> last layer (left -> right)
	{
	    queue <Node*> q;
	    q.push(root);                                             // Start from root
	    while(!q.empty()){                                       // If queue is empty, all node in this tree have visited
            Node* cur = q.front();                               // Get fist node in the queue
            q.pop();                                             // Delete and print it
            cout << cur -> data << " " << cur -> level << endl;

            if((cur -> left)){                                   // If leftchild != NULL, push it into queue
                q.push(cur -> left);
            }
            if((cur -> right)){
                q.push(cur -> right);                            // If rightchild != NULL, push it into queue
            }
	    }
	}
	Node* getRoot(){
	    if(root){
            return root;
	    }
	}
private:
	Node *root;
	void insert(struct Node **r, struct Node *n, int level)
	{
		if(*r == NULL){
			*r = n;
			n -> level = level;}
		else if(n->data > (*r)->data)
			insert(&((*r)->right), n, level+1);
		else
			insert(&((*r)->left), n, level+1);
	}
};

int main()
{
	Tree *tree = new Tree();
	Node *node;
	int j;
	srand(time(NULL));
	for(j = 0;j < 10;j ++)
	{
		node = new Node();
		node->data = rand();
		node->left = NULL;
		node->right = NULL;
		tree->insert(node);
	}
    cout << "--print inorder--" << endl;
    tree->inorder(tree->getRoot());
	printf("\n");
    cout << "--print preorder--" << endl;
	tree->preorder(tree->getRoot());
	printf("\n");
	cout << "--print postorder--" << endl;
	tree->postorder(tree->getRoot());
	printf("\n");
    cout << "--print levelorder--" << endl;
	tree->levelorder();
	printf("\n");
}
