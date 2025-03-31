<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Gaestebuch</title>
</head>
<body>
    <a href="../Gaestebuch">Menü</a>
    <h1>Aufgabe 14.1</h1>

    <?php
        $check = 0;
        if (empty($_POST["name"]) && $check == 0) {
    ?>

    <form action="Gaestebuch-1.php" method="post">
    <label for="name">Name:</label>
        <input type="text" name="name"> <br><br>
        <label for="email">eMail:</label>
        <input type="email" name="email"> <br><br>
        <label for="comment">Kommentar:</label> <br>
        <textarea name="comment" cols="30" rows="10"></textarea> <br><br>
        <input type="submit" value="Absenden">
    </form>

    <?php
        }
        else {
            $name = htmlentities($_POST["name"]);
            $email = htmlentities($_POST["email"]);
            $comment = htmlentities($_POST["comment"]);
            echo "<h3>Diese Daten wurden eingegeben:</h3>";
            echo "Name: $name <br>";
            echo "Email: $email <br>";
            echo "Kommentar: $comment";
            echo "<br><br>";

            echo"<hr><h1>Gästebuch<hr></h1>";

            $file = "gaeste.txt";
            if (!file_exists($file)) {
                exec ("/bin/echo . > $file");
            }
            $fp = fopen($file, "a");
            $day = date("d.m.Y");
            $time = date("H:i");
            $row="<b>$name</b>(<a href=mailto:$email>$email</a>) schrieb am $day um $time Uhr:<br>$comment<hr>\n\n";

            fputs($fp, $row);
            fclose($fp);

            readfile($file);

        }
    ?>
    
</body>
</html>