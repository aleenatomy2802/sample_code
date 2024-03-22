/**
 * .
`-- Graph/
    `-- Tree/
        `-- Binary Tree/ 
            |-- Traversal/
            |   |-- Bread First Traversal
            |   `-- Depth First Traversal/
            |       |-- In-order Traversal: Left - Root - Right (LEFT, <DATA>, RIGHT)
            |       |-- Pre-order Traversal: Root - Left - Right (<DATA>, LEFT, RIGHT)
            |       `-- Post-order Traversal: Left - Right - Root (LEFT, RIGHT, <DATA>)
            `-- Features/
                |-- Insert a Node
                |-- Update Data in a Node
                |-- Delete a Node
                |-- Display Tree
                `-- Search for Data (Binary Search)
        `-- Binary Search Tree/ (left data < right data)
            |-- Traversal/
            |   |-- Bread First Traversal
            |   `-- Depth First Traversal/
            |       |-- In-order Traversal: Left - Root - Right (LEFT, DATA, RIGHT) (SORTED LIST)
            |       |-- Pre-order Traversal: Root - Left - Right (DATA, LEFT, RIGHT)
            |       `-- Post-order Traversal: Left - Right - Root (LEFT, RIGHT, DATA)
*/

#include <iostream>
using namespace std;

class TreeNode {
public:
    int value;
    TreeNode *left, *right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}

    ~TreeNode() {
        delete left;
        delete right;
    }
};

class BinarySearchTree {
private:
    TreeNode *root;

    TreeNode* insert(TreeNode* node, int value) {
        if (!node) {
            return new TreeNode(value);
        }
        if (value < node->value) {
            node->left = insert(node->left, value);
        } else if (value > node->value) {
            node->right = insert(node->right, value);
        }
        return node;
    }

    TreeNode* search(TreeNode* node, int value) {
        if (!node || node->value == value) {
            return node;
        }
        if (value < node->value) {
            return search(node->left, value);
        }
        return search(node->right, value);
    }

    TreeNode* findMinimum(TreeNode* node) {
        while (node->left) {
            node = node->left;
        }
        return node;
    }

    TreeNode* deleteNode(TreeNode* node, int value) {
        if (!node) return nullptr;
        if (value < node->value) {
            node->left = deleteNode(node->left, value);
        } else if (value > node->value) {
            node->right = deleteNode(node->right, value);
        } else {
            if (!node->left) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }
            TreeNode* temp = findMinimum(node->right);
            node->value = temp->value;
            node->right = deleteNode(node->right, temp->value);
        }
        return node;
    }

    void inOrderTraversal(TreeNode* node) {
        if (!node) return;
        inOrderTraversal(node->left);
        cout << node->value << " ";
        inOrderTraversal(node->right);
    }

    void preOrderTraversal(TreeNode* node) {
        if (!node) return;
        cout << node->value << " ";
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }

    void postOrderTraversal(TreeNode* node) {
        if (!node) return;
        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        cout << node->value << " ";
    }

public:
    BinarySearchTree() : root(nullptr) {}

    ~BinarySearchTree() {
        delete root;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    bool search(int value) {
        return search(root, value) != nullptr;
    }

    void deleteNode(int value) {
        root = deleteNode(root, value);
    }

    void update(int oldValue, int newValue) {
        root = deleteNode(root, oldValue);
        root = insert(root, newValue);
    }

    void inOrderTraversal() {
        inOrderTraversal(root);
        cout << endl;
    }

    void preOrderTraversal() {
        preOrderTraversal(root);
        cout << endl;
    }

    void postOrderTraversal() {
        postOrderTraversal(root);
        cout << endl;
    }
};

int main() {
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    cout << "In-order traversal: ";
    bst.inOrderTraversal();

    cout << "Pre-order traversal: ";
    bst.preOrderTraversal();

    cout << "Post-order traversal: ";
    bst.postOrderTraversal();

    cout << "Searching for 40: " << (bst.search(40) ? "Found" : "Not found") << endl;

    bst.update(40, 45);
    cout << "After updating 40 to 45 and in-order traversal: ";
    bst.inOrderTraversal();

    bst.deleteNode(45);
    cout << "After deleting 45 and in-order traversal: ";
    bst.inOrderTraversal();

    return 0;
}