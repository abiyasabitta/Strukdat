#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct queueNode_t {
    int data;
    struct queueNode_t *next;
} QueueNode;

/* Struktur ADT Queue */

typedef struct queue_t {
    QueueNode   *_front, 
                *_rear;
    unsigned _size;
} Queue;

/* Function prototype */

void queue_init(Queue *queue);
bool queue_isEmpty(Queue *queue);
void queue_push_tot(Queue *queue, int value, int banyak);
void queue_push(Queue *queue, int value);
void queue_pop(Queue *queue);
int  queue_front(Queue *queue);
int  queue_size(Queue *queue);
float rata(Queue *queue);
int jumlah(Queue *queue, int bat);

void queue_init(Queue *queue)
{
    queue->_size = 0;
    queue->_front = NULL;
    queue->_rear = NULL;
}

bool queue_isEmpty(Queue *queue) {
    return (queue->_front == NULL && queue->_rear == NULL);
}

void queue_push(Queue *queue, int value)
{
    QueueNode *newNode = (QueueNode*) malloc(sizeof(QueueNode));
    if (newNode) {
        queue->_size++;
        newNode->data = value;
        newNode->next = NULL;
        
        if (queue_isEmpty(queue))                 
            queue->_front = queue->_rear = newNode;
        else {
            queue->_rear->next = newNode;
            queue->_rear = newNode;
        }
    }
}

void queue_push_tot(Queue *queue, int value, int banyak)
{
    QueueNode *newNode = (QueueNode*) malloc(sizeof(QueueNode));
    if (newNode) {
        queue->_size++;
        newNode->data = value*banyak;
        newNode->next = NULL;
        
        if (queue_isEmpty(queue))                 
            queue->_front = queue->_rear = newNode;
        else {
            queue->_rear->next = newNode;
            queue->_rear = newNode;
        }
    }
}

void queue_pop(Queue *queue)
{
    if (!queue_isEmpty(queue)) {
        QueueNode *temp = queue->_front;
        queue->_front = queue->_front->next;
        free(temp);
        
        if (queue->_front == NULL)
            queue->_rear = NULL;
        queue->_size--;
    }
}

float rata(Queue *queue){
    QueueNode *trav = queue->_front;
    float div = 0, temp = 0;
    while(trav){
	
        temp += trav->data;
        trav = trav->next;
        div++;
    }
    return temp/div;
}

int jumlah(Queue *queue, int bat){
	QueueNode *trav = queue->_front;
	int temp=0, x=0;
	while(trav&&x<bat){
		temp += trav->data;
		trav = trav->next;
		x++;
	}
	return temp;
}

int main(){

    Queue myQueue, myQueue1, myQueue2;
    queue_init(&myQueue);
	queue_init(&myQueue1);
	queue_init(&myQueue2);
    int test;
    int i;
    
    scanf("%d",&test);
    
    for (i = 0; i < test; i++)
    {
        int command, jum;
        int harga;
        
        scanf("%d",&command);
        
		if(command == 1){
            scanf("%d %d",&harga,&jum);
            queue_push(&myQueue, harga);
            queue_push(&myQueue1, jum);
			queue_push(&myQueue2,harga*jum);
        }
        else if(command == 2){
            if((!queue_isEmpty(&myQueue))){
                queue_pop(&myQueue2);
            	queue_pop(&myQueue1);
            	queue_pop(&myQueue);
			}
            else
            {
                printf("Yah habis :(\n");
            }
        }
        else if(command == 3){
            float divide = rata(&myQueue2);
            printf("Rata-rata : %.4f\n", divide);
//            printf("Rata-rata : %.4f\n",rata(&myQueue1));
//            printf("Rata-rata : %.4f\n",rata(&myQueue));
        }
        else if(command == 4){
        	int batas;
        	scanf("%d",&batas);
        	int sum = jumlah(&myQueue,batas);
        	int dum = jumlah(&myQueue1,batas);
        	printf("Harga Total : %d, Jumlah Total : %d\n", sum, dum );
		}
    }
}
