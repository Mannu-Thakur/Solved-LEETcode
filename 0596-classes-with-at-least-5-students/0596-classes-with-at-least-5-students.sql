# Write your MySQL query statement below
SELECT  class 
FROM(
    SELECT class
    FROM Courses
    GROUP BY class
    HAVING COUNT(*) >= 5
) AS t

