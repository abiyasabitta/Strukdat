#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/* Struktur Node */

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

/* Function definition below */

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

int queue_front(Queue *queue)
{
    if (!queue_isEmpty(queue)) {
        return (queue->_front->data);
    }
    return (int)0;
}

int queue_size(Queue *queue) {
    return queue->_size;
}

float rata(Queue *queue){
    QueueNode *now = queue->_front;
    float div = 0, temp = 0;
    while(now){
        temp += now->data;
        now = now->next;
        div++;
    }
    return temp/div;
}

int Total_barang(Queue *queue, int bates)
{
    QueueNode *now = queue->_front;
    int i=0, jumlah_barang=0;
    while(i<bates && now != NULL)
    {
        jumlah_barang += now->data;
        now = now->next;
        i++;
    }
    return jumlah_barang;
}

int Total_harga(Queue *queue, int batas)
{
    QueueNode *now = queue->_front;
    int i=0, jumlah_harga=0;
    while(i<batas && now != NULL)
    {
        jumlah_harga += now->data;
        now = now->next;
        i++;
    }
    return jumlah_harga;
}

int main(int argc, char const *argv[])
{
    Queue myQueue;
    Queue jumlah;
    Queue HARGA;

    queue_init(&myQueue);
    queue_init(&jumlah);
    queue_init(&HARGA);

    int T, i, perintah, X, Y;
    float rata2;

    scanf("%d", &T);
    for(i=0; i<T; i++)
    {
        scanf("%d", &perintah);
        if(perintah == 1)
        {
            scanf("%d %d", &X, &Y);
            queue_push(&myQueue, Y);
            queue_push(&jumlah, X*Y);
            queue_push(&HARGA, X);
        }
        else if(perintah == 2){
            if(!queue_isEmpty(&myQueue))
            {
                queue_pop(&myQueue);
                queue_pop(&jumlah);
                queue_pop(&HARGA);
            }
            else
            {
                printf("Yah habis :(\n");
            }
            
        }
        else if(perintah == 3){
            float divide = rata(&jumlah);
            printf("Rata-rata : %.4f\n", divide);
        }
        else if(perintah == 4){
            scanf("%d", &X);
            int jum_bar = Total_barang(&myQueue, X);
            int jum_har = Total_harga(&HARGA, X);
            printf("Harga Total : %d, Jumlah Total : %d\n", jum_har, jum_bar);
        }
    }
    return 0;
}