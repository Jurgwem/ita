<!DOCTYPE html>
<html lang="de">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Formulare2 - Lotto</title>
</head>
<body>
    <a href="./">Menü</a>
    <h1>Aufgabe 8.8</h1>

    <?php
        if (empty($_POST["age"])) {
    ?>

    <form action="Formulare2-8.php" method="post">
        <label for="age">Alter: </label>
        <input type="text" name="age">
        <input type="submit" value="Absenden">
    </form>

    <?php
        }
        else {
            $age = $_POST["age"];
            if ($age < 18 && $age > 0) {
                echo "Du bist zu Jung um Lotto zu spielen!";
                $_POST["age"] = NULL;
                echo "<form action='Formulare2-8.php'><input type='submit' value='Zurück'></form>";
            }
            else if ($age < 1 || $age > 110) {
                echo "Bitte gib ein gültiges Alter an!";
                $_POST["age"] = NULL;
                echo "<form action='Formulare2-8.php'><input type='submit' value='Zurück'></form>";
            }
            else {
                $array = array(0, 0, 0, 0, 0, 0);
                for ($i = 0; $i < 6; $i++) {
                    $number = random_int(1, 49);
                    $array[$i] = $number;
                }

                for ($i = 0; $i < 6; $i++) {
                    echo $i+1 . ". Zahl: " . $array[$i] . "<br><br>";
                }
                $_POST["age"] = NULL;
                echo "<form action='Formulare2-8.php'><input type='submit' value='Zurück'></form>";
            }
        }
    ?>
</body>
</html>