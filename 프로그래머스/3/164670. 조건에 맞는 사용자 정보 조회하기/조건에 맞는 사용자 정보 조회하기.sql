-- 중고 거래 게시물을 3건 이상 등록한 사용자의 사용자 ID, 닉네임, 전체주소, 전화번호 
-- 전체주소 : 시, 도로명 주소, 상세 주소  + 전화번호 

with 
Temp as (
    select
        B.writer_id
    from
        used_goods_board B
        inner join
        used_goods_user U
        on B.writer_id = U.user_id
    group by
        B.writer_id
    having
        count(B.writer_id) >= 3
)

select 
    U.user_id,
    U.nickname,
    U.city || ' ' || U.street_address1 || ' ' || U.street_address2 as 전체주소,
    substr(U.tlno, 1, 3) || '-' || substr(U.tlno, 4, 4) || '-' || substr(U.tlno, 8, 4) as 전화번호
from
    used_goods_user U
where
    U.user_id in (
        select *
        from Temp
    )
order by
    U.user_id desc