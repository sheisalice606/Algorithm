-- 완료된 중고 거래의 총 금액이 70만원 이상인 사람
with
Temp as (
    select 
        B.writer_id,
        sum(B.price) as total_sales
    from
        used_goods_board B
    where
        B.status = 'DONE'
    group by
        B.writer_id
    having 
        sum(B.price) >= 700000
)

select 
    U.user_id,
    U.nickname,
    T.total_sales
from 
    Temp T
    inner join
    used_goods_user U
    on T.writer_id = U.user_id
order by
    total_sales asc
    ;