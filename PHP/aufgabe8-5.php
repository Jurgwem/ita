<html><head><title></title></head><body>
<h1>8.5 Bundespräsident</h1>
<?php
if (empty($_POST["name"]) || empty( $_POST["year"]) || empty( $_POST["staat"])) {
?>
    Geben Sie Ihren Daten ein:
    <form action="aufgabe8-5.php" method="post" >
    Name: <input type="text" name="name" size="20"><br>
    Geburtsjahr: <input type="number" name="year" size="20"><br>
    Staatsangehörigkeit: <input type="text" name="staat" size="20">
    <input type="submit" value="Absenden">
    </form>
<?php
}
else {
    $canPresident = true;
    $canKanzler = true;
    if (date("Y") - $_POST["year"] <= 40)
    {
        $canPresident = false;
    }
    if (date("Y") - $_POST["year"] <= 18)
    {
        $canKanzler = false;
    }
    if ( !(str_contains(strtolower($_POST["staat"]), "deutsch")))
    {
        $canPresident = false;
        $canKanzler = false;
    }
    /*
    echo $_POST["name"];
    echo "<br>";
    echo $_POST["year"];
    echo "<br>";
    echo $_POST["staat"];
    echo "<br>";
    */
    if ($canPresident)
    {
        echo "Sie können Bundespräsident werden, yay<br>";
    }
    else
    {
        echo "Sie sind leider nicht berechtigt Bundespräsident zu werden<br>";
    }
    if ($canKanzler)
    {
        echo "Sie können Bundeskanzler werden, yay<br>";
    }
    else
    {
        echo "Sie sind leider nicht berechtigt Bundeskanzler zu werden<br>";
    }
}
?>
</body></html>