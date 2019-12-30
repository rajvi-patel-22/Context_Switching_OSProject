typedef struct Queue
{
        int capacity;
        int size;
        int front;
        int rear;
        int *elements;
		int* data;
		int s;
}Queue;

Queue * createQueue(int maxElements);
void Enqueue(Queue *Q,int element);
int Dequeue(Queue *Q);
int front(Queue *Q);
int display(Queue *Q);
int search(Queue *Q,int element);
