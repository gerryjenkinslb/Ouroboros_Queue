#include <stdlib.h>
#include <stdio.h>
#include <limits.h>


// Structure of a Node
struct Node
{
    int data;
    struct Node* link;
};

struct Queue
{
    struct Node *rear;
};

// prototypes
void enqueue(struct Queue *q, int data);
int dequeue(struct Queue *q);

// add value to queue q
void enqueue(struct Queue *q, int data)
{
    struct Node *n = malloc(sizeof(struct Node));
    n->data = data;
    if (q->rear == NULL) {
        n->link = n;
    } else {
        n->link = q->rear->link;
        q->rear->link = n;
    }
    q->rear = n;
}

// remove front item and return it or INT_MIN if empty queue
int dequeue(struct Queue *q)
{
    if (q->rear == NULL)
    {
        printf ("Queue is empty\n");
        return INT_MIN;
    }
    struct Node *front = q->rear->link;
    if( front->link == q->rear->link) {
      q->rear = NULL;
    } else {
      q->rear->link = front->link;
    }
    int data = front->data;
    free(front);
    return data;
}

// Function displaying the elements of Circular Queue
void displayQueue(struct Queue *q)
{ 
  printf("Elements in Circular Queue are: ");
    if(q->rear != NULL) {
      struct Node *n = q->rear->link; // front
      printf("%d ", n->data);
      while (n != q->rear) {
        n = n->link;
        printf("%d ", n->data);
      }
      printf("\n");
    }
}

/* Driver of the program */
int main()
{
    // Create a queue and initialize front and rear
    printf("testing\nenqueue 1, 2, 3 into Queue\n");
    struct Queue *q = malloc(sizeof(struct Queue));
    q->rear = NULL;
    
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);

    printf("dequeue(q) -> %d\n", dequeue(q));
    printf("enqueue 4, 5\n");
    enqueue(q, 4);
    enqueue(q, 5);

    displayQueue(q);

    printf("loop dequeue till empty\n");
    int data = 0;
    while(1) {
        data = dequeue(q);
        if(data == INT_MIN) {
            break;
        }
        printf("%d\n", data);
    }
    return 0;
}
