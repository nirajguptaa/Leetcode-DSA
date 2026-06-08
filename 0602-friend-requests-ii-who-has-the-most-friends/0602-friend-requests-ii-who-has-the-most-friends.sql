# Write your MySQL query statement below
SELECT id,
count(*) as num
from
(

    select requester_id as id
    from RequestAccepted
    union all
    select accepter_id as id
    from RequestAccepted
    
)t
group by id
order by num DESC
limit 1;
