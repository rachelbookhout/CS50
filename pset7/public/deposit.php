<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("deposit_form.php", ["title" => "Deposit Form"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        
     //check that the input is a number
     if (preg_match("/^\d+$/", $_POST["deposit"]) == false)
     {
         apologize("You can only deposit postive numbers");
     }

     //add money to balance
     CS50:: query("UPDATE users SET cash = cash + ? where id = ?",
            $_POST["deposit"], $_SESSION["id"]);
            
            
    $updated_balance = CS50:: query("SELECT cash FROM users where id = ?",
                        $_SESSION["id"]);       
     
     //add it in transaction history
    CS50::query("INSERT INTO history (user_id, symbol, price, shares, created_at, bought, sold, balance)
                        Values (?,?,?,?,NOW(),false,false, ?)",
                        $_SESSION["id"],"Deposit",$_POST["deposit"],null, $updated_balance[0]["cash"]);      
     
    
     //go to transaction history
     redirect("history.php");

    }
    
    else
    {
        render("deposit_form.php", ["title" => "Deposit"]);
    }

?>