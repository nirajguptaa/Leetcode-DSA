# Write your MySQL query statement below
(select u.name as results
from Users u
left join MovieRating m
on u.user_id=m.user_id
group by u.user_id 
order by count(*) DESC ,u.name ASC
limit 1
)
union all
(
select mov.title as results
from Movies mov
left join MovieRating m
on mov.movie_id =m.movie_id
where m.created_at between '2020-02-01' and '2020-02-29' 
group by mov.movie_id
order by avg(m.rating) DESC ,mov.title ASC
limit 1
);