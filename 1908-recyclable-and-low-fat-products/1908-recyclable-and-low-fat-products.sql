# Write your MySQL query statement below
SELECT P.product_id
FROM Products p
WHERE P.low_fats = 'Y' AND
P.recyclable = 'Y'
