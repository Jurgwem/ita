<? //ob_start(); // Ausgabe puffern ?>
<html><head><title></title></head><body>
<h1>Passwortschutz</h1>
<?php
    $count = 0;
    if ($count >= 3) {

    } else {
        if (empty($_POST["passwort"])) {
            echo "# Versuche: ";
            echo $count;
            echo "<br><br>";
        ?>
        Bitte Passwort eingeben: (<em>Passwort ist 123</em>)
            <form action="aufgabe11.3.php" method="post" >
                <input type="password" name="passwort" size="20">
                <input type="submit" value="Absenden">
            </form>
        <?php
        }
        else {
            if  ($_POST["passwort"]=="123") {
                //ob_end_clean();    // Puffer freigeben
                header("Location: versteckteWebsite/index.html");
                exit;  // Verarbeitung abbrechen
            }
            else {
                echo "Passwort falsch<br>";
                setcookie ("WARDA", "ich war hier", time()+10);
                if (isset($_COOKIE["WARDA"]))
                {
                    echo "cookie da";
                }
                echo "<br><br><br>";
                //while (isset($_COOKIE["WARDA"]))
                //{
                 //   echo "cookie da";
                //}
                exit;
            }
        }
    }
?>
</body></html>