/* 以 array 的方式完成 enqueue 和 dequeue 函數。 此為 Circular Queue 迴圈/環狀佇列 */

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
        flag = 0; //第二列開始，陣列是否已滿。
    }
    int enqueue(int d)
    {
        if(isFull() || b == (SIZE-1) && f == -1) //條件1→Array是滿的。
        {                                        //條件2→back到達Array的最末端且front還在初始位置(開頭)。
            return -1;
        }
        else{
            b = (b + 1) % SIZE; //找餘數，此式為了確保記憶體空間不被浪費，可重複使用。
            data[b] = d;
            if(f == b){         //確定現在陣列是否已滿。
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
            if(f == b){         //確定此列已經全部輸出過。
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
