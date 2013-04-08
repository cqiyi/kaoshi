create procedure usp_get_author_phone0 a
@last_name varchar(32)
as
select au_lname+','+au_fname as 'name',phone as 'phone'
from authors
where au_lname like @last_name+'%'
order by 'name' asc

create procedure usp_insert_new_author
@au_id varchar(11),
@au_lname varchar(40),
@au_fname varchar(20),
@phone char(12)='unknown',
@address varchar(40)=null,
@city varchar(20)=null,
@state char(2)=null,
@zip char(5)=null,
@contract bit=0
as
insert into authors
values (
        @au_id,@au_lname,@au_fname,@phone,@address,@city,
@state,@zip,@contract

)


usp_insert_new_author '141-11-1111','aa',bb,22,ffffffffff,bj,yz,'100094'

execute sp_helptext usp_insert_new_author,usp_get_author_phone0 a

