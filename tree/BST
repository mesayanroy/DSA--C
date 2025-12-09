// bst_menu_switch.c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *l, *r;
} Node;

// Create node
Node* newNode(int k) {
    Node *n = malloc(sizeof(Node));
    n->key = k;
    n->l = n->r = NULL;
    return n;
}

// Insert key (PUSH)
Node* insert(Node *root, int k) {
    if (!root) return newNode(k);

    if (k < root->key)
        root->l = insert(root->l, k);
    else if (k > root->key)
        root->r = insert(root->r, k);

    return root;
}

// Find minimum in right subtree
Node* minValueNode(Node *node) {
    Node *curr = node;
    while (curr && curr->l)
        curr = curr->l;
    return curr;
}

// Delete key (POP)
Node* deleteNode(Node *root, int k) {
    if (!root) return root;

    if (k < root->key)
        root->l = deleteNode(root->l, k);

    else if (k > root->key)
        root->r = deleteNode(root->r, k);

    else {  // FOUND THE NODE
        if (!root->l) {                    // One child or no child
            Node *temp = root->r;
            free(root);
            return temp;
        }
        else if (!root->r) {
            Node *temp = root->l;
            free(root);
            return temp;
        }

        // Two children: replace with inorder successor
        Node *temp = minValueNode(root->r);
        root->key = temp->key;
        root->r = deleteNode(root->r, temp->key);
    }
    return root;
}

// Peek = show root
int peek(Node *root) {
    if (!root) {
        printf("Tree empty\n");
        return -1;
    }
    return root->key;
}

int main() {
    Node *root = NULL;
    int ch, x;

    while (1) {
        printf("\n1. Push (Insert)");
        printf("\n2. Pop (Delete)");
        printf("\n3. Peek (Show Root)");
        printf("\n4. Exit");
        printf("\nChoose: ");

        if (scanf("%d", &ch) != 1) return 0;

        switch (ch) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &x);
                root = insert(root, x);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &x);
                root = deleteNode(root, x);
                printf("Deleted if present.\n");
                break;

            case 3:
                x = peek(root);
                if (x != -1)
                    printf("Root = %d\n", x);
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
}
