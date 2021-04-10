package main
import (
	"fmt"
	"go_code/GoDuLinkedList/DuLinkedList"
	"strconv"
)

func main(){
	var choice string
	var judge bool

	//生成头节点并初始化
	HNode := new(DuLinkedList.LNode)
	DuLinkedList.InitList(HNode)

	for choice != "0" {

		//打印主界面并选择功能
		DuLinkedList.PrintMenu()
		DuLinkedList.FuncChoice(&choice)

		switch choice {

		//退出系统
		case "0" :
			fmt.Printf("退出系统\n")

		//在节点p之后插入节点q pq
		case "1" :
			fmt.Printf("请输入要插入的位置的前一个节点存放的数据:")
			var f string
			DuLinkedList.IsNum(&f)
			nf,_ := strconv.ParseInt(f,10,64)

			fmt.Printf("请输入要存放的数据:")
			//e := DuLinkedList.DataJudge()
			var e string
			DuLinkedList.IsNum(&e)
			ne,_ := strconv.ParseInt(e,10,64)

			//定义新结点
			newNode := new(DuLinkedList.LNode)
			newNode.Data = ne
			newNode.Next = newNode
			newNode.Prior = newNode

			//查询该位置的节点
			judge = DuLinkedList.SearchList(HNode, nf)
			//查询不到该结点，则默认插入到头结点后的第一个位置
			if judge == false{
				fmt.Printf("查询不到该结点，默认插入到头结点后的第一个位置\n")
				DuLinkedList.InterstatesDul(HNode, newNode)
			}
			//查询到该结点
			if judge == true{
				DuLinkedList.InterstatesDul(DuLinkedList.Mark, newNode)
			}
			fmt.Printf("插入成功!\n")
			DuLinkedList.TraverseList(HNode)

		//在节点p之前插入节点q qp
		case "2" :
			fmt.Printf("请输入要插入的位置的后一个节点存放的数据:")
			var f string
			DuLinkedList.IsNum(&f)
			nf,_ := strconv.ParseInt(f,10,64)

			fmt.Printf("请输入要存放的数据:")
			//e := DuLinkedList.DataJudge()
			var e string
			DuLinkedList.IsNum(&e)
			ne,_ := strconv.ParseInt(e,10,64)

			//定义新结点
			newNode := new(DuLinkedList.LNode)
			newNode.Data = ne
			newNode.Next = newNode
			newNode.Prior = newNode

			//查询该位置的节点
			judge = DuLinkedList.SearchList(HNode, nf)
			//查询不到该结点，则默认插入到头结点后的第一个位置
			if judge == false{
				fmt.Printf("查询不到该结点，默认插入到头结点后的第一个位置\n")
				DuLinkedList.InterstatesDul(HNode, newNode)
			}
			//查询到该结点
			if judge == true{
				DuLinkedList.InsectivoresDul(DuLinkedList.Mark, newNode)
			}
			fmt.Printf("插入成功!\n")
			DuLinkedList.TraverseList(HNode)


		//遍历链表
		case "3" :
			DuLinkedList.TraverseList(HNode)

		//删除节点
		case "4" :
			if HNode.Next == HNode {
				fmt.Printf("该链表为空，删除失败!\n")
				break
			}
			DuLinkedList.TraverseList(HNode)
			
			//输入要删除的节点的上一个节点数据
			fmt.Printf("请输入要删除的节点的上一个节点数据：\n")

			var f string
			DuLinkedList.IsNum(&f)
			nf,_ := strconv.ParseInt(f,10,64)

			//寻找要删除的节点的上一个节点
			judge = DuLinkedList.SearchList(HNode, nf)
			//找不到
			if judge == false{
				fmt.Printf("查询不到改结点!删除失败!\n")
				break
			}
			//找到
			if judge == true{
				var e int64
				//如果该节点为最后一个结点
				if DuLinkedList.Mark.Next == HNode {
					fmt.Printf("被删除的节点是上一个节点为最后一个节点，删除失败!\n")
					break
				}
				DuLinkedList.DeleteList(DuLinkedList.Mark, &e)
				fmt.Printf("该数据为%d\n",e)
				fmt.Printf("删除成功!\n")
				DuLinkedList.TraverseList(HNode)
			}

		//查找节点
		case "5":
			//输入要查找的节点数据
			fmt.Printf("请输入要查找的节点数据：\n")
			//f := DuLinkedList.DataJudge()
			var f string
			DuLinkedList.IsNum(&f)
			nf,_ := strconv.ParseInt(f,10,64)


			//寻找节点
			judge = DuLinkedList.SearchList(HNode, nf)

			if judge == false{
				fmt.Printf("查询不到!\n")
			}

			if judge == true{
				fmt.Printf("查询到该节点!\n")
			}

		//销毁链表
		case "6":
			if HNode.Next == HNode {
				fmt.Printf("该链表为空!\n")
				break
			}
			DuLinkedList.DestroyList(HNode)
			fmt.Printf("销毁链表成功!\n")

		//判断是否为环
		case "7":
			judge = DuLinkedList.IsLoopList(HNode)
			if judge == false {
				fmt.Printf("该链表不为环!\n")
			}
			if judge == true {
				fmt.Printf("该链表为环!\n")
			}

		//反转链表 非递归
		case "8":
			if HNode.Next == HNode || HNode.Next.Next == HNode {
				fmt.Printf("该链表为空或只有一个节点，无法反转!\n")
				break
			}
			DuLinkedList.ReverseList01(HNode)
			fmt.Printf("反转成功!\n")
			DuLinkedList.TraverseList(HNode)

		//反转链表 递归
		case "9":
			if HNode.Next == HNode || HNode.Next.Next == HNode {
				fmt.Printf("该链表为空或只有一个节点，无法反转!\n")
				break
			}
			DuLinkedList.ReverseList02(HNode)
			fmt.Printf("反转成功!\n")
			DuLinkedList.TraverseList(HNode)



		}
	}
	return
}
