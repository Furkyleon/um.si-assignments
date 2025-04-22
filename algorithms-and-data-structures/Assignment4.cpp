#include <iostream>
using namespace std;

struct Node {
    int key;
    Node *parent;
    Node *left;
    Node *right;
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

    // helper function for inorder: start from left, go to root, then continue with right (recursive)
    void inorder(Node* node) {
        if (node != nullptr) {
            inorder(node->left);
            cout << node->key << " ";
            inorder(node->right);
        }
    }

    // DELETE CASE 1 or 2: handling remove of a node with at most one child:
    void delete_case_1_2(Node* y) {
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
        delete y; // delete y
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

    // insertion function
    void insert(int value){
        Node* y = nullptr; // helper node to find a place for value
        Node* x = root; // root of the tree

        // traversing the tree to find the insertion position for value
        while (x != nullptr) {
            y = x;
            if (value < x->key) // if value is smaller, go left
                x = x->left;
            else if (value > x->key) // if value is bigger, go right
                x = x->right;
            else { // the given value already exists in the tree
                cout << value << " is already inserted in tree!" << endl;
                return;
            }
        }

        // creating the new node (z) after a place is found (or not found)
        Node* z = new Node;
        z->key = value;
        z->left = nullptr;
        z->right = nullptr;
        z->parent = y;

        if (y == nullptr) { // if no place found (y=null), z becomes root
            root = z;
        }
        else if (z->key < y->key) { // if place found and value is smaller than root
            y->left = z;
        }
        else { // if place found and value is bigger than root
            y->right = z;
        }

        cout << value << " is inserted!" << endl;
    }

    // remove function
    void remove(int value) {
        Node* z = search(value);

        // case 1: leaf node || case 2: node with one child
        if (z->left == nullptr || z->right == nullptr) {
            delete_case_1_2(z);
        }
        // case 3: z has two children
        else {
            Node* y = successor(z); // find successor (to exchange with node to be deleted)
            int succKey = y->key; // get successor value (copy key method)
            delete_case_1_2(y); // delete y, which has at most one child
            z->key = succKey; // copy the successor's key to z (copy key method)
        }
    }

    // finding min value in the tree (left most node)
    Node* minimum(Node* x) {
        if (x == nullptr) {
            return nullptr;
        }
        while (x->left != nullptr) {
            x = x->left;
        }
        return x;
    }

    // finding max value in the tree (right most node)
    Node* maximum(Node* x) {
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
            return minimum(node->right);
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
            return maximum(node->left);
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

    // printing in order (ascending)
    void printInOrder() {
        inorder(root); // using inorder function
        cout << endl;
    }

    // printing tree with connections (parent -> child)
    void printConnections(Node* node) {
        if (node != nullptr) {
            // printing node key and its parent
            cout << "Node " << node->key;
            if (node->parent != nullptr) {
                cout << " (Parent: " << node->parent->key << ")";
            } else {
                cout << " (Root)";
            }
            cout << " -> ";

            // printing left child info
            cout << "Left: ";
            if (node->left != nullptr) {
                cout << node->left->key;
            } else {
                cout << "NULL";
            }
            cout << " | ";

            // printing right child info
            cout << "Right: ";
            if (node->right != nullptr) {
                cout << node->right->key;
            } else {
                cout << "NULL";
            }
            cout << endl;

            // recurse for left and right subtrees
            printConnections(node->left);
            printConnections(node->right);
        }
    }
};

int main() {

    int operation, number;
    BinarySearchTree bst;

    while (true) {
        // menu
        cout << "Binary search tree - operations:\n\n";
        cout << "1) Insert a value\n";
        cout << "2) Ordered print of keys\n";
        cout << "3) Print of connections\n";
        cout << "4) Search\n";
        cout << "5) Print min/max\n";
        cout << "6) Print successor and predecessor\n";
        cout << "7) Remove a node\n";
        cout << "8) End\n\n";
        cout << "Operation:";
        cin >> operation;

        // operations
        if (operation == 1) {
            cout << "Enter a value to insert:";
            cin >> number;
            bst.insert(number);
            cout << endl;
        }
        else if (operation == 2) {
            if (bst.getRoot() == nullptr){
                cout << "Tree is empty, so cannot print in order!" << endl;
            }
            else {
                bst.printInOrder();
            }
            cout << endl;
        }
        else if (operation == 3) {
            if (bst.getRoot() == nullptr){
                cout << "Tree is empty, so cannot print connections!" << endl;
            }
            else if (bst.getRoot()->left == nullptr && bst.getRoot()->right == nullptr){
                cout << "Only node in tree is the root: " << bst.getRoot()->key << endl;
            }
            else {
                bst.printConnections(bst.getRoot());
            }
            cout << endl;
        }
        else if (operation == 4) {
            cout << "Enter a value to search:";
            cin >> number;
            if (bst.search(number) != nullptr){
                cout << number << " exists in BST.\n";
            }
            else {
                cout << number << " does not exist in BST.\n";
            }
            cout << endl;
        }
        else if (operation == 5) {
            if (bst.getRoot() == nullptr){
                cout << "Tree is empty, so cannot find max/min value!" << endl;
            }
            else {
                cout << "Max number: " << bst.maximum(bst.getRoot())->key << endl;
                cout << "Min number: " << bst.minimum(bst.getRoot())->key << endl;
            }
            cout << endl;
        }
        else if (operation == 6) {
            cout << "Enter a value to find successor and predecessor:";
            cin >> number;
            Node* node = bst.search(number);

            if (node == nullptr){
                cout << "There is no such value!" << endl;
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
        else if (operation == 7) {
            cout << "Enter a value to remove:";
            cin >> number;
            if (bst.search(number)!=nullptr){
                bst.remove(number);
                cout << number << " is removed!" << endl;
            }
            else {
                cout << "There is no such value!" << endl;
            }
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
