<?php
    session_start();
?>
<html><head><title>Sessions</title>
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
</head>
<body>
    <h1>Aufgabe 23 - Sessions (Unterseite)</h1>
    <?php
        if ($_SESSION["passwd"] != "Test") {
    ?>
    <h1>Falsches Passwort!</h1>
    <?php
        } 
        else {
            echo "Du bist drinne";
        }
    ?>
    <br><br>
    <a href="aufgabe23.php">Zurück und Session beenden</a>
</body>
</html>