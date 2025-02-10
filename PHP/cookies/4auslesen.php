<html><head><title></title></head><body>
<h1>Cookies auslesen</h1>
<?php
foreach ($_COOKIE as $key => $value) {
  echo "$key = $value<br>\n";
}
 ?>
 <a href="./">zum Ordner</a>
</body></html>