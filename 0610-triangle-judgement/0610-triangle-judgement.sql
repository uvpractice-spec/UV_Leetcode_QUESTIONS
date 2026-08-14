# Write your MySQL query statement below
SELECT 
    *,
    CASE 
        WHEN x > 0 AND y > 0 AND z > 0
        and (x + y > z) AND (x + z > y) AND (y + z > x) THEN 'Yes'
        ELSE 'No'
    END AS triangle
FROM Triangle;