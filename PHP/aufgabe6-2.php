<html><head><title></title></head><body>
<h1>Berechnungen 6.2</h1>
<?php
    $uhr = date("H:i");
    $uhrzeit = "Fehler";

    echo "$uhr";
    echo "<br>";

    if ($uhr >= "06:00" && $uhr < "12:00")
    {
        $uhrzeit = "Guten Morgen!";
    }
    if ($uhr >= "12:00" && $uhr < "18:00")
    {
        $uhrzeit = "Guten Tag!";
    }
    if ($uhr >= "18:00" && $uhr < "23:00")
    {
        $uhrzeit = "Guten Abend!";
    }
    if ($uhr >= "23:00" && $uhr < "06:00")
    {
        $uhrzeit = "Guten Nacht!";
    }
  
    echo $uhrzeit;
?>
</body></html>