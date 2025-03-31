<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Daten_sa</title>
</head>
<body>
<h1>Daten sammeln</h1>
<?php if (empty($_POST["email"])) { ?>
<form method="post" action="Daten_sammeln-1.php">
<table>
<tr><td>Vorname:</td>
    <td>
    <input type="text" name="vorname" size="50">
    </td></tr>
<tr><td>Name:</td>
    <td>
    <input type="text" name="nachname" size="50">
    </td></tr>
<tr><td>Klasse:</td>
    <td><input type="text" name="klasse" size="5">
    </td></tr>
<tr><td>eMail:</td>
    <td><input type="text" name="email" size="50">
    </td></tr>
<tr><td>Homepage:</td>
    <td><input type="text" name="homepage" 
    value="http://" size="50"></td></tr>
<tr><td></td>
    <td><input type="submit" value="Absenden">
    <input type="reset" value="Löschen">
    </td></tr>
</table>
</form>
<?php
  }
    else {
        echo "<h2>Diese Daten wurden übermittelt:</h2>";
        echo "<table><tr><td>Vorname:</td>
            <td><b>".$_POST["vorname"]."</b></td></tr>";
        echo "<tr><td>Name:</td>
            <td><b>".$_POST["nachname"]."</b></td></tr>";
        echo "<tr><td>Klasse:</td>
            <td><b>".$_POST["klasse"]."</b></td></tr>";
        echo "<tr><td>eMail:</td>
            <td><b>".$_POST["email"]."</b></td></tr>";
        echo "<tr><td>Homepage:</td>
            <td><b>".$_POST["homepage"]."</b></td>
            </tr></table>";
        $data_file="Daten_sammeln-1.txt";
        // if (!file_exists($data_file)) 
        //    { exec ("/bin/echo . > $data_file"); }
        $zeile=$_POST["nachname"].",".$_POST["vorname"].",".$_POST["klasse"].",".$_POST["email"].",".$_POST["homepage"]."\n";
        $fp=fopen($data_file, "a");
        fputs($fp, $zeile);
        fclose($fp);
        echo "<h2>...und gespeichert.</h2>";
        echo "<a href=","Daten_sammeln-1.txt",">Ansehen?</a>";
    }
?>
</body>
</html>