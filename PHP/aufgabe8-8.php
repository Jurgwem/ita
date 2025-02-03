<html><head><title></title></head><body>
<h1>Berechnungen</h1>
<?php
if (empty($_POST["age"])) {
?>
    Geben Sie Ihren Daten ein:
    <form action="aufgabe8-8.php" method="post" >
    Name: <input type="number" name="age" size="20"><br>
    <input type="submit" value="Absenden">
    </form>
<?php
}
else{
    if ($_POST["age"] >= 18) {
        echo "<font size='100'>";
        echo "8.8 Lötto<br><br>";    //Aufgabe 4.1
        $array = [0, 0, 0, 0, 0, 0, 0]; //pos 6 = Glückszahl
        $exists = false;

        for ($i = 0; $i <= 6; $i++)
        {
            do{
                $exists = false;
                $var = random_int(1, 49);
                for ($k = 0; $k <= 6; $k++)
                {
                    if ($array[$k] == $var)
                    {
                        $exists = true;
                    }
                }
            } while ($exists);
            $array[$i] = $var;
        }
        for ($k = 0; $k <= 6; $k++)
        {
            if ($k != 6)
            {
                echo $k + 1, ". Zahl: ", $array[$k], "<br>";
            }
            else 
            {
                echo "Superzahl: ", $array[$k], "<br>";
            }
        }
    } else {
        echo "Sie sind nicht alt genung um Lotto zu spielen :(<br>";
    };
    echo "<br>Datum und Uhrzeit:<br>";
    echo date("d.m.Y");
};
?>
</body></html>