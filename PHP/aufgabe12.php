<html><head><title></title></head><body>
<h1>Counter - Seitenaufrufe zählen</h1>
<?php
    $counter_file="data/counterAufgabe12.txt";
    if (!file_exists($counter_file))
        { exec ("/bin/echo 1 > $counter_file"); }
    $fp=fopen($counter_file, "r+");
    $count=fgets($fp,10);
    if (!isset($_COOKIE["timer"]))
    {
        $count +=1;
        fseek ($fp, 0);
        fwrite($fp, $count, 10);
    } else
    {
        echo ("Sie müssen 5 sekunden warten, um den Counter zu erhöhen<br>");
    }
    fclose($fp);
    echo ("Du bist der $count. Besucher");
    
    setcookie ("timer", "ich war hier", time()+5);
?>
</body></html>