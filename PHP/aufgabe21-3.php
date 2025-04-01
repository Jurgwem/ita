<html><head><title>QR-Code-Lotto</title></head><body>
<?php
    $debug = 0;
    $result = "Lotto - QR-Code\n\n";
    if ($debug == 1) 
    {
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
    if ($debug == 1) echo $result;

    $PNG_TEMP_DIR = dirname(__FILE__).DIRECTORY_SEPARATOR.'temp'.DIRECTORY_SEPARATOR;
    $PNG_WEB_DIR = 'temp/';

    include "qrlib.php";   

    if (!file_exists($PNG_TEMP_DIR))
    {
        mkdir($PNG_TEMP_DIR);
    }

    $filename = $PNG_TEMP_DIR.'telefon.png';

    QRcode::png($result, $filename, "H", 10, 2);  
    echo '<img src="'.$PNG_WEB_DIR.basename($filename).'" />';
    
?>
</body></html>