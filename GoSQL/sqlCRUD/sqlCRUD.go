package sqlCRUD

import (
	"database/sql"
	_ "go-sql-driver/mysql"
)

var db *sql.DB

type User struct {
	Id       int
	Name     string
	Birthday string
}

//连接数据库
func InitDB (dsn string) (err error) {
	db,err = sql.Open("mysql",dsn)
	if err != nil {
		return
	}
	err = db.Ping()
	if err != nil {
		return
	}
	//设置连接池最大连接数目
	db.SetMaxOpenConns(10)
	//设置连接池最大闲置链接数
	db.SetMaxIdleConns(5)
	return
}

//查询单条记录
func QueryOne (query string) (error,*User) {
	var u User
	sqlStr := "select * from user where " + query + ";"
	rowObj := db.QueryRow(sqlStr)
	err := rowObj.Scan(&u.Id,&u.Name,&u.Birthday)
	if err != nil {
		return err,nil
	}
	return err,&u
}

//查询多条记录
func QueryMore (query string) (error,[]*User){
	sqlStr := "select * from user where " + query + ";"
	rows,err := db.Query(sqlStr)
	if err != nil {
		return err,nil
	}
	defer rows.Close()
	var users []*User
	for  rows.Next(){
		var u User
		err = rows.Scan(&u.Id,&u.Name,&u.Birthday)
		if err != nil {
			return err,nil
		}
		user := &User{
			Id:u.Id,
			Name: u.Name,
			Birthday: u.Birthday,
		}
		users = append(users,user)
	}
	return err,users
}

//插入数据
func Insert(user *User)error{
	sqlStr := "insert user (name,birthday) values (?,?) ;"
	_,err := db.Exec(sqlStr,user.Name,user.Birthday)
	return err
}

//删除数据
func DeleteRow(delete string)error{
	sqlStr := "delete from user where " + delete + ";"
	_,err := db.Exec(sqlStr)
	return err
}

//修改数据
func UpdateRow(new string,old string)error{
	sqlStr := "update user set " + new + " where " + old + ";"
	_,err := db.Exec(sqlStr)
	return err
}