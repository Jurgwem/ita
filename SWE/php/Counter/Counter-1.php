<!DOCTYPE html>
<html lang="en">
<head>
    <title>Counter-1</title>
</head>
<body>
    <?php
        if (!isset($_COOKIE["counter_lock"])) {
            $file = "counter.txt";
            if (!file_exists($file)) {
                exec ("/bin/echo 1 > $file");
            }
            $fp = fopen($file, "r+");
            $c = fgets($fp, 10);
            $c += 1;
            fseek($fp, 0);
            fwrite($fp, $c, 10);
            fclose($fp);
            echo "Du bist der " . $c . ". Besucher";
            setcookie("counter_lock", "Nur einmal zählen", time()+86400);
        }
        else {
            $file = "counter.txt";
            if (!file_exists($file)) {
                exec ("/bin/echo 1 > $file");
            }
            $fp = fopen($file, "r");
            $c = fgets($fp, 10);
            echo "Du wurdest schon gezählt!";
            echo "Der Zählerstand ist " . $c;
        }
    ?>
</body>
</html>