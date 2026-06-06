# Write your MySQL query statement below
select p.product_name,
sum(o.unit) as unit
FROM Products p left join 
Orders o on p.product_id= o.product_id
where date_format(o.order_date,'%Y-%m')='2020-02'
group by p.product_id,p.product_name
having sum(o.unit)>=100;