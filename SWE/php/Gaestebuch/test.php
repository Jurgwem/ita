<!DOCTYPE html>
<html>
<head>
    <title>Gästebuch</title>
</head>
<body>
<?php
$data_file = "pxmp14.txt";

// Einträge aus der Datei lesen
$eintraege = file($data_file, FILE_IGNORE_NEW_LINES);

// Löschvorgang verarbeiten
if (isset($_POST["delete"])) {
    $index = $_POST["index"];
    unset($eintraege[$index]); // Eintrag aus dem Array entfernen
    file_put_contents($data_file, implode("\n", $eintraege)); // Aktualisierte Einträge in die Datei schreiben
}
  echo "<h1>Gästebuch</h1>";
  foreach (array_reverse($eintraege) as $index => $eintrag) {
      echo "<p>$eintrag <form method='post' style='display:inline;'><input type='hidden' name='index' value='$index'><button type='submit' name='delete'>Löschen</button></form></p>";
  }

  echo "<br><br><br><a href=\"$data_file\">Roh-Daten ansehen?</a>";

?>
</body>
</html>