#include <iostream>
using namespace std;

// stack implementation
struct Stack {
    int *S;
    int top;
    int MAX;
};

void push (Stack & s, int number) {
    if (s.top == s.MAX) {
        cout << "Stack is full, the number cannot be inserted!" << endl;
    }
    else {
        s.S[s.top] = number;
        s.top++;
        cout << to_string(number) + " is inserted to stack." << endl;
    }
}

void pop (Stack & s) {
    if (s.top == 0){
        cout << "Stack is empty, anything can be read!" << endl;
    }
    else {
        s.top--;
        cout << to_string(s.S[s.top]) + " is read and removed." << endl;
    }
}

void printStack (Stack s){
    if (s.top == 0){
        cout << "Stack is empty, so cannot be printed!" << endl;
        return;
    }

    cout << "Stack" << endl;
    cout << "---------------------------" << endl;
    cout << "Top index: " << s.top << " | MAX index: " << s.MAX - 1 << endl;

    cout << "Index:";
    for (int k=0; k < s.MAX; k++){
        cout << " " << k;
    }
    cout << endl;
    cout << "Value:";
    for (int i=0; i < s.top; i++){
        cout << " " << s.S[i];
    }
    cout << endl;
}

// circular queue implementation
struct CircularQueue {
    int *Q;
    int head, tail;
    int MAX;
};

void enqueue (CircularQueue & q, int number) {
    int new_tail = (q.tail + 1) % q.MAX;  // Correct wrap-around calculation
    if (q.head == new_tail) {
        cout << "Queue is full, the number cannot be inserted!" << endl;
        return;  // Stop execution if full
    }

    q.Q[q.tail] = number;
    q.tail = new_tail;
    cout << number << " is inserted to queue." << endl;
}

void dequeue (CircularQueue & q) {
    if (q.head == q.tail){
        cout << "Queue is empty, nothing can be read!" << endl;
        return;
    }

    int x = q.Q[q.head];
    q.head++;
    if (q.head >= q.MAX) {
        q.head = 0;
    }
    cout << x << " is read and removed." << endl;
}

void printQueue (CircularQueue q) {
    if (q.head == q.tail) {
        cout << "Queue is empty, so cannot be printed!" << endl;
        return;
    }

    cout << "Queue" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "Head index: " << q.head << " | Tail index: " << q.tail << " | MAX index: " << q.MAX - 1 << endl;

    cout << "Index:";
    for (int k = 0; k < q.MAX; k++){
        cout << " " << k;
    }
    cout << endl;

    cout << "Value:";
    if (q.head < q.tail){
        for (int k = 0; k < q.MAX; k++){
            if (k >= q.head && k < q.tail) {
                cout << " " << q.Q[k];
            }
            else {
                cout << " _";
            }
        }
    }
    else {
        for (int k = 0; k < q.MAX; k++){
            if (k >= q.head || k < q.tail) {
                cout << " " << q.Q[k];
            }
            else {
                cout << " _";
            }
        }
    }
    cout << endl;
}

int main() {
    int size, selection, number;

    // getting size input
    cout << "Enter the size of stack/queue:";
    cin >> size;

    // stack
    Stack s;
    s.MAX = size;
    s.S = new int[s.MAX];
    s.top = 0;

    // queue
    CircularQueue q;
    q.MAX = size;
    q.Q = new int[q.MAX];
    q.head = 0;
    q.tail = 0;

    // displaying menu
    while (true){
        cout << endl;
        cout << "Stack - selection:" << endl;
        cout << "1) Insert a number" << endl;
        cout << "2) Read a number" << endl;
        cout << "3) Print the stack" << endl;
        cout << endl;
        cout << "Queue - selection:" << endl;
        cout << "4) Insert a number" << endl;
        cout << "5) Read a number" << endl;
        cout << "6) Print the queue from head to tail" << endl;
        cout << endl;
        cout << "7) Exit" << endl;
        cout << endl;

        // selection input
        cout << "Selection:";
        cin >> selection;
        cout << endl;

        // selection result
        if (selection == 1) {
            cout << "Enter a number to insert:";
            cin >> number;
            push(s, number);
        }
        else if (selection == 2) {
            pop(s);
        }
        else if (selection == 3) {
            printStack(s);
        }
        else if (selection == 4) {
            cout << "Enter a number to insert:";
            cin >> number;
            enqueue(q, number);
        }
        else if (selection == 5) {
            dequeue(q);
        }
        else if (selection == 6) {
            printQueue(q);
        }
        else if (selection == 7) {
            cout << "Program is being terminated..." << endl;
            break;
        }
        else {
            cout << "Enter a number between 1-7!" << endl;
        }
    }

    return 0;
}
