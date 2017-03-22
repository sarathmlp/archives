#include <iostream>
using namespace std;

#define MAX 4

class Queue {
private:
    int arr[MAX];
    int tail;

public:
    Queue():tail(-1)
    {}

    void enqueue(int val)
    {
        if (tail == MAX-1) {
            cout << "q is full" << endl;
            return;
        }
        arr[++tail] = val;
    }
    int dequeue(void)
    {
        if (tail < 0) {
            cout << "queue is empty" << endl;
            return -1;
        }
        int val = arr[0];
        for (int i=0; i < tail; i++) {
            arr[i] = arr[i+1];
        }
        tail--;
        return val;
    }
    void display(void)
    {
        if (tail < 0) {
            cout << "queue empty" << endl;
            return;
        }
        for (int i=0; i <= tail ; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(int argc, char* argv[])
{
    Queue q;
    q.enqueue(1);
    q.display();
    q.enqueue(2);
    q.display();
    q.enqueue(3);
    q.enqueue(4);
    q.display();
    q.enqueue(4);
    q.display();

    q.dequeue();
    q.display();
    q.enqueue(5);
    q.display();
    q.dequeue();
    q.display();
    q.dequeue();
    q.display();
    q.dequeue();
    q.display();
    q.dequeue();
    q.display();

    q.dequeue();
    q.display();
    q.dequeue();

    q.enqueue(1);
    q.display();
    q.enqueue(2);
    q.display();
    q.dequeue();
    q.display();
    q.enqueue(3);
    q.enqueue(4);
    q.display();
    q.enqueue(5);
    q.display();

    return 0;
}

