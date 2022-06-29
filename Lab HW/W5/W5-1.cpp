/*�H��V�쵲��C��@���X�A�x�s�覡�����|�A�ѩ󶰦X�̪������S�����ǤW�����Y�C
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
        element = NULL;    //��m�Ptop�C
        SIZE = 0;
    }

    int addElement(int e)
    {
        Node *newnode = new Node;
        if(newnode == NULL)
        {
            return false;
        }
        //�P�_��set�����������L�ۦP�C
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
        element = newnode;           //stack�s�k�A�]���C�@�Ӥ����S���������Y�C
        SIZE++;
        return true;
    }

    Set *unions(const Set *b) const
    {
        Set *save_u = new Set();
        Node *set1 = element;
        Node *set2 = b -> element;

        //�[�J���set���p���C
        for(set1; set1 != NULL; set1= set1->next)   //for( [A.]�@�}�l���������(��l��) ; [B.]����(�P�_�O�_����) ; [C.]�C�@���@���A�N������� )
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

        //�P�_�涰�C
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

        //�P�_�O�_�����������ۦP�C
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
