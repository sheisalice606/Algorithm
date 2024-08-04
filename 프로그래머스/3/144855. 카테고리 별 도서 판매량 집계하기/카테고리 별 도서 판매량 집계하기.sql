-- 2022년 1월의 카테고리 별 도서 판매량을 합산

with
Temp as (
    select 
        B.category,
        sum(S.sales) as total_sales
    from
        book B
        inner join
        book_sales S
        on B.book_id = S.book_id
        and S.sales_date
        between DATE '2022-01-01' and DATE '2022-01-31'
    group by
        B.category
)

select *
from Temp T
order by category asc