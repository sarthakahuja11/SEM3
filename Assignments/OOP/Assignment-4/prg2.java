import java.io.*;

class prg2{
	public static void main(String[] args) throws FileNotFoundException, IOException {
		FileInputStream f1 = new FileInputStream(new File(args[0]));
		FileInputStream f2 = new FileInputStream(new File(args[1]));

		int i1=0,i2=0;
		while(i1!=-1 || i2!=-1)
		{	i1=f1.read();
			i2=f2.read();
			if((i1-i2)!=0)
			{
				System.out.println("Different files");
				System.exit(0);
			}
		}
		System.out.println("Same files");
	}
}