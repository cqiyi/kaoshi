create database Test
on primary
(  name='Test_Data',
   filename='F:\experiment\数据库原理上机题\Test_Data.mdf',
   size=10MB,
   Maxsize=50mb,
filegrowth=5mb
)
log on 
(name='Test_Log',
 filename='F:\experiment\数据库原理上机题\Test_Log.ldf',
size=5mb,
Maxsize=25mb,
filegrowth=5mb
)
go