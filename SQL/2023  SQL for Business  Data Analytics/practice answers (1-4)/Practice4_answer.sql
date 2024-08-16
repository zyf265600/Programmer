-- 4.1
select * from countrylanguage;
select * from city;
select * from country;
-- 4.1.1
select c.*, l.language from 
country as c
join
countrylanguage as l
on c.code=l.CountryCode;

select c.*, l.language from 
country as c,
countrylanguage as l
where c.code=l.CountryCode;
-- 4.1.2
select c.*, ci.name as capitalname from 
country as c
join
city as ci
on c.capital=ci.id;
-- 4.1.3
select c.*, ci.name as capitalname,
ci.population as capital_pop,  
ci.population/c.population as cap_pop_perc
from
country as c
join
city as ci
on c.capital=ci.id;


-- 4.2.1

select c.*, l.language from 
country as c
left join
countrylanguage as l
on c.code=l.CountryCode;


select c.*, ci.name as capitalname from 
country as c
left join
city as ci
on c.capital=ci.id ;

select c.*, ci.name as capitalname,
ci.population as capital_pop,  
ci.population/c.population as cap_pop_perc
from
country as c
left join
city as ci
on c.capital=ci.id;



-- 4.2.2

select c.*, l.language from 
country as c
left join
countrylanguage as l
on c.code=l.CountryCode
where l.Isofficial='T';

-- 4.2.3
select c.name, 
count(l.language) as num_language from 
country as c
left join
countrylanguage as l
on c.code=l.CountryCode
group by 1;

-- 4.2.4
select c.name, 
count(l.language) as num_language from 
country as c
left join
countrylanguage as l
on c.code=l.CountryCode
where l.Isofficial='T'
group by 1;


-- 4.2.5

select c.name, l.language, 
l.percentage*c.population as language_pop,
l.isofficial, ci.name as capital_name
from country as c, city as ci, 
countrylanguage as l
where c.capital=ci.id
and c.code=l.CountryCode;

select c.name, l.language, 
l.percentage*c.population as language_pop,
l.isofficial, ci.name as capital_name
from country as c
left join
city as ci
on c.capital=ci.id
left join
countrylanguage as l
on c.code=l.CountryCode;

