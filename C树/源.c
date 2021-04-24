#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"binary_sort_tree.h"

/*
typedef struct Node {
	ElemType value;
	struct Node* left, * right;
}Node, * NodePtr;

typedef struct BinarySortTree {
	NodePtr root;
} BinarySortTree, * BinarySortTreePtr;
*/

int main()
{
	char choice[100] = "1";
	int Choice = 1;
	int judge = 0;

	//生成一棵树并初始化
	BinarySortTreePtr T = (BinarySortTreePtr)malloc(sizeof(BinarySortTree));
	if (T == NULL)
	{
		printf("分配内存失败!退出程序!\n");
		return 0;
	}
	BST_init(T);

	while (Choice != 0)
	{
		//打印主界面并选择功能
		printMenu();
		judge = funcChoice(choice);
		while (judge == 0)
		{
			printf("输入错误，请重新输入：\n");
			judge = funcChoice(choice);
		}
		Choice = atoi(choice);

		switch (Choice)
		{
			//退出系统
			case 0:
			{
				system("cls");
				printf("成功退出!\n");
				break;
			}

			//插入数据
			case 1:
			{
				system("cls");
				printf("请输入要插入的数据：\n");
				int data = 0;
				data = dataJudge();
				judge=BST_insert(T, data);
				if (judge == succeed)
				{
					printf("插入成功!\n");
				}
				else
				{
					printf("插入失败!\n");
				}
				break;
			}

			//删除数据
			case 2:
			{
				system("cls");
				printf("请输入要删除的数据：\n");
				int data = dataJudge();
				judge=BST_delete(T, data);
				if (judge == succeed)
				{
					printf("删除成功!\n");
				}
				else
				{
					printf("删除失败!\n");
				}
				break;
			}

			//寻找数据
			case 3:
			{
				system("cls");
				printf("请输入要寻找的数据:\n");
				int data = dataJudge();
				judge=BST_search(T, data);
				if (judge == succeed)
				{
					printf("查询到该数据!\n");
				}
				else
				{
					printf("查询不到该数据!\n");
				}
				break;
			}

			//非递归前序遍历
			case 4:
			{
				system("cls");
				if (T == NULL||T->root==NULL)
				{
					printf("该树暂无数据!\n");
					break;
				}
				BST_preorderI(T->root, visit);
				printf("\n");
				break;
			}

			//递归前序遍历
			case 5:
			{
				system("cls");
				if (T == NULL || T->root == NULL)
				{
					printf("该树暂无数据!\n");
					break;
				}
				BST_preorderR(T->root, visit);
				printf("\n");
				break;
			}

			//非递归中序遍历
			case 6:
			{
				system("cls");
				if (T == NULL || T->root == NULL)
				{
					printf("该树暂无数据!\n");
					break;
				}
				BST_inorderI(T->root, visit);
				printf("\n");
				break;
			}

			//递归中序遍历
			case 7:
			{
				system("cls");
				if (T == NULL || T->root == NULL)
				{
					printf("该树暂无数据!\n");
					break;
				}
				BST_inorderR(T->root, visit);
				printf("\n");
				break;
			}

			//非递归后序遍历
			case 8:
			{
				system("cls");
				if (T == NULL || T->root == NULL)
				{
					printf("该树暂无数据!\n");
					break;
				}
				BST_postorderI(T->root, visit);
				printf("\n");
				break;
			}

			//递归后续遍历
			case 9:
			{
				system("cls");
				if (T == NULL || T->root == NULL)
				{
					printf("该树暂无数据!\n");
					break;
				}
				BST_postorderR(T->root, visit);
				printf("\n");
				break;
			}

			//层次遍历
			case 10:
			{
				system("cls");
				if (T == NULL || T->root == NULL)
				{
					printf("该树暂无数据!\n");
					break;
				}
				BST_levelOrder(T->root, visit);
				printf("\n");
				break;
			}
		}
	}
	return 0;
}