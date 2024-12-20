<html><head><title></title></head><body>
<h1>Berechnungen 6.4</h1>
<?php
    $tag = date("I");
    $sf = date('d.m.Y', strtotime("17.07.2025"));
    $jt = date('d.m.Y', strtotime("01.01.2000"));
    $heute = date("d.m.Y");
    echo "Datum: $heute <br>";

    $sommerferien = (strtotime($sf) - strtotime($heute)) / (60 * 60 * 24);
    $jahrtausend = (strtotime($heute) - strtotime($jt)) / (60 * 60 * 24);
    $in2Wochen = strtotime("+14 day", strtotime($heute));
    $in2Wochen2 = date('d.m.Y', $in2Wochen);
    echo "In 2 Wochen ist der: $in2Wochen2";
    echo "<br>";
    echo "Die Sommerferien sind in $sommerferien Tage";
    echo "<br>";
    echo "Seit dem Jahrtausend sind $jahrtausend Tage vergangen";
?>
</body></html>