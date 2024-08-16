select * from actor limit 100;
select * from film_actor limit 100;
select * from film limit 100;
select * from language limit 100;
select * from film_category limit 100;
select * from category limit 100;
select * from film_text limit 100;

select f.*,l.name as languge_name
from film as f
left join
language as l
on f.language_id=l.language_id;

select fa.*, a.first_name,a.last_name, f.title  from 
film_actor as fa,
actor as a,
film as f
where fa.actor_id = a.actor_id
and fa.film_id=f.film_id;

select f.*, c.name as category_name 
from film as f left join film_category as fc on f.film_id=fc.film_id
left join category as c on fc.category_id=c.category_id;


select * from film where rating in ('G','PG-13','PG')
UNION
select * from film where rental_rate > 2;


