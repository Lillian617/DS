/* Maze in Dynamic Programming Algorithm(DPA) to store each grid's informations of four directions(0 or 1)
   用動態規劃演算法來先儲存每一個網格的四個方位各自的資訊(路或牆).
*/
#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

#define SIZE 10
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

class Grid
{
public:
    Grid(): Grid(0)
    {
    }
    Grid(int s)
    {
        state = s;  //自己的格子的資訊。
        dir[UP] = NULL;
        dir[DOWN] = NULL;
        dir[LEFT] = NULL;
        dir[RIGHT] = NULL;
    }
    Grid *getDir(int d) const
    {
        return dir[d];
    }
    int getState() const
    {
        return state;
    }
    void setDir(int d, Grid *g)
    {
        dir[d] = g;
    }
    void setState(int s)
    {
        state = s;
    }
private:
    Grid *dir[4];
    int state;
};

class List
{
public:
    List()
    {
        top = -1;
    }
    /*
    Insert an element from top
    */
    void addElement(Grid *g)
    {
        if(!(isFull()))
        {
            data[++top] = g;
        }
    }
    /*
    remove an element from top and return a pointer point to the element.
    If list is empty, return NULL.
    */
    Grid *removeElement()
    {
        if(top == -1)
        {
            return NULL;
        }
        else
        {
            return data[top--];
        }
    }

    Grid *topElement()
    {
        return data[top];
    }
    int gettop()
    {
        return top;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == SIZE * SIZE -1;
    }

    void printPath() const
    {
        int j;
        if(top == -1)
        {
            cout << "NULL" << endl;
            return;
        }
        cout<< "--------Path--------"<<endl;
        for(j = 1; j < top; j ++)
        {
            if(data[j] == data[j - 1]->getDir(UP))
            {
                cout<<data[j]<<"UP"<<data[j-1]<<endl;
            }
            else if(data[j] == data[j - 1]->getDir(DOWN))
            {
                cout<<"DOWN\n";
            }
            else if(data[j] == data[j - 1]->getDir(LEFT))
            {
                cout<<"LEFT\n";
            }
            else if(data[j] == data[j - 1]->getDir(RIGHT))
            {
                cout<<"RIGHT\n";
            }
        }
        cout<< "--------------------"<<endl;
    }
private:
    Grid *data[SIZE * SIZE];
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
    Alocate a 2-D link list with s * s sizes as the map of maze.
    Inside the maze enery gird with state 0 represent empty space and 1 represent wall.
    The gird in left top is start point and right bottom is finish point.
    Randomly generate 20% wall in the maze.
    Make sure start point and finish point are 0

    動態配置一個二維的鏈結串列，大小是 s * s，用這個鏈結串列表示迷宮的地圖
    節點中 0 的值表示可以移動的空間， 1 表示牆壁
    左上角的位置表示起點，右下角的位置表示終點
    請在迷宮中加入 20% 的牆壁
    然後確定起點跟終點都是可以移動的位置
    */
    void initMaze(int s)
    {
        Grid **m = new Grid *[s];
        Grid *row = new Grid [s * s];
        for(int i = 0; i < s; i++)
        {
            m[i] = row + i * s;
        }

        //Set the wall
        for(int i = 0; i < s; i++)
        {
            for(int j = 0; j < s; j++)
            {
                m[i][j] = 0;
            }
        }
        m[0][0] = 2;
        m[s - 1][s - 1] = 2;
        srand(time(NULL));
        int wall = s * s * 0.2;
        while(wall > 0)
        {
            int random_r = rand() % 10;
            int random_c = rand() % 10;
            if(m[random_r][random_c].getState() == 0)
            {
                m[random_r][random_c] = 1;
                wall--;
            }
        }
        m[0][0] = 0;
        m[s - 1][s - 1] = 0;

        /*add the informations of four directions around the grids*/
        for(int x = 0; x < s; x++)
        {
            for(int y = 0; y < s; y++)
            {
                if(x == 0)
                {
                    m[x][y].setDir(UP, NULL);
                }
                else
                {
                    m[x][y].setDir(UP, &m[x-1][y]);
                }

                if(y == 0)
                {
                    m[x][y].setDir(LEFT, NULL);
                }
                else
                {
                    m[x][y].setDir(LEFT, &m[x][y-1]);
                }

                if(x == s - 1)
                {
                    m[x][y].setDir(DOWN, NULL);
                }
                else
                {
                    m[x][y].setDir(DOWN, &m[x+1][y]);
                }

                if(y == s - 1)
                {
                    m[x][y].setDir(RIGHT, NULL);
                }
                else
                {
                    m[x][y].setDir(RIGHT, &m[x][y+1]);
                }
            }
        }
        maze = m[0];
    }
    /*
    function getPath
    This function will find a path between start point and finish point.
    Return a list content the path information inside.
    If there is no path between two point then the list will be empty.

    這個函數會找到起點到終點間的一條路徑
    回傳一個 list 包含著路徑的資訊
    如果找不到路徑的話 list 就會是空的
    */
    List *getPath()
    {
        List *path = new List();
        maze -> setState(2);
        path -> addElement(maze);
        while(!(path -> isEmpty()))
        {
            Grid *check = path -> topElement();

            if(check -> getDir(RIGHT) && check -> getDir(RIGHT) -> getState() == 0)
            {
                check = check -> getDir(RIGHT);
                check -> setState(2);
                //cout<<"data"<<path -> gettop()<<"R"<<endl;
                path -> addElement(check);
                if(!(check -> getDir(RIGHT)) && !(check -> getDir(DOWN)))
                {
                    break;
                }
            }

            else if(check -> getDir(DOWN) && check -> getDir(DOWN) -> getState() == 0)
            {
                check = check -> getDir(DOWN);
                check -> setState(2);
                //cout<<"data"<<path -> gettop()<<"D"<<endl;
                path -> addElement(check);
                if(!(check -> getDir(RIGHT)) && !(check -> getDir(DOWN)))
                {
                    break;
                }
            }

            else if(check -> getDir(LEFT) && check -> getDir(LEFT) -> getState() == 0)
            {
                check = check -> getDir(LEFT);
                check -> setState(2);
                //cout<<"data"<<path -> gettop()<<"L"<<endl;
                path -> addElement(check);
                if(!(check -> getDir(RIGHT)) && !(check -> getDir(DOWN)))
                {
                    break;
                }
            }

            else if(check -> getDir(UP) && check -> getDir(UP) -> getState() == 0)
            {
                check = check -> getDir(UP);
                check -> setState(2);
                //cout<<"data"<<path -> gettop()<<"U"<<endl;
                path -> addElement(check);
                if(!(check -> getDir(RIGHT)) && !(check -> getDir(DOWN)))
                {
                    break;
                }
            }

            else
            {
                //cout<<"data"<<path -> gettop()<<"REMOVE"<<endl;
                path -> removeElement();
            }
        }

        return path;
    }
    void printMaze() const
    {
        Grid *j = maze;
        Grid *k;
        while(j != NULL)     /*one of the loops(Grid *k) is printed rightwards, and the other(Grid *j) is printed downwards.*/
        {
            k = j;
            while(k != NULL)
            {
                cout << k -> getState() << " ";
                k = k -> getDir(RIGHT);
            }
            cout << endl;
            j = j -> getDir(DOWN);
        }
    }
private:
    Grid *maze;
};

int main()
{
    Maze *maze = new Maze();
    maze -> printMaze();
    maze -> getPath() -> printPath();
    maze -> printMaze();
}
