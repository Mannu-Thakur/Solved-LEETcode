SELECT Department, Employee, Salary
FROM (
    SELECT 
        D.name AS Department,
        E.name AS Employee,
        E.salary AS Salary,
        DENSE_RANK() OVER (PARTITION BY E.departmentId ORDER BY E.salary DESC) AS rank_in_dept
    FROM Employee E
    JOIN Department D ON E.departmentId = D.id
) ranked
WHERE rank_in_dept <= 3;
