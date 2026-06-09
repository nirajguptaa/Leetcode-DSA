# Write your MySQL query statement below
select d.name as Department,
 e.name as Employee,
 e.salary as Salary
from  (
    select *,
    DENSE_RANK() over(
        PARTITION BY departmentId
        Order by salary DESC
    )as rnk
    From Employee
)e
join department d
on e.departmentId=d.id
where rnk<=3;