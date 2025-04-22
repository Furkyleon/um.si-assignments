#include <iostream>
#include <fstream>
using namespace std;

struct Element {
    string name;
    Element *next;

    Element() {}
    Element(string name, Element* next = nullptr): name(name), next(next) {}
};
struct Node {
    int key; // date (like 19990101)
    Node *parent;
    Node *left;
    Node *right;
    Element *head; // linked list for movies

    Node() {}
    Node(int k, Node* p = nullptr): key(k), parent(p), left(nullptr), right(nullptr), head(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;

    // helper function to delete nodes
    void deleteSubtree(Node* node) {
        if (node != nullptr) {
            deleteSubtree(node->left);
            deleteSubtree(node->right);
            delete node;
        }
    }

    // recursive inorder helper to print all dates and movies
    void inorderPrint(Node* node) {
        if (node != nullptr) {
            inorderPrint(node->left);
            // print date
            cout << node->key << ":\n";
            // print all movies for this date
            for (Element* e = node->head; e != nullptr; e = e->next) {
                cout << "  - " << e->name << "\n";
            }
            inorderPrint(node->right);
        }
    }

    // free all elements in a linked list
    void deleteLinkedList(Element* head) {
        while (head) {
            Element* nxt = head->next;
            delete head;
            head = nxt;
        }
    }

    // DELETE CASE 1 or 2: handling remove of a node with at most one child:
    void delete_case_1_2(Node* y) {
        // delete the movie linked list for y
        deleteLinkedList(y->head);

        Node* x;
        // if left child exists, choose left; otherwise, choose right
        if (y->left != nullptr)
            x = y->left;
        else
            x = y->right;

        // if x exists, update its parent pointer:
        if (x != nullptr)
            x->parent = y->parent;

        // if y is the root, update root pointer:
        if (y->parent == nullptr) {
            root = x;
        } // if y is not root, exchange node to be deleted with child node
        else if (y == y->parent->left) {
            y->parent->left = x;
        }
        else {
            y->parent->right = x;
        }

        delete y;
    }

    // insertion function
    void insertMovieFromFile(int date, const string & movie_name) {
        Node* y = nullptr;
        Node* x = root;

        // Search for existing date
        while (x != nullptr) {
            y = x;
            if (date < x->key)
                x = x->left;
            else if (date > x->key)
                x = x->right;
            else
                break;  // found node with same date
        }

        if (x == nullptr) {
            // Date not found: create new node
            Node* z = new Node(date, y);
            z->head = new Element(movie_name);  // first movie
            if (y == nullptr) {
                root = z;                       // tree was empty
            }
            else if (date < y->key) {
                y->left = z;
            }
            else {
                y->right = z;
            }
        }
        else {
            Element* tail = x->head;
            // walk to the last element
            while (tail->next != nullptr) {
                tail = tail->next;
            }
            // attach new movie at end
            tail->next = new Element(movie_name);
        }
    }

public:
    BinarySearchTree(){ // constructor
        root = nullptr;
    };

    ~BinarySearchTree(){ // destructor
        deleteSubtree(root);
        cout << "Tree is also deleted!" << endl;
    };

    // getting root node
    Node* getRoot(){
        return root;
    }

    // search function (iterative)
    Node* search(int value){
        Node* x = root;
        while (x != nullptr){
            if (value == x->key){
                return x;
            }
            if (value < x->key){
                x=x->left;
            }
            else {
                x=x->right;
            }
        }
        return x;
    }

    // to find all movies for a given date (search function)
    void findMovieOfSpecificDate(int date) {
        Node* x = root;
        while (x != nullptr) {
            if (date == x->key)
                break;
            else if (date < x->key)
                x = x->left;
            else if (date > x->key)
                x = x->right;
        }

        if (x == nullptr) {
            cout << "No entries for date " << date << "!\n\n";
        } else {
            cout << "Movies on " << date << ":\n";
            for (Element* e = x->head; e != nullptr; e = e->next) {
                cout << " - " << e->name << "\n";
            }
        }
    }

    // insertion function (inserting date node and a movie)
    void insertMovie(int date, const string & movie_name) {
        Node* y = nullptr;
        Node* x = root;

        // searching for existing date
        while (x != nullptr) {
            y = x;
            if (date < x->key)
                x = x->left;
            else if (date > x->key)
                x = x->right;
            else
                break;  // found node with same date
        }

        if (x == nullptr) {
            // if date not found -> create new node
            Node* z = new Node(date, y);
            z->head = new Element(movie_name);  // first movie
            if (y == nullptr) {
                root = z;                       // tree was empty
            }
            else if (date < y->key) {
                y->left = z;
            }
            else {
                y->right = z;
            }
            cout << "Added movie \"" << movie_name << "\" to new date " << date << "\n";
        }
        else {
            Element* tail = x->head;
            // walk to the last element
            while (tail->next != nullptr) {
                tail = tail->next;
            }
            // attach new movie at end
            tail->next = new Element(movie_name);

            cout << "Added movie \"" << movie_name
                 << "\" to existing date " << date << "\n";
        }
    }

    // remove function (removing the date node and its movies linked list)
    void removeMovie(int value) {
        Node* z = search(value);

        // case 1: leaf node || case 2: node with one child
        if (z->left == nullptr || z->right == nullptr) {
            delete_case_1_2(z);
        }
        // case 3: z has two children
        else {
            Node* y = successor(z); // find successor (to exchange with node to be deleted)

            // get successor date and movie linked list (copy key method)
            int successorKey = y->key;
            Element* successorHead = y->head;


            y->head = nullptr; // Detach the list from y so it won't be deleted
            deleteLinkedList(z->head); // Delete z's original movie list
            delete_case_1_2(y); // delete y, which has at most one child

            // copy the successor's date and movie linked list to z (copy key method)
            z->key = successorKey;
            z->head = successorHead;
        }
    }

    // finding min value in the tree (left most node)
    Node* minimumDate(Node* x) {
        if (x == nullptr) {
            return nullptr;
        }
        while (x->left != nullptr) {
            x = x->left;
        }
        return x;
    }

    // finding max value in the tree (right most node)
    Node* maximumDate(Node* x) {
        if (x == nullptr) {
            return nullptr;
        }
        while (x->right != nullptr) {
            x = x->right;
        }
        return x;
    }

    // finding the successor of node (the value right after given value in order traverse)
    Node* successor(Node* node){
        if (node->right != nullptr){ // if a right subtree exists, find the minimum in that subtree
            return minimumDate(node->right);
        }
        else { // if no right subtree, look upward (parents)
            Node* y = node->parent;
            while (y != nullptr && node == y->right){
                node = y;
                y = y->parent;
            }
            return y;
        }
    }

    // finding the predecessor of node (the value right before given value in order traverse)
    Node* predecessor(Node* node) {
        if (node->left != nullptr) {  // if a left subtree exists, find the maximum in that subtree
            return maximumDate(node->left);
        }
        else {  // if no left subtree, look upward (parents)
            Node* y = node->parent;
            while (y != nullptr && node == y->left) {
                node = y;
                y = y->parent;
            }
            return y;
        }
    }

    // print all dates and their movies in ascending order
    void printAllMovies() {
        if (root == nullptr) {
            cout << "No movies in the database." << endl;
        } else {
            inorderPrint(root);
        }
        cout << endl;
    }

    // loading file
    void loadFromFile(const string &filename) {
        ifstream readFile(filename);
        if (!readFile) {
            cout << "\"" << filename << "\" << is cannot be opened!";
            return;
        }

        int N;
        readFile >> N; // num of movies line
        string line;
        getline(readFile, line);

        // reading all other lines (movie lines)
        for (int i = 0; i < N; ++i) {
            int date;
            readFile >> date;
            string name;
            getline(readFile, name);

            if (!name.empty() && name.front() == ' ')
                name.erase(name.begin());

            insertMovieFromFile(date, name);
        }

        cout << N << " movies is loaded from \"" << filename << "\"\n";
        readFile.close();
    }
};

int main() {

    int operation, date;
    string movie_name;
    BinarySearchTree bst;

    while (true) {
        // menu
        cout << "Binary search tree - operations:\n\n";
        cout << "1) Insert a movie\n";
        cout << "2) Print all movies\n";
        cout << "3) Find movies at the specific date\n";
        cout << "4) Print minimum and maximum date\n";
        cout << "5) Print successor and predecessor\n";
        cout << "6) Remove all movies at specific date\n";
        cout << "7) Load movies from the file\n";
        cout << "8) End\n\n";
        cout << "Operation:";
        cin >> operation;

        // operations
        if (operation == 1) {
            cout << "Enter a date and movie to insert:";
            cin >> date >> movie_name;
            bst.insertMovie(date, movie_name);
            cout << endl;
        }
        else if (operation == 2) {
            bst.printAllMovies();
        }
        else if (operation == 3) {
            cout << "Enter a date to find movies of it:";
            cin >> date;
            bst.findMovieOfSpecificDate(date);
            cout << endl;
        }
        else if (operation == 4) {
            if (bst.getRoot() == nullptr){
                cout << "Tree is empty, so cannot find max/min value!" << endl;
            }
            else {
                cout << "Minimum date: " << bst.minimumDate(bst.getRoot())->key << endl;
                cout << "Maximum date: " << bst.maximumDate(bst.getRoot())->key << endl;
            }
            cout << endl;
        }
        else if (operation == 5) {
            cout << "Enter a date to find its successor and predecessor:";
            cin >> date;
            Node* node = bst.search(date);

            if (node == nullptr){
                cout << "There is no such date!" << endl;
            }
            else {
                Node* successor = bst.successor(node);
                Node* predecessor = bst.predecessor(node);

                if (successor != nullptr){
                    cout << "Successor: " << successor->key << endl;
                }
                else {
                    cout << "No successor!" << endl;
                }

                if (predecessor != nullptr){
                    cout << "Predecessor: " << predecessor->key << endl;
                }
                else {
                    cout << "No predecessor!" << endl;
                }
            }
            cout << endl;
        }
        else if (operation == 6) {
            cout << "Enter a date to remove all movies of chosen date:";
            cin >> date;
            if (bst.search(date)!=nullptr){
                bst.removeMovie(date);
                cout << date << " is removed with all movies!" << endl;
            }
            else {
                cout << "There is no such date!" << endl;
            }
            cout << endl;
        }
        else if (operation == 7) {
            cout << "Enter file name to load:";
            string file_name;
            cin >> file_name;
            bst.loadFromFile(file_name);
            cout << endl;
        }
        else if (operation == 8) {
            cout << "Program is being terminated...\n";
            break;
        }
        else {
            cout << "Invalid selection, please enter a number again (between 1-8)! \n\n";
        }
    }

    return 0;
}