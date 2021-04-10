package main

import (
	"fmt"
	"go_code/Go链式队列/LQueue"
	"strconv"
)

func main(){
	var choice string
	var judge bool

	//创建一个队列并初始化
	Q := new(LQueue.LQueue)
	LQueue.InitLQueue(Q)

	for choice != "0" {

		//打印主界面并选择功能
		LQueue.PrintMenu()
		LQueue.FuncChoice(&choice)

		switch choice {

		//退出系统
		case "0":
			fmt.Printf("退出系统!\n")

		//入队
		case "1":
			fmt.Printf("请输入你想要入队的数据类型:\n")
			fmt.Printf("a.int64\tb.float64\tc.string[100]\n")
			var Type string
			LQueue.IsType(&Type)

			if Type == "a" {
				fmt.Printf("请输入要存放的数据：\n")
				var e string
				LQueue.IsNumInt(&e)
				ne,_ := strconv.ParseInt(e,10,64)
				LQueue.EnLQueue(Q,&ne,Type)
				fmt.Printf("入队成功!\n")
				break
			}
			if Type == "b" {
				fmt.Printf("请输入要存放的数据：\n")
				var e string
				LQueue.IsNumFloat64(&e)
				ne,_ := strconv.ParseFloat(e,64)
				LQueue.EnLQueue(Q,&ne,Type)
				fmt.Printf("入队成功!\n")
				break
			}
			if Type == "c" {
				fmt.Printf("请输入要存放的数据：\n")
				var e string
				LQueue.IsNumString(&e)
				LQueue.EnLQueue(Q,&e,Type)
				fmt.Printf("入队成功!\n")
				break
			}

		//出队
		case "2":
			judge = LQueue.DeLQueue(Q)
			if judge == false {
				fmt.Printf("该队列为空，暂无数据!\n")
				break
			}
			if judge == true {
				fmt.Printf("出队成功!\n")
				break
			}

		//检测队列是否为空
		case "3":
			judge = LQueue.IsEmptyLQueue(Q)
			if judge == true {
				fmt.Printf("该队列为空!\n")
				break
			}
			if judge == false {
				fmt.Printf("该队列不为空!\n")
				break
			}

		//查看队头元素
		case "4":
			if Q.Front == Q.Rear {
				fmt.Printf("该队列为空，暂无队头元素!\n")
				break
			}
			var e interface{}
			var a *int64
			var b *float64
			var c *string
			LQueue.GetHeadLQueue(Q,e)
			fmt.Println("该队头元素为:")
			if Q.Front.Next.Type == "a" {
				a,_ = Q.Front.Next.Data.(*int64)
				fmt.Println(*a)
				break
			}
			if Q.Front.Next.Type == "b" {
				b,_ = Q.Front.Next.Data.(*float64)
				fmt.Println(*b)
				break
			}
			if Q.Front.Next.Type == "c" {
				c,_ = Q.Front.Next.Data.(*string)
				fmt.Println(*c)
				break
			}

		//清空队列
		case "5":
			if Q.Front == Q.Rear {
				fmt.Printf("该队列原本就为空!\n")
				break
			}
			LQueue.ClearLQueue(Q)
			fmt.Printf("清空成功!\n")

		//销毁队列
		case "6":
			LQueue.DestroyLQueue(Q)
			fmt.Printf("销毁并成功退出程序!\n")
			choice = "0"

		//判断队列长度
		case "7":
			length := LQueue.LengthLQueue(Q)
			fmt.Println("该队列长度为:",length)

		//遍历队列
		case "8":
			LQueue.TraverseLQueue(Q)




		}





	}









}

