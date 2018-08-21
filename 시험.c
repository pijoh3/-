//예제 4-4
/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode
{
struct ListNode * llink;
char data[4];
struct ListNode *rlink;
}listNode;

typedef struct
{
listNode * head;
}linkedList_h;

linkedList_h * createLinkedList_h()
{
linkedList_h * DL;
DL = (linkedList_h *)malloc(sizeof(linkedList_h));
DL->head = NULL;
return DL;
}

void printList(linkedList_h * DL)
{
listNode * p;
printf(" DL = (");
p = DL->head;
while (p != NULL)
{
printf("%s", p->data);
p = p->rlink;
if (p != NULL)printf(", ");
}
printf(")\n");
}

void insertNode(linkedList_h * DL, listNode * pre, char *x)
{
	listNode * newNode = (listNode *)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	if (DL->head == NULL)
	{
		DL->head = newNode;
		newNode->llink = NULL;
		newNode->rlink = NULL;
	}
	else
	{
		newNode->rlink = pre->rlink;
		pre->rlink = newNode;
		newNode->llink = pre;
		if(newNode->rlink != NULL)
		newNode->rlink->llink = newNode;
	}
}

void deleteNode(linkedList_h * DL, listNode * old)
{
	if (DL->head == NULL) return 0;
	else if (old == NULL) return 0;
	old->llink->rlink = old->rlink;
	old->rlink->llink = old->llink;
	free(old);
}

listNode * searchNode(linkedList_h * DL, char * x)
{
listNode * temp;
temp = DL->head;
while (temp != NULL)
{
if (strcmp(temp->data, x) == 0)return temp;
else temp = temp->rlink;
}
return temp;
}

int main()
{
linkedList_h * DL;
listNode *p;
DL = createLinkedList_h();
printf("(1) 이중 연결 리스트 생성하기! \n");
printList(DL); getchar();

printf("(2) 이중 연결 리스트에 [월] 노드 삽입하기\n");
insertNode(DL, NULL, "월");
printList(DL); getchar();

printf("(3) 이중 연결 리스트의 [월] 노드 뒤에 [수] 노드 삽입하기!\n");
p = searchNode(DL, "월"); insertNode(DL, p, "수");
printList(DL); getchar();

printf("(4) 이중 연결 리스트의 [수] 노드 뒤에 [금] 노드 삽입하기!\n");
p = searchNode(DL, "수"); insertNode(DL, p, "금");
printList(DL); getchar();

printf("(5) 이중 연결 리스트에서 [수] 노드 삭제하기\n");
p = searchNode(DL, "수"); deleteNode(DL, p);
printList(DL); getchar();

return 0;
}*/

//예제 5-1
/*#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 100

typedef int element;

element stack[STACK_SIZE];
int top = -1;

int isEmpty()
{
if (top == -1) return 1;
else return 0;
}

int isFull()
{
if (top == STACK_SIZE - 1) return 1;
else return 0;
}

void push(element item)
{
	if (isFull())
	{
		printf("overflow!");
		return;
	}
	else stack[++top] = item;
}

element pop()
{
	if (isEmpty())
	{
		printf("underflow!");
		return;
	}
	else return stack[top--];
}

element peek()
{
if (isEmpty())
{
printf("\n\n Stack is Empty !\n");
exit(1);
}
else return stack[top];
}

void printStack()
{
int i;
printf("\n STACK [ ");
for (i = 0; i <= top; i++)
printf("%d", stack[i]);
printf("]");
}

void main()
{
element item;
printf("\n** 순차 스택 연산 **\n");
printStack();
push(1); printStack();
push(2); printStack();
push(3); printStack();

item = peek(); printStack();
printf("peek => %d", item);

item = pop(); printStack();
printf("\t pop => %d", item);

item = pop(); printStack();
printf("\t pop => %d", item);

item = pop(); printStack();
printf("\t pop => %d", item);

getchar();
}*/

//예제 6-1
#include <stdio.h>
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
printf("\n ***** 순차 큐 연산 ***** \n");
printf("\n 삽입 A>>"); enQueue(Q1, 'A'); printQ(Q1);
printf("\n 삽입 B>>"); enQueue(Q1, 'B'); printQ(Q1);
printf("\n 삽입 C>>"); enQueue(Q1, 'C'); printQ(Q1);
data = peek(Q1); printf(" peek item : %c \n", data);
printf("\n 삭제 >>"); data = deQueue(Q1); printQ(Q1);
printf("\t삭제 데이터 : %c", data);
printf("\n 삭제 >>"); data = deQueue(Q1); printQ(Q1);
printf("\t삭제 데이터 : %c", data);
printf("\n 삭제 >>"); data = deQueue(Q1); printQ(Q1);
printf("\t삭제 데이터 : %c", data);

printf("\n 삽입 D>>"); enQueue(Q1, 'D'); printQ(Q1);
printf("\n 삽입 E>>"); enQueue(Q1, 'E'); printQ(Q1);
getchar();
}