# Write your MySQL query statement below
select name
from Customer
where referee_id is null or referee_id <> 2


/*

Customer_df.filter((F.col("referee_id").isNull()) | (F.col("referee_id")!= 2)).select("name")

*/