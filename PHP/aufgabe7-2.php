<html><head><title></title></head><body>
<h1>7.2 Passwort</h1>
<?php
if (empty($_GET["passwort"])) {
?>
    Geben Sie Ihr Passwort ein:
    <form action="aufgabe7-2.php" method="get" >
    <input type="password" name="passwort" size="20">
    <input type="submit" value="Absenden">
    </form>
<?php
}
else {
    echo "Ihr Passwort lautet: ";
    echo "<br>";
    echo $_GET["passwort"];
}
?>
</body></html>