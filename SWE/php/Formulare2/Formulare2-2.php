<!DOCTYPE html>
<html lang="de">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Formulare - Alter berechnen</title>
</head>
<body>
    <a href="../Formulare2">Menü</a> <br>
    <h1>Aufgabe 8.2</h1>

    <?php
        if (empty($_POST["name"]) || empty($_POST["yob"])) {
    ?>
    <h2>Alter berechnen</h2>
    <form action="Formulare2-2.php" method="post">
        <label for="name">Name:</label>
        <input type="text" name="name"> <br>
        <label for="yob">Geburtsjahr:</label>
        <input type="number" name="yob">
        <input type="submit" value="Absenden">
    </form>

    <?php
        }
        else {
            $age = date("Y") - $_POST["yob"];
            if (($_POST["yob"] < 1900) || ($_POST["yob"] > date("Y"))) {
                echo "Das Geburtsdatum ist ungültig";
                $_POST["yob"] = NULL;
                echo "<form action='Formulare2-2.php'><input type='submit' value='Zurück'></form>";
            }
            else {
                echo "Hallo " . $_POST["name"] . ", du bist " . $age . " Jahre alt";
                $_POST["yob"] = NULL;
                echo "<form action='Formulare2-2.php'><input type='submit' value='Zurück'></form>";
            }
        }
    ?>
</body>
</html>