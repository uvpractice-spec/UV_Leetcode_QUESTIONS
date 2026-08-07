# Write your MySQL query statement below this is sql now
select Emp.name as Employee
from Employee Emp
inner join Employee mg
on Emp.managerId = mg.id
where Emp.salary > mg.salary

/*
from pyspark.sql import functions as F

# 1. Select only the necessary columns from the manager side before joining.
# This cuts down data payload volume during the network shuffle phase.
emp = employee_df.alias("emp")
mg = employee_df.select("id", "salary").alias("mg")

# 2. Switch to an inner join (implicit optimization from your filter)
result_df = (
    emp.join(
        mg,
        F.col("emp.managerId") == F.col("mg.id"),
        how="inner" # Changing to inner avoids unnecessary tracking of unmatched left rows
    )
    .filter(F.col("emp.salary") > F.col("mg.salary"))
    .select(F.col("emp.name").alias("Employee"))
)
*/

