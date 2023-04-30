/* 
	Practice 3
*/

# 3.1 -- 2023.4.17
/* 
Use SCHEMAS(Database) world to practice:
1. Create a report showing sum of population and average life expectancy for each continent, 
   and make sure your result doesn’t include any continent with total population less than 1000000;
2. Create a column called Population_size to segment the country by population size and calculate the average lifeexpectancy for each segment
   1. If population < 1 million, then ‘small’; if 1 million <= population < 10 million, then ‘medium’, if 10 million <= population < 100 million, then ‘large; if population >= 100 million, then ‘Extra large’;
   your final result should show the population size segment and the average life expectancy for each segment
3. Using table countrylanguage, to get the number of countries speaking each distinct language, 
   then rank the language by how many countries and by descending order
4. Calculate the average population for each region and exclude the region whose average population is fewer than the average population of all the countries in the country table. 
   The final result should have 2 columns – region and average population. Hint: use subquery to get the overall average population first
*/

SELECT continent, SUM(Population), AVG(LifeExpectancy)
FROM world.country 
group by continent 
HAVING SUM(Population) >= 1000000;

SELECT Case when Population < 1000000 then 'small'
			when Population < 10000000 then 'medium'
			when Population < 100000000 then 'large'
			when Population >= 100000000 then 'extra large'
            else 'invalid' end as Population_size,
AVG(LifeExpectancy)
FROM world.country 
Group By 1;

SELECT language, count(CountryCode)
FROM world.countrylanguage
Group By 1
Order By 2 DESC; 

SELECT region, AVG(population) as average_population
FROM world.country
Group By 1
HAVING AVG(population) > (SELECT AVG(population)
						  FROM world.country);

