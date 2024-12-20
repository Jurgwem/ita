<!DOCTYPE html>
<html lang="en">
<head>
    <title>php - Eulersche Zahl</title>
</head>
<body>
    <a href="../mathe">Menü</a> <br>
    <h1>Aufgabe 5.1</h1>
    <?php
        echo "n muss 16609 werden, damit die ersten 4 NAchkommastellen stimmen (2.7182)";
        echo "
        <table style='text-align: center;', border='1'>
            <tr>
                <th>x</th>
                <th>Formel</th>
                <th>n</th>
            </tr>";

        $t = 100000;
        for ($n = 1; $n <= $t; $n++) {
            $x = pow(1+1/$n, $n);
            //echo "Rechnung: 1 + 1/" . $n . " <br> Lösung: " . $x . "<br><br>";
            echo "
            <tr>
                <td>$x</td>
                <td>1 + 1/$n</td>
                <td>$n</td>
            </tr>";
        }
    ?>
</body>
</html>