<? ob_start(); // Ausgabe puffern ?>
<html><head><title></title></head><body>
<h1>Passwortschutz</h1>
<?php
  if (empty($_POST["passwort"])) {
?>
Bitte Passwort eingeben: ( <em>Passwort ist 123</em> )
  <form action="aufgabe9.php" method="post" >
  <input type="password" name="passwort" size="20">
  <input type="submit" value="Absenden">
  </form>
<?php
  }
else {
  if  ($_POST["passwort"]=="123") {
    ob_end_clean();    // Puffer freigeben
    header("Location: versteckteWebsite/index.html");
    exit;  // Verarbeitung abbrechen
    }
  else {
    ob_end_clean();  // Puffer freigeben
    echo "Passwort ist falsch";
    }
  }
  ?>

</body></html>