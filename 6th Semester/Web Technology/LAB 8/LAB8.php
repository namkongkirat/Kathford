<html>
<head>
</head>
<body>
    <?php
        echo "Hi";
        print "A"."B"."C";
        for($i=0; $i<5; $i++){
            echo $i;
        }
    ?>
    <form action="logincheck.php" method = "POST">
            Name:
            <input type="text", name="uname">
            Password:
            <input type="password", name="pass"><br>
            <input type="submit" value="Submit">
    </form>
</body>
</html>