<?php
	$id= $_GET['id'];
	require("connect.php");
	$sql="delete from user where id=$id";
	mysqli_query($con,$sql);
	header("Location:display.php");
?>