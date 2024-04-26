-- 2021년에 가입한 전체 회원들 중 상품을 구매한 회원의 // 수와 비율
-- 연,월 별로 출력하라
-- 비율은 소수점 두번째 자리에서 반올림 : 즉, 한자리

-- 나이 and 성별은 null 가능하다.

with
temp as(
    select *
    from   user_info
    where  to_char(joined, 'yyyy') = '2021'
),
temp2 as(
    select 
        to_number(to_char(O.sales_date, 'yyyy')) as year,
        to_number(to_char(O.sales_date, 'mm')) as month,
        count(distinct T.user_id) as purchased_users
    from 
        temp T
        inner join
        online_sale O
        on T.user_id = O.user_id
    group by
        to_number(to_char(O.sales_date, 'yyyy')),
        to_number(to_char(O.sales_date, 'mm'))
),
temp3 as(
    select count(T.user_id) as total
    from temp T
)

select 
    year,
    month,
    purchased_users,
    round((
        select purchased_users/total
        from temp3 T3
    ), 1) as purchased_ratio
from temp2 T
order by
    year asc,
    month asc
    ;




