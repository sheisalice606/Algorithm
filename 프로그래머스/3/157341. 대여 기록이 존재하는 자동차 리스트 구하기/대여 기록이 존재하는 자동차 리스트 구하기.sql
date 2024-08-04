-- 자동차 종류가 '세단'
-- 10월에 대여를 시작한 기록이 있음


with
Temp as (
    select
        distinct(C.car_id)
    from
        car_rental_company_car C
        inner join
        car_rental_company_rental_history H
        on C.car_id = H.car_id
        and C.car_type = '세단'
        and H.start_date 
        between DATE '2022-10-01' and DATE '2022-10-31'
)

select 
    *
from
    Temp T
order by
    car_id desc
