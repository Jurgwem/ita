<!DOCTYPE html>
<html lang="de">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Formulare2 - Bundeskanzler2</title>
</head>
<body>
    <?php
        $name = "Test";
        $yob = "Test";
        $nationality = "Test";
        echo "<h2>Kandidaten Bundeskanzler</h2>";

        $f = fopen("BK.csv", "r");
        while (($data = fgetcsv($f, 100)) !== false) {
            $num = count($data);
            echo "Name: <b>" . $data[0] . "</b><br>";
            echo "Geburtsdatum: <b>" . $data[1] . "</b><br>";
            echo "Staatsangehörigkeit: <b>" . $data[2] . "</b><br>";
            echo "<br><br>";  
        }
        fclose($f);

        echo "<h2>Kandidaten Bundespräsident</h2>";
        $f = fopen("BP.csv", "r");
        while (($data = fgetcsv($f, 100)) !== false) {
            $num = count($data);
            echo "Name: <b>" . $data[0] . "</b><br>";
            echo "Geburtsdatum: <b>" . $data[1] . "</b><br>";
            echo "Staatsangehörigkeit: <b>" . $data[2] . "</b><br>";
            echo "<br><br>";  
        }
        fclose($f);
    ?>
</body>
</html>