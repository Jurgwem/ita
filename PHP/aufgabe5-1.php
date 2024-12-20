<html><head><title></title></head><body>
<h1>Berechnungen</h1>
<?php
    echo "5.1 Formeln Berechnen<br><br>";

    $n = '25000'; //# an Iterationen

    echo "Man benötigt 16609 Stellen (?)";
    echo "<br>";
    echo exp(1);    //Referenz Ausgabe
    echo " (Referenz)";
    echo "<br><br>";
    echo "<table border='3px'>";
    echo "<th># an Iterationen</th><th>Zahl</th>";
   
    for ($a = 1; $a <= $n; $a++) {
        $temp=1 + 1 / $a;       //1. Teil der Formel
        $c = $temp;     
        for ($x = 1; $x < $a; $x++) {   //2. Teil der Formel (Exponent) UPDATE: Es gibt eine pow() oder "**" funktion, egal es funktioniert
            $c = $c * $temp;
        }
        echo "<tr><td>$a.</td><td>$c</td></tr>";
    }
    echo "</table>";
?>
</body></html>