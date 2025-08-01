# Write your MySQL query statement below
SELECT 
    u.user_id,
    CONCAT(UPPER(LEFT(u.name, 1)), LOWER(SUBSTRING(u.name, 2))) AS name
FROM Users u
ORDER BY u.user_id;
