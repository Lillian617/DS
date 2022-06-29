/*以單向鏈結串列實作集合，儲存方式為推疊，由於集合裡的元素沒有順序上的關係。
  Set using singly Linked List, and using the way stack store the elements*/

#include<iostream>
#include<cstdlib>

using namespace std;

struct Node
{
    Node()
    {
        data = 0;
        next = NULL;
    }
    int data;
    Node *next;
};

class Set
{
public:
    Set()
    {
        element = NULL;    //位置同top。
        SIZE = 0;
    }

    int addElement(int e)
    {
        Node *newnode = new Node;
        if(newnode == NULL)
        {
            return false;
        }
        //判斷跟set中的元素有無相同。
        Node *temp = element;
        for(temp; temp != NULL; temp = temp -> next)
        {
            if(temp-> data == e)
            {
                return false;
            }
        }

        newnode -> data = e;
        newnode -> next = element;
        element = newnode;           //stack存法，因為每一個元素沒有順序關係。
        SIZE++;
        return true;
    }

    Set *unions(const Set *b) const
    {
        Set *save_u = new Set();
        Node *set1 = element;
        Node *set2 = b -> element;

        //加入兩個set的聯集。
        for(set1; set1 != NULL; set1= set1->next)   //for( [A.]一開始先做什麼事(初始化) ; [B.]條件式(判斷是否執行) ; [C.]每作完一次，就做什麼事 )
        {
            save_u -> addElement(set1 -> data);
        }
        for(set2; set2 != NULL; set2 = set2->next)
        {
            save_u -> addElement(set2 -> data);
        }
        return save_u;
    }

    Set *intersetcions(const Set *b) const
    {
        Set *save_i = new Set();
        Node *set1 = element;

        //判斷交集。
        while(set1 != NULL)
        {
            Node *set2 = b -> element;
            while(set2 != NULL)
            {
                if(set1 -> data == set2 -> data)
                {
                    save_i -> addElement(set1 -> data);
                }
                set2 = set2 -> next;
            }
            set1 = set1 -> next;
        }
        return save_i;
    }

    bool equivalent(const Set *b) const
    {
        int issame = 0;
        Node *set1 = element;
        Node *set2 = b -> element;

        //判斷是否全部元素都相同。
        for(set1 = element; set1 != NULL; set1 = set1 -> next)
        {
            for(set2 = b -> element; set2 != NULL; set2 = set2 -> next)
            {
                if((set1 -> data) == (set2 ->data))
                {
                    issame ++;
                }
            }
        }
        return SIZE == issame;
    }

    void listAll() const
    {
        Node *cur = element;
        while(cur != NULL)
        {
            cout<<cur->data<<" ";
            cur = cur->next;
        }
        cout<<endl;
    }
private:
    Node *element;
    int SIZE;
};

int main()
{

    Set *a = new Set();
    Set *b = new Set();
    Set *c;
    Node *cur;

    // First
    a->addElement(1);
    a->addElement(2);
    a->addElement(3);
//----------------------
    b->addElement(3);
    b->addElement(4);
    b->addElement(5);
    b->addElement(5);
    //*/

    /*Second
    a->addElement(1);
    a->addElement(2);
    a->addElement(3);
//----------------------
    b->addElement(3);
    b->addElement(2);
    b->addElement(1);
    */

    /*Third
    a->addElement(1);
    a->addElement(2);
    a->addElement(3);
//----------------------
    b->addElement(4);
    b->addElement(5);
    b->addElement(6);
    b->addElement(7);
    */

    /*Fourth
    a->addElement(1);
    a->addElement(2);
    a->addElement(3);
//----------------------
    b->addElement(1);
    b->addElement(2);
    b->addElement(3);
    b->addElement(2);
    */


    /*Fifth
    a->addElement(1);
//----------------------
    b->addElement(9);
    */

    c = a->unions(b);
    c->listAll();

    c = a->intersetcions(b);
    c->listAll();

    if(a->equivalent(b) == 0)
        cout<<"Not equivalent.\n";
    else
        cout<<"Equivalent!\n";

}
