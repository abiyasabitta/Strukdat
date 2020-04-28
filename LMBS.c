#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/**
 * Node structure and
 * uniqueBST structure
 */

typedef struct bstnode_t {
    int key;
    struct bstnode_t \
        *left, *right;
} BSTNode;

typedef struct bst_t {
    BSTNode *_root;
    unsigned int _size;
} BST;

void ngecek(int angka, int kode);
/**
 * !!! WARNING UTILITY FUNCTION !!!
 * Recognized by prefix "__bst__"
 * ---------------------------------------------
 * Note that you better never access these functions, 
 * unless you need to modify or you know how these functions work.
 */

BSTNode* __bst__createNode(int value) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* __bst__insert(BSTNode *root, int value) {
    if (root == NULL) 
        return __bst__createNode(value);

    if (value < root->key)
        root->left = __bst__insert(root->left, value);
    else if (value > root->key)
        root->right = __bst__insert(root->right, value);
    
    return root;
}

BSTNode* __bst__search(BSTNode *root, int value) {
    while (root != NULL) {
        if (value < root->key)
            root = root->left;
        else if (value > root->key)
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

BSTNode* __bst__remove(BSTNode *root, int value) {
    if (root == NULL) return NULL;

    if (value > root->key) 
        root->right = __bst__remove(root->right, value);
    else if (value < root->key) 
        root->left = __bst__remove(root->left, value);
    else {
        
        if (root->left == NULL) {
            BSTNode *rightChild = root->right;
            free(root);
            return rightChild;
        }
        else if (root->right == NULL) {
            BSTNode *leftChild = root->left;
            free(root);
            return leftChild;
        }

        BSTNode *temp = __bst__findMinNode(root->right);
        root->key     = temp->key;
        root->right   = __bst__remove(root->right, temp->key);
    }
    return root;
}

void __bst__inorder(BSTNode *root, int kode) {
    if (root) {
        __bst__inorder(root->left, kode);
        ngecek(root->key, kode);
        __bst__inorder(root->right, kode);
    }
}

void __bst__postorder(BSTNode *root, int kode) {
    if (root) {
        __bst__postorder(root->left, kode);
        __bst__postorder(root->right, kode);
        ngecek(root->key, kode);
    }
}

void __bst__preorder(BSTNode *root, int kode) {
    if (root) {
        ngecek(root->key, kode);
        __bst__preorder(root->left, kode);
        __bst__preorder(root->right, kode);
    }
}

/**
 * PRIMARY FUNCTION
 * ---------------------------
 * Accessible and safe to use.
 */

void bst_init(BST *bst) {
    bst->_root = NULL;
    bst->_size = 0u;
}

bool bst_isEmpty(BST *bst) {
    return bst->_root == NULL;
}

bool bst_find(BST *bst, int value) {
    BSTNode *temp = __bst__search(bst->_root, value);
    if (temp == NULL)
        return false;
    
    if (temp->key == value)
        return true;
    else
        return false;
}

void bst_insert(BST *bst, int value) {
    if (!bst_find(bst, value)) {
        bst->_root = __bst__insert(bst->_root, value);
        bst->_size++;
    }
}

void bst_remove(BST *bst, int value) {
    if (bst_find(bst, value)) {
        bst->_root = __bst__remove(bst->_root, value);
        bst->_size--;
    }
}

// Ngecek-------------------------------------------------------------------------------
void cek_bentuk(int *form)
{
    char bentuk[10];
    scanf(" %s", &bentuk);
        if(strcmp(bentuk, "genap") == 0)
        {
            *form = 1;
        }
        else if(strcmp(bentuk, "ganjil") == 0)
        {
            *form = 2;
        }
        else if(strcmp(bentuk, "prima") == 0)
        {
            *form = 3;
        }
         else if(strcmp(bentuk, "semua") == 0)
        {
            *form = 4;
        }
}

void ngecek(int angka, int kode)
{
    int cek;
    cek = 0;
    if(kode == 1)
    {
        if(angka%2 == 0) printf("%d\n", angka);
    }
    else if(kode == 2)
    {
        if(angka%2 == 1) printf("%d\n", angka);
    }
    else if(kode == 3)
    {
        for(int j=2; j<angka; j++)
        {
            if(angka%j == 0)
            {
                cek++;
                break;
            }
        }
        if(cek == 0 && angka != 1 && angka != 0) printf("%d\n", angka);
    }
    else if(kode == 4) printf("%d\n", angka);
}

//NGISI TREE---------------------------------------------------------------------------------

void ngisi(BST *tree)
{
    int isi;
    scanf("%d", &isi);
    if(isi != -1)
    {
        bst_insert(tree, isi);
        ngisi(tree);
    }
}
/**
 * Binary search tree traversal
 * - Inorder
 * - Postorder
 * - Preorder
 */

void bst_inorder(BST *bst, int kode){
    __bst__inorder(bst->_root, kode);
}

void bst_postorder(BST *bst, int kode) {
    __bst__postorder(bst->_root, kode);
}

void bst_preorder(BST *bst, int kode) {
    __bst__preorder(bst->_root, kode);
}

int main()
{
    BST set;
    bst_init(&set);

    int test_case, bentuk;
    char perintah[10];

    ngisi(&set);

        scanf("%d", &test_case);
        for(int i=1; i<=test_case; i++)
        {
            scanf("%s", &perintah);
            if(strcmp(perintah, "preorder") == 0)
            {
                cek_bentuk(&bentuk);
                printf("Command : #%d\n", i);
                bst_preorder(&set, bentuk);
            }
            else if(strcmp(perintah, "postorder") == 0)
            {
                cek_bentuk(&bentuk);
                printf("Command : #%d\n", i);
                bst_postorder(&set, bentuk);
            }
            else if(strcmp(perintah, "inorder") == 0)
            {
                  cek_bentuk(&bentuk);
                  printf("Command : #%d\n", i);
                  bst_inorder(&set, bentuk);
            }
        }
    
    return 0;
}