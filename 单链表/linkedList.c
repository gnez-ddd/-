#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"linkedList.h"
LNode* mark;

//初始化链表
Status InitList(LinkedList* L)
{
	//若链表为空
	if (L == NULL)
	{
		return ERROR;
	}

	//若链表不为空
	(*L)->data = 0;
	(*L)->next = NULL;
	return SUCCESS;
}

//清空链表
void DestroyList(LinkedList* L)
{

	//如果链表为空直接退出
	if ((*L)->next == NULL)
	{
		return;
	}

	//如果链表不为空
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

//插入节点
Status InsertList(LNode* p, LNode* q)
{

	q->next = p->next;
	p->next = q;
	return SUCCESS;
}

//删除节点
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

//遍历链表
void TraverseList(LinkedList L, void (*visit)(ElemType e))
{
	//若链表为空
	if (L->next == NULL)
	{
		printf("该链表为空\n");
		return;
	}

	printf("该链表存储数据为：\n");
	LinkedList temp = L->next;
	//若链表不为空
	while (temp != NULL)
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
	printf("%d\t",e);
}

//查询节点
Status SearchList(LinkedList L, ElemType e)
{
	//若链表为空
	if (L->next == NULL)
	{
		return ERROR;
	}

	LNode* temp = L->next;
	while (temp != NULL&&temp->data != e )
	{
		temp = temp->next;
	}
	//找到
	if (temp != NULL)
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

//反转链表 非递归
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

//反转链表递归
LNode* ReverseList02(LinkedList head,LinkedList L,LinkedList tail)//反转单链表函数2
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


//判断是否成环
Status IsLoopList(LinkedList L)
{
	//当只有一个节点或无节点时
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

//奇偶调换
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

//寻找中间节点
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
	printf("==========1.插入节点               ==========\n");
	printf("==========2.遍历链表               ==========\n");
	printf("==========3.删除节点               ==========\n");
	printf("==========4.查找节点               ==========\n");
	printf("==========5.销毁链表               ==========\n");
	printf("==========6.反转链表(非递归)       ==========\n");
	printf("==========7.反转链表（递归)        ==========\n");
	printf("==========8.判断是否为环           ==========\n");
	printf("==========9.调换奇偶顺序           ==========\n");
	printf("==========10.查中间节点             ==========\n");
	printf("==========0.退出                   ==========\n");
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
	if (a < 0 || a>10)
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
		ret= charJudge(a);
	}
	d = atoi(a);
	return d;
	
}
