/* 
	Project 1 Manage a chain of Movie Rental Stores
*/

# 1.1 -- 2023.4.18
# Exercise 1
-- 1
select * from sakila.actor limit 100;
select * from sakila.film_actor limit 100;
select * from sakila.film limit 100;
select * from sakila.language limit 100;
select * from sakila.film_category limit 100;
select * from sakila.category limit 100;

-- 2
SELECT rating, MAX(rental_rate) FROM sakila.film Group By 1;

-- 3
SELECT rating, Count(distinct film_id) AS Num_Film FROM sakila.film Group By 1;

-- 4 
SELECT case When length >= 120 Then 'long'
			When length >= 60 Then 'standard'
            When length > 0 Then 'short'
            Else 'invalid' end AS film_length,
count(length)
FROM sakila.film 
Group By 1
Order By 2 DESC;
            
-- 5
SELECT concat(first_name, ' ', last_name)  FROM sakila.actor WHERE last_name = 'Johansson';

-- 6
SELECT count(DISTINCT last_name) FROM sakila.actor;

-- 7
SELECT last_name, count(actor_id) as num_appear FROM sakila.actor 
Group By last_name
Having num_appear = 1;

-- 8
SELECT last_name, count(actor_id) as num_appear FROM sakila.actor 
Group By last_name
Having num_appear > 1;

-- 9
SELECT film_id, count(actor_id) AS count_actor FROM sakila.film_actor
Group BY film_id
Order By count_actor DESC;

-- 10
SELECT actor_id, count(film_id) FROM sakila.film_actor Group By actor_id order by count(film_id) desc;


# 1.2 -- 2023.4.26
# Exercise 2
-- 1
select * from sakila.actor limit 100;
select * from sakila.film_actor limit 100;
select * from sakila.film limit 100;
select * from sakila.language limit 100;
select * from sakila.film_category limit 100;
select * from sakila.category limit 100;

-- 2
SELECT f.film_id, f.title, l.name AS language_name
FROM sakila.film AS f LEFT JOIN sakila.language AS l ON f.language_id = l.language_id;

-- 3
SELECT fa.*, f.title, a.first_name, a.last_name
FROM sakila.film_actor AS fa JOIN sakila.actor AS a ON fa.actor_id = a.actor_id
JOIN sakila.film AS f ON fa.film_id = f.film_id;

-- 4
SELECT f.*, fc.category_id, c.name AS category_name
FROM sakila.film AS f LEFT JOIN sakila.film_category AS fc ON f.film_id = fc.film_id
LEFT JOIN sakila.category AS c ON c.category_id = fc.category_id;

-- 5
select * from film where rating in ('G','PG-13','PG')
UNION
select * from film where rental_rate > 2;

