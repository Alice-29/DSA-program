/*Consider implementing a fixed size stack of maximum size 5 using an array.
Create a structure
struct stack {
int a[5];
int top;
};
Note:
The array a holds the contents of the stack and the integer top stores the index of the element at the top of the stack.
Write a program to implement push and pop operation on stack and to display the contents of the stack.
In the initstack function intialize the value of top to -1.
Print the message "Stack is full" in the push function when an attempt is made to push a data into a full stack.
Print the message "Stack is empty" in the pop function and return the value-1000 when an attempt is made to pop data from an empty stack.
Refer function specifications for further details.*/


#include <iostream>
using namespace std;

class Stack {
private:
    int top;
    int capacity;
    int* a;

public:
    Stack(int size) {
        top = -1;
        capacity = size;
        a = new int[capacity];
    }

    void push(int data) {
        if (top == capacity - 1) {
            cout << "Stack is full\n";
            return;
        }
        a[++top] = data;
        cout << data << " pushed.\n";
    }

    int pop() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return -1;
        }
        int temp = a[top--];
        return temp;
    }

    void display() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return;
        }
        for (int i = 0; i <= top; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    int choice, value;
    Stack s(5); 
    do {
        cout << "\nChoice 1 : Push\nChoice 2 : Pop\nChoice 3 : Display\nAny other choice: Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the element to be pushed: ";
            cin >> value;
            s.push(value);
            break;
        case 2:
            value = s.pop();
            if (value != -1)
                cout << "Popped element: " << value << "\n";
            break;
        case 3:
            cout << "Stack contents: ";
            s.display();
            break;
        default:
            cout << "Exiting...\n";
            return 0;
        }
    } while (true);

    return 0;
}
