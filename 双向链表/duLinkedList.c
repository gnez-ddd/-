#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"duLinkedList.h"
DuLNode* mark;

//初始化链表
Status InitList_DuL(DuLinkedList* L)
{
	//若无头结点
	if (L == NULL)
	{
		return ERROR;
	}

	//有头结点则初始化
	(*L)->data = 0;
	(*L)->next = (*L);
	(*L)->prior = (*L);
	return SUCCESS;
}

//销毁链表
void DestroyList_DuL(DuLinkedList* L)
{
	//若链表为空
	if ((*L)->next == (*L))
	{
		return;
	}

	//若链表不为空
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

//在节点p之后插入节点q pq
Status InsertAfterList_DuL(DuLNode* p, DuLNode* q)
{
	
	q->prior = p;
	q->next = p->next;
	p->next->prior = q;
	p->next = q;
	return SUCCESS;
}

//将节点q插入到节点p之前 qp
Status InsertBeforeList_DuL(DuLNode* p, DuLNode* q)
{
	q->next = p;
	q->prior = p->prior;
	p->prior->next = q;
	p->prior = q;
	return SUCCESS;
}

//删除节点p之后的第一个节点，并将其值赋给e
Status DeleteList_DuL(DuLNode* p, ElemType* e)
{
	//将所要删除的节点的值赋值给e
	*e = p->next->data;
	DuLNode* temp = p->next;
	temp->next->prior = p;
	p->next = temp->next;
	free(temp);
	temp = NULL;
	return SUCCESS;
}

//遍历双向链表
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
{
	//若链表为空
	if (L->next == L)
	{
		printf("该链表为空\n");
		return;
	}

	printf("该链表存储数据为：\n");
	DuLNode* temp = L->next;
	//若链表不为空
	while (temp != L)
	{
		visit(temp->data);
		temp = temp->next;
	}
	printf("\n");
	return;
}

//打印数据
void visit(ElemType e)
{
	printf("%d\t", e);
}

//查找节点
Status SearchList(DuLinkedList L, ElemType e)
{
	//若链表为空
	if (L->next == L)
	{
		return ERROR;
	}

	DuLNode* temp = L->next;
	while (temp != L && temp->data != e)
	{
		temp = temp->next;
	}
	//找到
	if (temp != L)
	{
		//将该节点记录在mark
		mark = temp;
		return SUCCESS;
	}
	else
	{
		return ERROR;
	}
}

//判断链表是否为环
Status IsLoopList(DuLinkedList L)
{
	//当只有一个节点或无节点时
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

//反转双向链表 非递归
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

//反转链表（next指针） 递归
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

//反转链表递归
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

//打印主菜单
void printMenu()
{
	printf("==========  hahahahahahahah         ==========\n");
	printf("==========1.插入在已知节点之后      ==========\n");
	printf("==========2.插入在已知节点之前      ==========\n");
	printf("==========3.遍历链表                ==========\n");
	printf("==========4.删除节点                ==========\n");
	printf("==========5.查找节点                ==========\n");
	printf("==========6.销毁链表                ==========\n");
	printf("==========7.判断链表是否成环        ==========\n");
	printf("==========8.反转链表(非递归)        ==========\n");
	printf("==========9.反转链表(递归)          ==========\n");
	printf("==========0.退出                    ==========\n");
	printf("请输入功能的对应编号:\n");
}

//输入数据判断
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
	//通过此循环说明全部都是数字
	for (i = 0; a[i] != '\0'; i++)
	{
		//第一位不符合
		if (i == 0 && a[i] != 45 && (a[i] < 48 || a[i]>57))
		{

			return ERROR;
		}
		if (i != 0 && (a[i] < 48 || a[i] > 57))
		{

			return ERROR;
		}
	}
	//若位数超过11位
	if (i > 11)
	{
		while ((c = getchar()) != EOF && c != '\n');
		return ERROR;
	}

	return SUCCESS;
}

//选择功能
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
	//通过此循环说明全部都是数字
	for (i = 0; choice[i] != '\0'; i++)
	{
		//第一位不符合
		if (i == 0 && choice[i] != 45 && (choice[i] < 48 || choice[i]>57))
		{

			return ERROR;
		}
		if (i != 0 && (choice[i] < 48 || choice[i] > 57))
		{

			return ERROR;
		}
	}
	//若位数超过3位
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

//输入数据
int dataJudge()
{
	int d = 0;
	char a[100];
	int ret = 0;
	ret = charJudge(a);
	while (ret == 0)
	{
		printf("输入有误，请重新输入：\n");
		ret = charJudge(a);
	}
	d = atoi(a);
	return d;
}
