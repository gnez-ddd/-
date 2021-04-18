package sort

import (
	"bufio"
	"fmt"
	"io"
	"math/rand"
	"os"
	"strconv"
	"time"
)

//打印菜单
func MenuPrintf(){
	fmt.Printf("==========  hahahahahaha              ==========\n")
	fmt.Printf("==========  1.大数据量下用时             ==========\n")
	fmt.Printf("==========  2.大量小数组下用时           ==========\n")
	fmt.Printf("==========  3.颜色排序                 ==========\n")
	fmt.Printf("==========  4.找第k大的数              ==========\n")
	fmt.Printf("==========  5.生成数据并保存到文件中      ==========\n")
	fmt.Printf("==========  6.从文件中读取数据并排序      ==========\n")
	fmt.Printf("==========  0.退出                    ==========\n")
	fmt.Printf("请输入功能的对于编号：\n")
}

//选择功能
func FuncChoice(choice *string) bool {
	var inputReader *bufio.Reader
	var input string
	inputReader = bufio.NewReader(os.Stdin)
	input, _ = inputReader.ReadString('\n')
	slice1 := []rune(input)
	slice2 := slice1[0:len(slice1)-2]
	var a string
	a = string(slice2)
	i,err := strconv.ParseInt(a,10,64)
	for err != nil || i < 0 || i > 6  {
		fmt.Printf("输入有误，请重新输入\n")
		input, _ = inputReader.ReadString('\n')
		slice1 = []rune(input)
		slice2 = slice1[0:len(slice1)-2]
		a = string(slice2)
		i,err = strconv.ParseInt(a,10,64)
	}
	*choice = a
	return true
}


//输入数据
func IsNum(num *string) bool {
	var inputReader *bufio.Reader
	var input string
	inputReader = bufio.NewReader(os.Stdin)
	input, _ = inputReader.ReadString('\n')
	slice1 := []rune(input)
	slice2 := slice1[0:len(slice1)-2]
	var a string
	a = string(slice2)
	_,err := strconv.ParseInt(a,10,64)
	for err != nil {
		fmt.Printf("输入有误，请重新输入\n")
		input, _ = inputReader.ReadString('\n')
		slice1 = []rune(input)
		slice2 = slice1[0:len(slice1)-2]
		a = string(slice2)
		_,err = strconv.ParseInt(a,10,64)
	}
	*num = a
	return true
}

//交换
func Swap(a []int,i int,j int){
	temp := a[i]
	a[i] = a[j]
	a[j] = temp
}

//插入排序算法
func InsertSort(a []int,n int){
	//如果切片个数为一个或者没有
	if n < 2 {
		return
	}

	i := 1
	temp := 0

	for i = 1;i < n;i++ {
		temp = a[i]
		j := i - 1

		for j = i - 1;j >= 0 && temp < a[j];j-- {
			a[j + 1] = a[j]
		}
		a[j + 1] =temp
	}
}

//归并排序（合并数组）
func MergeArray(a []int,begin int,mid int,end int, temp []int){
	begin2 := mid + 1
	begin1 := begin
	tempbegin := begin

	//在各自范围内
	for begin1 <= mid && begin2 <= end {
		if a[begin1] > a[begin2] {
			temp[tempbegin] = a[begin2]
			tempbegin++
			begin2++
		} else {
			temp[tempbegin] = a[begin1]
			tempbegin++
			begin1++
		}
	}
	for begin1 <= mid {
		temp[tempbegin] = a[begin1]
		tempbegin++
		begin1++
	}
	for begin2 <= end {
		temp[tempbegin] = a[begin2]
		tempbegin++
		begin2++
	}
	//将temp的值拷贝到a
	for begin <= end {
		a[begin] = temp[begin]
		begin++
	}
}

//归并排序
func MergeSort(a []int,begin int,end int,temp []int){
	if (end - begin + 1) < 2 {
		return
	}
	if begin >= end {
		return
	} else {
		m := (begin + end) / 2
		MergeSort(a,begin,m,temp)
		MergeSort(a,m+1,end,temp)
		MergeArray(a,begin,m,end,temp)
	}
	return
}

//快排递归版
func QuickSortRecursion(a []int,begin int,end int){
	if (end - begin + 1) < 2 {
		return
	}
	pivot := 0
	for begin < end {
		pivot = Partition(a,begin,end)
		QuickSortRecursion(a,begin,pivot - 1)
		begin = pivot + 1
	}
	return
}

//快排枢轴存放
func Partition(a []int,begin int,end int)int{
	temp := 0
	pivotkey := 0
	m := begin + (end - begin)/ 2
	if a[begin] > a[end] {
		Swap(a,begin,end)
	}
	if a[m] > a[end] {
		Swap(a,end,m)
	}
	if a[m] > a[begin] {
		Swap(a,m,begin)
	}
	pivotkey = a[begin]
	temp = pivotkey
	for begin < end {
		for begin < end && a[end] >= pivotkey {
			end--
		}
		a[begin] = a[end]
		for begin < end && a[begin] <= pivotkey {
			begin++
		}
		a[end] = a[begin]
	}
	a[begin] = temp
	return begin
}

//栈结构体
type Stack struct {
	elem []int
	top int
	size int
}

//初始化栈
func InitStack(s *Stack,sizes int)bool{
	s.elem = make([]int,sizes)
	s.size = sizes
	s.top = -1
	return true
}

//入栈
func PushStack(s *Stack,data int)bool{
	if s.top == s.size - 1 {
		return false
	}
	s.top++
	s.elem[s.top] = data
	return true
}

//出栈
func PopStack(s *Stack,data *int)bool{
	if s.top == -1 {
		return false
	}
	*data = s.elem[s.top]
	s.top--
	return true
}

//判断栈是否为空
func IsEmptyStack(s *Stack)bool{
	if s.top == -1 {
		return true
	}else {
		return false
	}
}

//快排非递归
func QuickSort(a []int,size int){
	if size < 2 {
		return
	}
	//建立并初始化一个栈
	s := new(Stack)
	InitStack(s,size)

	begin := 0
	end := size - 1
	PushStack(s,begin)
	PushStack(s,end)
	for !IsEmptyStack(s) {
		begin1 := 0
		end1 := 0
		PopStack(s,&end1)
		PopStack(s,&begin1)
		pivot := Partition(a,begin1,end1)
		if begin1 < pivot - 1 {
			PushStack(s,begin1)
			PushStack(s,pivot - 1)
		}
		if end1 > pivot + 1 {
			PushStack(s,pivot + 1)
			PushStack(s,end1)
		}
	}
}

//计数排序
func CountSort(a []int,size int,max int,min int){
	if size < 2 {
		return
	}
	i := 0
	j := 0
	nmax := max
	nmin := min
	if min < 0 {
		for i = 0;i < size;i++ {
			a[i] = a[i] - min
		}
		nmax = max - min
		nmin = 0
	}
	length := nmax - nmin + 1
	temp := make([]int,length)
	for i = 0;i < size;i++ {
		temp[a[i]-nmin]++
	}
	j = 0
	for i = 0;i < length;i++ {
		for temp[i] > 0 {
			temp[i]--
			a[j] = i + nmin
			j++
		}
	}
	if min < 0 {
		for i = 0;i < size;i++ {
			a[i] = a[i] + min
		}
	}
}

//在无序序列中找到第k大的数
func GetNum(a []int,size int,k int)int{
	if size < 2 {
		return a[0]
	}
	k = size - k + 1
	begin := 0
	end := size - 1
	pivot := Partition(a,begin,end)
	for begin <= end   {
		pivot = Partition(a,begin,end)

		if pivot + 1 == k {
			break
		} else if pivot + 1 < k {
			begin = pivot + 1
		} else {
			end = pivot - 1
		}
	}
	return a[pivot]

}

//获得最值
func MaxAndMin(a []int,max *int,min *int,size int){
	i := 0
	for i = 0;i < size;i++ {
		if a[i] > *max {
			*max = a[i]
		} else if a[i] < *min {
			*min = a[i]
		}
	}
}

//基数计数排序
func RadixCountSort(a []int,size int){
	max := 0
	min := 0
	MaxAndMin(a,&max,&min,size)
	i := 0
	temp := make([]int,size)
	if min < 0 {
		for i = 0;i < size;i++ {
			a[i] = a[i] - min
		}
		max = max - min
	}
	count := 1
	 for count = 1;max / count > 0;count = count * 10 {
	 	var buckets [10]int
	 	for i = 0;i < size;i++ {
	 		buckets[(a[i] / count) % 10]++
		}
		for i = 1;i < 10;i++ {
			buckets[i] = buckets[i] + buckets[i - 1]
		}
		for i = size - 1;i >= 0;i-- {
			ncount := (a[i] / count) % 10
			temp[buckets[ncount] - 1] = a[i]
			buckets[ncount]--
		}
		copy(a,temp)
	 }
	 if min < 0 {
	 	for i = 0;i < size;i++ {
	 		a[i] = a[i] + min
		}
	 }
}

//颜色排序
func ColorSort(a []int,size int){
	p0 := 0
	p2 := size - 1
	i := 0
	for i <= p2 {
		if a[i] == 0 {
			Swap(a,i,p0)
			p0++
			i++
		} else if a[i] == 2 {
			Swap(a,i,p2)
			p2--
		} else {
			i++
		}
	}
}

//生成随机数
func GetRandomNum(a []int,size int){
	rand.Seed(time.Now().Unix())
	i := 0
	for i = 0;i < size;i++ {
		a[i] = rand.Intn(2001) - 1000
	}
}

//生成数据并保存到文件中
func StoreNumFile(a []int,path string,size int)bool{
	file,err := os.OpenFile(path,os.O_CREATE | os.O_APPEND,0666)
	if err != nil {
		fmt.Println("打开文件失败！")
		return false
	}
	defer file.Close()
	i := 0
	writer := bufio.NewWriter(file)
	var str string
	for i = 0;i < size;i++ {
		str = strconv.Itoa(a[i])
		_, _ = writer.WriteString(str)
		_ = writer.WriteByte(' ')
	}
	_ = writer.Flush()
	return true
}

//读取文件数据
func ReadNumFile(path string,str *string)(bool,int,[]int){
	file,err := os.Open(path)
	if err != nil {
		return false,0,nil
	}
	defer file.Close()
	reader := bufio.NewReader(file)

	for {
		*str,err = reader.ReadString('\n')
		if err == io.EOF {
			break
		}
	}

	size,ret := ReadNum(*str)
	return true,size,ret
}

//提取数字
func ReadNum(str string)(int,[]int){
	i := 0
	j := 0
	count := 0
	start := 0
	num := 0
	tmp := []rune(str)
	ret := make([]int,len(tmp) + 1)
	for i = 0;i < len(tmp);i++ {
		if tmp[i] > 47 && tmp[i] < 58 {
			count = 0
			start = i
			for  i < len(tmp) - 1 && tmp[i + 1] > 47 && tmp[i + 1] < 58 {
				count++
				i++
			}
			if i == len(tmp) - 1 {
				if tmp[i] > 47 && tmp[i] < 58 {
					i++
				}
			}
			count++
			num = CutString(tmp,start,count)
			ret[j] = num
			j++
		}
	}
	return j,ret
}

func CutString(tmp []rune,start int,count int)int{
	ret := tmp[start : count+start]
	Ret := string(ret)
	num, _ := strconv.ParseInt(Ret,10,64)
	return int(num)
}