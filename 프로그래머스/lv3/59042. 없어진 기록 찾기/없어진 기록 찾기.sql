-- 입양 정보는 있음, 보호소 들어온 기록은 없음

select B.animal_id, B.name
from Animal_Outs B
left outer join Animal_Ins A on B.animal_id = A.animal_id
where A.datetime is null
order by B.animal_id asc;