package LQueue

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type Node struct {
	Data interface{}
	Next *Node
	Type string
}

type LQueue struct {
	Front *Node
	Rear *Node
	Length int
}

//初始化队列
func InitLQueue(Q *LQueue) {
	//创建头节点
	HNode := new(Node)
	HNode.Next = nil
	HNode.Type = "0"
	HNode.Data = nil
	Q.Front = HNode
	Q.Rear = HNode
	Q.Length = 0
}

//入队
func EnLQueue (Q *LQueue,data interface{},a string){
	newNode := new(Node)
	newNode.Data = data
	newNode.Type = a
	newNode.Next = nil
	Q.Rear.Next = newNode
	Q.Rear = newNode
	Q.Length++
}

//出队
func DeLQueue(Q *LQueue) bool {
	//若队列为空
	if Q.Front == Q.Rear {
		return false
	}
	temp := Q.Front.Next
	Q.Front.Next = temp.Next
	//若删除的元素为队尾元素
	if Q.Front.Next == nil {
		Q.Rear = Q.Front
	}
	temp = nil
	Q.Length--
	return true
}

//检测队列是否为空
func IsEmptyLQueue(Q *LQueue)bool {
	if Q.Front == Q.Rear {
		return true
	} else {
		return false
	}
}

//查看队头元素
func GetHeadLQueue(Q *LQueue,e interface{})bool{
	e = Q.Front.Next.Data
	return true
}

//清空队列
func ClearLQueue(Q *LQueue){
	Q.Rear=Q.Front
	for Q.Front.Next != nil {
		temp := Q.Front.Next
		Q.Front.Next = temp.Next
		temp = nil
	}
	Q.Length = 0
}

//销毁队列
func DestroyLQueue(Q *LQueue) bool{
	if Q.Front == Q.Rear {
		Q.Front = nil
		Q = nil
		return true
	}
	Q.Rear=Q.Front
	for Q.Front.Next != nil {
		temp := Q.Front.Next
		Q.Front.Next = temp.Next
		temp = nil
	}
	Q.Front = nil
	Q = nil
	return true
}

//队列长度
func LengthLQueue(Q *LQueue)int {
	return Q.Length
}

//遍历队列
func TraverseLQueue(Q *LQueue)bool{
	if Q.Front == Q.Rear {
		fmt.Printf("该队列为空!\n")
		return false
	}
	var a *int64
	var b *float64
	var c *string
	temp := Q.Front.Next
	fmt.Printf("该队列数据为:\n")
	for temp != nil {
		//若为int
		if temp.Type == "a" {
			a,_ = temp.Data.(*int64)
			fmt.Println(*a)
		}
		if temp.Type == "b" {
			b,_ = temp.Data.(*float64)
			fmt.Println(*b)
		}
		if temp.Type == "c" {
			c,_ = temp.Data.(*string)
			fmt.Println(*c)
		}
		temp = temp.Next
	}
	return true
}






//打印主菜单
func PrintMenu() {
	fmt.Printf("==========hahahahahahahah ==========\n")
	fmt.Printf("==========1.入队           ==========\n")
	fmt.Printf("==========2.出队           ==========\n")
	fmt.Printf("==========3.判断队列是否为空  ==========\n")
	fmt.Printf("==========4.查看队头元素      ==========\n")
	fmt.Printf("==========5.清空队列         ==========\n")
	fmt.Printf("==========6.销毁队列并退出程序 ==========\n")
	fmt.Printf("==========7.检测队列长度      ==========\n")
	fmt.Printf("==========8.遍历队列         ==========\n")
	fmt.Printf("==========0.退出           ==========\n")
	fmt.Printf("请输入功能的对应编号:\n")
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
	for err != nil || i < 0 || i > 8  {
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
func IsType(Type *string) bool {
	var inputReader *bufio.Reader
	var input string
	inputReader = bufio.NewReader(os.Stdin)
	input, _ = inputReader.ReadString('\n')
	slice1 := []rune(input)
	slice2 := slice1[0:len(slice1)-2]
	*Type = string(slice2)
	for *Type != "a" && *Type != "b" && *Type != "c" {
		fmt.Printf("输入有误，请重新输入\n")
		input, _ = inputReader.ReadString('\n')
		slice1 = []rune(input)
		slice2 = slice1[0:len(slice1)-2]
		*Type = string(slice2)
	}
	return true
}

//输入int数据
func IsNumInt(num *string) bool {
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

//输入float64数据
func IsNumFloat64(num *string) bool {
	var inputReader *bufio.Reader
	var input string
	inputReader = bufio.NewReader(os.Stdin)
	input, _ = inputReader.ReadString('\n')
	slice1 := []rune(input)
	slice2 := slice1[0:len(slice1)-2]
	var a string
	a = string(slice2)
	_,err := strconv.ParseFloat(a,64)
	for err != nil {
		fmt.Printf("输入有误，请重新输入\n")
		input, _ = inputReader.ReadString('\n')
		slice1 = []rune(input)
		slice2 = slice1[0:len(slice1)-2]
		a = string(slice2)
		_,err = strconv.ParseFloat(a,64)
	}
	*num = a
	return true
}

func IsNumString(num *string) bool {
	var inputReader *bufio.Reader
	var input string
	inputReader = bufio.NewReader(os.Stdin)
	input, _ = inputReader.ReadString('\n')
	slice1 := []rune(input)
	slice2 := slice1[0:len(slice1)-2]
	*num = string(slice2)

	return true
}