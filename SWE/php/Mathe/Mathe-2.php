<!DOCTYPE html>
<html lang="en">
<head>
    <title>php - Zinsberechnung 2</title>
</head>
<body>
    <a href="../mathe">Menü</a> <br>
    <h1>Aufgabe 4.2</h1>
    <?php
        $k = 50000;
        $z = 3.95/100;
        $t = 60;
        $e = $k;

        echo "<br>";
        echo "<p>Kapital: " . $k . "</p>";
        echo "<p>Zinssatz: " . $z*100 . "</p>";
        echo "<p>Zeitraum: " . $t . " Monate</p>";
        echo "<br>";

        echo "
        <table border='1'>
            <tr>
                <th>Monat</th>
                <th>Kapital</th>
            </tr>";
            for ($i = 1; $i <= 5; $i++) {
                $e = $k * pow(1 + $z/12, $i);
                echo "
                <tr>
                <td>$i</td>
                <td>$e</td>
                </tr>";
            }
        echo "</table>";

        $e = $k;
        for ($i = 1; $i <= 5; $i++) {
            $e = $k * pow(1 + $z/12, $i);
            echo "<p>Endkapital Monat "  . $i . ": " . $e . "</p>";
        }
        $e = $k * pow(1 + $z/12, $t);
        echo "<br> <p>Endkapital: $e </p>";
        echo "<hr>";
    ?>
</body>
</html>