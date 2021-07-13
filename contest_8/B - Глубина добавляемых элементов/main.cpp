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
    vector<size_t> depths;

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

    size_t getDepth (int64_t value, Node* leaf) const {
        if (leaf != nullptr) {
            if (value == leaf -> value) {
                return 1;
            } else if (value < leaf -> value) {
                return getDepth(value, leaf->left) + 1;
            } else {
                return getDepth(value, leaf->right) + 1;
            }
        } else {
            return 0;
        }
    }

public:
    BST& insert(int64_t value) {
        if (root != nullptr) {
            if(find(value, root) == nullptr) {
                insert(value, root);
            	depths.push_back(getDepth(value, root));
            }
        } else {
            root = new Node(value);
        	depths.push_back(getDepth(value, root));
        }
        
        return *this;
    }

    const vector<size_t>& getDepths () const {
        return depths;
    }

};

int main() {
    BST tree;
    int64_t element;
    while ((cin >> element) && (element != 0)) {
        tree.insert(element);
    }

    for (auto i : tree.getDepths()){
        cout << i << ' ';
    }

    return 0;
}