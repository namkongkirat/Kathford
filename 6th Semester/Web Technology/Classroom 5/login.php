<html>
<head>
</head>
<style>
.warning{
	background-color:red;
	color: white;
}
.success{
	background-color:teal;
	color: white;
}
</style>
</head>
<body>
<?php
if(isset($_GET['msg'])){
    if ($_GET['type']=="2")
    echo '<div class="success">' , $_GET['msg'], '</div>';
    else
    echo '<div class="warning">' , $_GET['msg'], '</div>';
}
?>
<form action = "logincheck2.php" method="POST">
    Name:
    <input type="text", name="uname"><br>
    Password:
    <input type="password", name="pass"><br>
    <input type="submit" value="Submit">
</form>
</body>
</html>