/* 
	Practice 1 
*/

# 1.1 -- 2023.3.26	
/* 
Use SCHEMAS(Database) world and table country to practice:
• Select all columns from table country and only display 5 records
• Only want to check code, name, region, population columns from table country; 
• Want to check different values of region in table country
• Comment out one of the query you just wrote down
*/
SELECT * FROM country LIMIT 5;
SELECT code,name,region, population FROM world.country;
# SELECT DISTINCT region FROM country;

# 1.2 -- 2023.3.30	
/* 
Use SCHEMAS(Database) world and table country to practice:
• Display the TOP 5 countries with the largest population
• Rank the country by descending region, and ascending surfaceArea
• List the countries with lifeExpectancy => 75 and rank by ascending population
• List countries became independent between 1980 and 1990;
• List countries in region Eastern Asia and indepYear is null;
• Select countries in Western Europe, with population less than 80000000 and surfacearea larger than 3000, 
  and rank these countries by descending Code column
*/
SELECT name, population FROM world.country Order By 2 desc LIMIT 5;
SELECT name, region, surfaceArea FROM world.country Order By 2 desc, 3 asc;
SELECT name, LifeExpectancy, population FROM world.country WHERE LifeExpectancy >= 75 Order By population asc;
SELECT name, indepYear FROM world.country WHERE indepYear Between 1980 And 1990;
SELECT name, region, indepYear FROM world.country WHERE region = 'Eastern Asia' AND indepYear IS NULL;
SELECT code, name, region, population, surfacearea FROM world.country 
WHERE (region = 'Western Europe') 
AND (population < 80000000) 
AND (surfacearea > 3000) 
Order By 1 desc;