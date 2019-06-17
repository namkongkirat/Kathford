/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package testingConnection;

import  java.sql.ResultSetMetaData;
import java.sql.SQLException;
import javax.sql.rowset.JdbcRowSet;
import com.sun.rowset.JdbcRowSetImpl;
/**
 *
 * @author namko
 */
public class JdbcRowSetTest{
    static final String DATABASE_URL = "jdbc:mysql://localhost:3306/books";
    static final String USERNAME = "root";
    static final String PASSWORD = "";
    public JdbcRowSetTest()
    {
        try
        {
            JdbcRowSet rowSet = new JdbcRowSetImpl();
            rowSet.setUrl( DATABASE_URL );
            rowSet.setUsername( USERNAME );
            rowSet.setPassword( PASSWORD );
            rowSet.setCommand( "SELECT * FROM Authors" );
            rowSet.execute();
            
            ResultSetMetaData metaData = rowSet.getMetaData();
            int numberOfColumns = metaData.getColumnCount();
            
          /*=========INSERT==============
            rowSet.last();
            rowSet.moveToInsertRow();
            rowSet.updateInt("sn", 7);
            rowSet.updateString("firstname", "Aniket");
            rowSet.updateString("lastname", "Maharjan");
            rowSet.insertRow();
            rowSet.first(); */
          
          
          /*=========DELETE==============
            rowSet.last();
            rowSet.deleteRow();
            rowSet.first(); */
          
          
          /*==========UPDATE============
            rowSet.absolute(2);
            rowSet.updateString("firstname", "Ram");
            rowSet.updateString("lastname", "Bhitrikoti");
            rowSet.updateRow();
            rowSet.first(); */
          
            System.out.println( "Authors Table of Books Database:\n" );
            for ( int i = 1; i <= numberOfColumns; i++ )
                System.out.printf( "%-8s\t", metaData.getColumnName( i ) );
                System.out.println();
            while(rowSet.next())
            {
                for ( int i = 1; i <= numberOfColumns; i++ )
                System.out.printf( "%-8s\t",rowSet.getObject( i ));
                System.out.println();
            }
            rowSet.close();
        }
        catch ( SQLException sqlException )
        {
            sqlException.printStackTrace();
            System.exit( 1 );
        }
    }
    public static void main( String args[] )
    {
        JdbcRowSetTest application = new JdbcRowSetTest();
        
    }
}