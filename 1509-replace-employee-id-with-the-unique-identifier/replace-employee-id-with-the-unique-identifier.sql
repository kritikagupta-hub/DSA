# Write your MySQL query statement below
select EmployeeUNI.unique_id , Employees.name
from employees
left join employeeUNI on 
employees.id = employeeUNI.id 

