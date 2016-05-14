<?php

    // configuration
    require("../includes/config.php"); 

    //get the user's balance  
    $total = CS50:: query( "SELECT cash FROM users where id = ?",
        $_SESSION["id"]);
    
    $balance = number_format($total[0]["cash"],2);
    
    // get the user's portfolio
    $data = CS50:: query("SELECT symbol, shares FROM portfolios where user_id = ?",
                $_SESSION["id"]);
    
    $portfolio = [];
   
   //iterate through the portfolio and print out the indivudal shares
    foreach ($data as $row)
    {
        $stock = lookup($row["symbol"]);
        
        if ($stock !== false)
        {
            $portfolio[] = [
                "name" => $stock["name"],
                "price" => number_format($stock["price"],2),
                "shares" => $row["shares"],
                "symbol" => $row["symbol"]
                ];
        }
    }
    
    render("portfolio.php", ["title" => "Portfolio", "portfolio" => $portfolio, "balance" => $balance]);
    
?>
