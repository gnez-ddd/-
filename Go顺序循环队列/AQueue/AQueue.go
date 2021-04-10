package AQueue

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type AQueue struct {
	Data [10]interface{}
	Front int
	Rear int
	Length int
}

var DataType [10]string

//初始化队列
func InitAQueue(Q *AQueue) {
	Q.Front = 0
	Q.Rear = 0
	Q.Length = 0
}

//入队
func EnAQueue (Q *AQueue,data interface{}) bool {
	Q.Data[Q.Rear] = data
	Q.Rear = (Q.Rear + 1) % 10
	Q.Length++
	return true
}

//出队
func DeAQueue (Q *AQueue) bool {
	//若队列为空
	if Q.Front == Q.Rear {
		return false
	}
	Q.Front = (Q.Front + 1) % 10
	Q.Length--
	return true
}

//判断队列是否为空
func IsEmptyAQueue (Q *AQueue) bool {
	if Q.Rear == Q.Front {
		return true
	} else {
		return false
	}
}

//检查队列是否满了
func IsFullAQueue(Q *AQueue) bool {
	if (Q.Rear+1) % 10 == Q.Front {
		return true
	} else {
		return false
	}
}

//查看队头元素
func GetHeadAQueue(Q *AQueue,e interface{}) {
	e = Q.Data[Q.Front]
}

//清空队列
func ClearAQueue (Q *AQueue) {
	Q.Front = 0
	Q.Rear = 0
	Q.Length = 0
}

//销毁队列
func DestroyAQueue(Q *AQueue) {
	Q=nil
}

//判断队列长度
func LengthAQueue(Q *AQueue) int {
	return Q.Length
}

//遍历队列
func TraverseAQueue(Q *AQueue) {
	if Q.Front == Q.Rear {
		fmt.Printf("该队列为空!\n")
		return
	}
	var a *int64
	var b *float64
	var c *string
	temp := Q.Front
	fmt.Printf("该队列数据为:\n")
	for temp != Q.Rear && temp != 10 {
		if DataType[temp] == "a" {
			a,_ = Q.Data[temp].(*int64)
			fmt.Println(*a)
		}
		if DataType[temp] == "b" {
			b,_ = Q.Data[temp].(*float64)
			fmt.Println(*b)
		}
		if DataType[temp] == "c" {
			c,_ = Q.Data[temp].(*string)
			fmt.Println(*c)
		}
		temp++
	}
	if temp != Q.Rear {
		temp = 0
		for temp != Q.Rear {
			if DataType[temp] == "a" {
				a,_ = Q.Data[temp].(*int64)
				fmt.Println(*a)
			}
			if DataType[temp] == "b" {
				b,_ = Q.Data[temp].(*float64)
				fmt.Println(*b)
			}
			if DataType[temp] == "c" {
				c,_ = Q.Data[temp].(*string)
				fmt.Println(*c)
			}
			temp++
		}
		return
	} else {
		return
	}
}

//打印主菜单
func PrintMenu() {
	fmt.Printf("==========hahahahahahahah ==========\n")
	fmt.Printf("==========1.入队           ==========\n")
	fmt.Printf("==========2.出队           ==========\n")
	fmt.Printf("==========3.判断队列是否为空  ==========\n")
	fmt.Printf("==========4.判断队列是否满    ==========\n")
	fmt.Printf("==========5.查看队头元素      ==========\n")
	fmt.Printf("==========6.清空队列         ==========\n")
	fmt.Printf("==========7.销毁队列并退出程序 ==========\n")
	fmt.Printf("==========8.检测队列长度      ==========\n")
	fmt.Printf("==========9.遍历队列         ==========\n")
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
	for err != nil || i < 0 || i > 9  {
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