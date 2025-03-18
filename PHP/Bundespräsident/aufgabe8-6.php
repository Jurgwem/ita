<!DOCTYPE html>
<head>
    <title>8.6 - Bundespräsident</title>
</head>
<body>
    <h1>Aufgabe 8.6</h1>

    <?php
        if (empty($_POST["name"]) || empty($_POST["yob"]) || empty($_POST["nationality"])) {
    ?>

    <form action="aufgabe8-6.php" method="post">
        <p>Bitte Name eingeben:</p>
            <input type="text" name="name"> <br><br>
        <p>Bitte Alter angeben:</p>
            <input type="radio" id="age1" name="yob" value="<18">
            <input type="radio" id="age2" name="yob" value="18-39">
            <label for="age1">Unter 18</label><br>
            <label for="age2">18 - 39</label><br>  
            <input type="radio" id="age3" name="yob" value=">40">
            <label for="age3">Über 40</label><br><br>
        <p>Bitte Nationalität angeben:</p>
            <input type="radio" id="nat1" name="nationality" value="ist Deutsch">
            <label for="nat1">hat die deutsche Staatsbürgerschaft</label><br>
            <input type="radio" id="nat2" name="nationality" value="ist nicht Deutsch">
            <label for="nat2">hat nicht die deutsche Staatsbürgerschaft</label><br><br>
        <input type="submit" value="Absenden">
        <br><br><br>
        <a href="kand.php">Liste</a>
    </form>
    <?php
        }
        else {
            $name = $_POST["name"];
            $yob = $_POST["yob"];
            $nationality = $_POST["nationality"];
            $allowed_k = false;
            $allowed_p = false;

            if (($yob == ">40" || $yob == "18-39") && $nationality == "ist Deutsch") {
                $allowed_k = true;
            }

            if ($yob == ">40" && $nationality == "ist Deutsch") {
                $allowed_p = true;
            }

            if ($allowed_k == true) {
                $daten = array($name, $yob, $nationality);
                $f = fopen("BK.csv", "a");
                fputcsv($f, $daten);
                fclose($f);
                echo $name . " kann Bundeskanzler werden <br>";;
            }
            else {
                echo $name . " kann KEIN Bundeskanzler werden <br>";
            }

            if ($allowed_p == true) {
                $daten = array($name, $yob, $nationality);
                $f = fopen("BP.csv", "a");
                fputcsv($f, $daten);
                fclose($f);
                echo $name . " kann Bundespräsident werden";
            }
            else {
                echo $name . " kann KEIN Bundespräsident werden";
            }
            $_POST["yob"] = NULL;
            echo "<form action='aufgabe8-6.php'><input type='submit' value='Zurück'></form>";
        }
    ?>
</body>
</html>