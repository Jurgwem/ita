<html><head><title></title></head><body>
<h1>Berechnungen</h1>
<?php
    echo "5.4 Formeln Berechnen<br><br>";  

    $x = '20'; //# an Iterationen
    $c = '1'; //Startwert
    $t = '1';   //Define Variabel weil gründe

    echo exp(1);    //Referenz Ausgabe
    echo " (Referenz)";
    echo "<br><br>";
    echo "<table border='3px'>";
    echo "<th>Anzahl an Iterationen</th><th>Zahl</th>";
   
    for ($a = 1; $a <= $x; $a++) {
        if ($a != 1) {
            $t = '1';
            for ($y = 2; $y <= $a; $y++) {
                $t = $t * $y;
            }
        }
        $c = $c + (1 / $t);
        echo "<tr><td>$a.</td><td>$c</td>";
    }
    echo "</table>";
?>
</body></html>