# Write your MySQL query statement below
SELECT Round(sum(tiv_2016),2) as tiv_2016
FROM Insurance
where tiv_2015 in(

SELECT tiv_2015
FROM Insurance
Group BY tiv_2015
Having COUNT(*)>1
)
AND (lat,lon) IN (
select lat,lon 
FROM Insurance
GROUP by lat,lon
having count(*)=1
);