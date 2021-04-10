#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"linkedList.h"
LNode* mark;

//��ʼ������
Status InitList(LinkedList* L)
{
	//������Ϊ��
	if (L == NULL)
	{
		return ERROR;
	}

	//������Ϊ��
	(*L)->data = 0;
	(*L)->next = NULL;
	return SUCCESS;
}

//�������
void DestroyList(LinkedList* L)
{

	//�������Ϊ��ֱ���˳�
	if ((*L)->next == NULL)
	{
		return;
	}

	//�������Ϊ��
	while ((*L)->next != NULL)
	{
		LNode* temp;
		temp = (*L)->next;
		(*L)->next = temp->next;
		temp->next = NULL;
		free(temp);
		temp = NULL;
	}
	return;
}

//����ڵ�
Status InsertList(LNode* p, LNode* q)
{

	q->next = p->next;
	p->next = q;
	return SUCCESS;
}

//ɾ���ڵ�
Status DeleteList(LNode* p, ElemType* e)
{
	LNode* temp = p->next;
	p->next = temp->next;
	*e = temp->data;
	temp->next = NULL;
	free(temp);
	temp = NULL;
	return SUCCESS;
}

//��������
void TraverseList(LinkedList L, void (*visit)(ElemType e))
{
	//������Ϊ��
	if (L->next == NULL)
	{
		printf("������Ϊ��\n");
		return;
	}

	printf("������洢����Ϊ��\n");
	LinkedList temp = L->next;
	//������Ϊ��
	while (temp != NULL)
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
	printf("%d\t",e);
}

//��ѯ�ڵ�
Status SearchList(LinkedList L, ElemType e)
{
	//������Ϊ��
	if (L->next == NULL)
	{
		return ERROR;
	}

	LNode* temp = L->next;
	while (temp != NULL&&temp->data != e )
	{
		temp = temp->next;
	}
	//�ҵ�
	if (temp != NULL)
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

//��ת���� �ǵݹ�
Status ReverseList01(LinkedList* L)
{
	LNode* pre = (*L)->next;
	LNode* temp = (*L)->next;
	while (temp->next!=NULL)
	{
		(*L)->next = temp->next;
		temp->next = (*L)->next->next;
		(*L)->next->next = pre;
		pre = (*L)->next;
	}
	return SUCCESS;
}

//��ת����ݹ�
LNode* ReverseList02(LinkedList head,LinkedList L,LinkedList tail)//��ת��������2
{
	if (head->next == NULL || head == NULL)
	{
		return head;
	}
	LNode* p = ReverseList02(head->next,L,tail);
	if (head == L)
	{
		L->next = tail;
		return L;
	}
	head->next->next = head;
	head->next = NULL;
	return p;
}


//�ж��Ƿ�ɻ�
Status IsLoopList(LinkedList L)
{
	//��ֻ��һ���ڵ���޽ڵ�ʱ
	if (L->next == NULL || L->next->next == NULL)
	{
		return ERROR;
	}
	LNode* temp1 = L;
	LNode* temp2 = L;
	do
	{
		temp1 = temp1->next->next;
		temp2 = temp2->next;
		if (temp1->next == NULL || temp1->next->next == NULL)
		{
			return ERROR;
		}
	} while ((temp1 != temp2));
	return SUCCESS;
}

//��ż����
LNode* ReverseEvenList(LinkedList* L)
{
	LNode* temp = (*L)->next;
	LNode* pre = (*L);
	while (temp != NULL)
	{
		pre->next = temp->next;
		temp->next = pre->next->next;
		pre->next->next = temp;
		pre = temp;
		temp = temp->next;
		if (temp==NULL||temp->next == NULL)
		{
			return *L;
		}
	}
	return *L;
	
}

//Ѱ���м�ڵ�
LNode* FindMidNode(LinkedList* L)
{
	if ((*L)->next == NULL)
	{
		return *L;
	}

	LNode* fast = (*L)->next;
	LNode* slow = (*L)->next;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

void printMenu()
{
	printf("==========hahahahahahahah          ==========\n");
	printf("==========1.����ڵ�               ==========\n");
	printf("==========2.��������               ==========\n");
	printf("==========3.ɾ���ڵ�               ==========\n");
	printf("==========4.���ҽڵ�               ==========\n");
	printf("==========5.��������               ==========\n");
	printf("==========6.��ת����(�ǵݹ�)       ==========\n");
	printf("==========7.��ת�����ݹ�)        ==========\n");
	printf("==========8.�ж��Ƿ�Ϊ��           ==========\n");
	printf("==========9.������ż˳��           ==========\n");
	printf("==========10.���м�ڵ�             ==========\n");
	printf("==========0.�˳�                   ==========\n");
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
	if (a < 0 || a>10)
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
		ret= charJudge(a);
	}
	d = atoi(a);
	return d;
	
}
