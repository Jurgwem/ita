<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Datum - Aktueller Wochentag</title>
</head>
<body>
    <a href="/php/Zeit">Menü</a>
    <h1>Aufgabe 6.1</h1>
    <?php
        $tage = array('Sonntag','Montag','Dienstag','Mittwoch','Donnerstag','Freitag','Samstag');
        $monate = array('','Januar','Februar','März','April','Mai','Juni','Juli','August','September','Oktober','November','Dezember');        
        $day = date("l");
        $date = date("d.m.Y");
        echo "Heute ist $day, der $date <br>";
        echo "Heute ist " . $tage[date("w")] . ", der $date";
    ?>
</body>
</html>