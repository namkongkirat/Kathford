<%-- 
    Document   : index
    Created on : May 12, 2019, 7:31:54 AM
    Author     : namko
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Testing Cookies</title>
    </head>
    <body>
        <form action="AddCookie" method="post">
            <label style="color: red;">
                <b>Testing Cookies</b></label><br><br>
            <b>Enter the value for cookie</b><br>
            First Name:
            <input type="text" name="firstName" size="20"><br><br>
            Last Name:
            <input type="text" name="surname" size="20"><br><br>
            <input type="submit" value="Submit"><br><br>
            <label>
                <b>Click below to get Cookies Value</b>
            </label><br><br>
            <a href="getCookie">click here</a> <br><br>
        </form>
    </body>
</html>
