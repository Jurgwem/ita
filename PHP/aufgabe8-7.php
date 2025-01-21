<html><head><title></title></head><body>
<h1>Berechnungen</h1>
<?php
    echo "<font size='100'>";
    echo "8.7 Lötto<br><br>";    //Aufgabe 4.1
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

    
?>
</body></html>