/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package LayoutManagers;


import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
/**
 *
 * @author namko
 */
public class borderLayout extends JFrame implements ActionListener
{
    private JButton[] buttons;
    private static final String[] names = { "Hide North", "Hide South", "Hide East", "Hide West", "Hide Center" };
    private BorderLayout layout;

    public borderLayout()
    {
        super( "BorderLayout Demo" );
        layout = new BorderLayout( 5, 5 );
        setLayout( layout );
        buttons = new JButton[ names.length ];

        for ( int count = 0; count < names.length; count++ ){
            buttons[ count ] = new JButton( names[ count ] );
            buttons[ count ].addActionListener( this );
        }
        add( buttons[ 0 ], BorderLayout.NORTH ); // add button to north
        add( buttons[ 1 ], BorderLayout.SOUTH ); // add button to south
        add( buttons[ 2 ], BorderLayout.EAST ); // add button to east
        add( buttons[ 3 ], BorderLayout.WEST ); // add button to west
        add( buttons[ 4 ], BorderLayout.CENTER ); // add button to center
    }
    public void actionPerformed( ActionEvent event )
    {
    for ( JButton button : buttons ){
        if ( event.getSource() == button )
            button.setVisible( false );
        else
            button.setVisible( true );
    }
    layout.layoutContainer( getContentPane() );
    }
    
    public static void main(String args[]){
        new borderLayout();
    }
    
}
