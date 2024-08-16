/* 
	Practice 4
*/

# 4.1 -- 2023.4.24
/* 
Use SCHEMAS(Database) world to practice:
• Use table Country and Language to find the language used in each country.
  I want all columns from Country table and language column from Language table
	• Use 2 types of Inner Join syntax to solve this: WHERE/Join On
• Use table Country and City to find each country’s capital city name. 
  Hint: check the capital column in table Country, and find which column you should use in table City to join these 2 tables.
• Use table Country and City to find each country’s capital city name, 
  the population in the capital city and the percentage of capital city’s population in the whole country. 
  Hint: you need to use calculated field, and you may want to rename the column, 
  so that the final table won’t have 2 columns with the same name.
*/

SELECT C.*, L.Language 
FROM world.country AS C, world.countrylanguage as L
WHERE C.Code = L.CountryCode;
SELECT C.*, L.Language 
FROM world.country AS C Join world.countrylanguage as L ON C.Code = L.CountryCode;

SELECT co.Name AS Country_Name, ci.Name AS Capital_Name
FROM world.city AS ci Join world.country as co ON ci.ID = co.Capital;

SELECT co.Name AS Country_Name, ci.Name AS Capital_Name, ci.Population AS Capital_Population, concat(ci.Population / co.Population * 100, '%') AS Percentage
FROM world.city AS ci Join world.country as co ON ci.ID = co.Capital;

# 4.2 -- 2023.4.25
/* 
Use SCHEMAS(Database) world to practice:
• For all questions in Practice 4.1, change to LEFT JOIN and check the differences
• Use table Country and Countrylanguage to find the official language used in each country. 
  Hint: use column Isofficial and WHERE filter
• Count the number of different languages used in each country. I only need columns: country name, number of languages used. Hint: do not forget GROUP BY
• Some countries may have more than one types of official languages. Count the number of different official languages used in each country.
  I only need columns: country name, number of languages used
• Multiple table joins – show me the information as below:
	• country name
	• Different languages used in the country
	• for each language, how many people speak as column ‘language_pop’
	• official language or not
	• capital city name 
*/
SELECT * FROM world.city;
SELECT * FROM world.country;
SELECT * FROM world.countrylanguage;

SELECT C.*, L.Language 
FROM world.country AS C, world.countrylanguage as L
WHERE C.Code = L.CountryCode;
SELECT C.*, L.Language 
FROM world.country AS C LEFT Join world.countrylanguage as L ON C.Code = L.CountryCode;
SELECT co.Name AS Country_Name, ci.Name AS Capital_Name
FROM world.city AS ci LEFT Join world.country as co ON ci.ID = co.Capital;
SELECT co.Name AS Country_Name, ci.Name AS Capital_Name, ci.Population AS Capital_Population, concat(ci.Population / co.Population * 100, '%') AS Percentage
FROM world.city AS ci LEFT Join world.country as co ON ci.ID = co.Capital;

SELECT c.*, cl.Language
FROM world.country AS c LEFT JOIN world.countrylanguage AS cl ON c.code = cl.CountryCode
WHERE cl.IsOfficial = 'T';

SELECT c.Name, count(cl.Language)
FROM world.country AS c LEFT JOIN world.countrylanguage AS cl ON c.code = cl.CountryCode
Group By c.Name;

SELECT c.Name, count(cl.Language) AS Num_Official_Language
FROM world.country AS c LEFT JOIN world.countrylanguage AS cl ON c.code = cl.CountryCode
WHERE cl.IsOfficial = 'T'
Group By c.Name;

SELECT cc.Name, cl.Language, cc.Population * cl.Percentage AS language_pop, cl.IsOfficial, c.Name
FROM world.country AS cc LEFT JOIN world.countrylanguage AS cl ON cc.code = cl.CountryCode LEFT JOIN world.city AS c ON c.id = cc.Capital;

