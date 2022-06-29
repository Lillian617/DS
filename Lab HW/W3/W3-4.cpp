/*�H��V�쵲��C��@��C�C
  Queue using singly Liked List. */

#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
	int data;
	Node *next;
};

class Queue
{
public:
	Queue()
	{
	    top = NULL;
	    bot = NULL;
	}
	int enqueue(int data)
	{
	    Node *new_node = new Node;
	    new_node -> data = data;
	    new_node ->next = NULL;  //�C���W�[��new_node�`�I���O�̫�@�Ӹ`�I�C(��i��X)
	    if(top == NULL){
            top = new_node;     //�Ĥ@�Ӹ`�I�C
	    }
	    else{
            bot -> next = new_node;
	    }
        bot = new_node;         //�C���q�̫�@�Ӹ`�I�W�[�`�I�A�ҥH�n��s��e�̫᭱���`�I�C
        return 1;
    }
	int *dequeue()
	{
	    if(top == NULL){
            return NULL;
	    }
	    Node *ptr;
	    ptr = top;
	    top = top -> next;
	    return &(ptr -> data);
	}
private:
	Node *top, *bot;
};

int main()
{
	int data, *temp;
	string command;
	Queue *queue = new Queue();
	while(1)
	{
		cin>>command;
		if(command.compare("exit") == 0)
		{
			break;
		}
		else if(command.compare("enqueue") == 0)
		{
			cout<<"Please input a integer data:";
			cin>>data;
			if(queue->enqueue(data) == 1)
			{
				cout<<"Successfully enqueue data "<<data<<" into queue."<<endl;
			}
			else
			{
				cout<<"Failed to enqueue data into queue."<<endl;
			}
		}
		else if(command.compare("dequeue") == 0)
		{
			temp = queue->dequeue();
			if(temp == NULL)
			{
				cout<<"Failed to dequeue a data from queue.\n";
			}
			else
			{
				cout<<"Dequeue data "<<*temp<<" from queue."<<endl;
			}
		}
	}
}
