<html><head><title>QR-Code-Lotto</title>
<style>
@media print {
    #num {
        display: none !important;
    }
}
</style>
</head><body>
<?php
    $debug = 1;
    $result = "Lotto - QR-Code\n\n";
    if ($debug == 1) 
    {
        echo "<div id='num'>";
        echo "<h1>Lotto - QR-Code</h1>";
        echo "<font size='100'>";
        echo "Lottozahlen, aber als QR-Code<br><br>";    //Aufgabe 4.1
    }
    $array = [0, 0, 0, 0, 0, 0, 0]; //pos 6 = Glückszahl
    $exists = false;

    for ($i = 0; $i <= 6; $i++)
    {
        do{
            $exists = false;
            $var = random_int(1, 49);
            for ($k = 0; $k <= 6; $k++)
            {
                if ($array[$k] == $var)
                {
                    $exists = true;
                }
            }
        } while ($exists);
        $array[$i] = $var;
    }
    sort($array);
    for ($k = 0; $k <= 6; $k++)
    {
        if ($k != 6)
        {
            if ($debug == 1) echo $k + 1, ". Zahl: ", $array[$k], "<br>";
            $result .= ($k + 1 . ". Zahl: " . $array[$k] . "\n");
        }
        else 
        {
            if ($debug == 1) echo "Superzahl: ", $array[$k], "<br>";
            $result .= ("Superzahl: " . $array[$k] . "\n");
        }
    }
    echo "</div>";

    include "qrlib.php";   


    QRcode::png($result, "temp/lotto.png", "H", 10, 2);  
    echo '<img src="temp/lotto.png">';
?>
</body></html>