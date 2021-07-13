#include <iostream>
#include <cstdint>
#include <algorithm>

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

    size_t getHeight() const {
        return getHeight(root);
    }

};

int main() {
    BST tree;
    int64_t element;
    while ((cin >> element) && (element != 0)) {
        tree.insert(element);
    }

    cout << tree.getHeight() << '\n';

    return 0;
}