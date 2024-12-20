<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="Zeit-3.css">
    <title>Datum - Kalender</title>
</head>
<body>
    <a href="/php/Zeit">Menü</a>

    <h1>Aufgabe 6.3</h1>
    <?php
        $tage = array('Sonntag','Montag','Dienstag','Mittwoch','Donnerstag','Freitag','Samstag');
        $tage_k = array("So", "Mo", "Di", "Mi", "Do", "Fr", "Sa");
        $monate = array('','Januar','Februar','März','April','Mai','Juni','Juli','August','September','Oktober','November','Dezember');
        $m = date("F");
        //$m = "June"; // Test für andere Monate
        echo "<p id='month'>" . $monate[date("n")] . " " . date("Y") . "</p>";
        ?>
    <div class="calender">
        <?php

            function fillCalender($str, $m) {
                $d = 2;
                $n = 0;
                $class = "day"; 
                if ($m == "January" || $m == "March" || $m == "May" || $m == "July" || $m == "August" || $m == "October" || $m == "December") {
                    for ($i = 0; $i < 30; $i++) {
                        if (date("l", strtotime($d . " " . $m . " " . date("Y"))) == "Saturday" || date("l", strtotime($d . " " . $m . " " . date("Y"))) == "Sunday") $class = "weekend";
                        else if ($n . $d == date("d")) $class = "today";
                        else $class = "days";
                        if ($d < 10) echo "<p class='$class'>" . $n . $d . "</p>";
                        else echo "<p class='$class'>" . $d . "</p>";
                        $d += 1;
                    }
                }
                else {
                    for ($i = 0; $i < 29; $i++) {
                        if (date("l", strtotime($d . " " . $m . " " . date("Y"))) == "Saturday" || date("l", strtotime($d . " " . $m . " " . date("Y"))) == "Sunday") $class = "weekend";
                        else $class = "days";
                        if ($d < 10) echo "<p class='$class'>" . $n . $d . "</p>";
                        else echo "<p class='$class'>" . $d . "</p>";
                        $d += 1;
                    }
                }
            }



            for ($i = 1; $i <= 5; $i++) {
                echo "<p class='days'>" . $tage_k[$i] . "</p>";
            }
            echo "<p class='weekend'>" . $tage_k[6] . "</p>";
            echo "<p class='weekend'>" . $tage_k[0] . "</p>";

            for ($i = 0; $i < 7; $i++) echo "<p class='days'>------</p>";
            
            $day_n = "01";
            $str = strtotime("01 ". $m ." " . date("Y"));
            if (date("D", $str) == "Sun") {
                for ($i = 0; $i <= 5; $i++) echo "<p></p>";
                echo "<p class='weekend'>" . date("d", $str) . "</p>";
                fillCalender($str, $m);
            }
            else if (date("D", $str) == "Mon") {
                echo "<p class='days'>" . date("d", $str) . "</p>";
                fillCalender($str, $m);
            }
            else if (date("D", $str) == "Tue") {
                for ($i = 0; $i <= 0; $i++) echo "<p></p>";
                echo "<p class='days'>" . date("d", $str) . "</p>";
                fillCalender($str, $m);
            }
            else if (date("D", $str) == "Wed") {
                for ($i = 0; $i <= 1; $i++) echo "<p></p>";
                echo "<p class='days'>" . date("d", $str) . "</p>";
                fillCalender($str, $m);
            }
            else if (date("D", $str) == "Thu") {
                for ($i = 0; $i <= 2; $i++) echo "<p></p>";
                echo "<p class='days'>" . date("d", $str) . "</p>";
                fillCalender($str, $m);
            }
            else if (date("D", $str) == "Fri") {
                for ($i = 0; $i <= 3; $i++) echo "<p></p>";
                echo "<p class='days'>" . date("d", $str) . "</p>";
                fillCalender($str, $m);
            }
            else if (date("D", $str) == "Sat") {
                for ($i = 0; $i <= 4; $i++) echo "<p></p>";
                echo "<p class='weekend'>" . date("d", $str) . "</p>";
                fillCalender($str, $m);
            }
            // if (date("D", strtotime("01/" . $monate[date("n")] . "/" . date("y"))) == "Sun") {
            //     echo "<p>" . date("d") . "</p>";
            // }
        ?>
    </div>
</body>
</html> 