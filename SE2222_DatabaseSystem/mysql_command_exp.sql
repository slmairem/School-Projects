use week03_lab;
select name, continent, region, governmentform from worldcountries where region = "Caribbean";
select name,population,capitalname from worldcountries where continent = "europe" and lifeexpectancy between 75 and 78;
select name, capitalname from worldcountries where GovernmentForm = "Republic" and region = "Southeast Asia";  
select*from worldcountries where (region = "Central Africa" or region = "Eastern Asia" or region = "Micronesia" or region = "Middle East" or region = "Southern Europe") order by region ;
select*from worldcountries order by surfacearea and population limit 20;
select*from worldcountries where name like '%ia';
select*from worldcountries where name like '%land' and name not like '%island';
select name from worldcountries where continent = 'europe' order by CapitalPopulation limit 8;
select*from worldcountries where indepyear>1991 and continent = 'europe' order by surfacearea limit 5;
select*from worldcountries where GovernmentForm not like '%republic%' order by CapitalPopulation desc limit 1;

