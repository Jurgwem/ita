<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Zeit-Abschluss</title>
</head>
<body>
<div class="header">
        <a href="/php/Zeit">Menü</a>
        <h1>Aufgabe 6.2</h1>
    </div>

    <?php
        $date = date("d.m.Y");
        $summerhol = "14.07.2025";
        $time_til_summer = (strtotime($summerhol) - strtotime($date)) / (60 * 60 * 24);
        $millenium = "2000-01-01";
        $time_millenium = (strtotime($date) - strtotime($millenium)) / (60 * 60 * 24);
        $date_two_weeks = date("d.m.Y", strtotime("+14 days"));
        echo "<p>Datum: " . $date . "</p>";
        echo "<p>Sommerferien in NRW beginnen am " . $summerhol . ".</p>";
        echo "<p>Bis zu den Sommerferien sind noch " . $time_til_summer . " Tage.</p>";
        echo "<p>Seit dem Jahr 2000 sind " . $time_millenium . " Tage vergangen</p>";
        echo "<p>In zwei Wochen (14 Tage) ist der " . $date_two_weeks . "</p>";
    ?>
</body>
</html>