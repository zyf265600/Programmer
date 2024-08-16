-- 2.1

select * from country where 
region in ('Eastern Africa', 'North America','Middle East')
order by region;

select * from country where 
region = 'Eastern Asia' and 
(population > 7000000 or LifeExpectancy > 75);

select * from country 
where name like 'A%a';


-- 2.2

select name, surfacearea, population, 
population/surfacearea as pop_density from country
order by pop_density desc;

select name, surfacearea, population, 
population/surfacearea as pop_density from country
where population/surfacearea > 1000
order by pop_density desc;


select name, case when population < 1000000 then 'small'
	when population < 10000000 then 'medium'
    when population < 100000000 then 'large'
    when population >= 100000000 then 'extra large'
    else 'invalid'
    end as population_size
    from country;

select * from country
where substring(code,1,2) <> code2;

select *, case when substring(code,1,2) = code2 then 'match'
else 'not match' end as code_check from country;


