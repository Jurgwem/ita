<html><head><title></title></head><body>
<h1>Berechnungen</h1>
<?php
    echo "5.3 Formeln Berechnen<br><br>";  

    echo exp(1);    //Referenz Ausgabe
    echo " (Referenz)";
    echo "<br><br>";
    echo "<table border='3px'>";
    echo "<th># an Iterationen</th><th>Zahl</th><th>Abweichung</th><th>% zur Eulerischen Zahl</th>";
   
    $abweichung = "-1";
    for ($a = 1; $abweichung < "-8.1827077541341E-5"; $a++) {
        $temp=1 + 1 / $a;   //1. Teil der Formel
        $c = $temp;
        for ($x = 1; $x < $a; $x++) {    //2. Teil der Formel (Exponent) UPDATE: Es gibt eine pow() oder "**" funktion, egal es funktioniert
            $c = $c * $temp;
        }
        $abweichung = $c - exp(1);  //Abweichung berechnen
        $prozent = $c / exp(1) * 100;   //Prozentsatz Berechnen
        $formProzent = number_format($prozent, 4, ',', '');     //Prozent auf 4 Nachkommastellen runden
        echo "<tr><td>$a.</td><td>$c</td><td>$abweichung</td><td>$formProzent%</td></tr>";
    }
    echo "</table>";
?>
</body></html>