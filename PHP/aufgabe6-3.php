<html><head><title></title></head><body>
<h1>Berechnungen 6.3</h1>
<?php
    $month = date("F");
    $tag = date("d");
    $intMonth = date('m');
    $monat = "Monat";
    $jahr = date("Y");
    $wochentag = date("l");
    $wtag = "0";
    $mTagAnzahl = cal_days_in_month(CAL_GREGORIAN, $intMonth, $jahr);   //Berechnung wieviele Tage der Monat hat
    $startOfMonth = "1";
    $spaltIndex = "0";
    switch($month)
    {
        case "January": $monat = "Januar"; break;
        case "February": $monat = "Februar"; break;
        case "March": $monat = "März"; break;
        case "April": $monat = "April"; break;
        case "May": $monat = "Mai"; break;
        case "June": $monat = "Juni"; break;
        case "July": $monat = "July"; break;
        case "August": $monat = "August"; break;
        case "September": $monat = "September"; break;
        case "October": $monat = "Oktober"; break;
        case "November": $monat = "November"; break;
        case "December": $monat = "Dezember"; break;
        default: $monat = "Fehler"; break;
    }
    echo "&nbsp;";
    echo $monat;
    echo " ";
    echo $jahr;
    $timestamp = mktime(0, 0, 0, $intMonth, 1, $jahr);  //Unix Zeit bis zum 1. des Monats
    $intStart = date('w', $timestamp);  //Unix Time -> Wochentag in int
    switch($intStart)   //Umstellung auf Wochenanfang Montag
    {
        case 0: $intStart = "6"; break;
        case 1: $intStart = "0"; break;
        case 2: $intStart = "1"; break;
        case 3: $intStart = "2"; break;
        case 4: $intStart = "3"; break;
        case 5: $intStart = "4"; break;
        case 6: $intStart = "5"; break;
        default: $intStart = "-1"; break;
    }
    echo "<table border='5px'>";
    echo '<th>Mo</th><th>Di</th><th>Mi</th><th>Do</th><th>Fr</th><th style="color:red;">Sa</th><th style="color:red;">So</th>';
    echo "<tr>";
    for ($x = 0; $x <= $intStart - 1; $x++)
    {
        if ($intStart == "0") break;
        $spaltIndex++;
        echo "<td>";
        echo "&nbsp;";
        echo "</td>";
    }
    $counter = 1;
    while ($counter <= $mTagAnzahl) 
    {
        echo "<td>";
        if ($counter % 7 == "0" || ($counter - 1) % 7 == "0") echo '<p style="color:red;">';    //Rote Färbung
        if ($counter == $tag) echo '<p style="color:blue;">';   //Blaue Färbung 
        echo $counter;
        echo "</td>";
        $spaltIndex++;
        if ($spaltIndex % 7 == "0") echo "</tr><tr>";   //Neue Spalte
        $counter++;
    }
    while ($spaltIndex % 7 != "0")
    {
        $spaltIndex++;
        echo "<td>";
        echo "&nbsp;";
        echo "</td>";
    }
    echo "</tr></table>";
?>
</body></html>