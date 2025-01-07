<html><head><title></title></head><body>
<h1>7.1 und 8.1 Zinsrechner</h1>
<?php
if (empty($_POST["zinsen"]) || empty( $_POST["kapital"])) {
?>
    Geben Sie Ihren Daten ein:
    <form action="aufgabe7-1und8.1.php" method="post" >
    Zinssatz: <input type="text" name="zinsen" size="20"><br>
    Startkapital: <input type="text" name="kapital" size="20">
    <input type="submit" value="Absenden">
    </form>
<?php
}
else {
    echo "4.1 Jahreszinsen<br><br>";    //Aufgabe 4.1

    $a=$_POST["kapital"]; //Start Kapital
    $b=$_POST["zinsen"];     //% Zinsen Pro Jahr
    $d='5';     //# an Jahren
   
    echo "Ihr Zinssatz beträgt: ";
    echo $b;
    echo "<br>";
    echo "Ihr Startkapital beträgt: ";
    echo $a;
    echo "<br>";
    echo "<table border='3px'>";
    echo "<th>Jahr</th><th>Kapital</th>";
    for ($x = 1; $x <= $d; $x++) {
        $c=$a*(1+$b/100);
        $format = number_format($c, 2, ',', '.');
        echo "<tr><td>$x</td><td>$format €</td></tr>";
        $a = $c;
    }
    echo "</table>";
}
?>
</body></html>