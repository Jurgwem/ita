<!DOCTYPE html>
<html lang="en">
<head>
    <title>Cookies - Introseite</title>
</head>
<body>
    <a href="/php/Cookies">Menü</a> <br>
    <h1>Aufgabe 11.1</h1>

    <?php
        setcookie("Intro", "Intro bereits angeguckt", time()+604800);
        if (isset($_COOKIE["Intro"])) {
            echo "<h2>Hauptseite</h2>";
            echo "<p>Das ist die Hauptseite</p>";
        }
        else {
            echo "<h2>Introseite</h2>";
            echo "<p>Das ist die Introseite</p>";
        }
    ?>
</body>
</html>