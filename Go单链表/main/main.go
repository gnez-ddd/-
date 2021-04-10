package main
import(
	"fmt"
	"go_code/GoLinkedList/LinkedList"
	"strconv"
)

func main(){
	var choice string
	var judge bool

	//生成头节点并初始化
	HNode := new(linkedList.LNode)
	linkedList.InitList(HNode)

	for choice != "0" {

		//打印主界面并选择功能
		linkedList.PrintMenu()
		linkedList.FuncChoice(&choice)

		switch choice {

		//退出系统
		case "0" :
			fmt.Printf("退出系统\n")

		//插入节点
		case "1" :
			fmt.Printf("请输入要插入的位置的前一个节点存放的数据:")
			var f string
			linkedList.IsNum(&f)
			nf,_ := strconv.ParseInt(f,10,64)

			fmt.Printf("请输入要存放的数据:")
			//e := linkedList.DataJudge()
			var e string
			linkedList.IsNum(&e)
			ne,_ := strconv.ParseInt(e,10,64)

			//定义新结点
			newNode := new(linkedList.LNode)
			newNode.Data = ne
			newNode.Next = nil

			//查询该位置的节点
			judge = linkedList.SearchList(HNode, nf)
			//查询不到该结点，则默认插入到头结点后的第一个位置
			if judge == false{
				fmt.Printf("查询不到该结点，默认插入到头结点后的第一个位置\n")
				linkedList.InsertList(HNode, newNode)
			}
			//查询到该结点
			if judge == true{
				linkedList.InsertList(linkedList.Mark, newNode)
			}
			fmt.Printf("插入成功!\n")
			linkedList.TraverseList(HNode)

		//遍历链表
		case "2" :
			linkedList.TraverseList(HNode)

		//删除节点
		case "3" :
			if HNode.Next == nil {
				fmt.Printf("该链表为空，删除失败!\n")
				break
			}
			linkedList.TraverseList(HNode)

			//输入要删除的节点的上一个节点数据
			fmt.Printf("请输入要删除的节点的上一个节点数据：\n")
			var f string
			linkedList.IsNum(&f)
			nf,_ := strconv.ParseInt(f,10,64)

			//寻找要删除的节点的上一个节点
			judge = linkedList.SearchList(HNode, nf)
			//找不到
			if judge == false{
				fmt.Printf("查询不到改结点!删除失败!\n")
				break
			}
			//找到
			if judge == true{
				var e int64
				//如果该节点为最后一个结点
				if linkedList.Mark.Next == nil {
					fmt.Printf("被删除的节点是上一个节点为最后一个节点，删除失败!\n")
					break
				}
				linkedList.DeleteList(linkedList.Mark, &e)
				fmt.Printf("该数据为%d\n",e)
				fmt.Printf("删除成功!\n")
				linkedList.TraverseList(HNode)
			}

		//查找节点
		case "4":
			//输入要查找的节点数据
			fmt.Printf("请输入要查找的节点数据：\n")
			//f := linkedList.DataJudge()
			var f string
			linkedList.IsNum(&f)
			nf,_ := strconv.ParseInt(f,10,64)


			//寻找节点
			judge = linkedList.SearchList(HNode, nf)

			if judge == false{
				fmt.Printf("查询不到!\n")
			}

			if judge == true{
				fmt.Printf("查询到该节点!\n")
			}

		//销毁链表
		case "5":
			if HNode.Next == nil {
				fmt.Printf("该链表为空!\n")
				break
			}
			linkedList.DestroyList(HNode)
			fmt.Printf("销毁链表成功!\n")

		//反转链表 非递归
		case "6":
			if HNode.Next == nil || HNode.Next.Next == nil {
				fmt.Printf("该链表为空或只有一个节点，无法反转!\n")
				break
			}
			linkedList.ReverseList01(HNode)
			fmt.Printf("反转成功!\n")
			linkedList.TraverseList(HNode)

		//反转链表 递归
		case "7" :
			if HNode.Next == nil || HNode.Next.Next == nil {
				fmt.Printf("该链表为空或只有一个节点，无法反转!\n")
				break
			}
			//寻找最后一个结点
			tail := HNode
			for tail.Next != nil {
				tail = tail.Next
			}
			linkedList.ReverseList02(HNode,HNode,tail)
			fmt.Printf("反转成功!\n")
			linkedList.TraverseList(HNode)


		//判断是否为环
		case "8":
			judge = linkedList.IsLoopList(HNode)
			if judge == false {
				fmt.Printf("该链表不为环!\n")
			}
			if judge == true {
				fmt.Printf("该链表为环!\n")
			}

		//调换奇偶顺序
		case "9":
			if HNode.Next == nil || HNode.Next.Next == nil {
				fmt.Printf("该链表为空或只有一个节点，无法调换!\n")
				break
			}
			linkedList.ReverseEvenList(HNode)
			fmt.Printf("调换成功!\n")
			linkedList.TraverseList(HNode)

		//查找中间节点
		case "10":
			if HNode.Next == nil {
				fmt.Printf("该链表为空，无中间节点!\n")
				break
			}
			linkedList.Mark = linkedList.FindMidNode(HNode)
			fmt.Printf("该列表中间节点为:%d\n", linkedList.Mark.Data)


		}
	}
	return
}
