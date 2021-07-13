#include <iostream>
#include <cstdint>
#include <algorithm>
#include <vector>

using namespace std;

struct BST {
private:
    struct Node {
        Node(int64_t value_): value(value_) {}
        int64_t value;
        Node* left = nullptr;
        Node* right = nullptr;
    };

    Node* root = nullptr;
    
    Node* findMin(Node* leaf) const {
        if (leaf != nullptr) {
            if (leaf -> left == nullptr) {
                return leaf;
            }
            else {
                return findMin(leaf -> left);
            }
        } else {
            return nullptr;
        }
    }

    Node* findMax(Node* leaf) const {
        if (leaf != nullptr) {
            if (leaf -> right == nullptr) {
                return leaf;
            }
            else {
                return findMax(leaf -> right);
            }
        } else {
            return nullptr;
        }
    }

    Node* getNext (int64_t key) const { // поиск следующего элемента для некоторого ключа value без использования информации о родителе
        Node* current = root;
        Node* successor = nullptr; // последний посещенный узел, ключ которого больше key
        while (current != nullptr) {
            if (current -> value > key) {
                successor = current;
                current = current -> left;
            } else {
                current = current -> right;
            }
        }
        return successor;
    }

    Node* getPrev (int64_t key) const { // поиск предыдущего элемента для некоторого ключа value без использования информации о родителе
        Node* current = root;
        Node* successor = nullptr; // последний посещенный узел, ключ которого меньше key
        while (current != nullptr) {
            if (current -> value < key) {
                successor = current;
                current = current -> right;
            } else {
                current = current -> left;
            }
        }
        return successor;
    }
    
    Node* find(int64_t value, Node* leaf) const {
        if (leaf != nullptr) {
            if (value == leaf -> value) {
                return leaf;
            } else if (value < leaf -> value) {
                return find(value, leaf->left);
            } else {
                return find(value, leaf->right);
            }
        } else {
            return nullptr;
        }
    }

    void insert(int64_t key, Node* leaf) {
        if (key < leaf -> value) {
            if (leaf -> left != nullptr) {
                return insert(key, leaf -> left);
            } else {
                leaf -> left = new Node(key);
            }
        } else {
            if (leaf -> right != nullptr) {
                return insert(key, leaf -> right);
            } else {
                leaf -> right = new Node(key);
            }
        }
    }
    
    size_t getHeight(Node* leaf) const {
        if (leaf == nullptr) {
            return 0;
        } else {
            size_t leftHeight = getHeight(leaf -> left);
            size_t rightHeight = getHeight(leaf -> right);
            return (max(leftHeight, rightHeight) + 1);
        }
    }

    bool isAVLBalanced(Node* leaf) const {
        bool isBalanced = true;
        Node* current = leaf;
        while (current != nullptr && isBalanced) {
            size_t minValue = min(getHeight(current -> left), getHeight(current -> right));
            size_t maxValue = max(getHeight(current -> left), getHeight(current -> right));
            if (maxValue - minValue > 1) {
                isBalanced = false;
            }
            current = getNext(current -> value);
        }
        return isBalanced;
    }

public:
    BST& insert(int64_t value) {
        if (root != nullptr) {
            if(find(value, root) == nullptr) {
                insert(value, root);
            }
        } else {
            root = new Node(value);
        }
        return *this;
    }
    
    bool isAVLBalanced() const {
        return isAVLBalanced(findMin(root));
    }

};

int main() {
    BST tree;
    int64_t element;
    while ((cin >> element) && (element != 0)) {
        tree.insert(element);
    }

    cout << (tree.isAVLBalanced() ? "YES" : "NO") << '\n';

    return 0;
}