# Write your MySQL query statement below
SELECT MAX(salary) SecondHighestSalary FROM Employee WHERE salary <> (SELECT MAX(salary) FROM Employee);