limport java.io.*;
import java.util.*;
public class lab10_1
{
 
public static void disp(File path)
{
    //File f1=new File(path);
    if(path.isFile())
    System.out.println(path.getName());    
    else
    {
        System.out.println(path.getName());
        File files[]=path.listFiles();
        for(File dir:files)
        disp(dir);
    }
}
 
 
public static void main(String args[])
{
    Scanner sc=new Scanner(System.in);
    String path="";
    //System.out.println("enter path");
    //path=sc.nextLine();
    //listDirectory(path,1);
    File f=new File("/home/150905110/lab10");
    disp(f);
}
}
