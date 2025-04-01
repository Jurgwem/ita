<html>
<head><title>Aufgabe 11.2</title>Aufgabe 11.2<br></head>
<?php
if (isset($_COOKIE["WARDA"])) {
    echo "<font size='32'>Willkommen auf der tollen NICHT Intro Seite, aka Startseite :)</font>";
  }
  else{
    echo "<font size='32'>Willkommen auf der tollen Intro Seite :)</font>";
  }
setcookie ("WARDA", "ich war hier", time()+10);
//Cookie löscht sich nach 10 Sekunden
?>
</html>