create database Test
on primary
(  name='Test_Data',
   filename='F:\experiment\���ݿ�ԭ���ϻ���\Test_Data.mdf',
   size=10MB,
   Maxsize=50mb,
filegrowth=5mb
)
log on 
(name='Test_Log',
 filename='F:\experiment\���ݿ�ԭ���ϻ���\Test_Log.ldf',
size=5mb,
Maxsize=25mb,
filegrowth=5mb
)
go