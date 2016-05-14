<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("buy_form.php", ["title" => "Buy Stock"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if (empty($_POST["symbol"]))
        {
            apologize("Please enter the symbol of the quote you wish to buy");
        }
        
        if (empty($_POST["symbol"]))
        {
            apologize("Please enter the number of shares you would like to buy");
        }
        
         if (!is_numeric($_POST["shares"]) || !preg_match("/^\d+$/", $_POST["shares"]))
        {
            apologize("Number of shares needs to be numeric");
        } 
        
        $stock = lookup($_POST["symbol"]);

        if ($stock != false)
        {
            
            $value = number_format($stock["price"],2);
            
            //check user's balance and make sure they have enough to buy the shares they want
            $total = CS50:: query("SELECT cash FROM users where id = ?",
                        $_SESSION["id"]);
            $balance = $total[0]["cash"];
            $purchase = number_format($value * $_POST["shares"],2);            
            
    
            if ($balance > $purchase)
            {
                //add stocks to portfolio
                $corrected_symbol = strtoupper($_POST["symbol"]);
                CS50:: query("INSERT INTO portfolios (user_id, symbol, shares) VALUES(?, ?, ?) 
                        ON DUPLICATE KEY UPDATE shares = shares + VALUES(shares)", 
                        $_SESSION["id"], $corrected_symbol, $_POST["shares"]);
            
                //update user's cash
                CS50:: query("UPDATE users SET cash = cash - ? WHERE id = ?", 
                            $purchase, $_SESSION["id"]);
                 
                 $new_balance = CS50:: query("SELECT cash FROM users where id = ?",
                        $_SESSION["id"]);
                        
                //update the transaction log
                CS50:: query("INSERT INTO history (user_id, symbol,price, shares, created_at, bought, sold, balance)
                        Values (?,?,?,?,NOW(),true,false,?)",
                        $_SESSION["id"], $corrected_symbol,$value,$_POST["shares"],$new_balance[0]["cash"]);  
        
                
            }
            else
            {
                apologize("You don't have enough money to purchase this stock as this quanity");
            }
          
            
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
        render("buy_form.php", ["title" => "Buy Stock"]);
    }

?>