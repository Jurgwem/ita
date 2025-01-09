<!DOCTYPE html>
<html lang="de">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Formulare - Alter in Tagen, Monaten und Jahren</title>
</head>
<body>
    <a href="../Formulare2">Menü</a> <br>
    <h1>Aufgabe 8.3</h1>

    <?php
        if (empty($_POST["name"]) || empty($_POST["yob"])) {
    ?>

    <form action="Formulare2-3.php" method="post">
        <label for="name">Name:</label>
        <input type="text" name="name"> <br><br>
        <label for="yob">Geburtsdatum:</label>
        <input type="date" name="yob"> <br><br>
        <input type="submit" value="Absenden">
    </form>

    <?php
        }
        else {
            $year = $_POST["yob"];
            $year = substr($year, 0, -6);
            $year = date("Y") - $year;

            $month = $_POST["yob"];
            $month = substr($month, 5, -3);
            $month = date("m") - $month;

            $day = $_POST["yob"];
            $day = substr($day, 8);
            $day = date("d") - $day;

            if ($day < 0) {
                $month--;
                $day *= -1;
            }

            if ($month < 0) {
                $year--;
                $month += 12;
            }
            echo $_POST["name"] . " ist " . $year . " Jahre, " . $month . " Monate und " . $day . " Tage alt";
            $_POST["yob"] = NULL;
            echo "<form action='Formulare2-3.php'><input type='submit' value='Zurück'></form>";
        }
    ?>
</body>
</html>