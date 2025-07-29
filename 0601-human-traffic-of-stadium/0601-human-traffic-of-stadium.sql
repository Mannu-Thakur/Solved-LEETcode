SELECT DISTINCT s1.*
FROM Stadium s1
JOIN Stadium s2 ON s2.id = s1.id + 1
JOIN Stadium s3 ON s3.id = s1.id + 2
WHERE s1.people >= 100 
  AND s2.people >= 100 
  AND s3.people >= 100

UNION

SELECT DISTINCT s2.*
FROM Stadium s1
JOIN Stadium s2 ON s2.id = s1.id + 1
JOIN Stadium s3 ON s3.id = s1.id + 2
WHERE s1.people >= 100 
  AND s2.people >= 100 
  AND s3.people >= 100

UNION

SELECT DISTINCT s3.*
FROM Stadium s1
JOIN Stadium s2 ON s2.id = s1.id + 1
JOIN Stadium s3 ON s3.id = s1.id + 2
WHERE s1.people >= 100 
  AND s2.people >= 100 
  AND s3.people >= 100
ORDER BY visit_date;
