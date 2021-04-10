package linkedList
import(
	"bufio"
	"fmt"
	"os"
	"strconv"
)


type LNode struct {
	Data int64
	Next *LNode
}

var Mark *LNode

//初始化链表
func InitList (L *LNode) bool {
	//若链表为空
	if L == nil {
		return false
	}

	L.Data = 0
	L.Next = nil
	return true
}

//销毁链表
func DestroyList (L *LNode) {
	//若链表为空
	if L.Next == nil {
		return
	}

	for L.Next != nil {
		var temp *LNode
		temp = L.Next
		L.Next = temp.Next
		temp = nil
	}
	return
}

//插入节点
func InsertList (p *LNode,q *LNode) bool {
	q.Next = p.Next
	p.Next = q
	return true
}

//删除节点
func DeleteList (p *LNode,e *int64) bool {
	var temp *LNode
	temp = p.Next
	*e = temp.Data
	p.Next = p.Next.Next
	temp = nil
	return true
}

//遍历链表
func TraverseList(L *LNode){
	//若链表为空
	if L.Next == nil {
		fmt.Printf("该链表为空!\n")
		return
	}
	fmt.Printf("该链表存储数据为：\n")
	var temp *LNode
	temp = L.Next
	for temp != nil {
		fmt.Printf("%v\n",temp.Data)
		temp = temp.Next
	}
	fmt.Printf("\n")
	return
}


//查询节点
func SearchList (L *LNode,e int64) bool {
	//若链表为空
	if L.Next == nil {
		return false
	}

	var temp *LNode
	temp = L.Next

	for temp != nil && temp.Data != e {
		temp = temp.Next
	}

	//找到
	if temp != nil {
		//将该节点记录在mark
		Mark = temp
		return true
	} else {
		return false
	}
}

//反转链表 非递归
func ReverseList01 (L *LNode) bool {

	var pre,temp *LNode
	pre = L.Next
	temp = L.Next

	for temp.Next != nil {
		L.Next = temp.Next
		temp.Next = L.Next.Next
		L.Next.Next = pre
		pre = L.Next
	}
	return true
}

//反转链表 递归
func ReverseList02 (head *LNode,L *LNode,tail *LNode) *LNode {
	if head.Next == nil || head == nil {
		return head
	}
	var (
		p = ReverseList02(head.Next, L, tail)
	)
	if head == L {
		L.Next = tail
		return L
	}
	head.Next.Next = head
	head.Next = nil
	return p
}

//判断是否成环
func IsLoopList (L *LNode) bool {
	//若链表为空或只有一个节点
	if L.Next == nil || L.Next.Next == nil{
		return false
	}

	var fast,slow *LNode
	fast = L.Next.Next
	slow = L.Next
	if fast.Next == nil || fast.Next.Next == nil {
		return false
	}
	for slow != fast{
		fast = fast.Next.Next
		slow = slow.Next
		if fast.Next == nil || fast.Next.Next == nil {
			return false
		}
	}
	return true
}

//奇偶调换
func ReverseEvenList (L *LNode) *LNode {

	var temp,pre *LNode
	temp = L.Next
	pre = L
	for temp != nil {
		pre.Next = temp.Next
		temp.Next = pre.Next.Next
		pre.Next.Next = temp
		pre = temp
		temp = temp.Next
		if temp == nil ||temp.Next == nil {
			return L
		}
	}
	return L
}

//寻找中间节点
func FindMidNode (L *LNode) *LNode {
	if L.Next == nil {
		return L
	}

	var fast,slow *LNode
	fast = L.Next
	slow = L.Next
	for fast != nil && fast.Next != nil {
		fast = fast.Next.Next
		slow = slow.Next
	}
	return slow
}

//打印主菜单
func PrintMenu() {
	fmt.Printf("==========hahahahahahahah ==========\n")
	fmt.Printf("==========1.插入节点        ==========\n")
	fmt.Printf("==========2.遍历链表        ==========\n")
	fmt.Printf("==========3.删除节点        ==========\n")
	fmt.Printf("==========4.查找节点        ==========\n")
	fmt.Printf("==========5.销毁链表        ==========\n")
	fmt.Printf("==========6.反转链表(非递归) ==========\n")
	fmt.Printf("==========7.反转链表(递归)   ==========\n")
	fmt.Printf("==========8.判断是否为环     ==========\n")
	fmt.Printf("==========9.调换奇偶顺序     ==========\n")
	fmt.Printf("==========10.查中间节点       ==========\n")
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

