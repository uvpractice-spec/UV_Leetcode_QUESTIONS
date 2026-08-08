# Write your MySQL query statement below

select name as Customers
from  Customers
left join Orders
on Customers.id = Orders.customerId
where Orders.customerId is null -- make sure that with left join use is null and not the = null


/* best is touse the left anti join in this case when we use the filter after the join left anti join is optimize approach if we use filter afte the join
  res_df = Cusotmers_df.join(
           Order_df,
           Customers_df["id"]==Orders_df["customerId"],
           how = "left"
        ).filter(F.col("customerId").isNull())
        .select(F.col("name").alias("Customers"))
*/