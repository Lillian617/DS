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
		int j, k;
		for(j = 0;j < 20;j ++)
			for(k = 0;k < 4;k ++)
				root[j][k] = -1;
	}
	int insert(int node)
	{
		int f = 0, index = 0;
		while(root[index][0] != -1)
			index ++;
		if(index >= 20)
			return -1;
		if(index == 0)
		{
			root[0][0] = 1;
			root[0][1] = node;
			return 1;
		}
		else
		{
			root[index][0] = 1;
			root[index][1] = node;
			while(1)
			{
				if(root[f][1] < node)        // 輸入的值 > visiting
				{
					if(root[f][3] == -1)
					{
						root[f][3] = index;
						return 1;
					}
					else
					{
						f = root[f][3];
					}
				}
				else                        // 輸入的值 < visiting
				{
					if(root[f][2] == -1)
					{
						root[f][2] = index;
						return 1;
					}
					else
					{
						f = root[f][2];
					}
				}
			}
		}
	}
	void inorder(int v) // L -> V -> R
	{
	    if(root[v][0])
        {
            inorder(root[v][2]);              // L
            cout << root[v][1] << endl;      // V
            inorder(root[v][3]);              // R
	    }
	}
	void preorder(int v) // V -> L -> R
	{

	    if(root[v][0])
        {
            cout << root[v][1] << endl;       // V
            preorder(root[v][2]);              // L
            preorder(root[v][3]);              // R
	    }
	}
	void postorder(int v) // L -> R -> V
	{
	    if(root[v][0])
        {
            postorder(root[v][2]);              // L
            postorder(root[v][3]);              // R
            cout << root[v][1] << endl;        // V
	    }
	}
	void levelorder()
	{
	    if(root[0][0]==-1){return;}
	    queue<int> q;
	    q.push(0);
	    while(!q.empty())
        {
            int cur = q.front();
            q.pop();
            cout << root[cur][1] << endl;
            if(root[cur][2]!=-1){
                q.push(root[cur][2]);
            }
            if(root[cur][3]!=-1){
                q.push(root[cur][3]);
            }

	    }
	}

private:
	int root[20][4];
};

int main()
{
	Tree *tree = new Tree();
	int j, node;
	srand(time(NULL));
	for(j = 0;j < 10;j ++)
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
