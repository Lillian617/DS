/* �H array ���覡���� enqueue �M dequeue ��ơC ���� Circular Queue �j��/������C */

#include <iostream>
#include <cstring>

#define SIZE 100

using namespace std;

class Queue
{
public:
    Queue()
    {
        f = -1;
        b = -1;
        flag = 0; //�ĤG�C�}�l�A�}�C�O�_�w���C
    }
    int enqueue(int d)
    {
        if(isFull() || b == (SIZE-1) && f == -1) //����1��Array�O�����C
        {                                        //����2��back��FArray���̥��ݥBfront�٦b��l��m(�}�Y)�C
            return -1;
        }
        else{
            b = (b + 1) % SIZE; //��l�ơA�������F�T�O�O����Ŷ����Q���O�A�i���ƨϥΡC
            data[b] = d;
            if(f == b){         //�T�w�{�b�}�C�O�_�w���C
                flag = 1;
            }
            return 1;
        }
    }
    int *dequeue()
    {
        if(isEmpty())
        {
            return NULL;
        }
        else{
            f = (f+1) % SIZE;
            if(f == b){         //�T�w���C�w�g������X�L�C
                flag = 0;
            }
            return (data + f);
        }
    }
    bool isFull(){
        if(f == b % SIZE && flag == 1){
            return 1;
        }
        else{
            return 0;
        }
    }
    bool isEmpty(){
        if(b == f && flag == 0){
            return 1;
        }
        return 0;
    }
private:
    int data[SIZE];
    int f;
    int b;
    bool flag;
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
