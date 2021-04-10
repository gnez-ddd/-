package main

import (
	"fmt"
	"go_code/Go顺序循环队列/AQueue"
	"strconv"
)

func main(){
	var choice string
	var judge bool

	//创建一个队列并初始化
	Q := new(AQueue.AQueue)
	AQueue.InitAQueue(Q)

	for choice != "0" {

		//打印主界面并选择功能
		AQueue.PrintMenu()
		AQueue.FuncChoice(&choice)

		switch choice {

		//退出系统
		case "0":
			fmt.Printf("退出系统\n")

		//入队
		case "1":
			if (Q.Rear + 1) % 10 == Q.Front {
				fmt.Printf("该队列已满，无法再添加数据!\n")
				break
			}
			fmt.Printf("请输入你想要入队的数据类型:\n")
			fmt.Printf("a.int64\tb.float64\tc.string[100]\n")
			var Type string
			AQueue.IsType(&Type)

			if Type == "a" {
				AQueue.DataType[Q.Length] = "a"
				fmt.Printf("请输入要存放的数据：\n")
				var e string
				AQueue.IsNumInt(&e)
				ne,_ := strconv.ParseInt(e,10,64)
				AQueue.EnAQueue(Q,&ne)
				fmt.Printf("入队成功!\n")
				break
			}
			if Type == "b" {
				AQueue.DataType[Q.Length] = "b"
				fmt.Printf("请输入要存放的数据：\n")
				var e string
				AQueue.IsNumFloat64(&e)
				ne,_ := strconv.ParseFloat(e,64)
				AQueue.EnAQueue(Q,&ne)
				fmt.Printf("入队成功!\n")
				break
			}
			if Type == "c" {
				AQueue.DataType[Q.Length] = "c"
				fmt.Printf("请输入要存放的数据:\n")
				var e string
				AQueue.IsNumString(&e)
				AQueue.EnAQueue(Q,&e)
				fmt.Printf("入队成功!\n")
				break
			}

		//出队
		case "2":
			judge = AQueue.DeAQueue(Q)
			if judge == false {
				fmt.Printf("该队列为空，暂无数据!\n")
				break
			}
			if judge == true {
				fmt.Printf("出队成功!\n")
				break
			}

		//判断队列是否为空
		case "3":
			judge = AQueue.IsEmptyAQueue(Q)
			if judge == true {
				fmt.Printf("该队列为空!\n")
				break
			}
			if judge == false {
				fmt.Printf("该队列不为空!\n")
				break
			}

		//检查队列是否满了
		case "4":
			judge = AQueue.IsFullAQueue(Q)
			if judge == true {
				fmt.Printf("该队列满了!\n")
				break
			}
			if judge == false {
				fmt.Printf("该队列不满!\n")
				break
			}

		//查看队头元素
		case "5":
			if Q.Front == Q.Rear {
				fmt.Printf("该队列为空，暂无队头元素!\n")
				break
			}
			var e interface{}
			var a *int64
			var b *float64
			var c *string
			AQueue.GetHeadAQueue(Q,e)
			fmt.Println("该队头元素为:")
			if AQueue.DataType[Q.Front] == "a" {
				a,_ = Q.Data[Q.Front].(*int64)
				fmt.Println(*a)
				break
			}
			if AQueue.DataType[Q.Front] == "b" {
				b,_ = Q.Data[Q.Front].(*float64)
				fmt.Println(*b)
				break
			}
			if AQueue.DataType[Q.Front] == "c" {
				c,_ = Q.Data[Q.Front].(*string)
				fmt.Println(*c)
				break
			}

		//清空队列
		case "6" :
			if Q.Front == Q.Rear {
				fmt.Printf("该队列原本就为空!\n")
				break
			}
			AQueue.ClearAQueue(Q)
			fmt.Printf("清空成功!\n")

		//销毁队列
		case "7":
			AQueue.DestroyAQueue(Q)
			fmt.Printf("销毁并成功退出程序!\n")
			choice = "0"

		//判断队列长度
		case "8":
			length := 0
			length = AQueue.LengthAQueue(Q)
			fmt.Println("该队列长度为:",length)

		//遍历队列
		case "9":
			AQueue.TraverseAQueue(Q)




		}





	}



}

