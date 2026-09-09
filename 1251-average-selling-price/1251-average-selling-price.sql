# Write your MySQL query statement below
select p.product_id,
round(ifNUll(sum(p.price *u.units)/sum(u.units),0),2) as average_price
from prices p
left join unitssold u
on p.product_id=u.product_id
and u.purchase_date>= start_date and u.purchase_date<=end_date
group by p.product_id;