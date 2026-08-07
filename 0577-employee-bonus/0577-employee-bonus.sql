# Write your MySQL query statement below
/*
result_df = Employee_df.join(
        Bonus_df,
        on="empId",
        how ="left"
        ).filter(
            ((F.col("bonus") < 1000) | (F.col("bonus").isNull()))
        ).select(
          "name",
          "bonus"
        )

*/
SELECT 
    e.name, 
    b.bonus
FROM Employee e
LEFT JOIN Bonus b 
    ON e.empId = b.empId
WHERE b.bonus < 1000 OR b.bonus IS NULL;

