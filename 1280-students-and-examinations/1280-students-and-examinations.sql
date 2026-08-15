# Write your MySQL query statement below

with cross_cte as(
    select *
    from Students
    cross join Subjects
),
cte2 as (
    select student_id,subject_name, count(subject_name) as sub_count
    from Examinations
    group by student_id, subject_name
)

select cross_cte.student_id,cross_cte.student_name,cross_cte.subject_name,IFNULL(cte2.sub_count, 0) AS attended_exams
from cross_cte
left join cte2
on cross_cte.student_id = cte2.student_id
and cross_cte.subject_name = cte2.subject_name
order by cross_cte.student_id,cross_cte.subject_name