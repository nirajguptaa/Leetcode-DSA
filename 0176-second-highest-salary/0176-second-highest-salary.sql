# Write your MySQL query statement below
Select MAX(salary)AS SecondHighestSalary
from Employee
where salary<(select max(salary) from Employee);