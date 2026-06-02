select 
ROUND(count(distinct a.player_id)/(select count(distinct player_id) FROM Activity),2)
 as fraction
FROM Activity a
join (
    select player_id ,min(event_date) as first_login
    from Activity
    group by player_id
)f
on a.player_id = f.player_id
and Datediff(a.event_date,f.first_login)=1;
