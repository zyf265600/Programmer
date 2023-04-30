select * from film limit 100;
select * from store;
select * from inventory limit 100;
select count(*) from rental;
select * from rental limit 100;
select * from category limit 100;
select * from payment limit 100;
select * from film_category limit 100;
select * from film;
/*
-- one with bug:
select distinct rental_date from rental 
where rental_date between '2005-05-01' and '2005-08-31';
-- better solutions:
select distinct rental_date from rental where substring(rental_date,1,7) between '2005-05' and '2005-08';
select distinct rental_date from rental 
where rental_date between '2005-05-01 00:00:00' and '2005-08-31 23:59:59';
*/

-- select count(*), count(distinct rental_date), count(rental_date) from rental;
-- 3.1
select count(rental_id) as volume from rental
where rental_date between '2005-05-01' and '2005-08-31';

-- 3.2
select 
substring(rental_date, 1,7) as rental_month, 
count(rental_Id) as volume from rental
where rental_date between '2005-05-01' and '2005-08-31' 
group by 1;

-- 3.3
select s.first_name, 
s.last_name, 
count(r.rental_Id) as volume from 
rental as r
left join
staff as s
on r.staff_id=s.staff_id
group by 1,2
order by volume desc;

-- 3.4
select film_id, store_id, count(inventory_id) from inventory
group by 1,2;

-- 3.5
select f.title as film_name, i.film_id, i.store_id, count(*)
from
inventory as i
left join
film as f on i.film_id=f.film_id
group by 1,2,3;


-- 3.6
-- In question 3.5 I used inventory as a base table actually can not identify the film which is out of stock
-- so you should use film as a base table, so out of stock film will have 0 count
select f.title as film_name, 
f.film_id,  -- be careful about which film_id you are using. if you select film_id from inventory table, you will get NULL value
c.name as category, 
i.store_id, 
count(i.film_id) as num_of_stock -- be careful which column you want to count to get the inventory number. if you count(*), NULL will be counted as 1
from
film as f 
left join inventory as i
on i.film_id=f.film_id
left join
film_category as fc on f.film_id=fc.film_id
left join
category as c on fc.category_id=c.category_id
group by 1,2,3,4;


-- 3.7
-- drop table inventory_rep;
create table inventory_rep as
select f.title as film_name, 
f.film_id, 
c.name as category, 
i.store_id, 
count(i.film_id) as num_of_stock 
from
film as f 
left join inventory as i
on i.film_id=f.film_id
left join
film_category as fc on f.film_id=fc.film_id
left join
category as c on fc.category_id=c.category_id
group by 1,2,3,4;


-- 3.8

select * from film where film_id in
(
select film_id from inventory_rep 
where num_of_stock = 0);


-- 3.9
select substring(payment_date, 1,7) 
as payment_month, 
sum(amount) as revenue from payment
where payment_date between '2005-05-01' and '2005-08-31' 
group by 1;

-- describe table
describe payment;

-- 3.10
select store_id, sum(amount) as revenue from 
payment p
join
staff s
on p.staff_id=s.staff_id
where payment_date 
between '2005-05-01' and '2005-05-31' group by 1;

-- 3.11

select 
f.film_id, 
f.title, 
c.name as category, 
count(distinct rental_id) as times_rented 
from 
rental as r
left join inventory as i
on i.inventory_id=r.inventory_id
left join film f
on i.film_id=f.film_id
left join film_category fc
on f.film_id=fc.film_id
left join category c
on fc.category_id=c.category_id
group by 1,2,3
order by 4 desc;
