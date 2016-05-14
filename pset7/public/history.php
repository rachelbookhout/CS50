<?php

    require("../includes/config.php");  
    
   //get all of the users transactions
    $transactions = CS50:: query("SELECT * from history where user_id = ? ORDER BY created_at DESC",
                    $_SESSION["id"]);
    
    //get the user's balance
    $total = CS50:: query( "SELECT cash FROM users where id = ?",
        $_SESSION["id"]);
    
    $balance = number_format($total[0]["cash"],2);
    
    render("history_record.php", ["title" => "Stock History", "transactions" => $transactions, "balance" => $balance]);
?>