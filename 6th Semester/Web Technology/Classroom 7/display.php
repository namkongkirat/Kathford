<?php
require("connect.php");
$sql2=mysqli_query($con,"select * from user");
?>
<table border="1">
<tr>
<th>SN</th>
<th>Username</th>
<th>Password</th>
<th>Email</th>
<th>Action</th>
<tr>
<?php
$i=1;
	while($det = mysqli_fetch_array($sql2)){
		echo '<tr><td>'.$i.'</td><td>'.$det[1].'</td><td>'.$det[2].'</td><td>'.$det[3].'</td><td><a href="editdata.php?id='.$det[0].'">Edit </a>|<a href="deletedata.php?id='.$det[0].'"> Delete</a></td></tr>';
	$i++;
	}
?>