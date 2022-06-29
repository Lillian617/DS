#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <ctime>
#include <queue>

using namespace std;

template<class T>
class Node
{
public:
    Node()
    {
        data = new T;
    }
    Node(T d)
    {
        data = new T;
        (*data) = d;
    }
    Node &operator=(T d)
    {
        (*data) = d;
        return *this;
    }
    friend std::ostream &operator<<(std::ostream &out, Node n)
    {
        out<<*(n.data);
        return out;
    }
    friend std::ostream &operator<<(std::ostream &out, Node *n)
    {
        out<<*(n->data);
        return out;
    }
    void setData(T d)
    {
        *data = d;
    }
    T &getData() const
    {
        return *data;
    }
protected:
    T *data;
};

template<class T>
class ListNode : public Node<T>
{
public:
    ListNode() : Node<T>()
    {
        prev = NULL;
        next = NULL;
    }
    ListNode(T d) : Node<T>(d)
    {
        prev = NULL;
        next = NULL;
    }
    ListNode(ListNode *p, ListNode *n) : Node<T>()
    {
        prev = p;
        next = n;
    }
    ListNode(T d, ListNode *p, ListNode *n) : Node<T>(d)
    {
        prev = p;
        next = n;
    }
    ListNode *getNext() const
    {
        return next;
    }
    ListNode *getPrev() const
    {
        return prev;
    }
    void setNext(ListNode *n)
    {
        next = n;
    }
    void setPrev(ListNode *p)
    {
        prev = p;
    }
    ListNode &operator=(T d)
    {
        this->setData(d);
        return *this;
    }
private:
    ListNode *prev, *next;
};

template<class T>
class LinkList
{
public:
    LinkList()
    {
        head = NULL;
        tail = NULL;
    }
    void addFromHead(T d)
    {
        ListNode<T> *node = new ListNode<T>(d);
        if(head != NULL)
        {
            head->setPrev(node);
        }
        node->setNext(head);
        head = node;
        if(tail == NULL)
            tail = node;
    }
    void addFromTail(T d)
    {
        ListNode<T> *node = new ListNode<T>(d);
        if(tail != NULL)
        {
            tail->setNext(node);
        }
        node->setPrev(tail);
        tail = node;
        if(head == NULL)
            head = node;
    }
    void addAfter(ListNode<T> *at, T d)
    {
        if(!exist(at))
            return;
        ListNode<T> *node = new ListNode<T>(d);
        if(at->getNext() != NULL)
            at->getNext()->setPrev(node);
        node->setNext(at->getNext());
        at->setNext(node);
        node->setPrev(at);
        if(node->getNext() == NULL)
            tail = node;
    }
    ListNode<T> *removeFromHead()
    {
        ListNode<T> *n = head;
        if(head != NULL)
        {
            head = head->getNext();
            if(head != NULL)
                head->setPrev(NULL);
            else
                tail = NULL;
            n->setNext(NULL);
        }
        return n;
    }
    ListNode<T> *removeFromTail()
    {
        ListNode<T> *n = tail;
        if(tail != NULL)
        {
            tail = tail->getPrev();
            if(tail != NULL)
                tail->setNext(NULL);
            else
                head = NULL;
            n->setPrev(NULL);
        }
        return n;
    }
    ListNode<T> *remove(ListNode<T> *n)
    {
        if(!exist(n))
            return NULL;
        if(n == head)
            return removeFromHead();
        if(n == tail)
            return removeFromTail();
        n->getPrev()->setNext(n->getNext());
        n->getNext()->setPrev(n->getPrev());
        n->setNext(NULL);
        n->setPrev(NULL);
        return n;
    }
    ListNode<T> *exist(T d)
    {
        ListNode<T> *j = head;
        while(j != NULL)
        {
            if(j->getData() == d)
                return j;
            j = j->getNext();
        }
        return NULL;
    }
    bool exist(ListNode<T> *n)
    {
        ListNode<T> *j = head;
        while(j != NULL)
        {
            if(j == n)
                return true;
            j = j->getNext();
        }
        return false;
    }
    ListNode<T> &operator[](int i)
    {
        ListNode<T> *j = head;
        int k;
        for(k = 0; k < i && j != NULL; k ++)
            j = j->getNext();
        if(j == NULL)
            throw std::invalid_argument("index does not exist.");
        return *j;
    }
    void print() const
    {
        ListNode<T> *j;
        j = head;
        while(j != NULL)
        {
            std::cout<<(*j)<<" ";
            j = j->getNext();
        }
        std::cout<<std::endl;
    }
protected:
    ListNode<T> *head, *tail;
};

/*
	Please finish the TreeNode class, TreeNode class respresent a node in a general tree.
	A general tree is different from binary tree, every node in binary tree have at most two child node, but a node in general tree may have more than two child node.
*/
template<class T>
class TreeNode : public Node<T>
{
public:
    TreeNode() : Node<T>()
    {
        child = new LinkList<TreeNode<T> *>();
    }
    TreeNode(T d) : Node<T>(d)
    {
        child = new LinkList<TreeNode<T> *>();
    }
    /*
    	Add a child to this node.
    */
    void addChild(TreeNode *n)
    {
        child -> addFromTail(n);
    }
    /*
    	Add a child to this node.
    */
    void addChild(T d)
    {
        child -> addFromTail(new TreeNode<T> (d));
    }
    /*
    	Return the nth child of the node.
    */
    TreeNode<T> *operator[](int n)
    {
        return (*child)[n].getData();
    }


private:
    LinkList<TreeNode<T> *> *child;
};

/*
	Please finish the Tree class. Tree class respresent a general tree, that means node on this tree may have more than two child node.

*/
template<class T>
class Tree
{
public:
    Tree()
    {
        root = NULL;
    }
    /*
    	return the nth node on this tree with level order.
    */
    TreeNode<T> *operator[](int n)
    {
        if(root == NULL)
        {
            return NULL;
        }
        queue <TreeNode<T> *> q;
        q.push(root);
        TreeNode<T> *cur = q.front();
        q.pop();

        for(int i = 0; i < n; i++)
        {
            int j = 0;
            while(1)
            {
                try
                {
                    TreeNode<T> *tt = (*cur)[j]; // check if the child of current node exists.
                    q.push(tt);
                }
                catch(invalid_argument e)
                {
                    break;
                }
                j++;
            }
            cur = q.front();
            q.pop();
        }
        return cur;             //new number will be the child of current node.
    }
    /*
    	return the number of nodes on this tree.
    */
    int count()
    {
        if(root == NULL)
        {
            return 0;
        }
        queue <TreeNode<T> *> q;
        q.push(root);
        int counts = 0;

        while(!q.empty()){
            int sz = q.size();
            counts += sz;
            for(int i = 0; i < sz; i++){
                int j = 0;
                TreeNode<T> *cur = q.front();
                q.pop();
                while(1)
                {
                    try
                    {
                        TreeNode<T> *tt = (*cur)[j];
                        q.push(tt);
                    }
                    catch(invalid_argument e)
                    {
                        break;
                    }
                    j++;
                }
            }
        }
        return counts;
    }
    /*
    	print all the node on this tree with level order.
    */
    void levelOrder()
    {
        cout << "LevelOrder: ";
        if(root == NULL)
        {
            cout << "The tree does not exists!";
        }
        queue <TreeNode<T> *> q;
        q.push(root);

        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                int j = 0;
                TreeNode<T> *cur = q.front();
                q.pop();
                cout << cur << " ";
                while(1)
                {
                    try
                    {
                        TreeNode<T> *tt = (*cur)[j];
                        q.push(tt);
                    }
                    catch(invalid_argument e)
                    {
                        break;
                    }
                    j++;
                }
            }
        }
    }
    /*
    	print all the node on this tree with preorder.
    */
    void preorder(TreeNode<T> *cur)
    {
        if(root == NULL)
        {
            cout << "The tree does not exists!";
        }
        cout << cur << " ";
        int j = 0;
        while(1)
        {
            try
            {
                preorder((*cur)[j]);
            }
            catch(invalid_argument e)
            {
                break;
            }
            j++;
        }
    }
    /*
    	print all the node on this tree with postorder.
    */
    void postorder(TreeNode<T> *cur)
    {
        if(root == NULL)
        {
            cout << "The tree does not exists!";
        }
        int j = 0;
        while(1)
        {
            try
            {
                postorder((*cur)[j]);
            }
            catch(invalid_argument e)
            {
                break;
            }
            j++;
        }
        cout << cur << " ";
    }
    /*
    	set the root of this tree.
    */
    void setRoot(T d)
    {
        root = new TreeNode<T> (d);
    }
    TreeNode<T> *getRoot()
    {
        if(root)
        {
            return root;
        }
    }
private:
    TreeNode<T> *root;
};

int main()
{
    Tree<int> *tree = new Tree<int>();
    srand(0);
    int j, k, i;
    for(j = 0; j < 10; j ++)
    {
        i = rand() % 100;
        if(tree->count() == 0)
        {
            cout << "node" << j << "\nNumber = " << i << endl;
            tree->setRoot(i);
        }
        else
        {
            k = rand() % tree->count();
            cout << "node" << j << "\nk = " << k << ", the child of number " << (*tree)[k] << ", number = " << i << endl;
            (*tree)[k]->addChild(i);
        }
    }
    cout << "Count: " << tree -> count() << endl;
    cout << "-----------------------------------\n";
    tree->levelOrder();
    cout << "\n\n";
    cout << "PreOrder: ";
    tree->preorder(tree->getRoot());
    cout << "\n\n";
    cout << "PostOrder: ";
    tree->postorder(tree->getRoot());
    cout << endl;
    return 0;
}
