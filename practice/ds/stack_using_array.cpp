#include <iostream>
using namespace std;

#define MAX 10

class Stack {
private:
    int arr[MAX];
    int top;

public:
    Stack():arr(),top(-1){}

    void push(int elem)
    {
        if (top == MAX-1){
            cout << "Stack full" << endl;
        } else {
            arr[++top] = elem;
        }
    }

    int pop()
    {
        if (top == -1) {
            cout << "Stack underflow" << endl;
            return -1;
        } else {
            return (arr[top--]);
        }
    }

    void display() 
    {
        if (top == -1) {
            cout << "stack empty" << endl;
            return;
        }
        for (int i=0; i <= top; i++)
            cout << arr[i] << " " ;
        cout << endl;
    }
    char* reverse(char *str);
};

char* Stack::reverse(char *str)
{
    int i;
    int n = strlen(str);

    for (i=0; i < n ; i++) {
        push(str[i]);
    }

    for (i=0; i < n ; i++) {
        str[i] = pop();
    }
    return str;
}


int main()
{
    Stack stack;
#if 0
    stack.push(1);
    stack.display();
    stack.push(2);
    stack.display();
    stack.push(3);
    stack.display();
    stack.push(3);
    stack.pop();
    stack.display();
    stack.pop();
    stack.display();
    stack.pop();
    stack.display();
    stack.pop();
    stack.display();
    stack.push(2);
    stack.display();
    stack.push(3);
    stack.display();
#endif
    char str[] = "GeeksQuiz";
 
    stack.reverse(str);
    printf("Reversed string is %s", str);
 
    return 0;
}
