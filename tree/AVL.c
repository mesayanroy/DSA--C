#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int key, h;
    struct Node *l,*r;
} Node;

int height(Node *n){ return n ? n->h : 0; }
int max(int a,int b){ return a>b?a:b; }

Node* create(int key){
    Node *n = malloc(sizeof(Node));
    n->key = key;
    n->h = 1;
    n->l = n->r = NULL;
    return n;
}

Node* rightRotate(Node *y){
    Node *x = y->l;
    Node *T2 = x->r;
    x->r = y;
    y->l = T2;
    y->h = max(height(y->l), height(y->r)) + 1;
    x->h = max(height(x->l), height(x->r)) + 1;
    return x;
}

Node* leftRotate(Node *x){
    Node *y = x->r;
    Node *T2 = y->l;
    y->l = x;
    x->r = T2;
    x->h = max(height(x->l), height(x->r)) + 1;
    y->h = max(height(y->l), height(y->r)) + 1;
    return y;
}

int getBalance(Node *n){
    return n ? height(n->l) - height(n->r) : 0;
}

Node* insert(Node* root, int key){
    if(!root) return create(key);
    if(key < root->key) root->l = insert(root->l, key);
    else if(key > root->key) root->r = insert(root->r, key);
    else return root;

    root->h = 1 + max(height(root->l), height(root->r));
    int bal = getBalance(root);

    if(bal > 1 && key < root->l->key) return rightRotate(root);
    if(bal < -1 && key > root->r->key) return leftRotate(root);
    if(bal > 1 && key > root->l->key){ root->l = leftRotate(root->l); return rightRotate(root); }
    if(bal < -1 && key < root->r->key){ root->r = rightRotate(root->r); return leftRotate(root); }

    return root;
}

int peek(Node *root){
    if(!root) return -1;
    return root->key;
}

int main(){
    Node *root=NULL;
    int arr[]={10,20,30,40,50,25};
    for(int i=0;i<6;i++) root = insert(root, arr[i]);
    printf("Root = %d\n", peek(root));
    return 0;
}
