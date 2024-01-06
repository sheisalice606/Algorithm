-- INGREDIENT_TYPE에는 아이스크림의 주 성분이 설탕이면 sugar_based라고 입력되고
-- 아이스크림의 주 성분이 과일이면 fruit_based라고 입력됩니다.

select 
    I.ingredient_type, sum(F.total_order) as total_order

from 
    first_half F
    inner join icecream_info I
    on F.flavor = I.flavor

group by
    I.ingredient_type;
    
