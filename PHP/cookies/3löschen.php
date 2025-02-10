<?php
setcookie ("KEKS1", 
   "...und aus bist du.", time()-3);
if (isset($_COOKIE["KEKS1"])) {
  echo "Keks 1 existiert<br>";
  }
else {
  echo "Keks 1 existiert nicht<br>";
  }
 ?>
<!DOCTYPE html>
<html><head><title></title></head><body>
<h1>Cookie löschen</h1>
<?php
foreach ($_COOKIE as $key => $value) {
  echo "$key = $value<br /><br />";
}
 ?>
 <p>Bitte diese Seite direkt noch einmal aufrufen.</p>
<a href="1setzen.php">zur ersten Seite</a><br>
<a href="./">zum Ordner</a>
</body></html>