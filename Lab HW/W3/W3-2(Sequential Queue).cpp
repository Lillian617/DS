/* 以 array 的方式完成 enqueue 和 dequeue 函數。 此為 Sequential Queue 順序佇列 */

#include <iostream>
#include <cstring>

#define SIZE 3

using namespace std;

class Queue
{
public:
    Queue()
    {
        f = 0;
        b = 0;
    }
    int enqueue(int d)
    {
        if(b == SIZE){
            return -1;
        }
        else{
            data[b] = d;
            b++;
            return 1;
        }
    }
    int *dequeue()
    {
        if(b == f){
            return NULL;
        }
        else{
            f++;
            return (data+f-1);
        }
    }
private:
    int data[SIZE];
    int c = 0;
    int f;
    int b;
};

int main()
{
    int data, *temp;
    char command[50];
    Queue *queue = new Queue();
    while(1)
    {
        cin>>command;
        if(strcmp(command, "exit") == 0)
        {
            break;
        }
        else if(strcmp(command, "enqueue") == 0)
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
        else if(strcmp(command, "dequeue") == 0)
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
