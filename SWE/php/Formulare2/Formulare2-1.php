<html>
<head>
    <title>php - Zinsberechnung mit Input</title>
</head>
<body>
    <a href="../Formulare2">Menü</a> <br>
    <h1>Aufgabe 8.1</h1>

    <?php
        if (empty($_POST["kapital"])) {
    ?>

        <form action="Formulare2-1.php" method="post">
            <label for="kapital">Kapital:</label>
            <input type="number" name="kapital" size="20">
            <input type="submit" value="Berechnen">
        </form>

    <?php
        }
        else {
            $k = $_POST["kapital"];
            $z = 4/100;
            $t = 5;
            $e = $k;

            echo "<br>";
            echo "<p>Kapital: " . $k . "</p>";
            echo "<p>Zinssatz: " . $z . "</p>";
            echo "<p>Zeitraum: " . $t . " Jahre</p>";
            echo "<br>";

            echo "
            <table border='1'>
                <tr>
                    <th>Jahr</th>
                    <th>Kapital</th>
                </tr>";
                for ($i = 1; $i <= 5; $i++) {
                    $e = $k * pow(1 + $z, $i);
                    echo "
                    <tr>
                    <td>$i</td>
                    <td>$e</td>
                    </tr>";
                }
            echo "</table>";

            $e = $k;

            for ($i = 1; $i <= 5; $i++) {
                $e = $k * pow(1 + $z, $i);
                echo "<p>Endkapital Jahr " . $i . ": " . $e . "</p>";
            }

            $e = $k * pow(1 + $z, $t);
            echo "<br> <p>Endkapital: " . $e . "</p>";

            echo "<hr>";
        }
    ?>
</body>
</html>