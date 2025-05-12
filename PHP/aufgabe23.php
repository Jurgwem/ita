<?php
    session_start();
    if (empty($_SESSION["passwd"]) or $_SESSION["passwd"] == "Test")
    {
        $_SESSION["passwd"] = "dummy";
    }
?>
<html><head><title>Sessions</title>
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
</head>
<body>
    <h1>Aufgabe 23 - Sessions</h1>
    <?php
        if (empty($_POST["pass"])) {
    ?>
    <form action="aufgabe23.php" method="post" >
    Passwort: 
    <input type="password" name="pass" size="20" required>
    <input type="submit" value="Absenden">
    <?php
        } 
        else {
            $_SESSION["passwd"] = $_POST["pass"];
            echo "Passwort wurde eingegeben!";
        }
    ?>
    <br><br>
    <a href="aufgabe23-unterseite.php">Unterseite</a>
</body>
</html>