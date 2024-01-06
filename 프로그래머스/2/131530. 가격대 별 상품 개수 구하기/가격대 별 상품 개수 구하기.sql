select 
    trunc(price, -4) as price_group, count(*) as products
from
    product

group by 
    trunc(price, -4)
order by 
    price_group;
    
