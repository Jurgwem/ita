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
	$result = mysqli_query ($link, "SELECT c.customerName, o.orderNumber, o.status, o.customerNumber, o.comments FROM orders o RIGHT JOIN customers c ON o.customerNumber = c.customerNumber WHERE o.status = 'On Hold' OR o.status = 'Disputed' ORDER BY status ASC");

    echo "<table border=3px>";
	echo "<tr><th>Customer Name</th><th>Order ID</th><th>Status</th><th>Customer ID</th><th>Comment</th></tr>";
	while ($row = mysqli_fetch_array($result, MYSQLI_BOTH)) 
	{  
		echo "<tr><td>$row[0]</td>" . "<td style='text-align: right;'>$row[1]</td>" . "<td style='text-align: right;'>$row[2]</td>" . "<td style='text-align: right;'>$row[3]</td>" . "<td>$row[4]</td></tr>";
	}	

    echo "</table>";
	
?></body>
</html> 	