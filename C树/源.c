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

	//����һ��������ʼ��
	BinarySortTreePtr T = (BinarySortTreePtr)malloc(sizeof(BinarySortTree));
	if (T == NULL)
	{
		printf("�����ڴ�ʧ��!�˳�����!\n");
		return 0;
	}
	BST_init(T);

	while (Choice != 0)
	{
		//��ӡ�����沢ѡ����
		printMenu();
		judge = funcChoice(choice);
		while (judge == 0)
		{
			printf("����������������룺\n");
			judge = funcChoice(choice);
		}
		Choice = atoi(choice);

		switch (Choice)
		{
			//�˳�ϵͳ
			case 0:
			{
				system("cls");
				printf("�ɹ��˳�!\n");
				break;
			}

			//��������
			case 1:
			{
				system("cls");
				printf("������Ҫ��������ݣ�\n");
				int data = 0;
				data = dataJudge();
				judge=BST_insert(T, data);
				if (judge == succeed)
				{
					printf("����ɹ�!\n");
				}
				else
				{
					printf("����ʧ��!\n");
				}
				break;
			}

			//ɾ������
			case 2:
			{
				system("cls");
				printf("������Ҫɾ�������ݣ�\n");
				int data = dataJudge();
				judge=BST_delete(T, data);
				if (judge == succeed)
				{
					printf("ɾ���ɹ�!\n");
				}
				else
				{
					printf("ɾ��ʧ��!\n");
				}
				break;
			}

			//Ѱ������
			case 3:
			{
				system("cls");
				printf("������ҪѰ�ҵ�����:\n");
				int data = dataJudge();
				judge=BST_search(T, data);
				if (judge == succeed)
				{
					printf("��ѯ��������!\n");
				}
				else
				{
					printf("��ѯ����������!\n");
				}
				break;
			}

			//�ǵݹ�ǰ�����
			case 4:
			{
				system("cls");
				if (T == NULL||T->root==NULL)
				{
					printf("������������!\n");
					break;
				}
				BST_preorderI(T->root, visit);
				printf("\n");
				break;
			}

			//�ݹ�ǰ�����
			case 5:
			{
				system("cls");
				if (T == NULL || T->root == NULL)
				{
					printf("������������!\n");
					break;
				}
				BST_preorderR(T->root, visit);
				printf("\n");
				break;
			}

			//�ǵݹ��������
			case 6:
			{
				system("cls");
				if (T == NULL || T->root == NULL)
				{
					printf("������������!\n");
					break;
				}
				BST_inorderI(T->root, visit);
				printf("\n");
				break;
			}

			//�ݹ��������
			case 7:
			{
				system("cls");
				if (T == NULL || T->root == NULL)
				{
					printf("������������!\n");
					break;
				}
				BST_inorderR(T->root, visit);
				printf("\n");
				break;
			}

			//�ǵݹ�������
			case 8:
			{
				system("cls");
				if (T == NULL || T->root == NULL)
				{
					printf("������������!\n");
					break;
				}
				BST_postorderI(T->root, visit);
				printf("\n");
				break;
			}

			//�ݹ��������
			case 9:
			{
				system("cls");
				if (T == NULL || T->root == NULL)
				{
					printf("������������!\n");
					break;
				}
				BST_postorderR(T->root, visit);
				printf("\n");
				break;
			}

			//��α���
			case 10:
			{
				system("cls");
				if (T == NULL || T->root == NULL)
				{
					printf("������������!\n");
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