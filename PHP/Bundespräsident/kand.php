<!DOCTYPE html>
<html lang="de">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Formulare2 - Bundeskanzler2</title>
</head>
<a href="aufgabe8-6.php">Eintragen</a>
<body>
    <?php
        $name = "Test";
        $yob = "Test";
        $nationality = "Test";

        echo "<h2>Kandidaten Bundeskanzler</h2>";

        $f = fopen("BK.csv", "r");
        echo "<table border='3px'><tr><th>Name</th><th>Alter</th><th>Staatsangehörigkeit</th></tr>";
        while (($data = fgetcsv($f, 100)) !== false) {
            $num = count($data);
            echo "<tr>";
            echo "<td>" . $data[0] . "</td>";
            echo "<td>" . $data[1] . "</td>";
            echo "<td>" . $data[2] . "</td>";
           echo "</tr>";
        }
        fclose($f);
        echo "</table>";

        echo "<h2>Kandidaten Bundespräsident</h2>";

        $f = fopen("BP.csv", "r");
        echo "<table border='3px'><tr><th>Name</th><th>Alter</th><th>Staatsangehörigkeit</th></tr>";

        while (($data = fgetcsv($f, 100)) !== false) {
            $num = count($data);
            echo "<tr>";
            echo "<td>" . $data[0] . "</td>";
            echo "<td>" . $data[1] . "</td>";
            echo "<td>" . $data[2] . "</td>";
        }
        fclose($f);
        echo "</table>";
    ?>
</body>
</html>