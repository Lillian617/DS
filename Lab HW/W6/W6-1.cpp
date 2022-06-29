/* Maze in stack
   用堆疊儲存。
*/
#include<iostream>
#include<cstdlib>
#include<ctime>

#define SIZE 10

using namespace std;

class Node
{
public:
    Node(): Node(0, 0)
    {
    }
    Node(int r, int c)
    {
        row = r;
        col = c;
    }
    int getRow() const
    {
        return row;
    }
    int getCol() const
    {
        return col;
    }
    void setRow(int r)
    {
        if(r >= 0 && r < SIZE)
            row = r;
    }
    void setCol(int c)
    {
        if(c >= 0 && c < SIZE)
            col = c;
    }
private:
    int col, row;
};

class List
{
public:
    List()
    {
        top = -1;
    }
    /*
    function addElement
    Insert an element into list
    */
    void addElement(int r, int c)
    {
        if(top != SIZE * SIZE - 1)
        {
            Node new_node = Node(r, c);
            data[++top] = new_node;
        }
    }
    /*
    function removeElement
    remove an element from list and return a pointer point to the element.
    If list is empty, return NULL.
    */
    Node *removeElement()
    {
        if(top == -1)
        {
            return NULL;
        }
        else
        {
            return &data[top--];
        }
    }
    Node *topElement()
    {

        return &data[top];

    }
    void printList()
    {
        int j;
        if (getTop())
        {
            cout << "NULL" << endl;
            return;
        }
        for(j = 0; j < top; j ++)
        {
            cout<<"("<<data[j].getRow()<<", "<<data[j].getCol()<<")"<<endl;
        }
    }
    bool getTop(){
        return top == -1;
    }

private:
    Node data[SIZE * SIZE];
    int top;
};

class Maze
{
public:
    Maze()
    {
        initMaze(SIZE);
    }
    /*
    function initMaze
    Alocate a 2-D array with s * s sizes
    Inside the maze where 0 represent empty space and 1 represent wall.
    [0][0] is start point and [s - 1][s - 1] is finish point.
    Randomly generate 20% wall in the maze.
    Make sure [0][0] and [s - 1][s - 1] are 0

    動態配置一個二維的陣列，大小是 s * s ，用這個陣列表示迷宮的地圖
    陣列中 0 的值表示可以移動的空間， 1 表示牆壁
    [0][0] 的位置表示起點 [s - 1][s - 1] 的位置表示終點
    請在迷宮中加入 20% 的牆壁
    然後確定起點跟終點都是可以移動的位置
    */
    void initMaze(int s)
    {
        maze = new int* [s];
        int* row = new int [s * s];
        for (int i = 0; i < s; i++)
        {
            maze[i] = row + i * s;
        }
        for(int i = 0; i < s; i++)
        {
            for(int j = 0; j < s; j++)
            {
                maze[i][j] = 0;
            }
        }
        //Generate 20% wall in the maze "randomly".Make sure [0][0] and [s - 1][s - 1] are 0
        srand(time(NULL));
        maze[0][0] = 2;
        maze[s-1][s-1] = 2;

        int wall = 0.2 * (s * s);
        while(wall > 0)
        {
            int random_row = rand() % 10;
            int random_col = rand() % 10;
            if(maze[random_row][random_col] == 0)
            {
                maze[random_row][random_col] = 1;
                wall--;
            }
        }
        maze[0][0] = 0;
        maze[s-1][s-1] = 0;
    }
    /*
    function getPath
    This function will find a path between start point and finish point.
    Return a list content the path information inside.
    If there is no path between two point then the list will be empty.

    這個函數會找到起點到終點間的一條路徑
    回傳一個 list， List 包含路徑的資訊
    如果找不到路徑的話 list 就會是空的
    */
    List *getPath()
    {
        List *path = new List();
        path -> addElement(0, 0);
        while(!(path -> getTop()))
        {
            int r = path -> topElement() -> getRow(); //up and down
            int c = path -> topElement() -> getCol(); //left and right

            //順序：上下左右

            if((r+1) < SIZE && maze[r+1][c] == 0)
            {
                maze[++r][c] = 2;
                path -> addElement(r, c);
                if(r == SIZE - 1 && c == SIZE -1)
                {
                    break;
                }
            }
            else if((c+1) < SIZE && maze[r][c+1] == 0)
            {
                maze[r][++c] = 2;
                path -> addElement(r, c);
                if(r == SIZE - 1 && c == SIZE -1)
                {
                    break;
                }
            }
            else if((r-1) >= 0 && maze[r-1][c] == 0)
            {
                maze[--r][c] = 2;
                path -> addElement(r, c);
                if(r == SIZE - 1 && c == SIZE -1)
                {
                    break;
                }
            }
            else if((c-1) >= 0 && maze[r][c-1] == 0)
            {
                maze[r][--c] = 2;
                path -> addElement(r, c);
                if(r == SIZE - 1 && c == SIZE -1)
                {
                    break;
                }
            }
            else
            {
                path -> removeElement();
            }
        }
        return path;
    }
    void printMaze()
    {
        int j, k;
        for(j = 0; j < SIZE; j ++)
        {
            for(k = 0; k < SIZE; k ++)
            {
                if(maze[j][k] == 0)
                    cout<<" 0 ";
                else if(maze[j][k] == 1)
                    cout<<" 1 ";
                else if(maze[j][k] == 2)
                    cout<<" 2 ";
            }
            cout<<"\n";
        }
    }
private:
    int **maze;
};

int main()
{
    Maze *maze = new Maze();
    maze -> printMaze();
    maze -> getPath() -> printList();
    maze -> printMaze();
}

