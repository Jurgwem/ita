<html><head><title></title></head><body>
<h1>Alles in einer Datei erledigen</h1>
<?php
if (empty($_POST["vorname"])) {
?>
    Wie heisst du?
    <form action="test.php" method="post" >
    <input type="text" name="vorname" size="20">
    <input type="submit" value="Absenden">
    </form>
<?php
}
else {
  echo "Hallo " . $_POST["vorname"];
}
?>
</body></html>