select 
    mcdp_cd as "진료과코드", count(*) as "5월예약건수"
from
    appointment
where
    APNT_YMD BETWEEN TO_DATE('2022-05-01','YYYY-MM-DD') AND  TO_DATE('2022-05-31','YYYY-MM-DD')
group by
    mcdp_cd
order by
    "5월예약건수", mcdp_cd;
    
