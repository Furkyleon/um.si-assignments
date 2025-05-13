#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>

using namespace std;

struct element {
    int key;
    element *prev, *next;
};

// swap keys of two elements
void swapKeys(element* a, element* b) {
    int temp = a->key;
    a->key = b->key;
    b->key = temp;
}

// partition function for doubly linked list
element* partition(element* start, element* end) {
    int pe = start->key;
    element* l = start->next;
    element* r = end;

    while (l != nullptr && r != nullptr && l != r->next) {
        while (l != r->next && l->key <= pe)
            l = l->next;

        while (r != start && r->key > pe)
            r = r->prev;

        if (l && r && l != r->next && l != r)
            swapKeys(l, r);
    }

    swapKeys(start, r);
    return r;
}

// quicksort function for doubly linked list
void quickSort(element* start, element* end) {
    if (!start || !end || start == end || end->next == start)
        return;

    element* q = partition(start, end);
    if (q && q != start)
        quickSort(start, q->prev);
    if (q && q != end)
        quickSort(q->next, end);
}

// adding a new node at the end
void append(element*& head, element*& tail, int value) {
    element* newNode = new element{value, tail, nullptr};
    if (tail) tail->next = newNode;
    else head = newNode; // first node
    tail = newNode;
}

// checking if list is sorted
bool isSorted(element* head) {
    while (head && head->next) {
        if (head->key > head->next->key)
            return false;
        head = head->next;
    }
    return true;
}

int main() {
    int choice;
    bool running = true;
    int size;

    element* head = nullptr;
    element* tail = nullptr;

    clock_t start, finish;
    double duration;

    // menu
    while (running) {
        cout << "Quicksort - operation:\n\n";
        cout << "1) Generate random sequence\n";
        cout << "2) Generate increasing sequence\n";
        cout << "3) Print the current sequence\n";
        cout << "4) Check if list is increasing (sorted)\n";
        cout << "5) Quicksort\n";
        cout << "6) End\n\n";
        cout << "Operation:";
        cin >> choice;

        // operations
        switch (choice) {
            case 1:
                // generating random sequence
                cout << "Enter a size for sequence:";
                cin >> size;

                // clear existing list
                while (head) {
                    element* temp = head;
                    head = head->next;
                    delete temp;
                }

                head = tail = nullptr;
                for (int i = 0; i < size; ++i)
                    append(head, tail, rand() % 100); // random numbers between 0-99
                cout << "\n";
                break;
            case 2:
                // generating increasing sequence (from 1 to size)
                cout << "Enter a size for sequence:";
                cin >> size;

                // clear existing list
                while (head) {
                    element* temp = head;
                    head = head->next;
                    delete temp;
                }

                head = tail = nullptr;
                for (int i = 1; i <= size; i++)
                    append(head, tail, i);
                cout << "\n";
                break;
            case 3:
                // printing the current sequence
                cout << "Sequence: ";
                while (head) {
                    cout << head->key << " ";
                    head = head->next;
                }
                cout << "\n\n";
                break;
            case 4:
                // checking if array is sorted (ascending sort)
                if (isSorted(head))
                    cout << "The sequence is sorted!\n\n";
                else
                    cout << "The sequence is not sorted!\n\n";
                break;
            case 5:
                // classic quicksort for doubly linked list
                if (head) {
                    start = clock();
                    quickSort(head, tail);
                    finish = clock();
                    duration = (double)(finish - start) / CLOCKS_PER_SEC;
                    cout << "Sequence is quickly sorted in " << duration << " seconds\n\n";
                } else {
                    cout << "Sequence is empty! Please generate a sequence first.\n\n";
                }
                break;
            case 6:
                // exiting program
                cout << "Exiting program...\n";
                running = false;
                break;
            default:
                cout << "Invalid operation. Please try again.\n\n";
                break;
        }
    }

    return 0;
}
