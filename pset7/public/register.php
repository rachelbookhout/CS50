<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("register_form.php", ["title" => "Register"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        
       // check that the user entered a username
        if (empty($_POST["username"]))
        {
            apologize("Please provide a username to create an account");
        }
        
                
        //check that they provided a password
        else if (empty($_POST["password"]))
        {
            apologize("Please provide a password to create an account");
        }
        
        //check that they typed something in the confirmation box
        else if (empty($_POST["confirmation"]))
        {
            apologize("Please confirm your password");
        }
        
        //check that the password and password confirmation match
        else if ($_POST["confirmation"] != $_POST["password"])
        {
            apologize("Password and Password Confirmation need to match");
        }
        
        //add users to the user record
        $insert = CS50:: query( "INSERT INTO users (username, hash, cash) VALUES (?, ?, ?)", 
                    $_POST["username"], crypt($_POST["password"]), 10000.0000);

        if ($insert !== false)
        {
            $rows = CS50::query("SELECT LAST_INSERT_ID() AS id");
            
            if ($rows !== false)
            {
                $_SESSION["id"] = $rows[0]["id"];
                 redirect("index.php");
            }
            else
            {
                apologize("Unable to log in. Please try again");
            }
        }
        else
        {
            apologize("Account was not created. Please try again");
        }
    }

?>