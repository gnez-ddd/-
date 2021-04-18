package main

import (
	"fmt"
	"go_code/排序/sort"
	"math/rand"
	"strconv"
	"time"
)

func main(){
	var choice string
	start := time.Now()
	cost := time.Since(start)

	for choice != "0" {
		//打印主界面并选择功能
		sort.MenuPrintf()
		sort.FuncChoice(&choice)

		switch choice {

			//退出系统
			case "0":
				fmt.Println("退出系统！")

			//大数据量下用时
			case "1":
				//i := 0
				fmt.Println("请输入数据量：")
				var n string
				sort.IsNum(&n)
				nn,_ := strconv.ParseInt(n,10,64)
				for nn <= 0 {
					fmt.Println("输入有误,请重新输入！")
					sort.IsNum(&n)
					nn,_ = strconv.ParseInt(n,10,64)
				}
				size := int(nn)
				A := make([]int,size)
				sort.GetRandomNum(A,size)
				a := make([]int,size)
				Temp := make([]int,size)

				//测试插入排序算法
				copy(a,A)
				start = time.Now()
				sort.InsertSort(a,size)
				cost = time.Since(start)
				fmt.Printf("插入排序算法运行时间为：%s\n",cost)

				//测试归并排序
				copy(a,A)
				start = time.Now()
				sort.MergeSort(a,0,size - 1,Temp)
				cost = time.Since(start)
				fmt.Printf("归并排序算法运行时间为：%s\n",cost)

				//测试快速递归排序算法
				copy(a,A)
				start = time.Now()
				sort.QuickSortRecursion(a,0,size - 1)
				cost = time.Since(start)
				fmt.Printf("快速排序递归法算法运行时间为：%s\n",cost)

				//测试快速排序非递归版
				copy(a,A)
				start = time.Now()
				sort.QuickSort(a,size)
				cost = time.Since(start)
				fmt.Printf("快速排序非递归法排序算法运行时间为：%s\n",cost)

				//测试计数排序
				copy(a,A)
				max := 0
				min := 0
				sort.MaxAndMin(a,&max,&min,size)
				start = time.Now()
				sort.CountSort(a,size,max,min)
				cost = time.Since(start)
				fmt.Printf("计数排序算法运行时间为：%s\n",cost)

				//测试基数排序
				copy(a,A)
				start = time.Now()
				sort.RadixCountSort(a,size)
				cost = time.Since(start)
				fmt.Printf("插入排序算法运行时间为：%s\n",cost)

			//大量小数组下用时
			case "2":
				A := make([]int,100)
				sort.GetRandomNum(A,100)
				a := make([]int,100)
				Temp := make([]int,100)
				i := 0

				//测试插入排序算法
				start = time.Now()
				for i = 0;i <= 100000;i++ {
					copy(a,A)
					sort.InsertSort(a,100)
				}
				cost = time.Since(start)
				fmt.Printf("插入排序算法运行时间为：%s\n",cost)

				//测试归并排序算法
				temp := make([]int,100)
				start = time.Now()
				for i = 0;i <= 100000;i++ {
					copy(a,A)
					sort.MergeSort(a,0,99,Temp)
					copy(Temp,temp)
				}
				cost = time.Since(start)
				fmt.Printf("归并排序算法运行时间为：%s\n",cost)

				//测试快排递归排序算法
				start = time.Now()
				for i = 0;i <= 100000;i++ {
					copy(a,A)
					sort.QuickSortRecursion(a,0,99)
				}
				cost = time.Since(start)
				fmt.Printf("快速排序递归算法运行时间为：%s\n",cost)

				//测试快速排序非递归排序算法
				start = time.Now()
				for i = 0;i <= 100000;i++ {
					copy(a,A)
					sort.QuickSort(a,100)
				}
				cost = time.Since(start)
				fmt.Printf("快速排序非递归算法运行时间为：%s\n",cost)

				//测试计数排序
				start = time.Now()
				max := 0
				min := 0
				sort.MaxAndMin(a,&max,&min,100)
				for i = 0;i <= 100000;i++ {
					copy(a,A)
					sort.CountSort(a,100,max,min)
				}
				cost = time.Since(start)
				fmt.Printf("计数排序算法运行时间为：%s\n",cost)

				//测试基数排序
				start = time.Now()
				for i = 0;i <= 100000;i++ {
					copy(a,A)
					sort.RadixCountSort(a,100)
				}
				cost = time.Since(start)
				fmt.Printf("基数排序算法运行时间为：%s\n",cost)

			//颜色排序
			case "3":
				i := 0
				fmt.Println("请输入数据量：")
				var n string
				sort.IsNum(&n)
				nn,_ := strconv.ParseInt(n,10,64)
				for nn <= 0 {
					fmt.Println("输入有误,请重新输入！")
					sort.IsNum(&n)
					nn,_ = strconv.ParseInt(n,10,64)
				}
				size := int(nn)
				a := make([]int,size)
				rand.Seed(time.Now().Unix())
				for i = 0;i < size;i++ {
					a[i] = rand.Intn(3) + 0
				}
				fmt.Println("排序前：")
				for _,v := range a {
					fmt.Printf("%v  ",v)
				}
				fmt.Println()
				sort.ColorSort(a,size)
				fmt.Println("排序后：")
				for _,v := range a {
					fmt.Printf("%v  ",v)
				}
				fmt.Println()

			//寻找第k大的数
			case "4":
				fmt.Println("请输入数据量：")
				var n string
				sort.IsNum(&n)
				nn,_ := strconv.ParseInt(n,10,64)
				for nn <= 0 {
					fmt.Println("输入有误,请重新输入！")
					sort.IsNum(&n)
					nn,_ = strconv.ParseInt(n,10,64)
				}
				size := int(nn)
				a := make([]int,size)
				sort.GetRandomNum(a,size)
				fmt.Println("该数据为：")
				for _,v := range a {
					fmt.Printf("%v  ",v)
				}
				fmt.Println()
				fmt.Println("请输入要寻找的第几大数据：")
				var m string
				sort.IsNum(&m)
				mm,_ := strconv.ParseInt(m,10,64)
				k := int(mm)
				for k <= 0 || k > size {
					fmt.Println("输入有误,请重新输入！")
					sort.IsNum(&n)
					nn,_ = strconv.ParseInt(n,10,64)
					k = int(nn)
				}
				num := sort.GetNum(a,size,k)
				fmt.Printf("该数据为:%v\n",num)

			//生成数据并保存到文件中
			case "5":
				var path string
				fmt.Printf("请输入文件路径\n")
				_, _ = fmt.Scanln(&path)
				fmt.Println("请输入数据量：")
				var n string
				sort.IsNum(&n)
				nn,_ := strconv.ParseInt(n,10,64)
				for nn <= 0 {
					fmt.Println("输入有误,请重新输入！")
					sort.IsNum(&n)
					nn,_ = strconv.ParseInt(n,10,64)
				}
				size := int(nn)
				a := make([]int,size)
				sort.GetRandomNum(a,size)
				fmt.Println("该数据为：")
				for _,v := range a {
					fmt.Printf("%v  ",v)
				}
				fmt.Println()
				judge := sort.StoreNumFile(a,path,size)
				if judge == false {
					fmt.Println("存储数据失败！")
				} else {
					fmt.Println("存储数据成功！")
				}

			//读取数据并排序
			case "6":
				var path string
				fmt.Printf("请输入文件路径\n")
				_, _ = fmt.Scanln(&path)
				var str string
				judge,size,ret := sort.ReadNumFile(path,&str)
				if judge == false {
					fmt.Println("读取数据失败!")
					break
				} else {
					fmt.Println("该文件中数据为：")
					for i := 0;i < size ;i++ {
						fmt.Printf("%v  ",ret[i])
					}
					fmt.Println()

					A := make([]int,size)
					copy(A,ret)
					a := make([]int,size)
					Temp := make([]int,size)

					//测试插入排序算法
					copy(a,A)
					start = time.Now()
					sort.InsertSort(a,size)
					cost = time.Since(start)
					fmt.Println("排序后为：")
					for i := 0;i < size ;i++ {
						fmt.Printf("%v  ",a[i])
					}
					fmt.Println()
					fmt.Printf("插入排序算法运行时间为：%s\n",cost)

					//测试归并排序
					copy(a,A)
					start = time.Now()
					sort.MergeSort(a,0,size - 1,Temp)
					cost = time.Since(start)
					fmt.Println("排序后为：")
					for i := 0;i < size ;i++ {
						fmt.Printf("%v  ",a[i])
					}
					fmt.Println()
					fmt.Printf("归并序算法运行时间为：%s\n",cost)

					//快速排序递归
					copy(a,A)
					start = time.Now()
					sort.QuickSortRecursion(a,0,size - 1)
					cost = time.Since(start)
					fmt.Println("排序后为：")
					for i := 0;i < size ;i++ {
						fmt.Printf("%v  ",a[i])
					}
					fmt.Println()
					fmt.Printf("快速排序递归算法运行时间为：%s\n",cost)

					//快速排序非递归
					copy(a,A)
					start = time.Now()
					sort.QuickSort(a,size)
					cost = time.Since(start)
					fmt.Println("排序后为：")
					for i := 0;i < size ;i++ {
						fmt.Printf("%v  ",a[i])
					}
					fmt.Println()
					fmt.Printf("快速排序非递归算法运行时间为：%s\n",cost)

					//计数排序
					copy(a,A)
					max := 0
					min := 0
					sort.MaxAndMin(a,&max,&min,size)
					start = time.Now()
					sort.CountSort(a,size,max,min)
					cost = time.Since(start)
					fmt.Println("排序后为：")
					for i := 0;i < size ;i++ {
						fmt.Printf("%v  ",a[i])
					}
					fmt.Println()
					fmt.Printf("计数排序算法运行时间为：%s\n",cost)

					//基数排序
					copy(a,A)
					start = time.Now()
					sort.RadixCountSort(a,size)
					cost = time.Since(start)
					fmt.Println("排序后为：")
					for i := 0;i < size ;i++ {
						fmt.Printf("%v  ",a[i])
					}
					fmt.Println()
					fmt.Printf("插入排序算法运行时间为：%s\n",cost)

				}
		}
	}
}
