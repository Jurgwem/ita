<!DOCTYPE html>
<html lang="de">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Formulare2 - Lotto</title>
</head>
<body>
    <a href="./">Menü</a>
    <h1>Aufgabe 8.7</h1>
    <?php
        $array = array(0, 0, 0, 0, 0, 0);
        for ($i = 0; $i < 6; $i++) {
            $number = random_int(1, 49);
            $array[$i] = $number;
        }

        for ($i = 0; $i < 6; $i++) {
            echo $i+1 . ". Zahl: " . $array[$i] . "<br><br>";
        }
    ?>
</body>
</html>