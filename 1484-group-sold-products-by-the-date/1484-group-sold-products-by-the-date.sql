SELECT sell_date, 
Count(Distinct product) as num_sold,
group_concat(Distinct product order by product asc)as products
 from Activities
 group by sell_date
 order by sell_date ASC;