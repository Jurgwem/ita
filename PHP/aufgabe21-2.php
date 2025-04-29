<html><head><title></title></head><body>
<h1>21.1 - QR-Code Telefonnummer</h1>
<?php
    $text = file("data/gg.txt");

    include("qrlib.php");

    QRcode::png(implode($text), "temp/gg.png", "H", 10, 2);  
    //Shit doesnt work because tooooo big
    echo '<img src="temp/gg.png">'; 

    echo "<br><br><br>";
    echo implode($text);
?>
</body></html>