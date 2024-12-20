<html><head><title></title></head><body>
<h1>Berechnungen</h1>
<?php
    echo "4.1 Jahreszinsen<br><br>";    //Aufgabe 4.1

    $a='50000'; //Start Kapital
    $b='4';     //% Zinsen Pro Jahr
    $d='5';     //# an Jahren
   
    echo "<table border='3px'>";
    echo "<th>Jahr</th><th>Kapital</th>";
    for ($x = 1; $x <= $d; $x++) {
        $c=$a*(1+$b/100);
        $format = number_format($c, 2, ',', '.');
        echo "<tr><td>$x</td><td>$format €</td></tr>";
        $a = $c;
    }
    echo "</table>";

    echo "<br><br>4.2 Monatszinsen<br><br>";    //Aufgabe 4.2

    $a='50000';     //Start Kapital
    $b='3.95';      //% Zinsen Pro Jahr
    $d='60';        //# an Monaten

    echo "<table border='3px'>";
    echo "<th>Monat</th><th>Kapital</th>";
    for ($x = 1; $x <= $d; $x++) {
        $c=$a*(1+(($b / 12)/100));  //Teilen durch 12, da der Prozentsatz po Jahr gegeben ist, wir aber in Monaten ausgeben
        $format = number_format($c, 2, ',', '.');
        echo "<tr><td>$x</td><td>$format €</td></tr>";
        $a = $c;
    }
    echo "</table>";
?>
</body></html>