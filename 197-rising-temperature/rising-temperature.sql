# Write your MySQL query statement below
select w1.id from Weather as w1 JOIN Weather as w2 on DATEDIFF(w1.recordDate, w2.recordDate) = 1 where w1.temperature > w2.temperature;


-- select *, w1.temperature from Weather as w1 JOIN Weather as w2 on w1.id = w2.id + 1;