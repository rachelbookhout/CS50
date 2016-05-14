<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("quote_form.php", ["title" => "Quote Title"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if (empty($_POST["symbol"]))
        {
            apologize("Please enter the symbol of the quote you wish to look up");
        }
        
        
        //look up the input the user gave
        $stock = lookup($_POST["symbol"]);
        
        //if the input corresponds to a stock
        if ($stock != false)
        {
            render("quote.php", ["title" => "Quote",
            "price" => $stock["price"], "name" => $stock["name"],
            "symbol" => $stock["symbol"]]);
        }
        
        else
        {
            apologize("The quote you entered is not valid. Please try again");
        }
       
    }
    
    else
    {
        render("quote_form.php", ["title" => "Quote"]);
    }

?>