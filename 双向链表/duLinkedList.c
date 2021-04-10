#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"duLinkedList.h"
DuLNode* mark;

//��ʼ������
Status InitList_DuL(DuLinkedList* L)
{
	//����ͷ���
	if (L == NULL)
	{
		return ERROR;
	}

	//��ͷ������ʼ��
	(*L)->data = 0;
	(*L)->next = (*L);
	(*L)->prior = (*L);
	return SUCCESS;
}

//��������
void DestroyList_DuL(DuLinkedList* L)
{
	//������Ϊ��
	if ((*L)->next == (*L))
	{
		return;
	}

	//������Ϊ��
	while ((*L)->next != (*L))
	{
		DuLNode* temp = (*L)->next;
		(*L)->next = temp->next;
		temp->next->prior = (*L);
		free(temp);
		temp = NULL;
	}
	return;
}

//�ڽڵ�p֮�����ڵ�q pq
Status InsertAfterList_DuL(DuLNode* p, DuLNode* q)
{
	
	q->prior = p;
	q->next = p->next;
	p->next->prior = q;
	p->next = q;
	return SUCCESS;
}

//���ڵ�q���뵽�ڵ�p֮ǰ qp
Status InsertBeforeList_DuL(DuLNode* p, DuLNode* q)
{
	q->next = p;
	q->prior = p->prior;
	p->prior->next = q;
	p->prior = q;
	return SUCCESS;
}

//ɾ���ڵ�p֮��ĵ�һ���ڵ㣬������ֵ����e
Status DeleteList_DuL(DuLNode* p, ElemType* e)
{
	//����Ҫɾ���Ľڵ��ֵ��ֵ��e
	*e = p->next->data;
	DuLNode* temp = p->next;
	temp->next->prior = p;
	p->next = temp->next;
	free(temp);
	temp = NULL;
	return SUCCESS;
}

//����˫������
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
{
	//������Ϊ��
	if (L->next == L)
	{
		printf("������Ϊ��\n");
		return;
	}

	printf("������洢����Ϊ��\n");
	DuLNode* temp = L->next;
	//������Ϊ��
	while (temp != L)
	{
		visit(temp->data);
		temp = temp->next;
	}
	printf("\n");
	return;
}

//��ӡ����
void visit(ElemType e)
{
	printf("%d\t", e);
}

//���ҽڵ�
Status SearchList(DuLinkedList L, ElemType e)
{
	//������Ϊ��
	if (L->next == L)
	{
		return ERROR;
	}

	DuLNode* temp = L->next;
	while (temp != L && temp->data != e)
	{
		temp = temp->next;
	}
	//�ҵ�
	if (temp != L)
	{
		//���ýڵ��¼��mark
		mark = temp;
		return SUCCESS;
	}
	else
	{
		return ERROR;
	}
}

//�ж������Ƿ�Ϊ��
Status IsLoopList(DuLinkedList L)
{
	//��ֻ��һ���ڵ���޽ڵ�ʱ
	if (L->next==L||L->next->next==L)
	{
		return ERROR;
	}


	DuLNode* fast = L;
	DuLNode* slow = L;
	do
	{
		fast = fast->next->next;
		slow = slow->next;
	} while (fast != slow);
	if (fast == L)
	{
		return ERROR;
	}
	if (fast != L)
	{
		return SUCCESS;
	}
}

//��ת˫������ �ǵݹ�
Status ReverseList01(DuLinkedList L)
{
	DuLNode* change = L->next->next;
	DuLNode* pre = L->next;
	while (pre->next != L)
	{
		pre->next = change->next;
		change->next = L->next;
		L->next = change;
		change = pre->next;
	}
	change = L;
	change->next->prior = change;
	change = change->next;
	while (change->next != L)
	{
		change->next->prior = change;
		change = change->next;
	}
	L->prior = change;
	return SUCCESS;
}

//��ת����nextָ�룩 �ݹ�
DuLNode* ReverseListNext(DuLinkedList head, DuLinkedList L, DuLinkedList tail)
{
	if (head->next == L)
	{
		return head;
	}
	DuLNode* p = ReverseListNext(head->next, L, tail);
	if (head == L)
	{
		L->next = tail;
		return L;
	}
	head->next->next = head;
	head->next = L;
	return p;
}

//��ת����ݹ�
Status ReverseList02(DuLinkedList L)
{
	DuLNode* head = L;
	DuLNode* tail = L->prior;
	ReverseListNext(head, L, tail);
	DuLNode* change = L;
	change->next->prior = change;
	change = change->next;
	while (change->next != L)
	{
		change->next->prior = change;
		change = change->next;
	}
	L->prior = change;
	return SUCCESS;

}

//��ӡ���˵�
void printMenu()
{
	printf("==========  hahahahahahahah         ==========\n");
	printf("==========1.��������֪�ڵ�֮��      ==========\n");
	printf("==========2.��������֪�ڵ�֮ǰ      ==========\n");
	printf("==========3.��������                ==========\n");
	printf("==========4.ɾ���ڵ�                ==========\n");
	printf("==========5.���ҽڵ�                ==========\n");
	printf("==========6.��������                ==========\n");
	printf("==========7.�ж������Ƿ�ɻ�        ==========\n");
	printf("==========8.��ת����(�ǵݹ�)        ==========\n");
	printf("==========9.��ת����(�ݹ�)          ==========\n");
	printf("==========0.�˳�                    ==========\n");
	printf("�����빦�ܵĶ�Ӧ���:\n");
}

//���������ж�
Status charJudge(char* a)
{
	char c;
	int ret;
	ret = gets(a);
	if (ret == 0)
	{
		while ((c = getchar()) != EOF && c != '\n');
		return ERROR;
	}
	int i = 0;
	if (a[0] == '\0')
	{
		return ERROR;
	}
	//ͨ����ѭ��˵��ȫ����������
	for (i = 0; a[i] != '\0'; i++)
	{
		//��һλ������
		if (i == 0 && a[i] != 45 && (a[i] < 48 || a[i]>57))
		{

			return ERROR;
		}
		if (i != 0 && (a[i] < 48 || a[i] > 57))
		{

			return ERROR;
		}
	}
	//��λ������11λ
	if (i > 11)
	{
		while ((c = getchar()) != EOF && c != '\n');
		return ERROR;
	}

	return SUCCESS;
}

//ѡ����
Status funcChoice(char* choice)
{

	char c;
	int ret;
	ret = gets(choice);
	if (ret == 0)
	{
		while ((c = getchar()) != EOF && c != '\n');
		return ERROR;
	}
	int i = 0;
	if (choice[0] == '\0')
	{
		return ERROR;
	}
	//ͨ����ѭ��˵��ȫ����������
	for (i = 0; choice[i] != '\0'; i++)
	{
		//��һλ������
		if (i == 0 && choice[i] != 45 && (choice[i] < 48 || choice[i]>57))
		{

			return ERROR;
		}
		if (i != 0 && (choice[i] < 48 || choice[i] > 57))
		{

			return ERROR;
		}
	}
	//��λ������3λ
	if (i > 3)
	{
		while ((c = getchar()) != EOF && c != '\n');
		return ERROR;
	}
	int a = 0;
	a = atoi(choice);
	if (a < 0 || a>9)
	{
		return ERROR;
	}

	return SUCCESS;


}

//��������
int dataJudge()
{
	int d = 0;
	char a[100];
	int ret = 0;
	ret = charJudge(a);
	while (ret == 0)
	{
		printf("�����������������룺\n");
		ret = charJudge(a);
	}
	d = atoi(a);
	return d;
}
