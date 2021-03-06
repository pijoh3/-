//예제 4-1
/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode
{
	char data[4];
	struct ListNode *link;
}listNode;

typedef struct
{
	listNode *head;
}linkedList_h;

linkedList_h * createLinkedList_h(void)
{
	linkedList_h *L;
	L = (linkedList_h *)malloc(sizeof(linkedList_h));
	L->head = NULL;
	return L;
}

void freeLinkedList_h(linkedList_h *L)
{
	listNode * p;
	while (L->head != NULL)
	{
		p = L->head;
		L->head = L->head->link;
		free(p);
		p = NULL;
	}
}

void printList(linkedList_h* L)
{
	listNode * p;
	printf("L = (");
	p = L->head;
	while (p != NULL)
	{
		printf("%s", p->data);
		p = p->link;
		if (p != NULL) printf(", ");
	}
	printf(") \n");
}

void insertFirstNode(linkedList_h * L, char *x)
{
	listNode * newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	newNode->link = L->head;
	L->head = newNode;
}

void insertMiddleNode(linkedList_h * L, listNode *pre, char *x)
{
	listNode * newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	if (L == NULL)
	{
		newNode->link = NULL;
		L->head = newNode;
	}
	else if (pre == NULL)
		L->head = newNode;
	else
	{
		newNode->link = pre->link;
		pre->link = newNode;
	}
}

void insertLastNode(linkedList_h *L, char *x)
{
	listNode * newNode;
	listNode * temp;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	newNode->link = NULL;
	if (L->head == NULL)
	{
		L->head = newNode;
		return;
	}

	temp = L->head;
	while (temp->link != NULL)temp = temp->link;
	temp->link = newNode;
}

int main()
{
	linkedList_h *L;
	L = createLinkedList_h();
	printf("(1) 공백 리스트 생성하기! \n");
	printList(L); getchar();

	printf("(2) 리스트에 [수] 노드 삽입하기! \n");
	insertFirstNode(L, "수");
	printList(L); getchar();

	printf("(3) 리스트 마지막에 [금] 노드 삽입하기! \n");
	insertLastNode(L, "금");
	printList(L); getchar();

	printf("(4) 리스트 첫 번째에 [월] 노드 삽입하기! \n");
	insertFirstNode(L, "월");
	printList(L); getchar();

	printf("(5) 리스트 공간을 해제하여 공백 리스트로 만들기! \n");
	freeLinkedList_h(L);
	printList(L);

	getchar();

	return 0;
}*/

//예제 4-2
/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode
{
	char data[4];
	struct ListNode *link;
}listNode;

typedef struct
{
	listNode *head;
}linkedList_h;

linkedList_h * createLinkedList_h(void)
{
	linkedList_h *L;
	L = (linkedList_h *)malloc(sizeof(linkedList_h));
	L->head = NULL;
	return L;
}

void freeLinkedList_h(linkedList_h *L)
{
	listNode * p;
	while (L->head != NULL)
	{
		p = L->head;
		L->head = L->head->link;
		free(p);
		p = NULL;
	}
}

void printList(linkedList_h* L)
{
	listNode * p;
	printf("L = (");
	p = L->head;
	while (p != NULL)
	{
		printf("%s", p->data);
		p = p->link;
		if (p != NULL) printf(", ");
	}
	printf(") \n");
}

void insertFirstNode(linkedList_h * L, char *x)
{
	listNode * newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	newNode->link = L->head;
	L->head = newNode;
}

void insertMiddleNode(linkedList_h * L, listNode *pre, char *x)
{
	listNode * newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	if (L == NULL)
	{
		newNode->link = NULL;
		L->head = newNode;
	}
	else if (pre == NULL)
		L->head = newNode;
	else
	{
		newNode->link = pre->link;
		pre->link = newNode;
	}
}

void insertLastNode(linkedList_h *L, char *x)
{
	listNode * newNode;
	listNode * temp;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	newNode->link = NULL;
	if (L->head == NULL)
	{
		L->head = newNode;
		return;
	}

	temp = L->head;
	while (temp->link != NULL)temp = temp->link;
	temp->link = newNode;
}
void deleteNode(linkedList_h* L, listNode *p)
{
	listNode * pre;
	if (L->head == NULL) return;
	if (L->head->link == NULL)
	{
		free(L->head);
		L->head = NULL;
		return;
	}
	else if (p == NULL)return;
	else
	{
		pre = L->head;
		while (pre->link != p)
		{
			pre = pre->link;
		}
		pre->link = p->link;
		free(p);
	}
}

listNode* searchNode(linkedList_h * L, char* x)
{
	listNode *temp;
	temp = L->head;
	while (temp != NULL)
	{
		if (strcmp(temp->data, x) == 0) return temp;
		else temp = temp->link;
	}
	return temp;
}

void reverse(linkedList_h *L)
{
	listNode *p;
	listNode *q;
	listNode *r;

	p = L->head;
	q = NULL;
	r = NULL;

	while (p != NULL)
	{
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}
	L->head = q;
}

int main()
{
	linkedList_h * L;
	listNode * p;
	L = createLinkedList_h();
	printf("(1)리스트에 [월], [수], [일] 노드 삽입하기! \n");
	insertLastNode(L, "월"); insertLastNode(L, "수"); insertLastNode(L, "일");
	printList(L); getchar();

	printf("(2)리스트에서 [수] 노드 탐색하기! \n");
	p = searchNode(L, "수");
	if (p == NULL)printf("찾는 데이터가 없습니다.\n");
	else printf("[%s]를 찾았습니다.\n", p->data);
	getchar();

	printf("(3)리스트에서 [수] 뒤에 [금] 노드 삽입하기! \n");
	insertMiddleNode(L, p, "금");
	printList(L); getchar();

	printf("(4) 리스트에서 [일] 노드 삭제하기! \n");
	p = searchNode(L, "일");
	deleteNode(L, p);
	printList(L); getchar();

	printf("(5) 리스트 순서를 역순으로 바꾸기! \n");
	reverse(L);
	printList(L);

	freeLinkedList_h(L);
	getchar();

	return 0;
}*/

//예제 4-3
/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode
{
	char data[4];
	struct ListNode* link;
} listNode;

typedef struct
{
	listNode* head;
}linkedList_h;

linkedList_h* createLinkedList_h(void)
{
	linkedList_h* CL;
	CL = (linkedList_h *)malloc(sizeof(linkedList_h));
	CL->head = NULL;
	return CL;
}

void printList(linkedList_h* CL)
{
	listNode * p;
	printf(" CL = (");
	p = CL->head;
	do 
	{
		printf("%s", p->data);
		p = p->link;
		if (p != CL->head) printf(", ");
	} while (p != CL->head);
	printf(") \n");
}

void insertFirstNode(linkedList_h * CL, char *x)
{
	listNode * newNode, *temp;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	if (CL->head == NULL)
	{
		CL->head = newNode;
		newNode->link = newNode;
	}
	else
	{
		temp = CL->head;
		while (temp->link != CL->head)
			temp = temp->link;
		newNode->link = temp->link;
		temp->link = newNode;
		CL->head = newNode;
	}
}

void insertMiddleNode(linkedList_h * CL, listNode *pre, char *x)
{
	listNode * newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	if (CL == NULL)
	{
		CL->head = newNode;
		newNode->link = newNode;
	}
	else
	{
		newNode->link = pre->link;
		pre->link = newNode;
	}
}

void deleteNode(linkedList_h* CL, listNode* old)
{
	listNode * pre;
	if (CL->head == NULL) return;
	if (CL->head->link == NULL)
	{
		free(CL->head);
		CL->head = NULL;
		return;
	}
	else if (old == NULL)return;
	else
	{
		pre = CL->head;
		while (pre->link != old)
			pre = pre->link;
	}
	pre->link = old->link;
	if (old == CL->head)
		CL->head = old->link;
	free(old);
}

listNode* searchNode(linkedList_h * CL, char* x)
{
	listNode *temp;
	temp = CL->head;
	while (temp != NULL)
	{
		if (strcmp(temp->data, x) == 0)return temp;
		else temp = temp->link;
	}
	return temp;
}

int main()
{
	linkedList_h * CL;
	listNode *p;
	CL = createLinkedList_h();
	printf("(1)원형 연결 리스트 생성하기! \n");
	

	printf("(2) 원형 연결 리스트에 [월] 노드 삽입하기! \n");
	insertFirstNode(CL, "월");
	printList(CL); 

	printf("(3) 원형 연결 리스트의 [월] 노드 뒤에 [수] 노드 삽입하기! \n");
	p = searchNode(CL, "월"); insertMiddleNode(CL, p, "수");
	printList(CL); 

	printf("(4) 원형 연결 리스트의 [수] 노드 뒤에 [금] 노드 삽입하기! \n");
	p = searchNode(CL, "수"); insertMiddleNode(CL, p, "금");
	printList(CL);

	printf("(5) 원형 연결 리스트에서 [수] 노드 삭제하기! \n");
	p = searchNode(CL, "수"); deleteNode(CL, p);
	printList(CL);

	return 0;
}*/

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
	listNode * newNode;
	newNode = (listNode *)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	if (DL->head == NULL)
	{
		newNode->llink = NULL;
		newNode->rlink = NULL;
		DL->head = newNode;
	}
	else
	{
		newNode->rlink = pre->rlink;
		pre->rlink = newNode;
		newNode->llink = pre;
		if (newNode->rlink != NULL)
			newNode->rlink->llink = newNode;
	}
}

void deleteNode(linkedList_h* DL, listNode* old) {
if (DL->head == NULL) return;
else
{
if (old == DL->head)
DL->head = old->rlink;
else if (old->rlink == NULL)
old->llink->rlink = NULL;
else if (old == NULL) return;
else
{
old->llink->rlink = old->rlink;
old->rlink->llink = old->llink;
free(old);
}
}
}//기존의 코드는 첫번째 노드나 마지막 노드를 삭제하면 오류 발생.첫번째 노드일때랑 마지막 노드일때인 경우를 생각

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