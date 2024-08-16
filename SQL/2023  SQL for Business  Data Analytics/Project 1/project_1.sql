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


# 1.3 -- 2023.5.1
# Exercise 3
select * from sakila.actor limit 100;
select * from sakila.film_actor limit 100;
select * from sakila.film limit 100;
select * from sakila.language limit 100;
select * from sakila.film_category limit 100;
select * from sakila.category limit 100;
select * from sakila.rental limit 100;
select * from sakila.staff limit 100; 
select * from sakila.inventory limit 100;
select * from sakila.inventory_rep limit 100;
select * from sakila.payment limit 100;
select * from sakila.store limit 100;

-- 1
SELECT count(*) AS 'Sales Volume'
FROM sakila.rental 
WHERE rental_date BETWEEN '2005-05-01' AND '2005-08-31';

-- 2
select substring(rental_date, 1,7) as rental_month, count(rental_Id) as volume 
from sakila.rental
where rental_date between '2005-05-01' and '2005-08-31' 
group by 1;

-- 3
SELECT r.staff_id, s.first_name, s.last_name, count(rental_id) AS rental_volumn
FROM sakila.rental AS r JOIN sakila.staff AS s ON r.staff_id = s.staff_id
Group By r.staff_id
Order By 4 DESC;

-- 4
SELECT store_id, film_id, count(inventory_id) 
From sakila.inventory
group by 1,2;

-- 5
SELECT i.store_id, i.film_id, f.title, count(inventory_id) 
From sakila.film AS f JOIN sakila.inventory AS i ON i.film_id = f.film_id
group by 1,2,3
Order By 1;

-- 6
SELECT f.title, c.name, i.film_id, i.store_id, count(inventory_id) 
From sakila.film AS f LEFT JOIN sakila.inventory AS i ON i.film_id = f.film_id
LEFT JOIN sakila.film_category as fc ON fc.film_id = i.film_id
LEFT JOIN sakila.category AS c ON fc.category_id = c.category_id
group by 1,2,3,4
Order By 1;

-- 7
DROP TABLE inventory_report;
CREATE TABLE inventory_report AS
SELECT f.title, c.name, i.film_id, i.store_id, count(inventory_id) as Number
From sakila.film AS f LEFT JOIN sakila.inventory AS i ON i.film_id = f.film_id
LEFT JOIN sakila.film_category as fc ON fc.film_id = i.film_id
LEFT JOIN sakila.category AS c ON fc.category_id = c.category_id
group by 1,2,3,4
Order By 1;

-- 8
SELECT * FROM sakila.inventory_report WHERE Number = 0;

-- 9 
SELECT substring(payment_date, 1, 7) AS month, SUM(amount) AS revenues
FROM sakila.payment
WHERE payment_date between '2005-05-01' and '2005-08-31'
Group By month;

-- 10
SELECT s.store_id AS store, SUM(amount) AS revenues
FROM sakila.payment AS p JOIN sakila.staff AS s ON p.staff_id = s.staff_id
WHERE payment_date between '2005-05-01' and '2005-08-31'
Group By 1
Order By 1;

-- 11
SELECT f.film_id, f.title, c.name AS category_name, count(p.payment_id) AS rental_times
FROM sakila.film AS f LEFT JOIN sakila.inventory AS i ON f.film_id = i.film_id
JOIN sakila.rental AS r ON i.inventory_id = r.inventory_id
JOIN sakila.payment AS p ON p.rental_id = r.rental_id
JOIN sakila.film_category AS fc ON fc.film_id = f.film_id
JOIN sakila.category AS c ON c.category_id = fc.category_id
Group By 1, 2, 3
Order By 4, 2;

