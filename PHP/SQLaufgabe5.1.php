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

    echo "<h1>Übersicht</h1>";
    echo "Aktuell sind 122 Kunden in der Datenbank<br><br>";
	
	$link = mysqli_connect ($host, $user, $password);
	$result = mysqli_query ($link, "USE $dbname");
	$result = mysqli_query ($link, "SELECT contactFirstName, contactLastName, city FROM customers ORDER BY city ASC");

    echo "<table>";

	while ($row = mysqli_fetch_array($result, MYSQLI_BOTH)) {  
		echo "<tr><td>$row[0]</td>" . "<td>$row[1]</td>" . "<td>$row[2]</td></tr>";
	}	

    echo "</table>";
	
?></body>
</html> 	