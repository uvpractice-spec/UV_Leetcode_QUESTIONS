# Write your MySQL query statement bel

update Salary
set sex = case when sex = 'm' then 'f'
when sex = 'f' then 'm' end

/*

salary = salary.withColumn(
    "sex",
    F.when(F.col("sex") == "m", "f")
     .when(F.col("sex") == "f", "m")
     .otherwise(F.col("sex")) 
)
*/