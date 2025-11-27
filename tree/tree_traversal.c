#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *left;
    struct node *right;
};
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void inorderTraversal(struct node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}
void preorderTraversal(struct node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
void postorderTraversal(struct node* root) {
    if (root == NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}
int main() {
    struct node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder Traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorderTraversal(root);
    printf("\n");

    // Free allocated memory
    free(root->left->left);
    free(root->left->right);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
/*
Output:
Inorder Traversal: 4 2 5 1 3
Preorder Traversal: 1 2 4 5 3
Postorder Traversal: 4 5 2 3 1
This code implements a binary tree and performs inorder, preorder, and postorder traversals.
It creates a simple binary tree, traverses it in different orders, and prints the results.       
Memory allocated for the nodes is freed at the end to prevent memory leaks.
The code demonstrates the basic structure and traversal methods of a binary tree in C.
The output shows the order of nodes visited in each traversal method.
The inorder traversal visits nodes in the order of left child, root, right child.
The preorder traversal visits nodes in the order of root, left child, right child.
The postorder traversal visits nodes in the order of left child, right child, root.
This code can be compiled and run in a C environment to see the traversal results.
It serves as a basic example of tree traversal techniques in C programming.
The code is structured to create a binary tree, perform different types of traversals,
and print the results to the console.
It is a fundamental example of how to work with trees in C, showcasing memory management and traversal techniques.
The code can be extended to include more complex tree structures or additional functionalities,
such as searching for a specific value or balancing the tree.
*/