# Write your MySQL query statement below
select s.user_id,
ROUND(IFNULL(AVG(c.action='confirmed'),0),2) as confirmation_rate
FROM Signups s left join 
Confirmations c
on s.user_id = c.user_id
group by s.user_id;

#IFNULL(value,0)- if value is null return 0 else return value