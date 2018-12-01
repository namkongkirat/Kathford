<?php
	$uname=$_POST['uname'];
	$pwd=$_POST['pwd'];
	require("connect.php");
	$sql=mysqli_query($con,"select * from profile where username='$uname' and password='$pword'");
	$rows=mysqli_num_rows($sql);
	if($rows==0){
		header("Location:login.php?msg=Invalid Login Yo & type=2");
	}
	else{
		echo "Welcome $uname";
	}
	
?>