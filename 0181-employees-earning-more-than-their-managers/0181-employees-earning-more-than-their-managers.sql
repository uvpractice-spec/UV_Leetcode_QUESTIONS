# Write your MySQL query statement below

select Emp.name as Employee
from Employee Emp
left join Employee mg
on Emp.managerId = mg.id
where Emp.salary > mg.salary
