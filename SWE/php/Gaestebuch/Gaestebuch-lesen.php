<!DOCTYPE html>
<html lang="de">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Gästebuch - daten</title>
</head>
<body>
    <a href="../Gaestebuch">Menü</a>
    <?php
        $file = file("gaeste.txt");
        echo "<h1>Gästebuch</h1><hr>";
        echo "<form action='Gaestebuch-del.php' method='post'><input type='submit' value='Nuke'></form><br>";

        $file = array_reverse($file);
        foreach ($file as $f) {
            echo $f;
        }
    ?>
</body>
</html>