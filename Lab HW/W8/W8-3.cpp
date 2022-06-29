#include<iostream>
#include<cstdlib>
#include<ctime>
#include<queue>

using namespace std;

class Tree
{
public:
    Tree()
    {
        int j;
        for(j = 0; j < 2000; j ++)
            root[j] = -1;
    }
    int insert(int node)
    {
        int index = 0;
        while(index < 2000 && root[index] != -1)
        {
            if(root[index] < node)
                index = index * 2 + 2;
            else
                index = index * 2 + 1;
        }
        root[index] = node;
    }

    void inorder(int v) // L -> V -> R
    {
        if(!isEmpty(v))
        {
            inorder(v * 2 + 1);              // L
            cout << root[v] << endl;        // V
            inorder(v * 2 + 2);              // R
        }
    }
    void preorder(int v) // V -> L -> R
    {

        if(!isEmpty(v))
        {
            cout << root[v] << endl;         // V
            preorder(v * 2 + 1);              // L
            preorder(v * 2 + 2);              // R
        }
    }
    void postorder(int v) // L -> R -> V
    {
        if(!isEmpty(v))
        {
            postorder(v * 2 + 1);              // L
            postorder(v * 2 + 2);              // R
            cout << root[v] << endl;          // V
        }
    }
    void levelorder()
    {
        if(isEmpty(0))
        {
            return;
        }
        queue<int> q;
        q.push(0);
        while(!q.empty())
        {
            int cur = q.front();
            q.pop();
            cout << root[cur] << endl;
            if(root[cur * 2 + 1]!=-1)
            {
                q.push(cur * 2 + 1);
            }
            if(root[cur * 2 + 2]!=-1)
            {
                q.push(cur * 2 + 2);
            }

        }
    }
    bool isEmpty(int v)
    {
        if(root[v] == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
private:
    int root[2000];
};

int main()
{
    Tree *tree = new Tree();
    int j, node;
    srand(time(NULL));
    for(j = 0; j < 10; j ++)
    {
        node = rand();
        tree->insert(node);
    }
    cout << "--print inorder--" << endl;
    tree->inorder(0);
    printf("\n");
    cout << "--print preorder--" << endl;
    tree->preorder(0);
    printf("\n");
    cout << "--print postorder--" << endl;
    tree->postorder(0);
    printf("\n");
    cout << "--print levelorder--" << endl;
    tree->levelorder();
    printf("\n");
}
