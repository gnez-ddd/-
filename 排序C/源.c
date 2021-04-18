#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"qgsort.h"

clock_t start, stop;
double duration;

int main()
{
	int judge = 0;
	char choice[100] = "1";
	int Choice = 1;

	while (Choice != 0)
	{
		//打印主界面并选择功能
		menuPrintf();
		judge = funcChoice(choice);
		while (judge == 0)
		{
			printf("输入错误，请重新输入:\n");
			judge = funcChoice(choice);
		}
		Choice = atoi(choice);

		switch (Choice)
		{
			//退出系统
			case 0:
			{
				system("cls");
				printf("成功退出！\n");
				break;
			}

			//大数据量下用时
			case 1:
			{
				
				system("cls");
				int i = 0;
				printf("请输入数据量：\n");
				int size = 0;
				size = intJudge();
				int* A = (int*)malloc(sizeof(int) * size);
				if (A == NULL)
				{
					printf("分配内存失败，退出系统！\n");
					return 0;
				}
				memset(A, 0, sizeof(int) * size);
				getRandomNum(A, size);
				int* a = (int*)malloc(sizeof(int) * size);
				if (a == NULL)
				{
					printf("分配内存失败，退出系统！\n");
					return 0;
				}
				memset(a, 0, sizeof(int) * size);
				int* Temp = (int*)malloc(sizeof(int) * size);
				if (Temp == NULL)
				{
					printf("分配内存失败，退出系统！\n");
					return 0;
				}
				memset(Temp, 0, sizeof(int) * size);
				
				//测试插入排序算法
				memcpy(a, A, sizeof(int) * size);
				start = clock();
				insertSort(a, size);
				stop = clock();
				duration = ((double)stop-(double)start) / CLOCKS_PER_SEC;
				printf("插入排序算法运行时间为：%lfs\n", duration);
				
				//测试归并排序
				memcpy(a, A, sizeof(int) * size);
				start = clock();
				MergeSort(a, 0, size - 1, Temp);
				stop = clock();
				duration = ((double)stop - (double)start) / CLOCKS_PER_SEC;
				printf("归并排序算法运行时间为：%lfs\n", duration);

				
				//测试快速排序递归版
				memcpy(a, A, sizeof(int) * size);
				start = clock();
				QuickSort_Recursion(a, 0, size - 1);
				stop = clock();
				duration = ((double)stop - (double)start) / CLOCKS_PER_SEC;
				printf("快速排序递归法算法运行时间为：%lfs\n", duration);

				//测试快速排序非递归版
				memcpy(a, A, sizeof(int) * size);
				start = clock();
				QuickSort(a, size);
				stop = clock();
				duration = ((double)stop - (double)start) / CLOCKS_PER_SEC;
				printf("快速排序非递归法算法运行时间为：%lfs\n", duration);

				//测试计数排序
				memcpy(a, A, sizeof(int) * size);
				int max = 0,min=0;
				MaxAndMin(a, &max, &min, size);
				start = clock();
				CountSort(a, size, max,min);
				stop = clock();
				duration = ((double)stop - (double)start) / CLOCKS_PER_SEC;
				printf("计数排序算法运行时间为：%lfs\n", duration);

				//测试基数排序
				memcpy(a, A, sizeof(int) * size);
				start = clock();
				RadixCountSort(a, size);
				stop = clock();
				duration = ((double)stop - (double)start) / CLOCKS_PER_SEC;
				printf("基数排序算法运行时间为：%lfs\n", duration);
				free(Temp);
				Temp = NULL;
				free(a);
				a = NULL;
				free(A);
				A = NULL;
				break;
			}

			//大量小数组下用时
			case 2:
			{
				system("cls");
				int* A = (int*)malloc(sizeof(int) * 100);
				if (A == NULL)
				{
					printf("分配内存失败，退出系统！\n");
					return 0;
				}
				memset(A, 0, sizeof(int) * 100);
				getRandomNum(A, 100);
				int* a = (int*)malloc(sizeof(int) * 100);
				if (a == NULL)
				{
					printf("分配内存失败，退出系统！\n");
					return 0;
				}
				memset(a, 0, sizeof(int) * 100);
				int* Temp = (int*)malloc(sizeof(int) * 100);
				if (Temp == NULL)
				{
					printf("分配内存失败，退出系统！\n");
					return 0;
				}
				memset(Temp, 0, sizeof(int) * 100);
				int i = 0;
				//测试插入排序算法
				start = clock();
				for (i = 0; i <= 100000; i++)
				{
					memcpy(a, A, sizeof(int)* 100);
					insertSort(a, 100);
				}
				stop = clock();
				duration = ((double)stop - (double)start) / CLOCKS_PER_SEC;
				printf("插入排序算法运行时间为：%lfs\n", duration);

				//测试归并排序算法
				start = clock();
				for (i = 0; i <= 100000; i++)
				{
					memcpy(a, A, sizeof(int) * 100);
					MergeSort(a, 0, 99, Temp);
					memset(Temp, 0, sizeof(int) * 100);
				}
				stop = clock();
				duration = ((double)stop - (double)start) / CLOCKS_PER_SEC;
				printf("归并排序算法运行时间为：%lfs\n", duration);

				//测试快排递归排序算法
				start = clock();
				for (i = 0; i <= 100000; i++)
				{
					memcpy(a, A, sizeof(int) * 100);
					QuickSort_Recursion(a, 0, 99);
				}
				stop = clock();
				duration = ((double)stop - (double)start) / CLOCKS_PER_SEC;
				printf("快排递归排序算法运行时间为：%lfs\n", duration);

				//测试快排非递归排序算法
				start = clock();
				for (i = 0; i <= 100000; i++)
				{
					memcpy(a, A, sizeof(int) * 100);
					QuickSort(a, 100);
				}
				stop = clock();
				duration = ((double)stop - (double)start) / CLOCKS_PER_SEC;
				printf("快排非递归排序算法运行时间为：%lfs\n", duration);

				//测试计数排序算法
				start = clock();
				int max = 0, min = 0;
				MaxAndMin(a, &max, &min, 100);
				for (i = 0; i <= 100000; i++)
				{
					memcpy(a, A, sizeof(int) * 100);
					CountSort(a, 100, max, min);
				}
				stop = clock();
				duration = ((double)stop - (double)start) / CLOCKS_PER_SEC;
				printf("计数排序算法运行时间为：%lfs\n", duration);

				//测试基数排序算法
				start = clock();
				for (i = 0; i <= 100000; i++)
				{
					memcpy(a, A, sizeof(int) * 100);
					RadixCountSort(a, 100);
				}
				stop = clock();
				duration = ((double)stop - (double)start) / CLOCKS_PER_SEC;
				printf("基数排序算法运行时间为：%lfs\n", duration);

				free(Temp);
				Temp = NULL;
				free(a);
				a = NULL;
				free(A);
				A = NULL;
				break;

			}

			//颜色排序
			case 3:
			{
				system("cls");
				int i = 0;
				printf("请输入数据量：\n");
				int size = 0;
				size = intJudge();
				int* a = (int*)malloc(sizeof(int) * size);
				srand((int)time(0));
				i = 0;
				for (i = 0; i < size; i++)
				{
					a[i] = rand() %3+0;
				}
				printf("排序前：\n");
				for (i = 0; i < size; i++)
				{
					printf("%d ",a[i]);
				}
				printf("\n");
				ColorSort(a, size);
				printf("排序后：\n");
				for (i = 0; i < size; i++)
				{
					printf("%d ", a[i]);
				}
				printf("\n");
				free(a);
				if (a != NULL)
				{
					a = NULL;
				}
				break;
			}

			//寻找第k大的数
			case 4:
			{
				system("cls");
				int i = 0;
				printf("请输入数据量：\n");
				int size = 0;
				size = intJudge();
				int* a = (int*)malloc(sizeof(int) * size);
				getRandomNum(a, size);
				printf("该数据组为：\n");
				for (i = 0; i < size; i++)
				{
					printf("%d ", a[i]);
				}
				printf("\n请输入要寻找的第几大数据：");
				int k = 0;
				k = intJudge();
				while (k > size || k <= 0)
				{
					printf("输入有误，请重新输入！\n");
					k = intJudge();
				}
				int num = 0;
				num = getNum(a, size, k);
				printf("该数据为：%d\n", num);
				free(a);
				a = NULL;
				break;

			}

			//生成数据并保存到文件中
			case 5:
			{
				char path[100] = "\0";
				printf("请输入文件路径:\n");
				gets(path);
				printf("请输入数据量：\n");
				int size = 0;
				size = intJudge();
				int* a = (int*)malloc(sizeof(int) * size);
				getRandomNum(a, size);
				storenumFile(a, path, size);
				break;

			}

			//读取数据并排序
			case 6:
			{
				int Size = 0;
				char path[100] = "\0";
				printf("请输入文件路径:\n");
				gets(path);
				int* Ret=readNumFild(path,&Size);
				if (Ret == NULL)
				{
					printf("读取数据失败！\n");
					break;
				}
				int i = 0;
				printf("该文件中数据为：\n");
				for (i = 0; i < Size; i++)
				{
					printf("%d  ", Ret[i]);
				}
				printf("\n");
				
				int* A = (int*)malloc(sizeof(int) * Size);
				if (A == NULL)
				{
					printf("分配内存失败，退出系统！\n");
					return 0;
				}
				memcpy(A, Ret, sizeof(int) * Size);
				int* a = (int*)malloc(sizeof(int) * Size);
				if (a == NULL)
				{
					printf("分配内存失败，退出系统！\n");
					return 0;
				}
				memset(a, 0, sizeof(int) * Size);
				int* Temp = (int*)malloc(sizeof(int) * Size);
				if (Temp == NULL)
				{
					printf("分配内存失败，退出系统！\n");
					return 0;
				}
				memset(Temp, 0, sizeof(int) * Size);

				//测试插入排序算法
				memcpy(a, A, sizeof(int) * Size);
				start = clock();
				insertSort(a, Size);
				stop = clock();
				duration = ((double)stop - (double)start) / CLOCKS_PER_SEC;
				printf("排序后为：\n");
				for (i = 0; i < Size; i++)
				{
					printf("%d  ", a[i]);
				}
				printf("\n");
				printf("插入排序算法运行时间为：%lfs\n", duration);

				//测试归并排序
				memcpy(a, A, sizeof(int) * Size);
				start = clock();
				MergeSort(a, 0, Size - 1, Temp);
				stop = clock();
				duration = ((double)stop - (double)start) / CLOCKS_PER_SEC;
				printf("排序后为：\n");
				for (i = 0; i < Size; i++)
				{
					printf("%d  ", a[i]);
				}
				printf("\n");
				printf("归并排序算法运行时间为：%lfs\n", duration);


				//测试快速排序递归版
				memcpy(a, A, sizeof(int) * Size);
				start = clock();
				QuickSort_Recursion(a, 0, Size - 1);
				stop = clock();
				duration = ((double)stop - (double)start) / CLOCKS_PER_SEC;
				printf("排序后为：\n");
				for (i = 0; i < Size; i++)
				{
					printf("%d  ", a[i]);
				}
				printf("\n");
				printf("快速排序递归法算法运行时间为：%lfs\n", duration);

				//测试快速排序非递归版
				memcpy(a, A, sizeof(int) * Size);
				start = clock();
				QuickSort(a, Size);
				stop = clock();
				duration = ((double)stop - (double)start) / CLOCKS_PER_SEC;
				printf("排序后为：\n");
				for (i = 0; i < Size; i++)
				{
					printf("%d  ", a[i]);
				}
				printf("\n");
				printf("快速排序非递归法算法运行时间为：%lfs\n", duration);

				//测试计数排序
				memcpy(a, A, sizeof(int) * Size);
				int max = 0, min = 0;
				MaxAndMin(a, &max, &min, Size);
				start = clock();
				CountSort(a, Size, max, min);
				stop = clock();
				duration = ((double)stop - (double)start) / CLOCKS_PER_SEC;
				printf("排序后为：\n");
				for (i = 0; i < Size; i++)
				{
					printf("%d  ", a[i]);
				}
				printf("\n");
				printf("计数排序算法运行时间为：%lfs\n", duration);

				//测试基数排序
				memcpy(a, A, sizeof(int) * Size);
				start = clock();
				RadixCountSort(a, Size);
				stop = clock();
				duration = ((double)stop - (double)start) / CLOCKS_PER_SEC;
				printf("排序后为：\n");
				for (i = 0; i < Size; i++)
				{
					printf("%d  ", a[i]);
				}
				printf("\n");
				printf("基数排序算法运行时间为：%lfs\n", duration);
				free(Temp);
				Temp = NULL;
				free(a);
				a = NULL;
				free(A);
				A = NULL;
				free(Ret);
				Ret = NULL;


				break;
			}

		}

	}
	return 0;
}