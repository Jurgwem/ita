<!DOCTYPE html>
<html lang="de">
<head>
    <meta charset="UTF-8">
</head>
<body>
    <h1>Aufgabe 8.3 - Alter berechnen Teil 2</h1>

    <?php
        if (empty($_POST["name"]) || empty($_POST["datum"])) {
    ?>

    test
    <form action="aufgabe8-3.php" method="post">
        <label for="name">Name:</label>
        <input type="text" name="name"> <br><br>

        <label for="datum">Geburtsdatum:</label>
        <input type="date" name="datum"> <br><br>
        <input type="submit" value="Absenden">
    </form>

    <?php
        }
        else {
            $year = $_POST["datum"];
            $year = substr($year, 0, -6);   //substr = gibt nur einen Teil von einem String zurück (1. = ofset, 2. = länge)
            $year = date("Y") - $year;

            $month = $_POST["datum"];
            $month = substr($month, 5, -3);
            $month = date("m") - $month;

            $day = $_POST["datum"];
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
        }
    ?>
</body>
</html>