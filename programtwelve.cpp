#include <iostream>
#include <vector>

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

//create tree
Node* insertNode(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value); //assigns first value as root of the tree
    }

    if (value < root->value) {
        root->left = insertNode(root->left, value);
    } else {
        root->right = insertNode(root->right, value);
    }
    return root;
}

void inOrder(Node* root) {
    if (root == nullptr) {
        return;
    }
    inOrder(root->left);
    std::cout << root->value << " ";
    inOrder(root->right);
}

void preOrder(Node* root) {
    if (root == nullptr) {
        return;
    }

    std::cout << root->value << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node* root) {
    if (root == nullptr) {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    std::cout << root->value << " ";
}

int main() {
    std::vector<int> tree = {50, 75, 25, 15, 60, 35, 90, 42, 20, 27, 5, 55, 95, 80, 70};

    Node* root = nullptr;

    for (int i = 0; i < tree.size(); i++) {
        root = insertNode(root, tree[i]);
    }

    std::cout << "Pre-order: ";
    preOrder(root);
    std::cout << std::endl;

    std::cout << "In-order: ";
    inOrder(root);
    std::cout << std::endl;

    std::cout << "Post-order: ";
    postOrder(root);
    std::cout << std::endl;

    return 0;
}
