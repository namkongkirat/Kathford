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
    static final String DATABASE_URL = "jdbc:mysql://localhost/books";
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