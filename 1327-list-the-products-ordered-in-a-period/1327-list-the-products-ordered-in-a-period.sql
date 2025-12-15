# Write your MySQL query statement below
SELECT p.product_name,sum(o.unit) as unit
FROM Products p  JOIN Orders o
ON p.product_id=o.product_id
WHERE order_date between '2020-02-01' AND '2020-02-29' 
GROUP By p.product_id,p.product_name
HAVING sum(o.unit)>=100;