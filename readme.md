# 类（结构体）
* Database 数据库
* Table 表
* Column 列
* Row  行
* Where 语句结构体


# 需要实现的SQL语句与对应接口

1. SQL: 插入
	`insert into tablename(column1,column2) values (value1,value2)`
    * function: 
	```sql
	bool insert(String tablename, String databasename, array[])
	//array[] 为关联数组 例：array[column1]=value1
	```

2. SQL: 删除
	`delete from tablename where column=value`
    * function:
    ```sql
	bool delete(String tablename, String databasename, Where 结构体)
	```

3. SQl: 选择
	`select column1 from tablename where column2=value`
    * function:
    ```sql
	Table select(String tablename, String databasename, String[], Where 结构体) 
	//Sring[] 数组用来储存 select 语句的参数
    ```
4. SQL: 更新
	`update tablename set column1=value1, column2=value2 where column3=value3`
    * function:
	```sql
    bool update(String tablename, String databasename, array[], Where 结构体)
	//array[] 为关联数组 例：array[column1]=value1
	```
	
5. SQL: 创建表
    ```sql
	create table tablename
	(
		colume1 type,
		column2 type,
		primary key(column1)
	)
	```
	
    * function:
    ```sql
	bool createTable(Table 结构体)
	```
	
6. SQL: 删除表
	`drop table tablename`
    * function:
    ```sql
	bool dropTable(String tablename, String databasename)
	```
	
7. SQL: 创建数据库
	`create database databasename`
    * function
    ```sql
	bool createDatabase(Database 结构体)
	```
	
8. SQL: 删除数据库
	`drop database databasename`
    * function:
    ```sql
	bool dropDatabase(String databasename)
	```
