#include <iostream>
using namespace std;

// stack implementation
struct Stack {
    int *S;
    int top;
    int MAX;
};

bool isFull (Stack s) {
    return s.top == s.MAX;
}

void push (Stack & s, int number) {
    if (s.top == s.MAX) {
        cout << "This tower is full, you cannot place a disk!\n";
    }
    else {
        s.S[s.top] = number;
        s.top++;
        cout << number << " is placed to the tower.\n";
    }
}

void pop (Stack & s) {
    if (s.top == 0){
        cout << "There is no disk in this tower, you cannot take a disk!\n";
    }
    else {
        int removedDisk = s.S[s.top - 1];
        s.top--;
        cout << removedDisk << " is removed from the tower.\n";
    }
}

void printStack (Stack s){
    if (s.top != 0) {
        for (int i=0; i < s.top; i++){
            cout << " " << s.S[i];
        }
        cout << endl;
    }
    else {
        cout << "" << endl;
    }
}

void moveDisk (Stack & t1, Stack & t2) {
    if (t1.top == 0){
        cout << "You cannot take a disk from first selected tower because it is empty!\n";
    }
    else if (t2.top == t2.MAX) {
        cout << "You cannot place the disk to second selected tower because it i full!\n";
    }
    else {
        int disk = t1.S[(t1.top)-1];
        int place = t2.S[(t2.top)-1];

        if (disk > place){
            cout << "You cannot place larger disks to smaller ones!\n";
        }
        else {
            pop(t1);
            push(t2, disk);
        }
    }
}

int main() {
    // specifying the number of disks:
    int X;
    cout << "Enter the number of disks:";
    cin >> X;

    // towers (stacks)
    Stack tower1, tower2, tower3;
    tower1.MAX = X; tower1.S = new int [tower1.MAX]; tower1.top = 0;
    tower2.MAX = X; tower2.S = new int [tower2.MAX]; tower2.top = 0;
    tower3.MAX = X; tower3.S = new int [tower3.MAX]; tower3.top = 0;

    // placing disks from "size" to 1 onto the first tower:
    for (int i = 0; i < X; i++) {
        tower1.S[i] = X - i;
        tower1.top++;
    }

    // program loop
    string process;
    int t1, t2;

    while (true) {
        if (isFull(tower2)) {
            cout << "\n Result:\n";
            cout << "Tower 1:";
            printStack(tower1);
            cout << "Tower 2:";
            printStack(tower2);
            cout << "Tower 3:";
            printStack(tower3);

            cout << "\nTower 2 is successfully completed, congratulations!\n";
            break;
        }
        else if (isFull(tower3)) {
            cout << "\n Result:\n";
            cout << "Tower 1:";
            printStack(tower1);
            cout << "Tower 2:";
            printStack(tower2);
            cout << "Tower 3:";
            printStack(tower3);

            cout << "\nTower 3 is successfully completed, congratulations!\n";
            break;
        }
        else {
            cout << endl;
            cout << "Write move, print or exit:";
            cin >> process;

            // moving upper disk from one tower to another tower:
            if (process == "move") {
                cout << "Enter first tower to take the disk (1,2,3):";
                cin >> t1;
                cout << "Enter second tower to place the disk (1,2,3):";
                cin >> t2;
                cout << endl;

                if (t1 == 1 && t2 == 2) {
                    moveDisk(tower1, tower2);
                }
                else if (t1 == 1 && t2 == 3) {
                    moveDisk(tower1, tower3);
                }
                else if (t1 == 2 && t2 == 1) {
                    moveDisk(tower2, tower1);
                }
                else if (t1 == 2 && t2 == 3) {
                    moveDisk(tower2, tower3);
                }
                else if (t1 == 3 && t2 == 1) {
                    moveDisk(tower3, tower1);
                }
                else if (t1 == 3 && t2 == 2) {
                    moveDisk(tower3, tower2);
                }
                else {
                    cout << "You entered wrong numbers or same numbers!" << endl;
                }
            }
            else if (process == "print") { // print the towers
                cout << "Tower 1:";
                printStack(tower1);
                cout << "Tower 2:";
                printStack(tower2);
                cout << "Tower 3:";
                printStack(tower3);
            }
            else if (process == "exit") { // exit from program
                cout << "\nProgram is being terminated..." << endl;
                break;
            }
            else {
                cout << "\nWrite 'move', 'print' or 'exit'!" << endl;
            }
        }
    }

    return 0;
}
