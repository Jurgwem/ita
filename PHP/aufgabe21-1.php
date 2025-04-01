<html><head><title></title></head><body>
<h1>21.1 - QR-Code Telefonnummer</h1>
<?php
if (empty($_POST["tel"])) {
?>
    Geben Sie eine Telefonnummer ein:
    <form action="aufgabe21-1.php" method="post" >
    Telefonnummer: <input type="text" name="tel" size="20" required><br>
    <input type="submit" value="Absenden">
    </form>
<?php
}
else
{
    $tel = $_POST["tel"];
    if (is_numeric($tel))
    {
        //Vorarbeit für QR-Code, kopiert aus der gegebenen "index.php" aus der Library
        //Temporärer Speicherort der QR-Codes wird auf /temp/ gesetzt
        $PNG_TEMP_DIR = dirname(__FILE__).DIRECTORY_SEPARATOR.'temp'.DIRECTORY_SEPARATOR;
        $PNG_WEB_DIR = 'temp/';

        include "qrlib.php";   

        //'/temp/' wird erstellt, falls noch nicht vorhanden
        if (!file_exists($PNG_TEMP_DIR))
        {
            mkdir($PNG_TEMP_DIR);
        }

        //QR-Code-Name wird auf 'telefon.png' gesetzt unter '/temp/'
        $filename = $PNG_TEMP_DIR.'telefon.png';

        //QR-Code wird generiert in /temp/telefon.png mit einem ECC Level von "H" (High) und einer Größe von 10
        QRcode::png($tel, $filename, "H", 10, 2);  
        //QR-Code wird ausgegeben
        echo '<img src="'.$PNG_WEB_DIR.basename($filename).'" />'; 
    }
    else
    {
        echo "Bitte geben Sie eine gültige Telefonnummer ein";
    }
        
};
?>
</body></html>