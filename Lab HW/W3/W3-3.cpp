/*�H��V�쵲��C��@���|�C
  Stack using singly Liked List. */

#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
	int data;
	Node *next;
};

class Stack
{
public:
    Stack()
    {
        top = NULL;
    }
    int push(int d)
    {
        Node *new_node = new Node;
        new_node -> data = d;
        new_node -> next = top;      //�W�@�ӷs�W��node�|�s���b�s��node����(���i��X)�C
        top = new_node;
        return 1;
    }

    int *pop()  //�Ǧ^�Ȭ����Ъ����
    {
        if(top == NULL){
            return NULL;
        }
        Node *ptr;
        ptr = top;
        top = top -> next;
        return &(ptr -> data);  //�Ǧ^data����}�A�A�Q�Φ���}�L�X�s�񪺭ȡC
    }
private:
    Node *top;
};

int main()
{
    int data, *temp;
    string command;
    Stack *stack = new Stack();
    while(1)
    {
        cin>>command;
        if(command.compare("exit") == 0)
        {
            break;
        }
        else if(command.compare("push") == 0)
        {
            cout<<"Please input a integer data:";
            cin>>data;
            if(stack->push(data) == 1)
            {
                cout<<"Successfully push data "<<data<<" into stack.\n";
            }
            else
            {
                cout<<"Failed to push data into stack.\n";
            }
        }
        else if(command.compare("pop") == 0)
        {
            temp = stack->pop();
            if(temp == NULL)
            {
                cout<<"Failed to pop a data from stack.\n";
            }
            else
            {
                cout<<"Pop data "<<*temp<<" from stack.\n";
            }
        }
    }
}
