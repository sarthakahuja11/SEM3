import java.awt.*;
import java.applet.*;
 
/*<applet code="oopl_11_3" width=700 height=300></applet>*/
public class oopl_11_3 extends Applet
{
    String m="";
    static int i=700;
    private class thread extends Thread
    {
        public void run()
        {
            while(true)
            {
                i--;
                if(i==0)
                    i=700;
                try{
                Thread.sleep(30);
                } catch(Exception e)
                {
                }
                repaint(); 
            }
           
        }
    }
    public void init()
    {
        setBackground(Color.cyan);
           
    }
    public void start()
    {  
        new thread().start();
    }
    public void paint(Graphics g)
    {
        
        g.drawString("lalalalalaalala lalalalala",i,20);
        showStatus("Status");
    }
}