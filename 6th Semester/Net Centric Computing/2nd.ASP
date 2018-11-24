<%
Dim n1, mul, i
n1 = Request.QueryString("txt1")
For i=1 to 10
mul = n1*i
Response.Write(n1& "*" &i& "=" &mul& "<br>")
Next
%>