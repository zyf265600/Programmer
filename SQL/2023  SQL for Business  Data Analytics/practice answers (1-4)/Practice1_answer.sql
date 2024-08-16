#1.1
SELECT * FROM country LIMIT 5;
SELECT code, name, region, population FROM country;
SELECT DISTINCT region from country;
SELECT /*DISTINCT*/ region from country;


#1.2

SELECT name, population from country 
order by population desc limit 5;

SELECT name, region, SurfaceArea from country 
order by region desc, SurfaceArea;

SELECT name, lifeexpectancy, population from country
where lifeexpectancy >=75 order by 3;

SELECT name, indepyear from country where 
indepyear between 1980 and 1990;

SELECT name, indepyear, region from country
where indepyear is null and region = 'Eastern Asia';

SELECT code, name, region, population, surfacearea, gnp
from country 
where region = 'Western Europe' 
and population < 80000000
and surfacearea > 100
order by code desc;
