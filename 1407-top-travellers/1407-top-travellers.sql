# Write your MySQL query statement below


SELECT 
    u.name,
    IFNULL(SUM(r.distance), 0) AS travelled_distance
FROM Users u
LEFT JOIN Rides r
    ON u.id = r.user_id
GROUP BY u.id, u.name
ORDER BY travelled_distance DESC, u.name ASC;
/*
select distinct u.name , case when r.distance is not null then sum(distance) over(partition by r.user_id order by r.user_id) else 0 end as travelled_distance
from Users u
left join Rides r
on u.id = r.user_id
order by travelled_distance desc , u.name*/