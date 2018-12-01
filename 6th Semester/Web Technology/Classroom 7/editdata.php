<?php
	$id= $_GET['id'];
	require("connect.php");//include for less important files and require for more important file, connect gives warning if file not found whereas require gives fatal error when file not found.
	
	$sql="update user set username='Hari',password='Gari',email='man@bhari.com' where id=$id";
	mysqli_query($con,$sql);
	header("Location:display.php");
?>