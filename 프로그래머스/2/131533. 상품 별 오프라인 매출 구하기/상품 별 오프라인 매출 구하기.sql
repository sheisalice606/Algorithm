select 
    P.product_code, sum(P.price * O.sales_amount) as "sales"
    
from    
    product P
    inner join offline_sale O
    on P.product_id = O.product_id
    
group by
    P.product_code
    
order by
    "sales" desc, product_code;