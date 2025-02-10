<?php
if (isset($_COOKIE["KEKS1"])) {
  echo "Keks 1 existiert<br>";
  }
else {
  echo "Keks 1 existiert nicht<br>";
  }
if (isset($_COOKIE["KEKS2"])) {
  echo "Keks 2 existiert<br>";
  }
else {
  echo "Keks 2 existiert nicht<br>";
  }
if (isset($_COOKIE["KEKS3"])) {
  echo "Keks 3 existiert<br>";
  }
else {
  echo "Keks 3 existiert nicht<br>";
  }
 ?>
<!DOCTYPE html>
<html><head><title></title></head><body>
<h1>Cookies ausgeben</h1>
<?php
foreach ($_COOKIE as $key => $value) {
  echo "$key = $value<br /><br />";
}
 ?>
 <p>Bitte diese Seite nach 5 bzw. 10s nochmal aufrufen.</p>
<a href="1setzen.php">zur vorherigen Seite</a><br />
<a href="3löschen.php">zur nächsten Seite</a><br>
<a href="./">zum Ordner</a>
</body></html>