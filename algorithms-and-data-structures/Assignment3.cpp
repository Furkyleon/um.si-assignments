#include <iostream>
using namespace std;

// doubly linked list node
struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int number) : data(number), prev(nullptr), next(nullptr) {}
};

// doubly linked list class
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
public:
    // constructor
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // destructor
    ~DoublyLinkedList() {
        Node* current = head;

        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    // searching for a specific number
    Node* searchNumber(int number) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == number)
                return current;
            current = current->next;
        }
        return nullptr;
    }

    // inserting number into head
    void insertHead(int number) {
        Node* newNode = new Node(number); // new node to insert

        newNode->next = head;
        newNode->prev = nullptr;
        if (head == nullptr) {
            tail = newNode;
        }
        else {
            head->prev = newNode;
        }
        head = newNode;
    }

    // inserting a number after a number
    void insertAfter(Node* element, int number) {
        Node* newNode = new Node(number); // new node to insert

        newNode->next = element->next;
        newNode->prev = element;

        if (element->next != nullptr) {
            element->next->prev = newNode;
            element->next = newNode;
        }
        else {
            element->next = newNode;
            tail = newNode;
        }
    }

    // inserting a number after tail
    void insertTail(int number) {
        Node* newNode = new Node(number);

        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // deleting a specific number from the list
    void deleteNode(Node* element) {
        // deleting only one node
        if (element->prev == nullptr && element->next == nullptr){
            head = nullptr;
            tail = nullptr;
        }
        else { // deleting "head" or "middle" or "tail"
            if (element->prev != nullptr) {
                element->prev->next = element->next;
            }
            else {
                head = element->next;
                head->prev = nullptr;
            }

            if (element->next != nullptr) {
                element->next->prev = element->prev;
            }
            else {
                tail = element->prev;
                tail->next = nullptr;
            }
        }

        delete element;
    }

    // printing the list from head to tail
    void printHeadToTail() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // printing the list from tail to head
    void printTailToHead() {
        Node* current = tail;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }
};

int main() {

    int selection, insertNum, searchNum, deleteNum;
    DoublyLinkedList dll; // DLL object

    while (true){
        // the menu
        cout << "Doubly linked list - selection:\n\n";
        cout << "1) Search data\n";
        cout << "2) Insert data into head\n";
        cout << "3) Insert data after the element\n";
        cout << "4) Insert data after tail\n";
        cout << "5) Delete one element\n";
        cout << "6) Print list from head to tail\n";
        cout << "7) Print list from tail to head\n";
        cout << "8) End\n\n";
        cout << "Selection:";
        cin >> selection;

        // after selection switch case part
        switch (selection) {
            case 1:
                cout << "Enter a number to search (integer):";
                cin >> searchNum;
                if (dll.searchNumber(searchNum)) {
                    cout << searchNum << " exists in the list.\n\n";
                }
                else {
                    cout << searchNum << " does not exist in the list.\n\n";
                }

                break;
            case 2:
                cout << "Enter a number to insert into head:";
                cin >> insertNum;

                dll.insertHead(insertNum);
                cout << insertNum << " is inserted to the list into head.\n\n";

                break;
            case 3:
                cout << "Enter a number to insert:";
                cin >> insertNum;
                cout << "Specify after which element:";
                cin >> searchNum;

                if (dll.searchNumber(searchNum) != nullptr){
                    dll.insertAfter(dll.searchNumber(searchNum), insertNum);
                    cout << insertNum << " is inserted to the list after " << searchNum << ". \n\n";
                }
                else {
                    cout << insertNum << " was not inserted because, there is no " << searchNum << " in the list.\n\n";
                }

                break;
            case 4:
                cout << "Enter a number to insert after tail:";
                cin >> insertNum;

                dll.insertTail(insertNum);
                cout << insertNum << " is inserted to the list after tail.\n\n";

                break;
            case 5:
                cout << "Enter a number to delete:";
                cin >> deleteNum;

                if (dll.searchNumber(deleteNum) != nullptr){
                    dll.deleteNode(dll.searchNumber(deleteNum));
                    cout << deleteNum << " is deleted.\n\n";
                }
                else {
                    cout << deleteNum << " was not deleted because there is no " << deleteNum << " in the list.\n\n";
                }

                break;
            case 6:
                cout << "Linked List: ";
                dll.printHeadToTail();
                cout << endl;

                break;
            case 7:
                cout << "Reversed Linked List: ";
                dll.printTailToHead();
                cout << endl;

                break;
            case 8:
                cout << "Exiting program..." << endl;
                exit(0);
            default:
                cout << "Invalid selection, please enter a number again (between 1-8)! \n\n";
                break;
        }
    }

    return 0;
}
