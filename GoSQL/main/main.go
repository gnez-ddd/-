package main

import (
	"fmt"
	"go_code/GoSQL/sqlCRUD"
)

func main(){
	//连接数据库
	err :=sqlCRUD.InitDB("root:Dadan1223@tcp(127.20.10.2:3306)/dd")
	if err != nil {
		fmt.Printf("连接数据库失败，错误为:%v\n",err)
	}
	fmt.Println("连接数据库成功!")

	//插入数据
	user1 := sqlCRUD.User{
		Name: "dd",
		Birthday: "2021-4-13",
	}
	err = sqlCRUD.Insert(&user1)
	if err != nil {
		fmt.Printf("操作失败，错误为：%v\n", err)
	}else {
		fmt.Println("操作成功!")
	}

	user2 := sqlCRUD.User{
		Name: "dd",
		Birthday: "2021-4-13",
	}
	err = sqlCRUD.Insert(&user2)
	if err != nil {
		fmt.Printf("操作失败，错误为：%v\n", err)
	}else {
		fmt.Println("操作成功!")
	}

	//修改数据
	err = sqlCRUD.UpdateRow("birthday='2001-12-23'","id=4")
	if err != nil {
		fmt.Printf("操作失败，错误为：%v\n", err)
	}else {
		fmt.Println("操作成功!")
	}

	//查询单条记录
	var user *sqlCRUD.User
	err,user = sqlCRUD.QueryOne("id=3")
	if err != nil {
		fmt.Printf("操作失败，错误为：%v\n", err)
	} else {
		fmt.Println("id:",user.Id,"name:",user.Name,"birthday:",user.Birthday)
	}

	//查询多条记录
	var users []*sqlCRUD.User
	err,users = sqlCRUD.QueryMore("id>0")
	if err != nil {
		fmt.Printf("操作失败，错误为:%v\n",err)
	}else {
		for _,v := range users {
			fmt.Println("id:",v.Id,"name:",v.Name,"birthday:",v.Birthday)
		}
	}

	//删除记录
	err = sqlCRUD.DeleteRow("id>0")
	if err != nil {
		fmt.Printf("操作失败，错误为：%v\n", err)
	}else {
		fmt.Println("操作成功!")
	}
}
