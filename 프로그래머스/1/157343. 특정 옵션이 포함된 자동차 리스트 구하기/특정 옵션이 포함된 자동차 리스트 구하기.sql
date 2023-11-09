-- 코드를 입력하세요
select 
    C.car_id, 
    C.car_type, 
    C.daily_fee, 
    C.options

from 
    car_rental_company_car C

where 
    C.options like '%네비게이션%'

order by C.car_id desc

    
