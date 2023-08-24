select car_id, round(avg(end_date - start_date + 1), 1) as AVERAGE_DURATION
from car_rental_company_rental_history
group by car_id
having round(avg(end_date - start_date + 1), 1) > = 7
order by AVERAGE_DURATION desc, car_id desc;

