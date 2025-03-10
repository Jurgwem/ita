<!DOCTYPE html>
<html lang="de">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="Zeit-2.css">
    <title>Datum - Begrüßung</title>
    <script src="Zeit-2.js" defer></script>
</head>
<body>
    <div class="header">
        <a href="/php/Zeit">Menü</a>
        <h1>Aufgabe 6.2</h1>
    </div>
    <div class="time">
        <?php
            header("Refresh:1"); // Automatisches neu laden der Seite
            $hour = date("H");
            $minute = date("i");
            $second = date("s");
            echo "<p class='clock'>$hour:$minute:$second</p>";
            echo "<p class='c_msg'>&nbspUhr</p>";
            switch (true) {
                case $hour >= 6 && $hour < 12:
                    echo "<p class='msg'>Guten Morgen!</p>";
                    break;
                case $hour >= 12 && $hour < 18:
                    echo "<p class='msg'>Guten Tag!</p>";
                    break;
                case $hour >= 18 && $hour < 23:
                    echo "<p class='msg'>Guten Abend!</p>";
                    break;
                default:
                echo "<p class='msg'>Gute Nacht!</p>";
                    break;
            }
        ?>
    </div>
</body>
</html>