<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("sell_form.php", ["title" => "Sell Stock"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if (empty($_POST["symbol"]))
        {
            apologize("Please enter the symbol of the quote you wish to sell");
        }
        
        $query = CS50:: query("SELECT * from users where id = ?",
                        $_SESSION["id"]);
        $current_balance = $query[0]["cash"];                
        $stock = lookup($_POST["symbol"]);
        $corrected_symbol = strtoupper($_POST["symbol"]);

        if ($stock != false)
        {
            $shares = CS50:: query("SELECT * from portfolios where user_id = ? AND symbol = ?",
                $_SESSION["id"], $corrected_symbol);
                
             if (empty($shares))
             {
                 apologize("You don't any shares of this stock to sell");
             }   
            
            //remove stock from portfolio
            CS50:: query("DELETE from portfolios where user_id = ? and symbol = ?",
                $_SESSION["id"], $corrected_symbol);
            
            //update moneyes
            $num = $shares[0]["shares"];
            $money = number_format($stock["price"] * $num, 2);
            CS50:: query("UPDATE users SET cash = cash + ? where id = ?",
                $money, $_SESSION["id"]);
            
            //update the transaction log
            CS50:: query("INSERT INTO history (user_id, symbol,price, shares, created_at, bought, sold, balance)
            Values (?,?,?,?,NOW(),false,true,?)",
            $_SESSION["id"],$corrected_symbol,$stock["price"],$num, $current_balance + $money);            
                        
            //redirect to index
            redirect("index.php");
        }
        
        else
        {
            apologize("The quote you entered is not valid. Please try again");
        }
       
    }
    
    else
    {
        render("sell_form.php", ["title" => "Sell Stock"]);
    }

?>