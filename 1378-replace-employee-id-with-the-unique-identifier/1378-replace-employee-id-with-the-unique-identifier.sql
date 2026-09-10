# Write your MySQL query statement below
select unique_id , name from EmployeeUNI eu right Join Employees em 
on eu.id=em.id;