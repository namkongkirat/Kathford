<%-- 
    Document   : clock
    Created on : May 13, 2019, 8:03:42 AM
    Author     : namko
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <title>Clock</title>
    </head>
    <body>
        <table>
            <tr>
                <td style="background-color: #87BCBF">
                    <p style="color: white; font-size: 2em; font-weight: bold; font-family: Lato">
                        <%
                        java.util.Locale locale = request.getLocale();
                        java.text.DateFormat dateFormat =
                        java.text.DateFormat.getDateTimeInstance(
                        java.text.DateFormat.LONG,
                        java.text.DateFormat.LONG, locale );
                        %>            
                        
                        <%= dateFormat.format( new java.util.Date() ) %>
                    </p>
                </td>
            </tr>
        </table>
    </body>
</html>
