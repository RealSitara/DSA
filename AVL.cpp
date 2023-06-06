/*
A Dictionary stores keywords and its meanings. 
Provide facility for adding new keywords
deleting keywords, updating values of any entry. 
Provide facility to display whole data sorted in ascending/ Descending order. 
Also find how many maximum comparisons may require for finding any keyword. 
Use Height balance tree and find the complexity for finding a keyword
*/
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string keyword;
    string meaning;
    Node* left;
    Node* right;
    int height;

    Node(const string& key, const string& value) {
        keyword = key;
        meaning = value;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

class AVLTree {
private:
    Node* root;

    int getHeight(Node* node) {
        if (node == NULL)
            return 0;
        return node->height;
    }

    int getBalanceFactor(Node* node) {
        if (node == NULL)
            return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    Node* insertNode(Node* node, const string& key, const string& value) {
        if (node == NULL)
            return new Node(key, value);

        if (key < node->keyword)
            node->left = insertNode(node->left, key, value);
        else if (key > node->keyword)
            node->right = insertNode(node->right, key, value);
        else {
            // Update the meaning if the keyword already exists
            node->meaning = value;
            return node;
        }

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

        int balanceFactor = getBalanceFactor(node);

        // Left Left Case
        if (balanceFactor > 1 && key < node->left->keyword)
            return rotateRight(node);

        // Right Right Case
        if (balanceFactor < -1 && key > node->right->keyword)
            return rotateLeft(node);

        // Left Right Case
        if (balanceFactor > 1 && key > node->left->keyword) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        // Right Left Case
        if (balanceFactor < -1 && key < node->right->keyword) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    Node* findMinNode(Node* node) {
        Node* current = node;
        while (current->left != NULL)
            current = current->left;
        return current;
    }

    Node* deleteNode(Node* node, const string& key) {
        if (node == NULL)
            return node;

        if (key < node->keyword)
            node->left = deleteNode(node->left, key);
        else if (key > node->keyword)
            node->right = deleteNode(node->right, key);
        else {
            if (node->left == NULL || node->right == NULL) {
                Node* temp = node->left ? node->left : node->right;
                if (temp == NULL) {
                    temp = node;
                    node = NULL;
                } else {
                    *node = *temp;
                }
                delete temp;
            } else {
                Node* temp = findMinNode(node->right);
                node->keyword = temp->keyword;
                node->meaning = temp->meaning;
                node->right = deleteNode(node->right, temp->keyword);
            }
        }

        if (node == NULL)
            return node;

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

        int balanceFactor = getBalanceFactor(node);

        // Left Left Case
        if (balanceFactor > 1 && getBalanceFactor(node->left) >= 0)
            return rotateRight(node);

        // Left Right Case
        if (balanceFactor > 1 && getBalanceFactor(node->left) < 0) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        // Right Right Case
        if (balanceFactor < -1 && getBalanceFactor(node->right) <= 0)
            return rotateLeft(node);

        // Right Left Case
        if (balanceFactor < -1 && getBalanceFactor(node->right) > 0) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
        return node;
 
    }

    void displayAscending(Node* node) {
        if (node == NULL)
            return;

        displayAscending(node->left);
        cout << node->keyword << ": " << node->meaning << endl;
        displayAscending(node->right);
    }

    void displayDescending(Node* node) {
        if (node == NULL)
            return;

        displayDescending(node->right);
        cout << node->keyword << ": " << node->meaning << endl;
        displayDescending(node->left);
    }

    int getMaxComparisons(Node* node, const string& key, int comparisons) {
        if (node ==NULL)
            return comparisons;

        if (key == node->keyword)
            return comparisons + 1;

        if (key < node->keyword)
            return getMaxComparisons(node->left, key, comparisons + 1);
        else
            return getMaxComparisons(node->right, key, comparisons + 1);
    }

public:
    AVLTree() {
        root =NULL;
    }

    void insert(const string& key, const string& value) {
        root = insertNode(root, key, value);
    }

    void remove(const string& key) {
        root = deleteNode(root, key);
    }

    void displayAscendingOrder() {
        displayAscending(root);
    }

    void displayDescendingOrder() {
        displayDescending(root);
    }

    int getMaxComparisons(const string& key) {
        return getMaxComparisons(root, key, 0);
    }
};

int main() {
    AVLTree dictionary;

    int choice;
    string key, meaning;

    do {
        cout << "----- Dictionary Menu -----\n";
        cout << "1. Add a keyword\n";
        cout << "2. Delete a keyword\n";
        cout << "3. Update the meaning of a keyword\n";
        cout << "4. Display in ascending order\n";
        cout << "5. Display in descending order\n";
        cout << "6. Find maximum comparisons for a keyword\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the keyword: ";
                cin >> key;
                cout << "Enter the meaning: ";
                cin >> meaning;
                dictionary.insert(key, meaning);
                cout << "Keyword added successfully.\n";
                break;
            case 2:
                cout << "Enter the keyword to delete: ";
                cin >> key;
                dictionary.remove(key);
                cout << "Keyword deleted successfully.\n";
                break;
            case 3:
                cout << "Enter the keyword to update: ";
                cin >> key;
                cout << "Enter the new meaning: ";
                cin >> meaning;
                dictionary.remove(key);
                dictionary.insert(key, meaning);
                cout << "Keyword updated successfully.\n";
                break;
            case 4:
                cout << "Keywords in ascending order:\n";
                dictionary.displayAscendingOrder();
                break;
            case 5:
                cout << "Keywords in descending order:\n";
                dictionary.displayDescendingOrder();
                break;
            case 6:
                cout << "Enter the keyword to find maximum comparisons: ";
                cin >> key;
                cout << "Maximum comparisons required: " << dictionary.getMaxComparisons(key) << endl;
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

        cout << endl;

    } while (choice != 7);

    return 0;
}

