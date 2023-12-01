// BST:
// Hierarchical data structure
//
// Left < Right
//
// Search O(n)
// Sort O(logn)
// Delete O(1) if node is known otherwise O(n) || O(logn) depending on tree type
// Insertion O(1) || O(n) || O(logn)

// BST in the example
// 
//                     50
//            __________|__________
//           |                     |
//           30                    70
//        ___|___               ___|___
//       |       |             |       |
//      20       40           60       80
//            ___|___
//           |       |
//          35       41

// BST in the example after removal of item Nr. 30
// 
//                     50
//            __________|__________
//           |                     |
//           35                    70
//        ___|___               ___|___
//       |       |             |       |
//      20       40           60       80
//               |___
//                   |
//                   41

#include <iostream>
#include <queue>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
private:
    TreeNode* root;

    TreeNode* insert(TreeNode* root, int val);
    TreeNode* remove(TreeNode* root, int val);
    TreeNode* findMin(TreeNode* node);
    void inorderTraversal(TreeNode* node);
    void preorderTraversal(TreeNode* node);
    void postorderTraversal(TreeNode* node);
    void levelorderTraversal(TreeNode* root);
    void printLeftBoundary(TreeNode* node);
    void printLeaves(TreeNode* node);
    void printRightBoundary(TreeNode* node);

public:
    BST() : root(nullptr) {}

    void insert(int val);
    void remove(int val);
    void inorderTraversal();
    void preorderTraversal();
    void postorderTraversal();
    void levelorderTraversal();
    void boundaryTraversal();
};

void BST::insert(int val) {
    root = insert(root, val);
}

TreeNode* BST::insert(TreeNode* root, int val) {
    if (root == nullptr) {
        return new TreeNode(val);
    }

    if (val < root->data) {
        root->left = insert(root->left, val);
    }
    else if (val > root->data) {
        root->right = insert(root->right, val);
    }

    return root;
}

void BST::remove(int val) {
    root = remove(root, val);
}

TreeNode* BST::remove(TreeNode* root, int val) {
    if (root == nullptr) {
        return nullptr;
    }

    if (val < root->data) {
        root->left = remove(root->left, val);
    }
    else if (val > root->data) {
        root->right = remove(root->right, val);
    }
    else {
        if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        TreeNode* temp = findMin(root->right);
        root->data = temp->data;
        root->right = remove(root->right, temp->data);
    }

    return root;
}

TreeNode* BST::findMin(TreeNode* node) {
    while (node->left != nullptr) {
        node = node->left;
    }

    return node;
}

void BST::inorderTraversal() {
    inorderTraversal(root);
    std::cout << std::endl;
}

void BST::inorderTraversal(TreeNode* node) {
    if (node != nullptr) {
        inorderTraversal(node->left);
        std::cout << node->data << " ";
        inorderTraversal(node->right);
    }
}

void BST::preorderTraversal() {
    preorderTraversal(root);
    std::cout << std::endl;
}

void BST::preorderTraversal(TreeNode* node) {
    if (node != nullptr) {
        std::cout << node->data << " ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }
}

void BST::postorderTraversal() {
    postorderTraversal(root);
    std::cout << std::endl;
}

void BST::postorderTraversal(TreeNode* node) {
    if (node != nullptr) {
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        std::cout << node->data << " ";
    }
}

void BST::levelorderTraversal() {
    levelorderTraversal(root);
    std::cout << std::endl;
}

void BST::levelorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    std::queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (!nodeQueue.empty()) {
        int levelSize = nodeQueue.size();

        for (int i = 0; i < levelSize; i++) {
            TreeNode* temp = nodeQueue.front();
            std::cout << temp->data << " ";
            nodeQueue.pop();

            if (temp->left != nullptr) {
                nodeQueue.push(temp->left);
            }

            if (temp->right != nullptr) {
                nodeQueue.push(temp->right);
            }
        }

        std::cout << std::endl;
    }
}

void BST::boundaryTraversal() {
    if (root != nullptr) {
        std::cout << root->data << " ";
        printLeftBoundary(root->left);
        printLeaves(root);
        printRightBoundary(root->right);
    }
    std::cout << std::endl;
}

void BST::printLeftBoundary(TreeNode* node) {
    if (node == nullptr || node->left == nullptr && node->right == nullptr) {
        return;
    }

    std::cout << node->data << " ";

    if (node->left != nullptr) {
        printLeftBoundary(node->left);
    } 
    else {
        printLeftBoundary(node->right);
    }
}

void BST::printLeaves(TreeNode* node) {
    if (node == nullptr) {
        return;
    }

    printLeaves(node->left);

    if (node->left == nullptr && node->right == nullptr) {
        std::cout << node->data << " ";
    }

    printLeaves(node->right);
}

void BST::printRightBoundary(TreeNode* node) {
    if (node == nullptr || node->left == nullptr && node->right == nullptr) {
        return;
    }

    std::cout << node->data << " ";

    if (node->right != nullptr) {
        printRightBoundary(node->right);
    }
    else {
        printRightBoundary(node->left);
    }
}

int main()
{
    BST bst;

    // Insert values into the BST
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(35);
    bst.insert(41);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    // Print inorder traversal of the BST
    std::cout << "Inorder Traversal: ";
    bst.inorderTraversal();

    // Print inorder traversal of the BST
    std::cout << "Preorder Traversal: ";
    bst.preorderTraversal();

    // Print postorder traversal of the BST
    std::cout << "Postorder Traversal: ";
    bst.postorderTraversal();

    // Print boundary traversal of the BST
    std::cout << "Boundary Traversal: ";
    bst.boundaryTraversal();

    // Print levelorder traversal of the BST
    std::cout << "Levelorder Traversal:\n";
    bst.levelorderTraversal();

    // Remove a value from the BST
    bst.remove(30);

    // Print inorder traversal after removal
    std::cout << "Inorder Traversal after removal: ";
    bst.inorderTraversal();

    // Print preorder traversal after removal
    std::cout << "Preorder Traversal after removal: ";
    bst.preorderTraversal();

    // Print Postorder traversal after removal
    std::cout << "Postorder Traversal after removal: ";
    bst.postorderTraversal();

    // Print boundary traversal of the BST
    std::cout << "Boundary Traversal after removal: ";
    bst.boundaryTraversal();

    // Print levelorder traversal after removal
    std::cout << "Levelorder Traversal after removal:\n";
    bst.levelorderTraversal();

    return 0;
}
