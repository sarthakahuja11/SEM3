import java.awt.*;
import java.awt.event.*;
import javax.swing.*;



/* <applet code="q2" width=500 height=500> </applet> */

public class q2 extends JApplet{

public void start()
{
setLayout(new FlowLayout());
repaint();

}


public void paint(Graphics g)
{

g.setColor(Color.BLACK);

g.drawOval(000,000,50,50);
g.fillOval(100,000,50,50);
g.drawOval(200,000,50,50);

g.fillOval(000,100,50,50);
g.drawOval(100,100,50,50);
g.fillOval(200,100,50,50);

g.drawOval(000,200,50,50);
g.fillOval(100,200,50,50);
g.drawOval(200,200,50,50);

}

}

/* Theory: drawOval(int left,int top,int width, int height) fillOval->same where left, top-> coordinates of bounding rectangle.
Rectangle=square for circle. */
