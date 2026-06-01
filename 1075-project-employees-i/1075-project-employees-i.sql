# Write your MySQL query statement below
select p.project_id,
ROUND(IFNULL(AVG(e.experience_years),0)
    ,2)as average_years
from Project p left join employee e
on p.employee_id = e.employee_id
group by project_id;