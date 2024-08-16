###### SQL Class4 ######
########################
########################


SELECT prod_id, prod_name, prod_price FROM Products;

-- do not forget semi-colon in the end of each query

SELECT * FrOM Products;

SELECT * FROM Products limit 5;


SELECT vend_id FROM Products;

SELECT DISTINCT vend_id FROM Products;

#SELECT DISTINCT vend_id, prod_price FROM Products;
/*
SELECT 
prod_name, 
vend_id
FROM Products;
*/

SELECT prod_name
FROM Products 
order by prod_name;

SELECT prod_id, prod_price, prod_name 
FROM Products
ORDER BY prod_price, prod_name;


SELECT prod_id, prod_price, prod_name
	FROM Products
	ORDER BY 2, 3;
    
SELECT prod_id, prod_price, prod_name
	FROM Products
	ORDER BY 2 desc, 3;


SELECT prod_id, prod_price,prod_name
	FROM Products
	ORDER BY 2, prod_name;

SELECT prod_id, prod_price, prod_name
	FROM Products
	ORDER BY prod_price DESC;
    
-- Where

select prod_name, prod_price 
	FROM Products
	WHERE prod_price <= 10
    order by 1;

SELECT vend_id, prod_name
	FROM Products
	WHERE vend_id <> 'DLL01';
    
SELECT prod_name, prod_price
	FROM Products
	WHERE prod_price BETWEEN 5 AND 10;

SELECT *
	FROM Customers
	WHERE cust_email is NULL;

SELECT *
	FROM Customers
	WHERE cust_email is not NULL;
    
SELECT prod_id, prod_price, prod_name
	FROM Products
	WHERE vend_id = 'DLL01' AND prod_price <= 4;
    
    
###### SQL Class5 ######
########################
########################

-- wrong one

SELECT vend_id, prod_name, prod_price
FROM Products
WHERE vend_id = 'DLL01' OR vend_id = 'BRS01'
      AND prod_price >= 10;

-- correct one

SELECT prod_name, prod_price, vend_id
	FROM Products
	WHERE (vend_id = 'DLL01' OR vend_id = 'BRS01') 
    AND prod_price >= 10;

-- in
SELECT prod_name, prod_price,vend_id
	FROM Products
	WHERE vend_id IN ('DLL01','BRS01');

SELECT prod_name, prod_price,vend_id
	FROM Products
	WHERE vend_id ='DLL01'
    or vend_id ='BRS01';



    
SELECT prod_id, prod_name
	FROM Products
	WHERE prod_name LIKE 'Fish%';
    
SELECT prod_id, prod_name
FROM Products
WHERE prod_name LIKE '%bean bag%';

SELECT prod_id, prod_name
	FROM Products
	WHERE prod_name LIKE '__inch teddy bear';
-- vs    
SELECT prod_id, prod_name
FROM Products
WHERE prod_name LIKE '%inch teddy bear';

###### SQL Class6 ######
########################
########################

-- calculated fields

SELECT vend_name, vend_country, 
concat(vend_name, ' (', vend_country, ')')
	FROM Vendors
	ORDER BY vend_name;
    
    
SELECT vend_name, vend_country, 
Concat(vend_name, ' (', vend_country, ')')  vend_title
	FROM Vendors
	ORDER BY vend_name;

SELECT *, 
concat(vend_name, ' (' , vend_zip, ')')  
as vend_detail
FROM Vendors
ORDER BY vend_name;

SELECT quantity*item_price AS total_sales,
prod_id, quantity, item_price
	FROM OrderItems
	WHERE order_num = 20008;
    
    
-- functions:

SELECT vend_name, 
upper(vend_name) AS vend_name_uppercase
	FROM Vendors
	ORDER BY vend_name;
    
SELECT vend_name, 
substring(vend_name,1,4) 
AS first_4_letters_of_vend_name
	FROM Vendors
	ORDER BY vend_name;


select substring(order_date, 1,7) as month1,
substring(order_date,6,2) as month2
from Orders;

SELECT order_num, order_date
	FROM Orders
	WHERE YEAR(order_date) = 2012;
    
SELECT order_num, order_date, NOW() as currentdateandtime
	FROM Orders;
    
SELECT order_num, order_date,
NOW() as currentdateandtime, curdate() as curdt,
datediff(curdate(), order_date) as dategap
	FROM Orders;

SELECT prod_price,
case when prod_price < 6 then 'low price'
	 else 'high price' 
     end
     from Products;
     
SELECT prod_price,
case when prod_price < 6 then 'low price'
	 else 'high price' 
     end as price_segment
     from Products;
     
-- use case when to create a segmentation column
SELECT 
prod_price,
case when prod_price < 6 then 'low price'
	 when prod_price < 9 then 'medium price'
     else  'high price'
     end as price_segment
     from Products;
     
SELECT 
case when prod_price < 6 then 'low price'
	 when prod_price < 9 then 'medium price'
	 when prod_price >= 9 then 'high price'
     else 'invalid' 
     end as price_segment
     from Products;

###### SQL Class7 ######
########################
########################

SELECT AVG(prod_price) AS avg_price
	FROM Products;

SELECT AVG(prod_price) AS avg_price
	FROM Products
	WHERE vend_id = 'DLL01';

SELECT COUNT(*) AS num_cust
	FROM Customers;
    
SELECT COUNT(cust_email) AS num_cust
	FROM Customers;
select * from    Customers; 
SELECT COUNT(cust_email) AS num_cust
	FROM Customers;
    
SELECT MAX(prod_price) AS max_price
	FROM Products;

SELECT MIN(prod_price) AS min_price
	FROM Products;

SELECT SUM(quantity) AS items_ordered
	FROM OrderItems
	WHERE order_num = 20005;

SELECT SUM(item_price*quantity) AS total_sales
	FROM OrderItems
	WHERE order_num = 20005;
    
SELECT AVG(DISTINCT prod_price) AS avg_price
	FROM Products
	WHERE vend_id = 'DLL01';


SELECT COUNT(distinct vend_id) FROM products;

SELECT COUNT(*) AS num_items,
	MIN(prod_price) AS price_min,
	MAX(prod_price) AS price_max,
	AVG(prod_price) AS price_avg
	FROM Products;

SELECT COUNT(vend_id) FROM Products;
SELECT COUNT(*) FROM Products;
SELECT COUNT(distinct vend_id) FROM Products;

-- identify 
-- 1)how many records?
-- 2)whether there are missings?
-- 3)whether there are dup records?








select 
count(*), 
count(vend_id), 
count(distinct vend_id) from Products;


###### SQL Class8 ######
########################
########################


SELECT vend_id, COUNT(*) AS num_prods
	FROM Products
	GROUP BY vend_id
    ORDER by num_prods;
    
SELECT vend_id, count(*) as num_prods, avg(prod_price) as avg_price
		FROM Products
        Group By vend_id;
    
 SELECT vend_id, COUNT(*) AS num_prods
	FROM Products
	GROUP BY vend_id
    having num_prods >3;
    
    
    
    
SELECT cust_id, COUNT(*) AS orders
	FROM Orders
	GROUP BY cust_id
	HAVING orders >= 2;
    
    
SELECT vend_id, COUNT(*) AS num_prods
	FROM Products
	GROUP BY vend_id
	HAVING COUNT(*) >= 3;


SELECT vend_id, COUNT(*) AS num_prods
	FROM Products
	WHERE prod_price >= 4
	GROUP BY vend_id
	HAVING COUNT(*) >= 2
    order by num_prods;
    


SELECT order_num
FROM OrderItems
WHERE prod_id = 'RGAN01';

SELECT cust_id
FROM Orders
WHERE order_num IN (20007,20008);

SELECT cust_name, cust_contact
FROM Customers
WHERE cust_id IN ('1000000004','1000000005');

SELECT cust_name, cust_contact
	FROM Customers
	WHERE cust_id IN 
    (SELECT cust_id
				FROM Orders
				WHERE order_num IN 
                (SELECT order_num FROM OrderItems
									WHERE prod_id = 'RGAN01'));










