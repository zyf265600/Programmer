/* 
	Practice 2
*/

# 2.1 -- 2023.4.3
/* 
Use SCHEMAS(Database) world and table country to practice:
• List countries in region Eastern Africa or North America or Middle East order by region
• For all countries in region Eastern Asia , select the countries with population > 7000000 
  or lifeexpectancy > 75
• Identify countries with name beginning with ‘A’ and ending with ‘a’
*/
SELECT name, region From world.country WHERE region IN ('Eastern Africa', 'North America', 'Middle East') Order By region;
SELECT name, region, population, lifeexpectancy From world.country WHERE region = 'Eastern Asia'
And (population > 7000000 Or  lifeexpectancy > 75);
SELECT name From world.country WHERE name LIKE 'A%a';

# 2.2 -- 2023.4.4
/* 
Use SCHEMAS(Database) world and table country to practice:
• Use population/surfacearea to get pop_density and rank pop_density by descending order
• Bonus: how can I get countries with pop_density > 1000
• Create a column called Population_size to segment the country by population size:
  • If population < 1 million, then ‘small’; if 1 million <= population < 10 million, then ‘medium’,
      if 10 million <= population < 100 million, then ‘large; if population >= 100 million, then ‘Extra large’; 
    Then show country name and population_siz 
• In the table, we found a column called as Code which should be country code, 
  and another column called as Code2. I want to know whether Code2 is just the first 2 letters of Code. 
  Please write query to confirm this. 
  Hint: use substring to get the first 2 letters of Code, 
  and compare with Code2, if they match with each other, then we can confirm
*/
SELECT name, Population, Surfacearea, Population/Surfacearea as pop_density FROM world.country 
WHERE Population/Surfacearea > 1000 Order By pop_density DESC;
SELECT name, Population,
CASE when Population >= 100000000 then 'Extra large'
	 when Population >= 10000000 then 'large'
     when Population >= 1000000 then 'medium'
     when Population <  1000000 then 'small'
     else 'invalid' 
     end AS population_size
 FROM world.country;
SELECT name, code, code2, substring(code,1,2), 
	Case  when substring(code,1,2) = code2 then 'match'
    else 'not match'
    end AS 'vertification'
    FROM world.country;
SELECT * FROM world.country where substring(code,1,2) <> code2;



