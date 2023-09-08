-- 아직 입양을 못간 동물 : 입양 데이터가 없음

select C2.name, C2.datetime
from ( 
    select A2.name, A2.datetime
    from Animal_Ins A2 
    left outer join Animal_Outs B2 on A2.animal_id = B2.animal_id 
    where B2.animal_id is null 
    order by A2.datetime asc
) C2
where rownum <= 3;
    