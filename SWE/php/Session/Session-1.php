<?php session_start(); ?>

<!DOCTYPE html>
<html lang="de">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Session - Passwortabfrage</title>
</head>
<body>
    <a href="../Session">Menü</a>
    <h1>Aufgabe 23</h1>

    <?php if (!isset($_POST["pass"])) { ?>
    <form action="Session-1.php" method="post">
    <label for="pass">Passwort:</label>
        <input type="password" name="pass" id=""> <br> <br>
        <input type="submit" value="Absenden">
    </form>

    <?php
        }
        else {
            $_SESSION["pass"] = htmlentities($_POST["pass"]);
            echo "Erfolgreich Angemeldet<br>";
            echo "<a href='Seite1.php'>Seite 1</a><br>";
            echo "<a href='Seite2.php'>Seite 2</a>";
        }
    ?>
</body>
</html>