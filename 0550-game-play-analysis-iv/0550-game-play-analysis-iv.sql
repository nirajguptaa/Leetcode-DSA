# Write your MySQL query statement below
With min_Event_Date as(
    select player_id,min(event_date) as first_Date
    from Activity
    group by player_id
)
select
round(count(distinct a.player_id)/(select count(distinct player_id ) from Activity),2) as 
fraction
from Activity a
join min_Event_Date m
on a.player_id=m.player_id and
Datediff(a.event_date,m.first_Date)=1;
