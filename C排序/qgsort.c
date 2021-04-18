#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"qgsort.h"

//打印菜单
void menuPrintf()
{
	printf("==========  hahahahahaha              ==========\n");
	printf("==========  1.大数据量下用时          ==========\n");
	printf("==========  2.大量小数组下用时        ==========\n");
	printf("==========  3.颜色排序                ==========\n");
	printf("==========  4.找第k大的数             ==========\n");
	printf("==========  5.生成数据并保存到文件中  ==========\n");
	printf("==========  6.从文件中读取数据并排序  ==========\n");
	printf("==========  0.退出                    ==========\n");
	printf("请输入功能的对于编号：\n");
	return;
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
		if (choice[i] < 48 || choice[i] > 57)
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
	if (a < 0 || a>6)
	{
		return ERROR;
	}

	return SUCCESS;
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

//输入int数据
int intJudge()
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

//交换
void swap(int* a, int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
	return;
}

//插入排序算法
//数组指针 a, 数组长度 n
void insertSort(int* a, int n)
{
	//如果数组个数只有一个或没有
	if (n < 2)
	{
		return;
	}

	int i = 1;
	int temp = 0;
	for (i = 1; i < n; i++)
	{
		temp = a[i];
		int j = i - 1;

		for (j = i - 1; j >= 0 && temp < a[j]; j--)
		{
			a[j + 1] = a[j];
		}
		a[j + 1] = temp;
	}
	return;
}


//归并排序（合并数组）
//数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
void MergeArray(int* a, int begin, int mid, int end, int* temp)
{
	int begin2 = mid+1, begin1 = begin, tempbegin = begin;
	//在各自范围内
	while ( begin1 <= mid && begin2 <= end)
	{
		if (a[begin1] > a[begin2])
		{
			temp[tempbegin++] = a[begin2++];
		}
		else
		{
			temp[tempbegin++] = a[begin1++];
		}
	}
	while (begin1 <= mid)
	{
		temp[tempbegin++] = a[begin1++];
	}
	while (begin2 <= end)
	{
		temp[tempbegin++] = a[begin2++];
	}
	//将temp中的值拷贝到a
	while (begin <= end)
	{
		a[begin] = temp[begin++];
	}
	return;
}

//归并排序
//数组指针a，数组起点begin，数组终点end，承载数组指针temp
void MergeSort(int* a, int begin, int end, int* temp)
{
	if ((end - begin + 1) < 2)
	{
		return;
	}
	if (begin >= end)
	{
		return;
	}
	else
	{
		int m = (begin + end) / 2;
		MergeSort(a, begin,m, temp);
		MergeSort(a, m+1, end, temp);
		MergeArray(a,begin, m, end,temp);
	}
	return;
}

//快速排序（递归版）
//数组指针a，数组起点begin，数组终点end
void QuickSort_Recursion(int* a, int begin, int end)
{
	if ((end - begin + 1) < 2)
	{
		return;
	}
	int pivot = 0;
	while (begin < end)
	{
		pivot = Partition(a, begin, end);
		QuickSort_Recursion(a, begin, pivot - 1);
		begin = pivot + 1;
	}
	return;
}

//快速排序（枢轴存放）
//数组指针a，数组起点begin，数组终点end
int Partition(int* a, int begin, int end)
{
	int temp = 0;
	int pivotkey = 0;
	int m = begin + (end - begin)/2;
	if (a[begin] > a[end])
	{
		swap(a, begin, end);
	}
	if (a[m] > a[end])
	{
		swap(a, end, m);
	}
	if (a[m] > a[begin])
	{
		swap(a, m, begin);
	}
	pivotkey = a[begin];
	temp = pivotkey;
	while (begin < end)
	{
		while (begin < end && a[end] >= pivotkey)
		{
			end--;
		}
		a[begin] = a[end];
		while (begin < end && a[begin] <= pivotkey)
		{
			begin++;
		}
		a[end] = a[begin];
	}
	a[begin] = temp;
	return begin;

}

//初始化栈
Status initStack(Stack* s, int sizes)
{
	s->elem = (int*)malloc(sizeof(int) * sizes);
	if (s->elem == NULL)
	{
		return ERROR;
	}
	memset(s->elem, 0, sizeof(int) * sizes);
	s->size = sizes;
	s->top = -1;
	return SUCCESS;
}

//入栈
Status pushStack(Stack* s, int data)
{
	//判断栈是否满
	if (s->top == s->size - 1)
	{
		return ERROR;
	}

	s->top++;
	s->elem[s->top] = data;
	return SUCCESS;
}

//出栈
Status popStack(Stack* s,int* data)
{
	//若栈为空
	if (s->top == -1)
	{
		return ERROR;
	}
	*data = s->elem[s->top];
	s->top--;
	return SUCCESS;
}

//判断栈是否为空
Status isEmptyStack(Stack* s)
{
	if (s->top == -1)
	{
		return SUCCESS;
	}
	else
	{
		return ERROR;
	}
}

//快速排序（非递归版）
//数组指针a，数组长度size
void QuickSort(int* a, int size)
{
	if(size<2)
	{ 
		return;
	}
	//建立一个栈并初始化
	Stack* s = (Stack*)malloc(sizeof(Stack));
	if (s == NULL)
	{
		return;
	}
	initStack(s, size);

	int begin = 0;
	int end = size - 1;
	int temp = 0;
	pushStack(s, begin);
	pushStack(s, end);
	while (!isEmptyStack(s))
	{
		int begin1 = 0;
		int end1 = 0;
		popStack(s,&end1);
		popStack(s, &begin1);
		int pivot = Partition(a, begin1, end1);
		if (begin1 < pivot - 1)
		{
			pushStack(s, begin1);
			pushStack(s, pivot - 1);
		}
		if (end1 > pivot + 1)
		{
			pushStack(s,pivot + 1);
			pushStack(s,end1);
		}

	}
	free(s->elem);
	s->elem = NULL;
	free(s);
	s = NULL;
	return;
}

//计数排序
//数组指针a，数组长度size，数组最大值max
void CountSort(int* a, int size, int max,int min)
{
	if (size < 2)
	{
		return;
	}
	int i = 0, j = 0;
	int nmax = max, nmin = min;
	if (min < 0)
	{
		for (i = 0; i < size; i++)
		{
			a[i] = a[i] - min;
		}
		nmax = max - min;
		nmin = 0;
	}
	int range = nmax - nmin + 1;
	int* temp = (int*)malloc(sizeof(int) * range);
	if (temp == NULL)
	{
		return;
	}
	memset(temp, 0, sizeof(int)*range);
	for (i = 0; i < size; i++)
	{
		temp[a[i]-nmin]++;
	}
	j = 0;
	for (i = 0; i < range; i++)
	{
		while ((temp[i]--) > 0)
		{
			a[j] = i + nmin;
			j++;
		}
	}
	if (min < 0)
	{
		for (i = 0; i < size; i++)
		{
			a[i] = a[i] + min;
		}
	}
	free(temp);
	temp = NULL;
	return;
}

//在一个无序序列中找到第K大/小的数
//数组指针a，数组长度size
//利用快排
int getNum(int* a, int size, int k)
{
	if (size < 2)
	{
		return a[0];
	}
	//找第n-k+1小的数字
	k = size - k + 1;
	int begin = 0;
	int end = size - 1;
	while (begin <= end)
	{
		int pivot = Partition(a, begin, end);
		//找到了
		if (pivot + 1 == k)
		{
			return a[pivot];
		}
		//在右边找
		else if (pivot + 1 < k)
		{
			begin = pivot + 1;
		}
		//在左边找
		else
		{
			end = pivot - 1;
		}
	}

}

//获取最值
void MaxAndMin(int* a, int* max, int* min, int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		if (a[i] > *max)
		{
			*max = a[i];
		}
		else if(a[i]<*min)
		{
			*min = a[i];
		}
	}
	return;
}

//基数计数排序
//数组指针a，数组长度size
void RadixCountSort(int* a, int size)
{
	//寻找最大和最小的数
	int max = 0, min = 0;
	MaxAndMin(a, &max, &min, size);
	int i = 0;
	//临时数组
	int* temp = (int*)malloc(sizeof(int) * size);
	if (temp == NULL)
	{
		return;
	}
	memset(temp, 0, sizeof(int) * size);
	//如果最小的数为负数,则全部数减去此最小数,将全部数变为大于大于0的数
	if (min < 0)
	{
		for (i = 0; i < size; i++)
		{
			a[i] = a[i] - min;
		}
		max = max - min;
	}
	//位数
	int count = 1;
	//从个位开始排序
	for (count = 1; max / count > 0; count = count * 10)
	{
		//10个桶
		int buckets[10] = { 0 };

		//将数据位数出现次数存放在桶中
		for (i = 0; i < size; i++)
		{
			buckets[(a[i] / count) % 10]++;
		}

		//将桶中的值改为元素在temp中位置的下标
		for (i = 1; i < 10; i++)
		{
			buckets[i] = buckets[i] + buckets[i - 1];
		}

		//将a中的元素存放在temp中
		for (i = size - 1; i >= 0; i--)
		{
			int ncount = (a[i] / count) % 10;
			temp[buckets[ncount] - 1] = a[i];
			buckets[ncount]--;
		}
		//将temp的值复制到a中
		memcpy(a, temp, sizeof(int) * size);
	}
	//如果当初全部转为整数
	if (min < 0)
	{
		for (i = 0; i < size; i++)
		{
			a[i] = a[i] + min;
		}
	}
	free(temp);
	temp = NULL;
	return;
}

//颜色排序
//数组指针a（只含0，1，2元素），数组长度size
void ColorSort(int* a, int size)
{
	int p0 = 0, p2 = size - 1, i = 0;
	for (; i <= p2;)
	{
		if (a[i] == 0)
		{
			swap(a, i, p0++);
			i++;
		}
		else if (a[i] == 2)
		{
			swap(a, i, p2--);
		}
		else
		{
			i++;
		}
	}
	return;
}

//生成随机数
void getRandomNum(int* a,int size)
{
	srand((int)time(0));
	int i = 0;
	for (i = 0; i < size; i++)
	{
		a[i] = rand() % 2001 - 1000;
	}
	return;
}

//生成数据并保存到文件中
void storenumFile(int* a, char* PATH,int size)
{
	errno_t err;
	FILE* fp;
	err = fopen_s(&fp,PATH, "at+");
	if (err != 0)
	{
		printf("打开文件失败\n");
		return;
	}
	int i = 0;
	for (i = 0; i < size; i++)
	{
		fprintf(fp, "%d", a[i]);
		fprintf(fp, "  ");
	}
	fclose(fp);
	fp = NULL;
	printf("保存成功！\n");
	return;

}

//提取数字
int readNum(char* tmp, int* ret,int size)
{
	 int i = 0, j = 0, count = 0, start = 0;
	 int num = 0;
	char cut[1000] = "\0";
	for (i = 0; i < size; i++)
	{
		//遇到数字就一直读直到下一个不为数字
		if (tmp[i] > 47 && tmp[i] < 58)
		{
			count = 0;
			start = i;
			for (i;tmp[i+1]>47&&tmp[i+1]<58&&i<size-1;i++)
			{
				count++;
			}
			//如果最后一位位数字
			if (i == size-1)
			{
				if (tmp[i] > 47 && tmp[i] < 58)
				{
					count++;
					i++;
				}
			}
			count++;
			num=cutChar(tmp, start, count, cut);
			ret[j] = num;
			j++;
		}
	}
	return j;
}

//剪切字符串
int cutChar(char* str, int start, int count, char* cut)
{
	memcpy(cut, str, strlen(str));
	memcpy(cut, cut + start, strlen(cut) - start);
	memset(cut + count, '\0', strlen(cut) - count);
	int num = 0;
	num = atoi(cut);
	return num;
}

//读取文件数据并排序
int* readNumFild(char* PATH,int* Size)
{
	errno_t err;
	FILE* fp;
	long file_size;//文件字符数
	char* tmp;
	err = fopen_s(&fp,PATH, "r");
	if (err != 0)
	{
		return NULL;
	}
	fseek(fp, 0, SEEK_END);//将文件指针指向该文件的最后
	file_size = ftell(fp);//根据指针位置读出文件的字符数
	tmp = (char*)malloc((file_size+1) * sizeof(char));
	if (tmp == NULL)
	{
		return NULL;
	}
	int* ret = (int*)malloc(sizeof(int) * (file_size + 1));
	if (ret == NULL)
	{
		return NULL;
	}
	memset(tmp, '\0', (file_size+1) * sizeof(char));
	fseek(fp, 0, SEEK_SET);//将指针指向文件首部
	fread(tmp, sizeof(char), file_size, fp);//读取文件保存到tmp中
	tmp[file_size] = '\0';
	*Size = readNum(tmp, ret, file_size + 1);
	int* Ret = (int*)malloc(sizeof(int) * (*Size));
	if (Ret == NULL)
	{
		return NULL;
	}
	memcpy(Ret, ret, sizeof(int) * (*Size));
	return Ret;
}





