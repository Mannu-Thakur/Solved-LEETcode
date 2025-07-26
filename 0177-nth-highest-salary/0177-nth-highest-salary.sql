CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.

      SELECT e.salary
      FROM Employee e
      WHERE N - 1 = (
        SELECT COUNT(DISTINCT e2.salary) FROM Employee e2
        WHERE e2.salary > e.salary
      ) LIMIT 1


  );
END