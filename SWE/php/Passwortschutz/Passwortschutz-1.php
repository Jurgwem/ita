<html>
    <head>
        <title>Passwortschutz - 1</title>
    </head>
<body>
    <a href="../Passwortschutz">Menü</a>
    <h1>Aufgabe 9.1</h1>
    <?php
        ob_start();
        if (empty($_POST["pass"])) {
    ?>
        <p>Bitte Passwort eingeben: (<em>Passwort ist 123</em>)</p>
        <form action="Passwortschutz-1.php" method="post">
        <label for="pass"></label>
        <input type="password" name="pass" size="20">
        <input type="submit" value="Absenden">
        </form>
    <?php
        }
        else {
        if ($_POST["pass"]=="123" && !isset($_COOKIE["psswd_lock"])) {
            ob_end_clean();
            header("Location: ../../ITA32/Weiss/home.html");
            exit;
            }
        else if (isset($_COOKIE["psswd_lock"])) {
            ob_end_clean();
            echo "Passworteingabe gesperrt bis " . date("d.m.Y H:i:s", time()+3600);
        }
        else {
            ob_end_clean();
            echo "Passwort ist falsch";
            echo "<form action='Passwortschutz-1.php'><input type='submit' value='Zurück'></form>";
            if (!isset($_COOKIE["psswd_lock"])) {
                setcookie("psswd_lock", "Passwort gesperrt", time()+3600);
            }
            else {
                echo "Passworteingabe gesperrt bis " . date("d.m.Y H:i:s", time()+3600);
            }
            //echo $_COOKIE["psswd_lock"];
            }
        }
  ?>

</body></html>