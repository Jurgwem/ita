<html><head><title></title></head><body>
<h1>Counter - Seitenaufrufe zählen</h1>
<?php
    $ip = getenv('REMOTE_ADDR');
    $counter_file="data/counterAufgabe13.txt";
    if (!file_exists($counter_file))
    { 
        exec ("/bin/echo 1 > $counter_file"); 
        $fp=fopen($counter_file, "r+");
        fseek($fp, 0, SEEK_END);
        fwrite($fp, "0\n\nIP-Adressen:\n");
        fclose($fp);
    }
    $fp=fopen($counter_file, "r+");
    $count=fgets($fp,10);
    if (!isset($_COOKIE["ip_log"]))
    {
        $count +=1;
        fseek ($fp, 0);
        fwrite($fp, $count, 10);
        fseek($fp, 0, SEEK_END);
        fwrite($fp, $ip);
        fwrite($fp, "\n");
        echo ("Ihre IP-Adresse wurde geloggt: $ip<br>");
    } else
    {
        echo ("Sie waren schonmal hier<br>");
    }
    fclose($fp);
    echo ("Du bist der $count. Besucher<br><br>");

    setcookie ("ip_log", "ich war hier, aber als IP", time()+3600);
?>
</body></html>