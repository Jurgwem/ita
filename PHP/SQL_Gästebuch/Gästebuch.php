<html>
    <head>
        <title>Gästebuch</title>
		<style>
			body {
				margin: 32px;
			}
		</style>
    </head>
<body>
<?php   				
	$host="localhost";	
	$user="root";		
	$password="";		
	$dbname="gästebuch";	

	$link = mysqli_connect ($host, $user, $password);
	$result = mysqli_query ($link, "USE $dbname");

	//delete callback
	if (isset($_POST['delete_id'])) 
	{
		$delete_id = $_POST['delete_id'];;
		mysqli_query ($link, "DELETE FROM einträge WHERE id = $delete_id");
	}

	?>
	<h1>Gästebuch</h1>
	<h2>Eintrag hinzufügen</h2>
    <form action="Gästebuch.php" method="post">
        <label for="name">Name:</label>
        <input type="text" name="name" required> <br>

		<label for="email">E-Mail:</label>
        <input type="email" name="email" required> <br>

		<label for="comment">Kommentar:</label> <br>
		<textarea name="comment" cols="30" rows="10"></textarea> <br><br>
        
        <input type="submit" value="Absenden">
    </form>
	<?php

	//insert callback
	if (!empty($_POST["name"]) && !empty($_POST["email"])) 
	{
		$name = htmlentities($_POST["name"]);
		$email = htmlentities($_POST["email"]);
		$comment = htmlentities($_POST["comment"]);
		
		$day = date("Y-m-d");
		$time = date("H:i:s");
		
		$sql = "INSERT INTO einträge (name, mail, text, datum, uhrzeit) VALUES ('$name', '$email', '$comment', '$day', '$time')";
		
		mysqli_query($link, $sql);
	}
		
	echo "<h2>Alle Einträge</h2>";
	
	//display entries
	$link = mysqli_connect ($host, $user, $password);
	$result = mysqli_query ($link, "USE $dbname");
	$result = mysqli_query ($link, "SELECT * FROM einträge ORDER BY datum DESC, uhrzeit DESC");

	while ($row = mysqli_fetch_array($result, MYSQLI_BOTH)) 
	{  
        echo "<b>$row[name]</b> (<a href='mailto:$row[mail]'>$row[mail]</a>) schrieb am $row[datum] um $row[uhrzeit]:";
		echo '<form action="Gästebuch.php" method="post" style="display: inline;">';
		echo '<input type="hidden" name="delete_id" value="' . $row['id'] . '">';
		echo '&nbsp;&nbsp;&nbsp;<input type="submit" value="Löschen">';
		echo '</form>';
		echo "<br>$row[text]";
		echo "<hr>";
	}	

	mysqli_close($link);
?></body>
</html> 	