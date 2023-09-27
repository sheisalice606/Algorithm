select
    B.category, sum(BC.sales) as total_sales
from book B 
inner join book_sales BC on B.book_id = BC.book_id
where BC.sales_date >= TO_DATE('2022-01-01', 'YYYY-MM-DD') 
    and BC.sales_date < TO_DATE('2022-02-01', 'YYYY-MM-DD')
group by B.category
order by B.category asc;
