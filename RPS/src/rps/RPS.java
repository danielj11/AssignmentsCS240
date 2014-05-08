package rps;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**
 * @author Jacob Daniel
 * 5/6/14
 * CS 240
 */

public class RPS 
{

    /**
     * @param args the command line arguments
     */
    static int userChoice = 0;
    
    public static void main(String[] args) {
        
        int choice = 0;
  
        
        JFrame frame = new JFrame();
 
        JButton rock = new JButton("Rock");
        JButton paper = new JButton("Paper");
        JButton scissors = new JButton("Scissors");
        JLabel label = new JLabel("Choose one: ");
        JLabel winMessage = new JLabel("You win!");
        JLabel loseMessage = new JLabel("You lose...");
        JLabel tieMessage = new JLabel("It's a tie!");
        
        ActionListener rListener = new RockListener();
        ActionListener pListener = new PaperListener();
        ActionListener sListener = new ScissorsListener();
        rock.addActionListener(rListener);
        paper.addActionListener(pListener);
        scissors.addActionListener(sListener);
 
        JPanel panel = new JPanel();
        JPanel panel2 = new JPanel();
        panel.add(label);
        panel.add(rock);
        panel.add(paper);
        panel.add(scissors);
        frame.add(panel);
        panel2.add(winMessage);
        //frame.add(panel2);
        
 
        final int FRAME_WIDTH = 400;//350
        final int FRAME_HEIGHT = 100;//75
        frame.setSize(FRAME_WIDTH, FRAME_HEIGHT);
        frame.setTitle("Rock, Paper, Scissors!");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
 
        frame.setVisible(true);
    }
    
}