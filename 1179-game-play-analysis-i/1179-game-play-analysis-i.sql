# Write your MySQL query statement below
SELECT DISTINCT a.player_id , MIN(a.event_date) AS first_login
FROM Activity a
GROUP BY a.player_id
