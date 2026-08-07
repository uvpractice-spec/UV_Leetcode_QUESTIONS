# Write your MySQL query statement below this is sql

select Emp.name as Employee
from Employee Emp
inner join Employee mg
on Emp.managerId = mg.id
where Emp.salary > mg.salary
