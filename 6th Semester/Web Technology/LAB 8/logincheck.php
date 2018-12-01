<html>
<head>
</head>
<body>
    <?php
    if($_POST["uname"]=="ram"){
        echo "Welcome";
        echo md5($_POST["pass"]);
    }
    else{
        echo "gtfo";
    }
    ?>
</body>
</html>