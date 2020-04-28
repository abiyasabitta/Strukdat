#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct bstnode_t {
    int key, distance, shortest;
    struct bstnode_t \
        *left, *right;
} BSTNode;

typedef struct bst_t {
    BSTNode *_root;
    unsigned int _size;
} BST;

BSTNode* __bst__createNode(int nilai, int distance) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = nilai;
    newNode->distance = distance;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* __bst__insert(BSTNode *root, int nilai, int distance) {
    if (root == NULL) 
        return __bst__createNode(nilai, distance);

    if (nilai < root->key)
        root->left = __bst__insert(root->left, nilai, distance);
    else if (nilai > root->key)
        root->right = __bst__insert(root->right, nilai, distance);
    
    return root;
}

BSTNode* __bst__search(BSTNode *root, int nilai) {
    while (root != NULL) {
        if (nilai < root->key)
            root = root->left;
        else if (nilai > root->key)
            root = root->right;
        else
            return root;
    }
    return root;
}

BSTNode* __bst__findMinNode(BSTNode *node) {
    BSTNode *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;
    
    return currNode;
}

void bst_init(BST *bst) {
    bst->_root = NULL;
    bst->_size = 0u;
}

bool bst_isEmpty(BST *bst) {
    return bst->_root == NULL;
}

bool bst_find(BST *bst, int nilai) {
    BSTNode *temp = __bst__search(bst->_root, nilai);
    if (temp == NULL)
        return false;
    
    if (temp->key == nilai)
        return true;
    else
        return false;
}

void bst_insert(BST *bst, int nilai, int distance) {
    if (!bst_find(bst, nilai)) {
        bst->_root = __bst__insert(bst->_root, nilai, distance);
        bst->_size++;
    }
}

int find_shortest(BSTNode *root){
    if (root) {
        if (root->left == NULL && root->right == NULL) root->shortest = 0;
        else if (root->left && root->right){
            int kiri = root->left->distance + find_shortest(root->left);
            int kanan = root->right->distance + find_shortest(root->right);
            if (kiri<kanan){
                root->shortest = kiri;
            } else {
                root->shortest = kanan;
            }
        }
        else if (root->left)
            root->shortest = root->left->distance + find_shortest(root->left);
        else if (root->right) 
            root->shortest = root->right->distance + find_shortest(root->right);
        
        return root->shortest;
    }
    return 0;
}

void cari_atas(BSTNode *parent, BSTNode *root){
    if (root->shortest > parent->shortest + root->distance)
        root->shortest = parent->shortest + root->distance;
    if (root->left) cari_atas(root, root->left);
    if (root->right) cari_atas(root, root->right);
}

void cari_atas2(BSTNode *root) {
    if (root->left) cari_atas(root, root->left);
    if (root->right) cari_atas(root, root->right);
}

void Find(BSTNode *root, int value){
    while (root != NULL) {
        if (value < root->key)
            root = root->left;
        else if (value > root->key)
            root = root->right;
        else{
            printf("%d\n", root->shortest);
            break;
        }
    }
}

int main ()
{
    BST set;
    bst_init(&set);

    int N, nilai, i, distance, Q;
    scanf("%d", &N);
    scanf("%d", &nilai);

    bst_insert(&set, nilai, 0);
    for (i=1; i<N; i++) {
        scanf("%d %d", &nilai, &distance);
        bst_insert(&set, nilai, distance);
    }
    set._root->shortest = find_shortest(set._root);
    cari_atas2(set._root);
    scanf("%d", &Q);
    for(i=0; i<Q; i++){
        scanf("%d", &nilai);
        Find(set._root, nilai);
    }
}