# Write your MySQL query statement below
Select Max(salary) as secondhighestsalary from employee where salary <(select max(salary) from employee);
