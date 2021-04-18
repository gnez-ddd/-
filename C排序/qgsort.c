#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"qgsort.h"

//��ӡ�˵�
void menuPrintf()
{
	printf("==========  hahahahahaha              ==========\n");
	printf("==========  1.������������ʱ          ==========\n");
	printf("==========  2.����С��������ʱ        ==========\n");
	printf("==========  3.��ɫ����                ==========\n");
	printf("==========  4.�ҵ�k�����             ==========\n");
	printf("==========  5.�������ݲ����浽�ļ���  ==========\n");
	printf("==========  6.���ļ��ж�ȡ���ݲ�����  ==========\n");
	printf("==========  0.�˳�                    ==========\n");
	printf("�����빦�ܵĶ��ڱ�ţ�\n");
	return;
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
		if (choice[i] < 48 || choice[i] > 57)
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
	if (a < 0 || a>6)
	{
		return ERROR;
	}

	return SUCCESS;
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

//����int����
int intJudge()
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

//����
void swap(int* a, int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
	return;
}

//���������㷨
//����ָ�� a, ���鳤�� n
void insertSort(int* a, int n)
{
	//����������ֻ��һ����û��
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


//�鲢���򣨺ϲ����飩
//����ָ��a���������begin�������е�mid�������յ�end����������ָ��temp
void MergeArray(int* a, int begin, int mid, int end, int* temp)
{
	int begin2 = mid+1, begin1 = begin, tempbegin = begin;
	//�ڸ��Է�Χ��
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
	//��temp�е�ֵ������a
	while (begin <= end)
	{
		a[begin] = temp[begin++];
	}
	return;
}

//�鲢����
//����ָ��a���������begin�������յ�end����������ָ��temp
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

//�������򣨵ݹ�棩
//����ָ��a���������begin�������յ�end
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

//�������������ţ�
//����ָ��a���������begin�������յ�end
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

//��ʼ��ջ
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

//��ջ
Status pushStack(Stack* s, int data)
{
	//�ж�ջ�Ƿ���
	if (s->top == s->size - 1)
	{
		return ERROR;
	}

	s->top++;
	s->elem[s->top] = data;
	return SUCCESS;
}

//��ջ
Status popStack(Stack* s,int* data)
{
	//��ջΪ��
	if (s->top == -1)
	{
		return ERROR;
	}
	*data = s->elem[s->top];
	s->top--;
	return SUCCESS;
}

//�ж�ջ�Ƿ�Ϊ��
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

//�������򣨷ǵݹ�棩
//����ָ��a�����鳤��size
void QuickSort(int* a, int size)
{
	if(size<2)
	{ 
		return;
	}
	//����һ��ջ����ʼ��
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

//��������
//����ָ��a�����鳤��size���������ֵmax
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

//��һ�������������ҵ���K��/С����
//����ָ��a�����鳤��size
//���ÿ���
int getNum(int* a, int size, int k)
{
	if (size < 2)
	{
		return a[0];
	}
	//�ҵ�n-k+1С������
	k = size - k + 1;
	int begin = 0;
	int end = size - 1;
	while (begin <= end)
	{
		int pivot = Partition(a, begin, end);
		//�ҵ���
		if (pivot + 1 == k)
		{
			return a[pivot];
		}
		//���ұ���
		else if (pivot + 1 < k)
		{
			begin = pivot + 1;
		}
		//�������
		else
		{
			end = pivot - 1;
		}
	}

}

//��ȡ��ֵ
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

//������������
//����ָ��a�����鳤��size
void RadixCountSort(int* a, int size)
{
	//Ѱ��������С����
	int max = 0, min = 0;
	MaxAndMin(a, &max, &min, size);
	int i = 0;
	//��ʱ����
	int* temp = (int*)malloc(sizeof(int) * size);
	if (temp == NULL)
	{
		return;
	}
	memset(temp, 0, sizeof(int) * size);
	//�����С����Ϊ����,��ȫ������ȥ����С��,��ȫ������Ϊ���ڴ���0����
	if (min < 0)
	{
		for (i = 0; i < size; i++)
		{
			a[i] = a[i] - min;
		}
		max = max - min;
	}
	//λ��
	int count = 1;
	//�Ӹ�λ��ʼ����
	for (count = 1; max / count > 0; count = count * 10)
	{
		//10��Ͱ
		int buckets[10] = { 0 };

		//������λ�����ִ��������Ͱ��
		for (i = 0; i < size; i++)
		{
			buckets[(a[i] / count) % 10]++;
		}

		//��Ͱ�е�ֵ��ΪԪ����temp��λ�õ��±�
		for (i = 1; i < 10; i++)
		{
			buckets[i] = buckets[i] + buckets[i - 1];
		}

		//��a�е�Ԫ�ش����temp��
		for (i = size - 1; i >= 0; i--)
		{
			int ncount = (a[i] / count) % 10;
			temp[buckets[ncount] - 1] = a[i];
			buckets[ncount]--;
		}
		//��temp��ֵ���Ƶ�a��
		memcpy(a, temp, sizeof(int) * size);
	}
	//�������ȫ��תΪ����
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

//��ɫ����
//����ָ��a��ֻ��0��1��2Ԫ�أ������鳤��size
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

//���������
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

//�������ݲ����浽�ļ���
void storenumFile(int* a, char* PATH,int size)
{
	errno_t err;
	FILE* fp;
	err = fopen_s(&fp,PATH, "at+");
	if (err != 0)
	{
		printf("���ļ�ʧ��\n");
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
	printf("����ɹ���\n");
	return;

}

//��ȡ����
int readNum(char* tmp, int* ret,int size)
{
	 int i = 0, j = 0, count = 0, start = 0;
	 int num = 0;
	char cut[1000] = "\0";
	for (i = 0; i < size; i++)
	{
		//�������־�һֱ��ֱ����һ����Ϊ����
		if (tmp[i] > 47 && tmp[i] < 58)
		{
			count = 0;
			start = i;
			for (i;tmp[i+1]>47&&tmp[i+1]<58&&i<size-1;i++)
			{
				count++;
			}
			//������һλλ����
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

//�����ַ���
int cutChar(char* str, int start, int count, char* cut)
{
	memcpy(cut, str, strlen(str));
	memcpy(cut, cut + start, strlen(cut) - start);
	memset(cut + count, '\0', strlen(cut) - count);
	int num = 0;
	num = atoi(cut);
	return num;
}

//��ȡ�ļ����ݲ�����
int* readNumFild(char* PATH,int* Size)
{
	errno_t err;
	FILE* fp;
	long file_size;//�ļ��ַ���
	char* tmp;
	err = fopen_s(&fp,PATH, "r");
	if (err != 0)
	{
		return NULL;
	}
	fseek(fp, 0, SEEK_END);//���ļ�ָ��ָ����ļ������
	file_size = ftell(fp);//����ָ��λ�ö����ļ����ַ���
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
	fseek(fp, 0, SEEK_SET);//��ָ��ָ���ļ��ײ�
	fread(tmp, sizeof(char), file_size, fp);//��ȡ�ļ����浽tmp��
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





