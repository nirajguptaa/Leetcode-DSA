# Write your MySQL query statement below
SELECT patient_id,patient_name ,conditions
FROM Patients
where conditions LIKE 'DIAB1%' or conditions LIKE '% DIAB1%';