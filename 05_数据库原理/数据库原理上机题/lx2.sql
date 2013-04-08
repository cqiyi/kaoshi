select au_fname,au_lname,phone
from authors

select au_fname+','+au_lname as 'name','phone:'+phone
as 'phone number'
from authors
where state in ('CA','OR')
order by 'name' asc

select title
from titles
where price between 15.00 and 20.00

