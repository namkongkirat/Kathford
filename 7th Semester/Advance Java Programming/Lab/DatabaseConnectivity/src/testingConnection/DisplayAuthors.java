/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package testingConnection;

import java.sql.Connection;
import java.sql.Statement;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.ResultSetMetaData;
import java.sql.SQLException;
import java.sql.Savepoint;
/**
 *
 * @author namko
 */
public class DisplayAuthors {
    static final String DATABASE_URL="jdbc:mysql://localhost/books";
    public static void main(String args[]){
        Connection connection = null;
        //PreparedStatement pstmt = null;
        Statement statement = null;
        ResultSet resultSet = null;
        try
        {
            connection = DriverManager.getConnection(DATABASE_URL,"root","");
            connection.setAutoCommit(false);
            PreparedStatement pstmt = connection.prepareStatement("INSERT INTO authors VALUES(?, ?, ?)");
            
            pstmt.setInt(1,5);
            pstmt.setString(2, "Srijal");
            pstmt.setString(3,"KC");
            pstmt.addBatch();
            
            Savepoint svpt = connection.setSavepoint();
            
            pstmt.setInt(1,7);
            pstmt.setString(2, "Neha");
            pstmt.setString(3,"Adhikari");
            pstmt.addBatch();
            
            int [] updateCounts = pstmt.executeBatch();
            connection.rollback(svpt);
            connection.commit();
            
            
            statement = connection.createStatement(ResultSet.TYPE_SCROLL_SENSITIVE, ResultSet.CONCUR_UPDATABLE);
            resultSet = statement.executeQuery("SELECT * FROM authors");
            
            /*
            //=============Update Value (single row)=============//
            while(resultSet.next()){
                resultSet.updateString("lastname","Karki");
                resultSet.updateRow();
            }
            resultSet.beforeFirst();
            
            
            //=============Insert Value=============//
            resultSet.moveToInsertRow();
            resultSet.updateInt("sn",3);
            resultSet.updateString("firstname","Ruxana");
            resultSet.updateString("lastname","Maharjan");
            resultSet.insertRow();*/
            
            
            resultSet.beforeFirst();
            
            ResultSetMetaData metaData = resultSet.getMetaData();
            int numberOfColumns = metaData.getColumnCount();
            System.out.println("Authors Table:");
            
            for(int i=1; i<=numberOfColumns; i++)
                System.out.printf( "%-8s\t",metaData.getColumnName(i));
                System.out.println();
                
            while(resultSet.next())
            {
            for ( int i=1; i<= numberOfColumns; i++ )
                System.out.printf( "%-8s\t",resultSet.getObject(i));
                System.out.println();
                
            }
        }
        catch(SQLException sqlException)
        {
            sqlException.printStackTrace();
        }
        finally
        {
            try
            {
                resultSet.close();
                statement.close();
                connection.close();
            }
            catch (Exception exception)
            {
                exception.printStackTrace();
            }
        }
    }
}
