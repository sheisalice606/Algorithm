-- 코드를 입력하세요

select A.animal_id, A.name
from Animal_Ins A
inner join Animal_Outs B on A.animal_id = B.animal_id
where A.datetime > B.datetime
order by A.datetime;