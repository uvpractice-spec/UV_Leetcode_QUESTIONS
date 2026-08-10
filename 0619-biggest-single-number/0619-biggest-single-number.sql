# Write your MySQL query statement below
with cte as
(select num
from MyNumbers
group by num
having count(num) =1)

select 
case when COUNT(*) > 0 then  max(num)
else NULL end as num
from cte

/*

window_spec = Window.partitionBy("num")

 Step 2 Filter for unique numbers and aggregate MAX directly
result_df = my_numbers_df \
    .withColumn("num_count", F.count("num").over(window_spec)) \
    .filter(F.col("num_count") == 1) \
    .select(F.max("num").alias("num"))

 Step 3 a row with NULL is returned if no single numbers exist
if result_df.isEmpty():
    final_df = spark.createDataFrame([(None,)], ["num"])
else:
    final_df = result_df
*/