//���� 4-4
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
	printf("(1) ���� ����Ʈ �����ϱ�! \n");
	printList(L); getchar();

	printf("(2) ����Ʈ�� [��] ��� �����ϱ�! \n");
	insertFirstNode(L, "��");
	printList(L); getchar();

	printf("(3) ����Ʈ �������� [��] ��� �����ϱ�! \n");
	insertLastNode(L, "��");
	printList(L); getchar();

	printf("(4) ����Ʈ ù ��°�� [��] ��� �����ϱ�! \n");
	insertFirstNode(L, "��");
	printList(L); getchar();

	printf("(5) ����Ʈ ������ �����Ͽ� ���� ����Ʈ�� �����! \n");
	freeLinkedList_h(L);
	printList(L);

	getchar();

	return 0;
}*/

//���� 4-2
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
	printf("(1)����Ʈ�� [��], [��], [��] ��� �����ϱ�! \n");
	insertLastNode(L, "��"); insertLastNode(L, "��"); insertLastNode(L, "��");
	printList(L); getchar();

	printf("(2)����Ʈ���� [��] ��� Ž���ϱ�! \n");
	p = searchNode(L, "��");
	if (p == NULL)printf("ã�� �����Ͱ� �����ϴ�.\n");
	else printf("[%s]�� ã�ҽ��ϴ�.\n", p->data);
	getchar();

	printf("(3)����Ʈ���� [��] �ڿ� [��] ��� �����ϱ�! \n");
	insertMiddleNode(L, p, "��");
	printList(L); getchar();

	printf("(4) ����Ʈ���� [��] ��� �����ϱ�! \n");
	p = searchNode(L, "��");
	deleteNode(L, p);
	printList(L); getchar();

	printf("(5) ����Ʈ ������ �������� �ٲٱ�! \n");
	reverse(L);
	printList(L);

	freeLinkedList_h(L);
	getchar();

	return 0;
}*/

//���� 4-3
#include <stdio.h>
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
	printf("(1)���� ���� ����Ʈ �����ϱ�! \n");
	

	printf("(2) ���� ���� ����Ʈ�� [��] ��� �����ϱ�! \n");
	insertFirstNode(CL, "��");
	printList(CL); 

	printf("(3) ���� ���� ����Ʈ�� [��] ��� �ڿ� [��] ��� �����ϱ�! \n");
	p = searchNode(CL, "��"); insertMiddleNode(CL, p, "��");
	printList(CL); 

	printf("(4) ���� ���� ����Ʈ�� [��] ��� �ڿ� [��] ��� �����ϱ�! \n");
	p = searchNode(CL, "��"); insertMiddleNode(CL, p, "��");
	printList(CL);

	printf("(5) ���� ���� ����Ʈ���� [��] ��� �����ϱ�! \n");
	p = searchNode(CL, "��"); deleteNode(CL, p);
	printList(CL);

	return 0;
}