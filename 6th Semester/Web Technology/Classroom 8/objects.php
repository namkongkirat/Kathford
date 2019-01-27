<?php
class User{
	Function __construct(){
		echo"First Line";
	}
	Function __destruct(){
		echo "Second Line";
	}
	Function saveUser(){
	echo "Hello World";
	}
	Function saveUser2(){
	echo "Hello Nepal";
	}
	Function saveUser3($val1,$val2){
		return"Hello Nepal".$val1."".$val2;
	}
}
$user=new User;
//$user->saveUser();
//$user=new User;
//$user->saveUser2();
//echo $user->saveUser3();


?>