# Write your MySQL query statement below
with oddcte as
(select *
from Cinema
where id % 2 <> 0)

select id,movie,description,rating
from oddcte
where  description <> 'boring'
order by rating desc


/*


result = Cinema_df.filter((F.col("Id")%2 !=0) & (F.col("description")!='boring'))\
               .orderBy(F.col("rating").desc())\
               .select("id","movie","description","rating")
*/