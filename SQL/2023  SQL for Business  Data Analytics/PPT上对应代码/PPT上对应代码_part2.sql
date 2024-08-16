###### Join ######
########################
########################

select * from Vendors;
select * from Products;
-- cartesian product
SELECT *
	FROM Vendors, Products;
    
SELECT *
	FROM Vendors, Products
    WHERE Vendors.vend_id = Products.vend_id
    and vend_country = 'USA';

SELECT *
	FROM Vendors JOIN Products
	ON Vendors.vend_id = Products.vend_id
    WHERE vend_country = 'USA';

SELECT vend_name, prod_name, prod_price
	FROM Vendors Inner JOIN Products
	ON Vendors.vend_id = Products.vend_id;
    
    
select * from OrderItems;

SELECT order_num, prod_name, vend_name, prod_price, quantity
	FROM OrderItems, Products, Vendors
	WHERE Products.vend_id = Vendors.vend_id
	AND OrderItems.prod_id = Products.prod_id
	AND order_num = 20007;

SELECT cust_name, cust_contact
	FROM Customers, Orders, OrderItems
	WHERE Customers.cust_id = Orders.cust_id
	AND OrderItems.order_num = Orders.order_num
	AND prod_id = 'RGAN01';

-- join multiple tables
SELECT cust_name, cust_contact
	from Customers join Orders on Customers.cust_id = Orders.cust_id
    join OrderItems on OrderItems.order_num = Orders.order_num
    where prod_id = 'RGAN01';




SELECT C.cust_id,cust_name,cust_contact
	FROM Customers AS C, Orders AS O, OrderItems AS OI
	WHERE C.cust_id = O.cust_id
	AND OI.order_num = O.order_num
	AND prod_id = 'RGAN01';
    
    
-- only write the column you need

SELECT C.*, O.order_num, 
O.order_date, 
OI.prod_id, OI.quantity, OI.item_price
	FROM Customers AS C, Orders AS O, OrderItems AS OI
	WHERE C.cust_id = O.cust_id AND OI.order_num = O.order_num 
	AND prod_id = 'RGAN01';

SELECT *
	FROM Customers AS C, Orders AS O, OrderItems AS OI
	WHERE C.cust_id = O.cust_id AND OI.order_num = O.order_num 
	AND prod_id = 'RGAN01';
    



SELECT C.cust_id, O.order_num
FROM Customers as C
Left JOIN
Orders as O
on C.cust_id=O.cust_id;

SELECT C.cust_id, O.order_num
FROM Customers as C
RIGHT JOIN
Orders as O
on C.cust_id=O.cust_id;

SELECT C.cust_id, O.order_num
FROM Orders as O
LEFT JOIN
Customers as C
on C.cust_id=O.cust_id;

SELECT C.cust_id, O.order_num
FROM Customers as C
JOIN
Orders as O
on C.cust_id=O.cust_id;


SELECT C.cust_id,cust_name, cust_contact
	FROM Customers AS C
    LEFT JOIN Orders AS O
	ON C.cust_id = O.cust_id
    LEFT JOIN OrderItems AS OI
    ON OI.order_num = O.order_num
    where prod_id = 'RGAN01';


SELECT Customers.cust_id, 
COUNT(Orders.order_num) AS num_ord 
FROM Customers JOIN Orders
 ON Customers.cust_id = Orders.cust_id
GROUP BY Customers.cust_id;

SELECT Customers.cust_id, 
COUNT(Orders.order_num) AS num_ord  -- be careful about count(*)
FROM Customers LEFT JOIN Orders
 ON Customers.cust_id = Orders.cust_id
GROUP BY Customers.cust_id;

SELECT Customers.cust_id, Orders.order_num 
FROM Customers LEFT JOIN Orders
 ON Customers.cust_id = Orders.cust_id;

###### Union ######
########################
########################

select cust_name, cust_contact, cust_email, cust_state from Customers
where cust_state in ('IL', 'IN','MI')
UNION 
select cust_name, cust_contact, cust_email, cust_state from Customers#customers2
where cust_name = 'Fun4All';

select cust_name, cust_contact, cust_email from Customers
where cust_state in ('IL', 'IN','MI')
UNION ALL
select cust_name, cust_contact, cust_email from Customers
where cust_name = 'Fun4All';

select cust_name, cust_contact, cust_email from Customers 
where cust_state in ('IL', 'IN','MI')
UNION ALL
select cust_name, cust_contact, cust_email from Customers
where cust_name = 'Fun4All'
order by cust_name,cust_contact;

SELECT Customers.cust_id, COUNT(Orders.order_num) AS num_ord  
FROM Customers LEFT OUTER JOIN Orders
 ON Customers.cust_id = Orders.cust_id
GROUP BY Customers.cust_id
union
SELECT Customers_order.cust_id, num_ord  
FROM Customers_order
order by 1;


###### Change tables: Insert/Update/Delete/Drop/Create ######
########################
########################
select * from Customers;

insert into Customers
values(
'Toy Land2',
'1000000010',
'123 Any Street',
'New York',
'NY',
'11111',
'USA',null,
null);

select * from Customers;

insert into Customers
(cust_id,
cust_name,
cust_address,cust_city,
cust_state,
cust_zip,
cust_country,
cust_contact,cust_email)
values(
'1000000017',
'Toy Land',
'123 Any Street',
'New York',
'NY',
'11111',
'USA',
NULL,
NULL);


insert into Customers
(cust_id,
cust_name,
cust_address,cust_city,
cust_state,
cust_zip,
cust_country,
cust_contact,cust_email)
select
cust_id,
cust_name,
cust_address,cust_city,
cust_state,
cust_zip,
cust_country,
cust_contact,cust_email
from CustNew;


select * from Customers where cust_id = '1000000005';

select * from Customers;

UPDATE Customers 
SET cust_email = 'kenabc@gmail.com'
WHERE cust_id = '1000000005';

UPDATE Customers 
SET cust_email = 'abcefg@gmail.com',
	cust_contact = 'EZcareer';




DELETE FROM Customers
WHERE cust_id = 'Toy Land2';

select * from Customers; 

CREATE TABLE new_customers AS
SELECT C.cust_id,cust_name, cust_contact
	FROM Customers AS C
    LEFT JOIN Orders AS O
    ON C.cust_id = O.cust_id
    LEFT JOIN OrderItems AS OI
    ON OI.order_num = O.order_num
    where prod_id = 'RGAN01';
    
    
select * from new_customers;

delete from new_customers;

drop table if exists new_customers;


SELECT vend_id, COUNT(*) AS num_prods
	FROM Products
	WHERE prod_price >= 4
	GROUP BY vend_id
    Having num_prods >=2
    order by num_prods;

drop table a;
create table a as
SELECT vend_id, COUNT(*) AS num_prods
	FROM Products
	WHERE prod_price >= 4
	GROUP BY vend_id
    Having num_prods >=2
    order by num_prods;
    
    
SELECT a.vend_id, b.vend_city  FROM 
(SELECT vend_id, COUNT(*) AS num_prods
	FROM Products
	WHERE prod_price >= 4
	GROUP BY vend_id
    Having num_prods >=2
    order by num_prods) AS A
    left join
Vendors as b
on a.vend_id=b.vend_id;


###### Window Function ######
########################
########################



SELECT cust_id, 
order_date, 
ROW_NUMBER() OVER (PARTITION BY cust_id ORDER BY order_date desc) AS row_num 
FROM Orders;

select cust_id, order_date, order_num from
(SELECT *, 
ROW_NUMBER() OVER (PARTITION BY cust_id ORDER BY order_date desc) AS row_num 
FROM Orders) as t
where t.row_num=1;

SELECT cust_id, 
order_date, 
ROW_NUMBER() OVER (PARTITION BY cust_id, order_date ORDER BY order_date desc) AS row_num 
FROM Orders;
