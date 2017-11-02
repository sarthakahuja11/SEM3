import java.util.Scanner;

class GradeException extends Exception{
	static public char correctGrade []={'A','B','C','D','F','I'};
	char grade;
	GradeException(){
		toString();}
	
	@Override
	public String toString(){
		return "Invalid Grade";
	}
}

class Q5{
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int id[]=new int[10];
		char grade[]=new char[10];
	
		System.out.println("Student ID");
		for(int i=0;i<10;i++)
	
		System.out.println(id[i]=i+1);
		System.out.println("Enter your Grades");
		for(int i=0;i<10;i++)
		{
			System.out.println("Enter Grade "+(i+1));
			grade[i]=in.next().charAt(0);
			in.nextLine();
			try{
				boolean check=false;
				for(char c:GradeException.correctGrade)
					if(c==grade[i])
						{check=true;
							break;}
				if(!check)
					throw new GradeException();
			}
			catch(GradeException g){
				grade[i]='I';
				System.out.println(g);}


		}
		for(int i=0;i<10;i++)
			System.out.println(id[i]+"\t"+grade[i]);
	}
}