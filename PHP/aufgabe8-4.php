<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
</head>
<body>
    <h1>Aufgabe 8.4</h1>
    <?php
        if (empty($_POST["number"])) {
    ?>

    <form action="aufgabe8-4.php" method="post">
        <label for="number">Anzahl:</label>
        <input type="number" name="number"> <br><br>
        <input type="submit" value="Berechnen">
    </form>

    <?php
        }
        else {
            $number = $_POST["number"];
            $price = 10;
            $discount = 0.0;
            $delivery = 4;
            $mwst = 0.19;
            $netto = 0;
            $skonto = 0;


            if ($number < 10) {
                echo "Anzahl zu gering, um zu bestellen bitte mehr eingeben";
            }
            if ($number > 50) {
                $delivery = 8;
                $discount = 0.08;
            }
            if ($number > 100) {
                $delivery = 15;
                $discount = 0.12;
            }
            if ($number > 500) {
                $delivery = 0;
                $discount = 0.25;
            }

            $netto = $price * $number;
            $netto -= $netto * $discount;
            $mwst = ($netto + $delivery) * $mwst;
            $sum = $netto + $delivery + $mwst;
            $skonto = $sum * 0.03;


            echo "
            <table border='3px'>
                <thead>
                    <tr>
                        <th>Anzahl</th>
                        <th>Einzelpreis</th>
                        <th>Rabatt</th>
                        <th>Nettobetrag</th>
                        <th>Versand</th>
                        <th>MwSt</th>
                        <th>Gesamtbetrag</th>
                        <th>Skontobetrag</th>
                    </tr>
                </thead>
                <tbody>
                    <tr>
                        <td>" . $number . "</td>
                        <td>" . $price . " €</td>
                        <td>" . $discount*100 . "%</td>
                        <td>" . $netto . " €</td>
                        <td>" . $delivery . " €</td>
                        <td>" . $mwst . " €</td>
                        <td>" . $sum . " €</td>
                        <td>" . $skonto . " %</td>
                    </tr>
                </tbody>
            </table> <br>";
        }
    ?>
</body>
</html>