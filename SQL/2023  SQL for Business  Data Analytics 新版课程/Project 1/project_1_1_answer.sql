-- before doing any exercise, you should explore the data first

-- 1
select * from actor limit 100;
select * from film_actor limit 100;
select * from film limit 100;
select * from language limit 100;
select * from film_category limit 100;
select * from category limit 100;

-- 2 
select rating, 
max(rental_rate) from film group by 1;

-- 3
select rating, 
count(distinct film_id) from film group by rating;

-- 4
SELECT CASE WHEN length > 0 and length < 60 THEN 'short'			
		    WHEN length >= 60 and length < 120 THEN 'standard'            
		    WHEN length >=120  THEN 'long'           
                         ELSE 'others'            
                         END as film_length, 
                         count(film_id) from film            
                         group by 1
                         order by 2;
-- 5
select * from actor where last_name= 'Johansson';
-- 6
select count(distinct last_name) from actor;
-- 7
select last_name, 
count(*) as num from actor group by last_name 
having count(*) = 1;
-- 8
select last_name, 
count(*) as num from actor 
group by last_name 
having count(*) > 1;
-- 9
select film_id, 
count(distinct actor_id) as num_of_actor 
from film_actor group by film_id order by num_of_actor desc;
-- 10
select actor_id, 
count(distinct film_id) as num_of_film 
from film_actor group by actor_id order by num_of_film desc;

