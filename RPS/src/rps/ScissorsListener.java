package rps;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Random;

/**
 *
 * @author Jacob
 */
public class ScissorsListener implements ActionListener
{
    public void actionPerformed(ActionEvent event)
    {
    String result;
    Random randomGenerator = new Random();
    int AIChoice = randomGenerator.nextInt(3) + 1;
    if (AIChoice == 1)
    {
        System.out.println("You Lose...");
       result = "You Lose...";
    }
    else if (AIChoice == 2)
    {
        System.out.println("You Win!");
        result = "You Win!";
    }
    else
    {
        System.out.println("It's a tie!");
        result = "It's a tie!";
    }
    
    JFrame message = new JFrame();
    JLabel displayMessage = new JLabel(result);
    message.add(displayMessage);
    
     final int FRAME_WIDTH = 100;//350
     final int FRAME_HEIGHT = 70;//75
     message.setSize(FRAME_WIDTH, FRAME_HEIGHT);
     message.setTitle("Results");
     message.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
     message.setVisible(true);
    } 
}
