-- 조회수가 가장 높은 중고거레 개시물에 대한 첨부파일 경로

with
Temp as (
    select
        '/home/grep/src/' || B.board_id || '/' || F.file_id || F.file_name || F.file_ext as file_path
    from
        used_goods_board B
        inner join
        used_goods_file F
        on B.board_id = F.board_id
    where
        B.views = (
            select max(views)
            from used_goods_board
        )
    order by
        F.file_id desc
)

select 
    *
from
    Temp T