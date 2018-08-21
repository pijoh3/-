//¿¹Á¦ 6-1
/*#include <stdio.h>
#include <stdlib.h>
#define Q_SIZE 4

typedef char element;
typedef struct
{
	element queue[Q_SIZE];
	int front, rear;
}QueueType;

QueueType * createQueue()
{
	QueueType * Q;
	Q = (QueueType *)malloc(sizeof(QueueType));
	Q->front = -1;
	Q->rear = -1;
	return Q;
}

int isEmpty(QueueType *Q)
{
	if (Q->front == Q->rear)
	{
		printf(" Queu is empty! ");
		return 1;
	}
	else return 0;
}

int isFull(QueueType * Q)
{
	if (Q->rear == Q_SIZE - 1)
	{
		printf(" Queue is full! ");
		return 1;
	}
	else return 0;
}

void enQueue(QueueType * Q, element item)
{
	if (isFull(Q)) return;
	else
	{
		Q->rear++;
		Q->queue[Q->rear] = item;
	}
}

element deQueue(QueueType * Q)
{
	if (isEmpty(Q)) return;
	else
	{
		Q->front++;
		return Q->queue[Q->front];
	}
}

element peek(QueueType *Q)
{
	if (isEmpty(Q))exit(1);
	else return Q->queue[Q->front + 1];
}

void printQ(QueueType *Q)
{
	int i;
	printf(" Queue : [");
	for (i = Q->front + 1; i <= Q->rear; i++)
		printf("%3c", Q->queue[i]);
	printf(" ]");
}

void main()
{
	QueueType * Q1 = createQueue();
	element data;
	printf("\n ***** ¼øÂ÷ Å¥ ¿¬»ê ***** \n");
	printf("\n »ðÀÔ A>>"); enQueue(Q1, 'A'); printQ(Q1);
	printf("\n »ðÀÔ B>>"); enQueue(Q1, 'B'); printQ(Q1);
	printf("\n »ðÀÔ C>>"); enQueue(Q1, 'C'); printQ(Q1);
	data = peek(Q1); printf(" peek item : %c \n", data);
	printf("\n »èÁ¦ >>"); data = deQueue(Q1); printQ(Q1);
	printf("\t»èÁ¦ µ¥ÀÌÅÍ : %c", data);
	printf("\n »èÁ¦ >>"); data = deQueue(Q1); printQ(Q1);
	printf("\t»èÁ¦ µ¥ÀÌÅÍ : %c", data);
	printf("\n »èÁ¦ >>"); data = deQueue(Q1); printQ(Q1);
	printf("\t»èÁ¦ µ¥ÀÌÅÍ : %c", data);

	printf("\n »ðÀÔ D>>"); enQueue(Q1, 'D'); printQ(Q1);
	printf("\n »ðÀÔ E>>"); enQueue(Q1, 'E'); printQ(Q1);
	getchar();
}*/

/*//¿¹Á¦ 6-2
#include <stdio.h>
#include <stdlib.h>
#define cQ_SIZE 4

typedef char element;
typedef struct
{
	element queue[cQ_SIZE];
	int front, rear;
}QueueType;

QueueType * createQueue()
{
	QueueType *cQ;
	cQ = (QueueType*)malloc(sizeof(QueueType));
	cQ->front = 0;
	cQ->rear = 0;
	return cQ;
}

int isEmpty(QueueType * cQ)
{
	if (cQ->front == cQ->rear)
	{
		printf("Circular Queue is empty! ");
		return 1;
	}
	else return 0;
}

int isFull(QueueType * cQ)
{
	if ((cQ->rear + 1) % cQ_SIZE == cQ->front)
	{
		printf("Circular Queue is full! ");
		return 1;
	}
	else return 0;
}

void enQueue(QueueType *cQ, element item)
{
	if (isFull(cQ)) return;
	else
	{
		cQ->rear = (cQ->rear + 1) % cQ_SIZE;
		cQ->queue[cQ->rear] = item;
	}
}

element deQueue(QueueType * cQ)
{
	if (isEmpty(cQ)) exit(1);
	else
	{
		cQ->front = (cQ->front + 1) % cQ_SIZE;
		return cQ->queue[cQ->front];
	}
}

element peek(QueueType *cQ)
{
	if (isEmpty(cQ)) exit;
	else return cQ->queue[(cQ->front + 1) % cQ_SIZE];
}

void printQ(QueueType * cQ)
{
	int i, first, last;
	first = (cQ->front + 1) % cQ_SIZE;
	last = (cQ->rear + 1) % cQ_SIZE;
	printf(" Circular Queue : [");
	i = first;
	while (i != last)
	{
		printf("%3c", cQ->queue[i]);
		i = (i + 1) % cQ_SIZE;
	}
	printf(" ] ");
}

void main()
{
	QueueType *cQ = createQueue();
	element data;
	printf("\n ***** ¿øÇü Å¥ ¿¬»ê ***** \n");
	printf("\n »ðÀÔ A>>"); enQueue(cQ, 'A'); printQ(cQ);
	printf("\n »ðÀÔ B>>"); enQueue(cQ, 'B'); printQ(cQ);
	printf("\n »ðÀÔ C>>"); enQueue(cQ, 'C'); printQ(cQ);
	data = peek(cQ); printf(" peek item : %c \n", data);
	printf("\n »èÁ¦ >>"); data = deQueue(cQ); printQ(cQ);
	printf("\t»èÁ¦ µ¥ÀÌÅÍ : %c", data);
	printf("\n »èÁ¦ >>"); data = deQueue(cQ); printQ(cQ);
	printf("\t»èÁ¦ µ¥ÀÌÅÍ : %c", data);
	printf("\n »èÁ¦ >>"); data = deQueue(cQ); printQ(cQ);
	printf("\t\t»èÁ¦ µ¥ÀÌÅÍ : %c", data);
	printf("\n »ðÀÔ D>>"); enQueue(cQ, 'D'); printQ(cQ);
	printf("\n »ðÀÔ E>>"); enQueue(cQ, 'E'); printQ(cQ);
	getchar();
}*/

/*//¿¹Á¦ 6-3
#include <stdio.h>
#include <malloc.h>

typedef char element;
typedef struct QNode
{
	element data;
	struct QNode * link;
}QNode;

typedef struct
{
	QNode *front, *rear;
}LQueueType;

LQueueType *createLinkedQueue()
{
	LQueueType * LQ;
	LQ = (LQueueType *)malloc(sizeof(LQueueType));
	LQ->front = NULL;
	LQ->rear = NULL;
	return LQ;
}

int isEmpty(LQueueType *LQ)
{
	if (LQ->front == NULL)
	{
		printf(" Linked Queue is empty! ");
		return 1;
	}
	else return 0;
}

void enQueue(LQueueType *LQ, element item)
{
	QNode *newNode = (QNode *)malloc(sizeof(QNode));
	newNode->data = item;
	newNode->link = NULL;
	if (LQ->front == NULL)
	{
		LQ->front = newNode;
		LQ->rear = newNode;
	}
	else
	{
		LQ->rear->link = newNode;
		LQ->rear = newNode;
	}
}

element deQueue(LQueueType * LQ)
{
	QNode * old = LQ->front;
	element item;
	if (isEmpty(LQ))return 0;
	else
	{
		item = old->data;
		LQ->front = LQ->front->link;
		if (LQ->front == NULL)
			LQ->rear = NULL;
		free(old);
		return item;
	}
}

element peek(LQueueType *LQ)
{
	element item;
	if (isEmpty(LQ)) return 0;
	else
	{
		item = LQ->front->data;
		return item;
	}
}

void printLQ(LQueueType *LQ)
{
	QNode *temp = LQ->front;
	printf(" Linked Queue : [");
	while (temp)
	{
		printf("%3c", temp->data);
		temp = temp->link;
	}
	printf(" ]");
}

void main()
{
	LQueueType *LQ = createLinkedQueue();
	element data;
	printf("\n ***** ¿¬°á Å¥ ¿¬»ê ***** \n");
	printf("\n »ðÀÔ A>>"); enQueue(LQ, 'A'); printLQ(LQ);
	printf("\n »ðÀÔ B>>"); enQueue(LQ, 'B'); printLQ(LQ);
	printf("\n »ðÀÔ C>>"); enQueue(LQ, 'C'); printLQ(LQ);
	printf("\n »ðÀÔ D>>"); enQueue(LQ, 'D'); printLQ(LQ);
	printf("\n »ðÀÔ E>>"); enQueue(LQ, 'E'); printLQ(LQ);
	printf("\n »ðÀÔ F>>"); enQueue(LQ, 'F'); printLQ(LQ);
	printf("\n »ðÀÔ G>>"); enQueue(LQ, 'G'); printLQ(LQ);
	printf("\n »ðÀÔ H>>"); enQueue(LQ, 'H'); printLQ(LQ);

	data = peek(LQ); printf(" peek item : %c \n", data);
	printf("\n »èÁ¦ >>"); data = deQueue(LQ); printLQ(LQ);
	printf("\t»èÁ¦ µ¥ÀÌÅÍ : %c", data);
	printf("\n »èÁ¦ >>"); data = deQueue(LQ); printLQ(LQ);
	printf("\t»èÁ¦ µ¥ÀÌÅÍ : %c", data);
	printf("\n »èÁ¦ >>"); data = deQueue(LQ); printLQ(LQ);
	printf("\t\t»èÁ¦ µ¥ÀÌÅÍ : %c", data);
	printf("\n »ðÀÔ D>>"); enQueue(LQ, 'D'); printLQ(LQ);
	printf("\n »ðÀÔ E>>"); enQueue(LQ, 'E'); printLQ(LQ);
	getchar();
}*/

//¿¹Á¦ 6-4
#include <stdio.h>
#include <malloc.h>

typedef char element;
typedef struct DQNode
{
	element data;
	struct DQNode *llink;
	struct DQNode *rlink;
}DQNode;

typedef struct
{
	DQNode *front, *rear;
}DQueType;

DQueType * createDQue()
{
	DQueType *DQ;
	DQ = (DQueType *)malloc(sizeof(DQueType));
	DQ->front = NULL;
	DQ->rear = NULL;
	return DQ;
}

int isEmpty(DQueType * DQ)
{
	if (DQ->front == NULL)
	{
		printf("\n Linked Queue is empty! \n");
		return 1;
	}
	else return 0;
}

void insertFront(DQueType *DQ, element item)
{
	DQNode * newNode = (DQNode *)malloc(sizeof(DQNode));
	newNode->data = item;
	if (DQ->front == NULL)
	{
		DQ->front = newNode;
		DQ->rear = newNode;
		newNode->rlink = NULL;
		newNode->llink = NULL;
	}
	else
	{
		DQ->front->llink = newNode;
		newNode->rlink = DQ->front;
		newNode->llink = NULL;
		DQ->front = newNode;
	}
}

void insertRear(DQueType *DQ, element item)
{
	DQNode * newNode = (DQNode *)malloc(sizeof(DQNode));
	newNode->data = item;
	if (DQ->rear == NULL)
	{
		DQ->front = newNode;
		DQ->rear = newNode;
		newNode->rlink = NULL;
		newNode->llink = NULL;
	}
	else
	{
		DQ->rear->rlink = newNode;
		newNode->rlink = NULL;
		newNode->llink = DQ->rear;
		DQ->rear = newNode;
	}
}

element deleteFront(DQueType *DQ)
{
	DQNode *old = DQ->front;
	element item;
	if (isEmpty(DQ))return 0;
	else
	{
		item = old->data;
		if (DQ->front->rlink == NULL)
		{
			DQ->front = NULL;
			DQ->rear = NULL;
		}
		else
		{
			DQ->front = DQ->front->rlink;
			DQ->front->llink = NULL;
		}
		free(old);
		return item;
	}
}

element deleteRear(DQueType *DQ)
{
	DQNode *old = DQ->rear;
	element item;
	if (isEmpty(DQ)) return 0;
	else
	{
		item = old->data;
		if (DQ->rear->llink == NULL)
		{
			DQ->front = NULL;
			DQ->rear = NULL;
		}
		else
		{
			DQ->rear = DQ->rear->llink;
			DQ->rear->rlink = NULL;
		}
		free(old);
		return item;
	}
}

element peekFront(DQueType *DQ)
{
	element item;
	if (isEmpty(DQ)) return 0;
	else
	{
		item = DQ->front->data;
		return item;
	}
}

element peekRear(DQueType *DQ)
{
	element item;
	if (isEmpty(DQ)) return 0;
	else
	{
		item = DQ->rear->data;
		return item;
	}
}

void printDQ(DQueType *DQ)
{
	DQNode * temp = DQ->front;
	printf("DeQue : [");
	while (temp)
	{
		printf("%3c", temp->data);
		temp = temp->rlink;
	}
	printf(" ]");
}

void main()
{
	DQueType *DQ1 = createDQue();
	element data;
	printf("\n ***** µ¥Å© ¿¬»ê ***** \n");
	printf("\n front »ðÀÔ A>> "); insertFront(DQ1, 'A'); printDQ(DQ1);
	printf("\n front »ðÀÔ B>> "); insertFront(DQ1, 'B'); printDQ(DQ1);
	printf("\n rear »ðÀÔ C>> "); insertRear(DQ1, 'C'); printDQ(DQ1);
	printf("\n front »èÁ¦ >> "); data = deleteFront(DQ1); printDQ(DQ1);
	printf("\t»èÁ¦ µ¥ÀÌÅÍ : %c", data);
	printf("\n rear »èÁ¦ >> "); data = deleteRear(DQ1); printDQ(DQ1);
	printf("\t\t»èÁ¦ µ¥ÀÌÅÍ : %c", data);
	printf("\n rear »ðÀÔ D>> "); insertRear(DQ1, 'D'); printDQ(DQ1);
	printf("\n front »ðÀÔ E>> "); insertFront(DQ1, 'E'); printDQ(DQ1);
	printf("\n front »ðÀÔ F>> "); insertFront(DQ1, 'F'); printDQ(DQ1);

	data = peekFront(DQ1); printf("\n peek Front item : %c \n", data);
	data = peekRear(DQ1); printf(" peek Rear item : %c \n", data);

	getchar();
}