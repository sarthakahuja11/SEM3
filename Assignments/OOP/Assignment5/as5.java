import java.awt.*;
import java.awt.event.*;
import javax.swing.*;


/* <applet code="as5" width=500 height=500> </applet> */


public class as5 extends JApplet{
JTextField jtf1;
JTextField jtf2;
JTextField jtf3;
JButton jbtn;
int rect1=0,rect2=0,rect3=0;
public void start()
{
setLayout(new FlowLayout());

jtf1=new JTextField(5);
jtf2=new JTextField(5);
jtf3=new JTextField(5);
jbtn=new JButton("Click");
add(jtf1);
add(jtf2);
add(jtf3);
add(jbtn);
jbtn.addActionListener(new ActionListener(){
public void actionPerformed(ActionEvent ae){
rect1=Integer.parseInt(jtf1.getText());
rect2=Integer.parseInt(jtf2.getText());
rect3=Integer.parseInt(jtf3.getText());
repaint();
}
}
);
}
public void paint(Graphics g){

g.setColor(Color.RED);
g.drawString("one",0,80);
g.setColor(Color.BLUE);
g.fillRect(40,60,rect1,30);
g.drawString(String.valueOf(rect1),rect1+10+40,80);


g.setColor(Color.RED);
g.drawString("two",0,120);
g.setColor(Color.BLUE);
g.fillRect(40,100,rect2,30);
g.drawString(String.valueOf(rect2),rect2+10+40,120);

g.setColor(Color.RED);
g.drawString("three",0,160);
g.setColor(Color.BLUE);
g.fillRect(40,140,rect3,30);
g.drawString(String.valueOf(rect3),rect3+10+40,160);

}

}
