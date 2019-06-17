<%-- 
    Document   : signup
    Created on : May 13, 2019, 8:03:56 AM
    Author     : namko
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
    <title>Sample Sign Up Page</title>
</head>
    <body>
        <%
            String fname = request.getParameter( "firstname" );
            String lname = request.getParameter( "lastname" );
            if ( fname != null & lname != null)
            {
        %>
        <h1 style="color: black; font-size: 3em; font-weight: normal; font-family: Raleway">
        Hello <%= fname %> <%= lname %>, <br>
        This is a sample page after submitting the name.
        </h1>
        <%
        }
        else {
        %>
        <form action = "signup.jsp" method = "get">
            <p style="color: black; font-size: 1em; font-weight: normal; font-family: Raleway">Please input required values</p>
            <p style="color: black; font-size: 1em; font-weight: normal; font-family: Raleway">
                <input type = "text" placeholder="First Name" name = "firstname" />
                <input type = "text" placeholder="Last Name" name = "lastname" />
                <input type = "submit" value = "Submit" />
            </p>
        </form>
        <%
        }
        %>
    </body>
</html>