# Write your MySQL query statement below
select product_name,year,price from product pd join sales s
on pd.product_id=s.product_id; 