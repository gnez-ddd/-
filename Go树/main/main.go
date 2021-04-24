package main

import (
	"fmt"
	"go_code/Go树/binary_sort_tree"
	"strconv"
)

func main(){

	var choice string
	var judge bool

	//建一棵树并初始化
	T := new(binary_sort_tree.BinarySortTree)
	binary_sort_tree.InitBST(T)


	for choice != "0" {

		//打印主界面并选择功能
		binary_sort_tree.PrintMenu()
		binary_sort_tree.FuncChoice(&choice)

		switch choice {

		//退出系统
		case "0":
			fmt.Println("成功退出系统！")

		//插入数据
		case "1":
			fmt.Println("请输入要插入的数据：")
			var data string
			binary_sort_tree.IsNum(&data)
			ndata,_ := strconv.ParseInt(data,10,64)
			judge = binary_sort_tree.InsertBST(T,int(ndata))
			if judge == true {
				fmt.Println("插入成功！")
			} else {
				fmt.Println("插入失败！")
			}

		//删除数据
		case "2":
			fmt.Println("请输入要删除的数据：")
			var data string
			binary_sort_tree.IsNum(&data)
			ndata,_ := strconv.ParseInt(data,10,64)
			judge = binary_sort_tree.DeleteBST(T,int(ndata))
			if judge == true {
				fmt.Println("删除成功！")
			} else {
				fmt.Println("删除失败！")
			}

		//寻找数据
		case "3":
			fmt.Println("请输入要寻找的数据：")
			var data string
			binary_sort_tree.IsNum(&data)
			ndata,_ := strconv.ParseInt(data,10,64)
			judge = binary_sort_tree.SearchBST(T,int(ndata))
			if judge == true {
				fmt.Println("查询到该数据！")
			} else {
				fmt.Println("查询不到该数据！")
			}

		//非递归前序遍历
		case "4":
			if T == nil || T.Root == nil {
				fmt.Println("该树暂无数据！")
				break
			}
			binary_sort_tree.PreorderIBST(T.Root)
			fmt.Println("")

		//递归前序遍历
		case "5":
			if T == nil ||T.Root == nil{
				fmt.Println("该树暂无数据！")
				break
			}
			binary_sort_tree.PreorderRBST(T.Root)
			fmt.Println("")

		//非递归中序遍历
		case "6":
			if T == nil || T.Root == nil {
				fmt.Println("该树暂无数据！")
				break
			}
			binary_sort_tree.InorderIBST(T.Root)
			fmt.Println("")

		//递归中序遍历
		case "7":
			if T == nil || T.Root == nil {
				fmt.Println("该树暂无数据！")
				break
			}
			binary_sort_tree.InorderRBST(T.Root)
			fmt.Println("")

		//非递归后序遍历
		case "8":
			if T == nil || T.Root == nil {
				fmt.Println("该树暂无数据！")
				break
			}
			binary_sort_tree.PostorderIBST(T.Root)
			fmt.Println("")

		//递归后序遍历
		case "9":
			if T == nil || T.Root == nil {
				fmt.Println("该树暂无数据！")
				break
			}
			binary_sort_tree.PostorderRBST(T.Root)
			fmt.Println("")

		//层次遍历
		case "10":
			if T == nil || T.Root == nil {
				fmt.Println("该树暂无数据！")
				break
			}
			binary_sort_tree.LevelOrderBST(T.Root)
			fmt.Println("")
		}
	}
}
