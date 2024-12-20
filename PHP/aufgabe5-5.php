<html><head><title></title></head><body>
<h1>Berechnungen</h1>
<?php
    echo "5.5 Formeln Berechnen<br><br>";  

    $x = '100'; //# an Iterationen

    echo pi();    //Referenz Ausgabe
    echo " (Referenz)";
    echo "<br><br>";
    echo "<table border='3px'>";
    echo "<th>Anzahl an Iterationen</th><th>Zahl</th>";
   
    for ($a = 1; $a <= $x; $a++) {
        $result = 0;    //ergebnis  
        $sign = 1;  //vorzeichen, 1 = positiv, -1 = negativ
        $y = '1';   //arctan wert
        for ($i = 1; $i <= $a; $i++) {
            $term = $sign * pow($y, (2 * $i - 1)) / (2 * $i - 1);
            $result += $term;
            $sign *= -1;
        }
        $result *= 4;
        echo "<tr><td>$a.</td><td>$result</td>";
    }
    echo "</table>";
?>
</body></html>