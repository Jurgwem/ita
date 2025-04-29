<html><head><title></title></head><body>
<h1>21.1 - QR-Code Telefonnummer</h1>
<?php
if (empty($_POST["tel"])) {
?>
    Geben Sie eine Telefonnummer ein:
    <form action="aufgabe21-1.php" method="post" >
    Telefonnummer: 
    <input type="text" name="tel" size="20" required><br>
    <input type="submit" value="Absenden">
    </form>
<?php
}
else
{
    $tel = "tel:" . $_POST["tel"];
    if (is_numeric($_POST["tel"]))
    {
        include "qrlib.php";   

        //QR-Code wird generiert in /temp/telefon.png mit einem ECC Level von "H" (High) und einer Größe von 10
        QRcode::png($tel, "temp/telefon.png", "H", 10, 2);  
        //QR-Code wird ausgegeben
        echo '<img src="temp/telefon.png">'; 
    }
    else
    {
        echo "Bitte geben Sie eine gültige Telefonnummer ein (ohne Leerzeichen)";
    }
        
};
?>
</body></html>