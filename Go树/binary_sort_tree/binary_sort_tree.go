package binary_sort_tree

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

//二叉树结点结构体
type Node struct {
	Value int
	Left,Right *Node
}

//二叉树结构体
type BinarySortTree struct {
	Root *Node
}

//栈结点
type StackNode struct{
	data *Node
	next *StackNode
}

//栈结构体
type LinkStack struct {
	top *StackNode
}

//队列结点
type QueueNode struct{
	data *Node
	next *QueueNode
}

//队列结构体
type LQueue struct {
	front *QueueNode
	rear *QueueNode
}

//初始化二叉排序树
func InitBST(T *BinarySortTree){
	T.Root = nil
}

//插入节点
func InsertBST(T *BinarySortTree,data int)bool{
	//如果没有这棵树
	if T == nil {
		return false
	}
	//若该树没有节点
	if T.Root == nil {
		T.Root = new(Node)
		T.Root.Left = nil
		T.Root.Right = nil
		T.Root.Value = data
		return true
	}
	//创建一个新节点
	newNode := new(Node)
	newNode.Left = nil
	newNode.Right = nil
	newNode.Value = data
	//定义一个指针指示位置
	temp := T.Root
	flag := false
	for flag != true {
		if temp.Value == data {
			newNode = nil
			flag = true
		} else if temp.Value > data {
			if temp.Left == nil {
				temp.Left = newNode
				flag = true
			} else {
				temp = temp.Left
			}
		} else if temp.Value < data {
			if temp.Right == nil {
				temp.Right = newNode
				flag = true
			} else {
				temp = temp.Right
			}
		}
	}
	return true
}

//删除节点
func DeleteBST(T *BinarySortTree,data int)bool {
	if T == nil || T.Root == nil {
		return  false
	}
	temp := T.Root
	var tempParents *Node
	flag := false

	for flag != true {
		if temp.Value == data {
			flag = true
		} else if temp.Value > data {
			if temp.Left == nil {
				temp = nil
				flag = true
			} else {
				tempParents = temp
				temp = temp.Left
			}
		} else if temp.Value < data {
			if temp.Right == nil {
				temp = nil
				flag = true
			} else {
				tempParents = temp
				temp = temp.Right
			}
		}
	}

	if temp == nil {
		return false
	}

	if temp.Left == nil && temp.Right == nil {
		if tempParents == nil {
			temp = nil
			T.Root = nil
			return true
		}

		if tempParents.Left == temp {
			tempParents.Left = nil
			temp = nil
			return  true
		}

		if tempParents.Right == temp {
			tempParents.Right = nil
			temp = nil
			return true
		}
	}

	if (temp.Left == nil && temp.Right != nil) || (temp.Right == nil && temp.Left != nil) {
		if tempParents == nil {
			if temp.Left != nil {
				T.Root = temp.Left
				temp = nil
				return  true
			}

			if temp.Right != nil {
				T.Root = temp.Left
				temp = nil
				return true
			}
		}

		if tempParents.Left == temp {
			if temp.Left != nil {
				tempParents.Left = temp.Left
				temp = nil
				return true
			}

			if temp.Right != nil {
				tempParents.Left = temp.Right
				temp = nil
				return true
			}
		}

		if tempParents.Right == temp {
			if temp.Left != nil {
				tempParents.Right = temp.Left
				temp = nil
				return true
			}

			if temp.Right != nil {
				tempParents.Right = temp.Right
				temp = nil
				return true
			}
		}
	}

	if temp.Left != nil && temp.Right != nil {
		rightMost := T.Root.Left
		rightMostParents := T.Root

		for rightMost.Right != nil {
			rightMostParents = rightMost
			rightMost =rightMost.Right
		}

		change := temp.Value
		temp.Value = rightMost.Value
		rightMost.Value = change

		if rightMostParents == T.Root {
			if rightMost.Left != nil {
				rightMostParents.Left = rightMost.Left
				rightMost = nil
				return true
			}

			if rightMost.Left != nil {
				rightMostParents.Left = nil
				rightMost = nil
			}
		}

		if rightMost.Left != nil {
			rightMostParents.Right = rightMost.Left
			rightMost = nil
			return true
		}

		if rightMost.Left == nil {
			rightMostParents.Right = nil
			rightMost = nil
			return true
		}
	}
	return true
}

//寻找节点
func SearchBST(T *BinarySortTree,data int)bool{
	if T == nil || T.Root == nil {
		return false
	}
	temp := T.Root
	flag := false
	 for flag != true {
	 	if temp.Value == data {
	 		flag = true
		} else if temp.Value > data {
			if temp.Left == nil {
				temp = nil
				flag = true
			} else {
				temp = temp.Left
			}
		} else if temp.Value < data {
			if temp.Right == nil {
				temp = nil
				flag = true
			} else {
				temp = temp.Right
			}
		}
	 }

	 if temp == nil {
	 	return false
	 } else {
	 	return true
	 }
}

//无递归前序遍历
func PreorderIBST(T *Node)bool {
	if T == nil {
		return false
	}
	s := new(LinkStack)
	InitLStack(s)
	PushLStack(s,T)
	for IsEmptyLStack(s) != true {
		var temp *Node
		PopLStack(s,&temp)
		fmt.Printf("%v\t",temp.Value)

		if temp.Right != nil {
			PushLStack(s,temp.Right)
		}
		if temp.Left != nil {
			PushLStack(s,temp.Left)
		}
	}
	s = nil
	return true
}

//递归前序遍历
func PreorderRBST(T *Node)bool{
	if T == nil {
		return false
	}
	temp := T
	fmt.Printf("%v\t",temp.Value)
	PreorderRBST(temp.Left)
	PreorderRBST(temp.Right)
	return true
}

//无递归中序遍历
func InorderIBST(T *Node)bool{
	if T == nil {
		return false
	}
	s := new(LinkStack)
	InitLStack(s)

	temp := T

	for temp != nil || s.top != nil {
		for temp != nil {
			PushLStack(s,temp)
			temp = temp.Left
		}
		if s.top != nil {
			PopLStack(s,&temp)
			fmt.Printf("%v\t",temp.Value)
			temp = temp.Right
		}
	}
	s = nil
	return true
}

//递归中序遍历
func InorderRBST(T *Node)bool{
	if T == nil {
		return false
	}
	temp := T
	InorderRBST(temp.Left)
	fmt.Printf("%v\t",temp.Value)
	InorderRBST(temp.Right)
	return true
}

//非递归后序遍历
func PostorderIBST(T *Node)bool{
	if T == nil {
		return false
	}
	tempStack := new(LinkStack)
	allStack := new(LinkStack)
	InitLStack(tempStack)
	InitLStack(allStack)

	temp := T
	for temp != nil || IsEmptyLStack(tempStack) != true {

		for temp != nil {
			PushLStack(tempStack,temp)
			PushLStack(allStack,temp)
			temp = temp.Right
		}

		if temp == nil && IsEmptyLStack(tempStack) != true {
			PopLStack(tempStack,&temp)
			temp = temp.Left
		}
	}

	for IsEmptyLStack(allStack) != true {
		PopLStack(allStack,&temp)
		fmt.Printf("%v\t",temp.Value)
	}
	tempStack = nil
	allStack = nil
	return true
}

//递归后序遍历
func PostorderRBST(T *Node)bool{
	if T == nil {
		return false
	}

	temp := T
	PostorderRBST(temp.Left)
	PostorderRBST(temp.Right)
	fmt.Printf("%v\t",temp.Value)
	return true
}

//层次遍历
func LevelOrderBST(T *Node)bool{
	if T == nil {
		return false
	}

	Q := new(LQueue)
	InitLQueue(Q)
	EnLQueue(Q,T)
	var temp *Node

	for IsEmptyLQueue(Q) != true {
		DeLQueue(Q,&temp)
		fmt.Printf("%v\t",temp.Value)

		if temp.Left != nil {
			EnLQueue(Q,temp.Left)
		}
		if temp.Right != nil {
			EnLQueue(Q,temp.Right)
		}
	}
	Q.front = nil
	Q = nil
	return true
}


//初始化栈
func InitLStack(s *LinkStack)bool{
	if s == nil {
		return false
	}
	s.top = nil
	return true
}

//判断栈是否为空
func IsEmptyLStack(s *LinkStack)bool{
	if s == nil || s.top == nil {
		return true
	}else {
		return false
	}
}

//入栈
func PushLStack(s *LinkStack,data *Node)bool{
	newNode := new(StackNode)
	newNode.data = data
	newNode.next = s.top
	s.top = newNode
	return true
}

//出栈
func PopLStack(s *LinkStack,temp **Node)bool{
	if s == nil || s.top == nil {
		return false
	}
	*temp = s.top.data
	del := s.top
	s.top = del.next
	del.data = nil
	del = nil
	return true
}

//初始化队列
func InitLQueue(Q *LQueue)bool{
	hNode := new(QueueNode)
	hNode.next = nil
	hNode.data = nil
	Q.front = hNode
	Q.rear = hNode
	return true
}

//判断队列是否为空
func IsEmptyLQueue(Q *LQueue)bool{
	if Q.front == Q.rear {
		return true
	} else {
		return false
	}
}

//入队
func EnLQueue(Q *LQueue,data *Node)bool{
	newNode := new(QueueNode)
	newNode.data = data
	newNode.next = nil
	Q.rear.next = newNode
	Q.rear = newNode
	return true
}

//出队
func DeLQueue(Q *LQueue,data **Node)bool{
	if Q.front == Q.rear {
		return false
	}
	*data = Q.front.next.data
	temp := Q.front.next
	Q.front.next = temp.next
	if Q.front.next == nil {
		Q.rear = Q.front
	}
	temp.data = nil
	temp = nil
	return true
}

//打印主菜单
func PrintMenu() {
	fmt.Printf("==========hahahahahahahah     ==========\n")
	fmt.Printf("==========1.插入数据           ==========\n")
	fmt.Printf("==========2.删除数据           ==========\n")
	fmt.Printf("==========3.寻找数据           ==========\n")
	fmt.Printf("==========4.非递归前序遍历      ==========\n")
	fmt.Printf("==========5.递归前序遍历        ==========\n")
	fmt.Printf("==========6.非递归中序遍历      ==========\n")
	fmt.Printf("==========7.递归中序遍历        ==========\n")
	fmt.Printf("==========8.非递归后序遍历      ==========\n")
	fmt.Printf("==========9.递归后序遍历       ==========\n")
	fmt.Printf("==========10.层次遍历         ==========\n")
	fmt.Printf("==========0.退出             ==========\n")
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
	for err != nil || i < 0 || i > 10  {
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
