#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>


typedef struct stackNode_t {
    int data, data1;
    struct stackNode_t *next;
} StackNode;

typedef struct stack_t {
    StackNode *_top;
    unsigned _size;
} Stack;

void stack_init(Stack *stack);
bool stack_isEmpty(Stack *stack);
void stack_push(Stack *stack, int value);
void stack_pop(Stack *stack);
int stack_top(Stack *stack);
unsigned stack_size(Stack *stack);
void combine(Stack *stack, int past, int future, int* hasil);
int stack_top1(Stack *stack);

int main()
{
	int n,q;
	scanf("%d %d", &n, &q);
	Stack myStack[n];
	
	int i,j;
	for(i=0;i<n;i++)
		stack_init(&myStack[i]);
	
	while(q--){
		int urutan, comm;
		int angka;
		scanf("%d", &comm);
		if(comm==1){
			
			scanf("%d", &urutan);
			scanf("%d", &angka);
			stack_push(&myStack[urutan-1], angka);
		}
		else if(comm==2){
			scanf("%d", &urutan);
			stack_pop(&myStack[urutan-1]);
		}
		else if(comm==3){
			int s1,s2;
			scanf("%d %d", &s1, &s2);
			int hasil;
			combine(myStack, s1,s2, &hasil);
			if (hasil<0) printf("Tidak Ada!\n");
			else printf("%d\n", hasil);
		}
	}
	return 0;
}

void combine(Stack *stack, int past, int future, int* hasil){
	int max1,max2;
	max1=-1;max2=-1;
	int i;
	for(i=past-1; i<future; i++){
		if(!stack_isEmpty(&stack[i])){
			int m1=stack[i]._top->data;
			int m2=stack[i]._top->data1;
			if(max1 < m1){
				max2=max1;
				max1=m1;
			}
		
			else if(max2 < m1)
				max2=m1;
		
			if(max2 < m2)
				max2=m2;
		}
	}	
	if (max2 < 0){
		*hasil=max1; return;
	} 
	else{
		*hasil=max2; return;	
	} 
}

void stack_init(Stack *stack) 
{
    stack->_size = 0;
    stack->_top = NULL;
    return;
}

bool stack_isEmpty(Stack *stack) {
    return (stack->_top == NULL);
}

void stack_push(Stack *stack, int value) 
{
    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
    if (newNode) {
        stack->_size++;
        if (stack_isEmpty(stack)){
        	newNode->data=value;
        	newNode->data1=-1;
        	newNode->next = NULL;
		} 
        else{
        	newNode->data=stack_top(stack);
        	newNode->data1=stack_top1(stack);
        	
			if(newNode->data < value){
				newNode->data1=newNode->data;
				newNode->data=value;
			}
        	
			else if (newNode->data1 < value)
				newNode->data1=value;
			
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
    if (stack_isEmpty(stack)) return -1;
    return stack->_top->data;
}

int stack_top1(Stack *stack) 
{
    if (stack_isEmpty(stack)) return -1;
    return stack->_top->data1;
}

unsigned stack_size(Stack *stack) {
    return stack->_size;
}
