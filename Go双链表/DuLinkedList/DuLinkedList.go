package DuLinkedList

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type LNode struct {
	Data int64
	Next *LNode
	Prior *LNode
}

var Mark *LNode

//初始化链表
func InitList (L *LNode) bool {
	//若链表为空
	if L == nil {
		return false
	}

	L.Data = 0
	L.Next = L
	L.Prior = L
	return true
}

//销毁链表
func DestroyList (L *LNode) {
	//若链表为空
	if L.Next == L {
		return
	}

	for L.Next != L {
		var temp *LNode
		temp = L.Next
		L.Next = temp.Next
		temp.Next.Prior = L
		temp = nil
	}
	return
}

//在节点p之后插入节点q pq
func InterstatesDul(p *LNode,q *LNode) bool{

	q.Prior = p
	q.Next = p.Next
	p.Next.Prior = q
	p.Next = q
	return true
}

//将节点q插入到节点p之前 qp
func InsectivoresDul(p *LNode,q *LNode)bool{
	q.Next = p
	q.Prior = p.Prior
	p.Prior.Next = q
	p.Prior = q
	return true
}

//删除节点
func DeleteList (p *LNode,e *int64) bool {
	var temp *LNode
	temp = p.Next
	*e = temp.Data
	temp.Next.Prior = p
	p.Next = temp.Next
	temp = nil
	return true
}

//遍历链表
func TraverseList(L *LNode){
	//若链表为空
	if L.Next == L {
		fmt.Printf("该链表为空!\n")
		return
	}

	fmt.Printf("该链表存储数据为:\n")
	var temp *LNode
	temp = L.Next
	for temp != L {
		fmt.Printf("%v\t",temp.Data)
		temp = temp.Next
	}
	fmt.Printf("\n")
	return
}


//查询节点
func SearchList (L *LNode,e int64) bool {
	//若链表为空
	if L.Next == L {
		return false
	}

	var temp *LNode
	temp = L.Next

	for temp != L && temp.Data != e {
		temp = temp.Next
	}

	//找到
	if temp != L {
		//将该节点记录在mark
		Mark = temp
		return true
	} else {
		return false
	}
}

//判断是否成环
func IsLoopList (L *LNode) bool {
	//若链表为空或只有一个节点时
	if L.Next == L || L.Next.Next == L {
		return false
	}

	var fast,slow *LNode
	fast = L.Next.Next
	slow = L.Next
	for slow != fast {
		fast = fast.Next.Next
		slow = slow.Next
	}
	if fast == L {
		return false
	} else {
		return true
	}
}

//反转链表 非递归
func ReverseList01(L *LNode) bool {
	change := L.Next.Next
	pre := L.Next
	for pre.Next != L {
		pre.Next = change.Next
		change.Next = L.Next
		L.Next = change
		change = pre.Next
	}
	change = L
	change.Next.Prior = change
	change = change.Next
	for change.Next != L {
		change.Next.Prior = change
		change = change.Next
	}
	L.Prior=change
	return true
}

//反转链表（next指针）递归
func ReverseListNext (head *LNode,L *LNode,tail *LNode) *LNode {
	if head.Next == L {
		return head
	}
	p := ReverseListNext(head.Next,L,tail)
	if head == L {
		L.Next = tail
		return L
	}
	head.Next.Next = head
	head.Next = L
	return p
}

//反转链表 递归
func ReverseList02 (L *LNode) bool {
	head := L
	tail := L.Prior
	ReverseListNext(head,L,tail)
	change := L
	change.Next.Prior = change
	change = change.Next
	for change.Next != L {
		change.Next.Prior = change
		change = change.Next
	}
	L.Prior = change
	return true
}

//打印主菜单
func PrintMenu() {
	fmt.Printf("==========hahahahahahahah         ==========\n")
	fmt.Printf("==========1.插入在已知节点之后        ==========\n")
	fmt.Printf("==========2.插入在已知节点之前        ==========\n")
	fmt.Printf("==========3.遍历链表                ==========\n")
	fmt.Printf("==========4.删除节点                ==========\n")
	fmt.Printf("==========5.查找节点                ==========\n")
	fmt.Printf("==========6.销毁链表                ==========\n")
	fmt.Printf("==========7.判断是否为环             ==========\n")
	fmt.Printf("==========8.反转链表(非递归)         ==========\n")
	fmt.Printf("==========9.反转链表(递归)           ==========\n")
	fmt.Printf("==========0.退出                   ==========\n")
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
