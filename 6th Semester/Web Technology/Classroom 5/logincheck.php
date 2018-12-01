<?php
$uname= $_GET["uname"];
if ($uname=="ram"){
	header("Location:login.php?msg=Success&type=1");
}
else
	header("Location:login.php?msg=Invalid Login&type=2");
?>