<html><head><title></title></head><body>
<h1>eMail Adresse prüfen</h1>
<?php  
if (empty($_POST["email"])) { ?>
Bitte gib deine eMail Adresse ein:
  <form action="aufgabe10.php" method="post" >
  <input type="text" name="email"
     size="30" maxsize="255">
  <input type="submit" value="Prüfen">
  </form>
<?php
} else {
  $e=$_POST["email"];
  $valid=true;
  #if (!strstr($e, "??@??")) {$valid = false;}
  #if (!strstr($e, ".??")) {$valid = false;}

  if (!fnmatch("*??@??*", $e)) {$valid = false;}
  if (!fnmatch("*??.??*", $e)) {$valid = false;}
  if (strlen($e) - strpos($e, ".") > 9) {$valid = false;}
  if (strlen($e) > 25) {$valid = false;}

  if  ($valid) {
    echo "Die eMail Adresse ist gültig.";
    }
  else {
    echo "<font color=\"#ff0000\" size=\"+2\">
       Die eMail Adresse ist ungültig.</font>";
    }
  } ?>
</body></html>