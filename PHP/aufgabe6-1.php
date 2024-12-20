<html><head><title></title></head><body>
<h1>Berechnungen 6.1</h1>
<?php
    $tag = date("l");
    $tagd = "Fehler";

    echo "Heute ist ";

    switch ($tag)
    {
        case "Monday": $tagd = "Montag"; break;
        case "Tuesday": $tagd = "Dienstag"; break;
        case "Wednesday": $tagd = "Mittwoch"; break;
        case "Thursday": $tagd = "Donnerstag"; break;
        case "Friday": $tagd = "Friday"; break;
        case "Saturday": $tagd = "Samstag"; break;
        case "Sunday": $tagd = "Sonntag"; break;
        default: $tagd = "Fehler"; break;
    }
    echo $tagd;
?>
</body></html>