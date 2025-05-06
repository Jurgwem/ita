<html>
    <head>
        <title>QR-Code-Lotto</title>
        <style>
            @media print {
                .numbers {
                    display: none;
                }
            }
        </style>
    </head>
<body>
<?php
    $result = "Lotto - QR-Code\n\n";
    $array = [0, 0, 0, 0, 0, 0, 0]; //pos 6 = Superzahl
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
            $result .= ($k + 1 . ". Zahl: " . $array[$k] . "\n");
        }
        else 
        {
            $result .= ("Superzahl: " . $array[$k] . "\n");
        }
    }

    $PNG_TEMP_DIR = dirname(__FILE__).DIRECTORY_SEPARATOR.'temp'.DIRECTORY_SEPARATOR;
    $PNG_WEB_DIR = 'temp/';

    include "qrlib.php";   

    if (!file_exists($PNG_TEMP_DIR))
    {
        mkdir($PNG_TEMP_DIR);
    }

    $filename = $PNG_TEMP_DIR.'Lotto.png';

    QRcode::png($result, $filename, "H", 10, 2);  
    echo '<img src="'.$PNG_WEB_DIR.basename($filename).'" /><br>';
    echo "<div class='numbers'>";
    echo "<h3>Lottozahlen: </h3>";
    for ($i = 0; $i < 7; $i++) {
        if ($i != 6) echo $i+1 . ". Zahl: ";
        else echo "Superzahl: ";
        echo "<b>" . $array[$i] . "</b>" . " | ";
    }
    echo "</div>";
    
?>
</body></html>