<?php
    $uname=$_POST['uname'];
    $pass=$_POST['pass'];
	$email=$_POST['email'];

    $con = mysqli_connect ("localhost", "root", "", "phpdb");
	
	$sql = "insert into user(username,password,email) values ('$uname','$pass','$email')";
	mysqli_query($con, $sql);
	echo "Data Saved";
	$sql2=mysqli_query($con,"select * from user where username like 'Neha%'");
?>
<table border="1">
<tr>
<th>SN</th>
<th>Username</th>
<th>Password</th>
<th>Email</th>
<tr>
<?php
	while($det = mysqli_fetch_array($sql2)){
		echo '<tr><td>'.$det[0].'</td><td>'.$det[1].'</td><td>'.$det[2].'</td><td>'.$det[3].'</td></tr>';
	}
?>