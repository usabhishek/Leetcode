# Write your MySQL query statement below
select s.name, s.population , s.area from World s where s.area >= 3000000 OR s.population  >= 25000000;