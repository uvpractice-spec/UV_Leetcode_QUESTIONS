# Write your MySQL query statement below
select customer_number
from Orders
group by customer_number
order by count(order_number) desc
limit 1;


/*
from pyspark.sql import functions as F
from pyspark.sql.window import Window

# Step 1 Count orders per customer
counts_df = orders_df.groupBy("customer_number").count()

# Step 2  Use dense_rank to handle ties
window_spec = Window.orderBy(F.col("count").desc())

result_df = counts_df.withColumn("rank", F.dense_rank().over(window_spec)) \
    .filter(F.col("rank") == 1) \
    .select("customer_number")
*/