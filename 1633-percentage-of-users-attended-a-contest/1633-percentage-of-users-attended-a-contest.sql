# Write your MySQL query statement below
select r.contest_id,
ROUND(count(DISTINCT r.user_id)*100/ (select count(*) from users),2) 
as percentage
FROM  Register r
group by r.contest_id 
order by percentage DESC , r.contest_id ASC; 