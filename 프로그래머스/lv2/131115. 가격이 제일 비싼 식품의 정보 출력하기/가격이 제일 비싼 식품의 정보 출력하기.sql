select 
      P.product_id
    , P.product_name
    , P.product_cd
    , P.category
    , P.price
    from food_product P
    where P.price = ( select max(P2.price) 
                        from food_product P2 );
