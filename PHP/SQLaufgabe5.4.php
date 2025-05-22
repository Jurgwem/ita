<html>
    <head>
        <title>Batendanken</title>
    </head>
	<style>
		.info {
			position: fixed;
			bottom: 40%;
			right: 10%;
			font-size: 32;
		}
	</style>
<body>
<?php   				
	$host="localhost";	
	$user="root";		
	$password="";		
	$dbname="classicmodels";	

	$sum = 0;
	$num = 0;

    echo "<h1>Versanddauer</h1>";
	
	$link = mysqli_connect ($host, $user, $password);
	$result = mysqli_query ($link, "USE $dbname");
	$result = mysqli_query ($link, "SELECT orderDate, shippedDate FROM orders");

    echo "<table border=3px>";
	echo "<tr><th>OrderDate</th><th>shippedDate</th><th>Order timestamp</th><th>shipped timestamp</th><th>diff</th><th>Dauer in Tage</th></tr>";
	while ($row = mysqli_fetch_array($result, MYSQLI_BOTH)) 
	{  
		echo "<tr><td>$row[0]</td>" . "<td>$row[1]</td>";

		if (isset($row[0]))
		{
			$orderTS = strtotime($row[0]);
			echo "<td>$orderTS</td>";
		} else {
			unset($orderTS);
			echo "<td>&nbsp;</td>";
		}

		if (isset($row[1]))
		{
			$shipTS = strtotime($row[1]);
			echo "<td>$shipTS</td>";
		} else {
			unset($shipTS);
			echo "<td>&nbsp;</td>";
		}

		if (isset($row[0]) && isset($row[1]))
		{
			$diff = abs($orderTS - $shipTS);
			$sum += $diff;
			$num++;
			echo "<td>$diff</td>";
			$days = $diff / 60 / 60 / 24;
			echo "<td>$days</td>";
		} else {
			echo "<td>&nbsp;</td>";
			echo "<td>&nbsp;</td>";
		}
		
		echo "</tr>";
	}	
    echo "</table>";

	$sum = $sum / 60 / 60 / 24;
	$avg = $sum / $num;

	echo "<div class='info'>";
	echo "Summe Tage: " . $sum . " Tage<br>";
	echo "Durchschnitt: " . $avg . " Tage<br>";
	echo "Anzahl an vollständigen Bestellungen: " . $num . "<br>";
	echo "</div>";
	
?></body>
</html> 	