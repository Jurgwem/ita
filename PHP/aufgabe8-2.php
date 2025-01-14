<!DOCTYPE html>
<html lang="de">
<head>
    <meta charset="UTF-8">
    <title>Formulare - Alter berechnen</title>
</head>
<body>
    <h1>Aufgabe 8.2</h1>
    <?php
        if (empty($_POST["name"]) || empty($_POST["year"])) {
    ?>
    <h2>Alter berechnen</h2>
    <form action="aufgabe8-2.php" method="post">
        <label for="name">Name:</label>
        <input type="text" name="name"> <br>

        <label for="year">Geburtsjahr:</label>
        <input type="number" name="year">
        <input type="submit" value="Absenden">
    </form>

    <?php
        }
        else {
            $age = date("Y") - $_POST["year"];

            if (($_POST["year"] < 1920) || ($_POST["year"] > date("Y"))) {
                echo "Das Geburtsdatum ist ungültig";
            }
            else {
                echo "Hallo " . $_POST["name"] . ", du bist " . $age . " Jahre alt";
            }
        }
    ?>
</body>
</html>