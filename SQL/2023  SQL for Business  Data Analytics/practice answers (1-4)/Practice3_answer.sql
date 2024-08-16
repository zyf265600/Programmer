-- 3.1

select continent, sum(population) as sum_pol, avg(lifeexpectancy) as avg_lf 
from country group by 1
having sum_pol >= 1000000;

-- 3.2
select case when population < 1000000 then 'small'
	when population < 10000000 then 'medium'
    when population < 100000000 then 'large'
    when population >= 100000000 then 'extra large' end as population_size, 
    avg(LifeExpectancy)
    from country group by 1;

-- 3.3
select language, count(distinct countrycode) as num_of_country 
from countrylanguage group by 1 order by 2 desc;

-- 3.4
select region, avg(population) as pol_avg from country
group by 1
having pol_avg > (select avg(population) from country);