<!DOCTYPE html>
<html lang="de">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Qr - 2</title>
</head>
<body>
    <?php
        include "qrlib.php";

        $PNG_TEMP_DIR = dirname(__FILE__).DIRECTORY_SEPARATOR.'temp'.DIRECTORY_SEPARATOR;

        $file = "gg.txt";
        $filename = $PNG_TEMP_DIR . "gg.png";

        QRcode::png("TestTestTest");
        readfile("gg.txt");
    ?>
</body>
</html>