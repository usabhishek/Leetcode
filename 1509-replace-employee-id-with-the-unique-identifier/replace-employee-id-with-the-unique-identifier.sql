# Write your MySQL query statement below
select em.unique_id, e.name from Employees e LEFT JOIN EmployeeUNI em on e.id = em.id; 