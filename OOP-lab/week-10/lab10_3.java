import java.io.*;
 
       public class lab10_3 {
          public static void main(String args[])
           {
             try
              {
                String stringSearch = "hell";
 
                 BufferedReader bf = new BufferedReader(new FileReader("/home/150905110/lab10/temp.txt"));
 
         int linecount = 0;
            String line;
 
        System.out.println("Searching for " + stringSearch + " in file...");
 
        while (( line = bf.readLine()) != null)
        {
            linecount++;
            int indexfound = line.indexOf(stringSearch);
 
            if (indexfound > -1)
            {   System.out.println(line);
                System.out.println("Word is at position " + indexfound + " on line " + linecount);
            }
        }
        bf.close();
    }
    catch (IOException e)
    {
        System.out.println("IO Error Occurred: " + e.toString());
    }
}}