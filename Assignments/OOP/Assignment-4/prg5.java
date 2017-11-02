import java.io.*;

public class prg5{

	public static void main(String[] args) throws IOException,EOFException{
		RandomAccessFile raf = new RandomAccessFile(args[0],"rw");
		
		long length = raf.length()/4;
			
		raf.seek(0);

			do
			{	
				System.out.print(raf.readInt()+"\t");

				length-=1;
			}
			while(length>=1);
			System.out.println();
			
				raf.seek(0);
				length = raf.length()/4;
				for(int i=0;i<length-1;i++){
						for(int j=0;j<length-i-1;j++){
							raf.seek(j*4);
							int a=raf.readInt();
							int b=raf.readInt();
							
								

							if(a>b){raf.seek(j*4);
								raf.writeInt(b);
							raf.writeInt(a);}
						}
					}
						
					raf.seek(0);

					do
					{	
						System.out.print(raf.readInt()+"\t");

						length-=1;
					}
					while(length>=1);
					System.out.println();
}}