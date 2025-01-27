<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Formulare2 - Bundespräsident</title>
</head>
<body>
    <a href="../Formulare2">Menü</a> <br>
    <h1>Aufgabe 8.5</h1>

    <?php
        if (empty($_POST["name"]) || empty($_POST["yob"]) || empty($_POST["nationality"])) {
    ?>

    <form action="Formulare2-6.php" method="post">
        <label for="name">Name:</label>
        <input type="text" name="name"> <br><br>
        <label for="yob">Geburtsdatum:</label>
        <input type="date" name="yob"> <br><br>
        <label for="nationality">Staatsangehörigkeit:</label>
        <input type="text" name="nationality"> <br><br>
        <input type="submit" value="Absenden">
    </form>

    <?php
        }
        else {
            $name = $_POST["name"];
            $yob = $_POST["yob"];
            $nationality = $_POST["nationality"];
            $allowed_k = false;
            $allowed_p = false;

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

            if ($year >= 18 && ($nationality == "Deutsch" || $nationality == "deutsch")) {
                $allowed_k = true;
            }

            if ($year >= 40 && ($nationality == "Deutsch" || $nationality == "deutsch")) {
                $allowed_p = true;
            }

            if ($allowed_k == true) {
                $daten = array($name, $yob, $nationality);
                $f = fopen("BK.csv", "a");
                fputcsv($f, $daten);
                fclose($f);
                echo $name . " kann Bundeskanzler werden <br>";;
            }
            else {
                echo $name . " kann KEIN Bundeskanzler werden <br>";
            }

            if ($allowed_p == true) {
                $daten = array($name, $yob, $nationality);
                $f = fopen("BP.csv", "a");
                fputcsv($f, $daten);
                fclose($f);
                echo $name . " kann Bundespräsident werden";
            }
            else {
                echo $name . " kann KEIN Bundespräsident werden";
            }
            $_POST["yob"] = NULL;
            echo "<form action='Formulare2-6.php'><input type='submit' value='Zurück'></form>";
        }
    ?>
</body>
</html>