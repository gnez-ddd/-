#pragma once

#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

typedef enum Status
{
	ERROR = 0, SUCCESS = 1
}Status;

//栈
typedef struct Stack
{
	int* elem;
	int top;
	int size;
}Stack;

//选择功能
Status funcChoice(char* choice);

//打印菜单
void menuPrintf();

//生成随机数
void getRandomNum(int* a, int size);

//输入数据判断
Status charJudge(char* a);

//输入int数据
int intJudge();

//初始化栈
Status initStack(Stack* s, int sizes);

//入栈
Status pushStack(Stack* s, int data);

//出栈
Status popStack(Stack* s,int* data);

//判断栈是否为空
Status isEmptyStack(Stack* s);

/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : 插入排序算法
 *  @param       : 数组指针 a, 数组长度 n
 */
void insertSort(int* a, int n);


/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : 归并排序（合并数组）
 *  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
 */
void MergeArray(int* a, int begin, int mid, int end, int* temp);


/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : 归并排序
 *  @param       : 数组指针a，数组起点begin，数组终点end，承载数组指针temp
 */
void MergeSort(int* a, int begin, int end, int* temp);



/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : 快速排序（递归版）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
void QuickSort_Recursion(int* a, int begin, int end);


/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : 快速排序（非递归版）
 *  @param       : 数组指针a，数组长度size
 */
void QuickSort(int* a, int size);


/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : 快速排序（枢轴存放）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
int Partition(int* a, int begin, int end);


/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : 计数排序
 *  @param       : 数组指针a，数组长度size，数组最大值max
 */
void CountSort(int* a, int size, int max,int min);

//获取最值
void MaxAndMin(int* a, int* max, int* min, int size);

/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度size
 */
void RadixCountSort(int* a, int size);


/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : 颜色排序
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
 */
void ColorSort(int* a, int size);


/**
 *  @name        : 自拟
 *  @description : 在一个无序序列中找到第K大/小的数
 *  @param       : 数组指针a，数组长度size
 */
int getNum(int* a, int size, int k);

//交换
void swap(int* a, int i, int j);

//生成数据并保存到文件中
void storenumFile(int* a, char* PATH, int size);

//读取文件数据并排序
int* readNumFild(char* PATH,int* Size);

int readNum(char* tmp, int* ret,int size);

//剪切字符串
int cutChar(char* str, int start, int count, char* cut);

#endif // QUEUE_H_INCLUDED

