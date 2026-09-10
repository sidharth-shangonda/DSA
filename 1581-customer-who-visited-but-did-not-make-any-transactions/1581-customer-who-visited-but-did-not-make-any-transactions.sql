# Write your MySQL query statement below
select customer_id ,count(*)-count(transaction_id) as count_no_trans
from Transactions tr right join Visits vi on tr.visit_id=vi.visit_id
group by customer_id 
having count_no_trans>0
order by count_no_trans;