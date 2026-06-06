# Write your MySQL query statement below
Select user_id,
CONCAT(
    upper(substring(name,1,1)),
    lower(substring(name,2))
)as name
from Users
order by user_id;
