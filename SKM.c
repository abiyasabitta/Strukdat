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

void cari_anak(BST *bst, int angka, int *no_anak)
{
    BSTNode *temp = __bst__search(bst->_root, angka);
    
    if(temp->left == NULL && temp->right == NULL)
    {
        printf("diManakah Anak- aNakkuu :(\n");
        *no_anak = 1;
    }
    else
    {
        if(temp->left == NULL) printf("- ");
        else printf("%d ", temp->left->key);
        if(temp->right == NULL) printf("-\n");
        else printf("%d\n", temp->right->key);
    }
    
}

void cari_emak(BST *bst, int angka)
{
    BSTNode* cek1 = bst->_root;
    BSTNode* cek2 = cek1;

        while (cek1 != NULL)
        {
            if (angka > cek1->key)
            {
                cek2 = cek1;
                cek1 = cek1->right;
            }
            else if (angka < cek1->key)
            {
                cek2 = cek1;
                cek1 = cek1->left;
            }
            else if (angka == cek1->key)
            {
                break;
            }
        }

        if (cek1 == bst->_root)
            printf("Aku adalaH sesepuH\n");
        else
            printf("%d\n", cek2->key);        
}



int main()
{
    BST keluarga;
    bst_init(&keluarga);

    int test, perintah, angka, i, no_kids = 0;
    char tipe[5];

    scanf("%d", &test);
    for(i = 0; i<test; i++)
    {
        scanf("%d", &perintah);
        if(perintah == 1)
        {
            scanf("%d", &angka);
            bst_insert(&keluarga, angka);
        }
        else if(perintah == 2)
        {
            scanf("%s", &tipe);
            if(tipe[0] == 'i')
            {   
                scanf("%d", &angka);
                cari_emak(&keluarga, angka);
            }
            else if(tipe[0] == 'a')
            {
                scanf("%d", &angka);
                cari_anak(&keluarga, angka, &no_kids);
                if(no_kids == 1) break;
            }
        }
    }
    return 0;
}