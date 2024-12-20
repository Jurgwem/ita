<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Formulare - Passwort anzeigen</title>
</head>
<body>
<a href="/php/Formulare/Formulare-2.php">Zurück</a>
    <?php
        echo "<p>Ihr Passwort lautet " . $_POST["pswd"] . "</p>";
    ?>
</body>
</html>