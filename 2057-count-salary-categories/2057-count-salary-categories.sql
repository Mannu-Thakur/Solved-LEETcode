WITH categories AS (
    SELECT 'Low Salary' AS category
    UNION ALL
    SELECT 'Average Salary'
    UNION ALL
    SELECT 'High Salary'
),
categorized_accounts AS (
    SELECT
      CASE 
        WHEN income < 20000 THEN 'Low Salary'
        WHEN income BETWEEN 20000 AND 50000 THEN 'Average Salary'
        WHEN income > 50000 THEN 'High Salary'
      END AS category
    FROM Accounts
)
SELECT 
  c.category,
  COUNT(a.category) AS accounts_count
FROM categories c
LEFT JOIN categorized_accounts a
  ON c.category = a.category
GROUP BY c.category;
