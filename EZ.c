#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/* Struktur Node */

typedef struct stackNode_t {
    int max1, max2;
    struct stackNode_t *next;
} StackNode;

/* Struktur ADT Stack */

typedef struct stack_t {
    StackNode *_top;
    unsigned _size;
} Stack;

/* Function prototype */

void stack_init(Stack *stack);
bool stack_isEmpty(Stack *stack);
void stack_push(Stack *stack, int value);
void stack_pop(Stack *stack);
int stack_top(Stack *stack);
unsigned stack_size(Stack *stack);

/* Function definition below */

void stack_init(Stack *stack) 
{
    stack->_size = 0;
    stack->_top = NULL;
}

bool stack_isEmpty(Stack *stack) {
    return (stack->_top == NULL);
}

void stack_push(Stack *stack, int value) 
{
    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
    if (newNode) {
        stack->_size++;
        if (stack_isEmpty(stack))
        {
            newNode->next = NULL;
            newNode->max1 = value;
            newNode->max2 = -1;
            stack->_top = newNode;
        }
        else
        {
            newNode->max1 = stack->_top->max1;
            newNode->max2 = stack->_top->max2;

            if(newNode->max1 < value){
                newNode->max2 = newNode->max1;
                newNode->max1 = value;
            }
            else if(newNode->max2 < value)
            {
                newNode->max2 = value;
            }
            newNode->next = stack->_top; 
        } 

        stack->_top = newNode;
    }
}

void stack_pop(Stack *stack) 
{
    if (!stack_isEmpty(stack)) {
        StackNode *temp = stack->_top;
        stack->_top = stack->_top->next;
        free(temp);
        stack->_size--;
    }
}

int stack_top(Stack *stack) 
{
    if (!stack_isEmpty(stack)) 
        return stack->_top->max1;
    return 0;
}


unsigned stack_size(Stack *stack) {
    return stack->_size;
}

void cek(Stack *stack, int awal, int akhir, int *hasil)
{
    int maks1=-1, maks2=-1;
    int i;
    for(i=awal-1 ; i<akhir; i++)
    {
        if(!stack_isEmpty(&stack[i]))
        {
            int m1 = stack[i]._top->max1;
            int m2 = stack[i]._top->max2;
            if(maks1 < m1)
            {
                maks2 = maks1;
                maks1 = m1;
            }
            else if(maks2 < m1)
            {
                maks2 = m1;
            }
            
            if(maks2 < m2)
            {
                maks2 = m2;
            }

        }
    }
    if(maks2 < 0) *hasil = maks1;
    else *hasil = maks2;
}

int main(int argc, char const *argv[])
{
    int stak, test, X, V, L, R, perintah;
    int i;

    scanf("%d %d", &stak, &test);

    Stack stack[stak];
    for(i=0; i<stak; i++)
    {
        stack_init(&stack[i]);
    }

    for(i=0; i<test; i++)
    {
        scanf("%d", &perintah);
        if(perintah == 1)
        {
            scanf("%d %d", &X, &V);
            stack_push(&stack[X-1], V);
        }
        else if(perintah == 2)
        {
            scanf("%d", &X);
            stack_pop(&stack[X-1]);
        }
        else if(perintah == 3)
        {
            scanf("%d %d", &L, &R);
            int hasil =0;
            cek(stack, L, R, &hasil);
            if(hasil > 0) printf("%d\n", hasil);
            else printf("Tidak Ada!\n");
        }
    }
    return 0;
}