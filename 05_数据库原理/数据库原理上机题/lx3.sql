select distinct(type)
from titles
select power(9,9)

select avg(price)
from titles

select sum(price)
from titles

select type as 'book category',avg(price)
as 'average price'
from titles
group by type

select type as 'book category',pub_id
as 'publisher id',avg(price)
as 'average price'
from titles
group by type ,pub_id
having avg(price)>12.00


select authors.au_lname +','+ authors.au_fname as 'name',
       authors.state
from authors

where authors.state in
(select distinct(state)
from publishers
)

select au_fname,au_lname
into author_names
from authors
go
select *
from empty_authors
go

select *
from authors


select * from sales_data_1996
union
select * from sales_data_1997

sp_help authors

insert authors values ('511-12-7654','chester','brooke',
default,'5691 north south st.','ford',
'wa','56571',0
)
insert authors (au_id,au_lname,au_fname,contract) values ('555-55-5555','angel','becky',1
)

select *
from authors
where au_id = '123-45-6789'

insert authors default values

create table phone_list
(author_name varchar(32),
 phone_number varchar(18)
)
go
insert phone_list
select au_lname +','+au_fname as 'author name',phone as 
'phone'
from authors
order by 'author name'
go
select *from phone_list
go

select *
from titles
where au_id='123-45-6789'
go
update authors
set phone ='185-625-1212'
where au_id='123-45-6789'
go
select *
from phone_list
where au_id='123-45-6789'
go

update titles
set price=price*0.10

delete phone_list