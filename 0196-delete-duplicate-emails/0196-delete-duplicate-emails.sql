# Write your MySQL query statement below
Delete p1 
FROM Person P1
Join Person P2
on P1.email =P2.email
AND P1.id>P2.id;