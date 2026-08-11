# Write your MySQL query statement below

select actor_id, director_id
from ActorDirector
group by actor_id,director_id
having count(timestamp) >=3


/*

   
   result = (
        actordirector
        .groupBy("actor_id","director_id")
        .agg(F.count("timestamp").alias("cnt"))
        .filter(F.col("cnt")>=3)
        .select("actor_id","director_id")
   
       )
*/