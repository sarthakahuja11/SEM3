import java.io.*;
class CopyFile {
public static void main(String args[])
throws IOException {
int i,j,flag=0;
FileInputStream fin;
FileInputStream fin2;
try {
// open input file
try {
fin = new FileInputStream(args[0]);
} catch(FileNotFoundException e) {
System.out.println("Input File Not Found");
return; }

// open output file
try {
fin2 = new FileInputStream(args[1]);
} catch(FileNotFoundException e) {
System.out.println("Error Opening Output File");
return;
}
} catch(ArrayIndexOutOfBoundsException e) {
System.out.println("Usage: CopyFile From To");
return;
}

// Copy File
try {
do {
i = fin.read();
j= fin2.read();
if(i==j)
	flag=0;
else 
	{flag=1;break;}
} while(i != -1);
} catch(IOException e) {
System.out.println("File Error");
}
fin.close();
fin2.close();
if(flag==0)
System.out.println("equal");
else
System.out.println("sdfsdk");
}
}
