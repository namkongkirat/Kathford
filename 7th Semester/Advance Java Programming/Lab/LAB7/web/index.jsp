<%-- 
    Document   : index
    Created on : May 13, 2019, 7:26:12 AM
    Author     : namko
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Sample Home Page</title>
    </head>
    <body>
        <table>
            <tr>
                <td style="width: 215px; text-align: center">
                    <jsp:include page="banner.html" flush="true"/>
                </td>
                <td style="vertical-align: top">
                    <jsp:include page="clock.jsp" flush="true"/>
                </td>
            </tr>
            <tr>
                <td style="vertical-align: top">
                    <jsp:include page="signup.jsp" flush="true"/>
                </td>
            </tr>
        </table>
    </body>
</html>
