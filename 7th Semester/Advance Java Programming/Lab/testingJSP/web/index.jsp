<%-- 
    Document   : index
    Created on : May 12, 2019, 8:07:10 AM
    Author     : namko
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Processing "get" requests with data</title>
</head>
<body>
    <%
    String name = request.getParameter( "firstName" );
    if ( name != null )
    {
        %>
        <h1>
        Hello <%= name %>, <br>
        Welcome to JavaServer Pages!
        </h1>
        <%
    }
    else {
        %>
        <form action = "index.jsp" method = "get">
        <p>Type your first name and press Submit</p>
        <p><input type = "text" name = "firstName" />
        <input type = "submit" value = "Submit" />
        </p>
        </form>
        <%
    }
    %> 
</body>
</html>
