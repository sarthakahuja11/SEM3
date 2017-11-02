import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*; //For GregorianCalendar



/*<applet code="q3" width=500 height=500> </applet> */


public class q3 extends JApplet implements Runnable{

public Thread t;

JLabel j1,j2,j3;
JButton jbtn;
String hours,minutes,seconds;
Calendar calendar=new GregorianCalendar();



public void run()
{
while(true)
{
repaint();
try{

Thread.sleep(1000);

}
catch(Exception e){}
}
}


public void start(){


setLayout(new FlowLayout());
t=new Thread(this);
t.start();
}

public void paint(Graphics g)
{
super.paint(g);
Calendar cal = new GregorianCalendar();
      String hour = String.valueOf(cal.get(Calendar.HOUR));
      String minute = String.valueOf(cal.get(Calendar.MINUTE));
      String second = String.valueOf(cal.get(Calendar.SECOND));
      g.drawString(hour + ":" + minute + ":" + second, 20, 30);



} 



}



/* Theory:calendar.get(Calendar.HOUR_OF_DAY));  calendar.get(Calendar.MINUTE)); calendar.get(Calendar.SECOND)); */
