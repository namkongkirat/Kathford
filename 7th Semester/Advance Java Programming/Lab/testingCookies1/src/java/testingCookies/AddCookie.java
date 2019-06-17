/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package testingCookies;

import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 *
 * @author namko
 */
public class AddCookie extends HttpServlet {

    /**
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code>
     * methods.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    protected void processRequest(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        PrintWriter out = response.getWriter();
        try {
            String data = request.getParameter("firstName");
            String data1 = request.getParameter("surname");
            Cookie cookie = new Cookie("FirstCookie", data);
            Cookie cookie1 = new Cookie("SecondCookie", data1);
            response.addCookie(cookie);
            response.addCookie(cookie1);
            out.println("<html>");
            out.println("<head>");
            out.println("<title>Servlet AddCookie</title>");
            out.println("</head>");
            out.println("<body>");
            out.println("<B>MyCookie has been set to");
            out.println(data);
            out.println("<br/>");
            out.println(data1);
            out.println("</body>");
            out.println("</html>");
        } finally {
            out.close();
        }
    }
}

    