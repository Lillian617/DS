/*以單向鏈結串列實作佇列。
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
	    new_node ->next = NULL;  //每次增加的new_node節點都是最後一個節點。(後進後出)
	    if(top == NULL){
            top = new_node;     //第一個節點。
	    }
	    else{
            bot -> next = new_node;
	    }
        bot = new_node;         //每次從最後一個節點增加節點，所以要更新當前最後面的節點。
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
