-- 자동차의 종류가 세단 or SUV 이다
-- 2022년 11월 1일 부터 11월 30일까지 대여 가능해야한다.
-- 30일간의 대여 금액이 50만원 이상 200만원 미만이여야 한다.
-- 위의 조건을 만족하는 자동차에 대해서 자동차ID, 자동차 종류, 대여금액 리스트를 출력하라

with
temp as (
    select 
        C.car_id,
        C.car_type,
        C.daily_fee
    from 
        car_rental_company_car C
    where 
        car_type in ('세단', 'SUV')
        and
        C.car_id not in (
            select 
                distinct(H.car_id)
            from 
                car_rental_company_rental_history H
            where
                H.start_date <= DATE '2022-11-30'
                and
                H.end_date >= DATE '2022-11-01'
        )
)

select 
    T.car_id,
    T.car_type,
    30 * T.daily_fee * ((100 - P.discount_rate) / 100) as fee
from
    car_rental_company_discount_plan P
    inner join
    temp T
    on P.car_type = T.car_type
    and P.duration_type = '30일 이상'
    and
        30 * T.daily_fee * ((100 - P.discount_rate) / 100) >= 500000
        and
        30 * T.daily_fee * ((100 - P.discount_rate) / 100) < 2000000
order by
    fee desc,
    car_type asc,
    car_id desc