import java.util.*;

class GradeException extends Exception{
    
    public static char arr[]={'A','B','C','D','I'};
    
    GradeException(String s)
    {
        super(s);
    }
    
    
}

public class q5 {

    /**
     * @param args the command line arguments
     */
    
    static void validate(char testGrade) throws GradeException
    {
        boolean flag=false;
            for(char tg:GradeException.arr)
                if(tg==testGrade)
                {
                    flag=true;
                    break;
                }
        if(!flag)
            throw new GradeException("Invalid Grade entered");
        
    }
    
    public static void main(String[] args) {
        
        Scanner sc=new Scanner(System.in);
        int ids[]=new int[10];
        char grades[]=new char[10];
        
        //Ask user to enter 10 user IDs
        for(int i=0;i<10;i++)
            ids[i]=sc.nextInt();
        
        //Temporary grade that will be used for testing
        
        char testGrade;
        boolean flag=false;
        
        //For each of those IDs, ask for the grade
        for(int i=0;i<10;i++)
        {
            System.out.println("Enter the grade for the id"+ids[i]);
            testGrade=sc.next().charAt(0);
            flag=false;
            try{
                validate(testGrade);
            }
            catch(Exception e)
            {
                grades[i]='I';
                flag=true;
                System.out.println("Exception Caught:"+e);
                
            }
            finally{
                if(!flag)
                    grades[i]=testGrade;
            }
            
            
            
            
            
                
        }
        
        //Output
        int counter=0;
        for(int id:ids)
            System.out.println(id+" "+grades[counter++]);
            
            
            
      
    }
    
}

/* Output
1
2
3
4
5
6
7
8
9
10
Enter the grade for the id1
A
Enter the grade for the id2
B
Enter the grade for the id3
C
Enter the grade for the id4
I
Enter the grade for the id5
M
Exception Caught:q5.GradeException: Invalid Grade entered
Enter the grade for the id6
F
Exception Caught:q5.GradeException: Invalid Grade entered
Enter the grade for the id7
A
Enter the grade for the id8
B
Enter the grade for the id9
C
Enter the grade for the id10
I
1 A
2 B
3 C
4 I
5 I
6 I
7 A
8 B
9 C
10 I

*/
