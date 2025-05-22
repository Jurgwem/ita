<html>
    <head>
        <title>Batendanken</title>
    </head>
<body>
<?php   				
	$host="localhost";	
	$user="root";		
	$password="";		
	$dbname="classicmodels";	

    echo "<h1>Offene Bestellungen</h1>";
	
	$link = mysqli_connect ($host, $user, $password);
	$result = mysqli_query ($link, "USE $dbname");
	$result = mysqli_query ($link, "SELECT orderNumber, status, customerNumber FROM orders WHERE status = 'On Hold' OR status = 'Disputed' ORDER BY status ASC");

    echo "<table border=3px>";
	echo "<tr><th>Order ID</th><th>Status</th><th>Customer ID</th></tr>";
	while ($row = mysqli_fetch_array($result, MYSQLI_BOTH)) 
	{  
		echo "<tr><td style='text-align: right;'>$row[0]</td>" . "<td style='text-align: right;'>$row[1]</td>" . "<td style='text-align: right;'>$row[2]</td></tr>";
	}	

    echo "</table>";
	
?></body>
</html> 	