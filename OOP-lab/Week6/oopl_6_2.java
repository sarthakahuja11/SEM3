import java.util.*;
import java.text.*;

class Patient
{
	String name;
	int age, hospNum;
	Patient()
	{
		name="";
		age=0;
		hospNum=1000;
	}
	Patient(String n, int a, int h)
	{
		name=n; age=a; hospNum=h;
	}
	Patient(Patient p)
	{
		name=p.name;
		age=p.age; hospNum=p.hospNum;
	}
}

class InPatient extends Patient
{
	String depName,roomType;
	GregorianCalendar dateOfAdm;
	InPatient()
	{
		name="";
		age=0;
		hospNum=1000;
		depName="";
		roomType="";
		dateOfAdm=new GregorianCalendar();
	}

	InPatient(String n, int a, int h, String d, GregorianCalendar dat, String r)
	{
		super(n, a, h);
		depName=d; dateOfAdm=dat; roomType=r;
	}

}

class Billing extends InPatient
{
	GregorianCalendar dateOfDis;
	Billing()
	{
		name="";
		age=0;
		hospNum=1000;
		depName="";
		roomType="";
		dateOfAdm=new GregorianCalendar();
		dateOfDis=new GregorianCalendar();
	}
	Billing(String n, int a, int h, String d, GregorianCalendar dat, String r, GregorianCalendar dis)
	{
		super(n, a, h, d, dat, r);
		dateOfDis=dis;
	}

	
	void input()
	{
		int yy,mm,dd,yy1,mm1,dd1;
		Scanner sc=new Scanner(System.in);
		System.out.println("Name : ");name=sc.next();
		System.out.println("Age : ");age=sc.nextInt();
		System.out.println("Hospital No. : ");hospNum=sc.nextInt();
		System.out.println("Department Name : ");depName=sc.next();
		System.out.println("Date of Admission [dd/mm/yyyy] : ");
		dd=sc.nextInt();
		mm=sc.nextInt();
		yy=sc.nextInt();
		dateOfAdm=new GregorianCalendar(yy,mm-1,dd);
		System.out.println("Room Type : ");roomType=sc.next();
		System.out.println("Date of Discharge [dd/mm/yyyy] : ");
		dd1=sc.nextInt();
		mm1=sc.nextInt();
		yy1=sc.nextInt();
		dateOfDis=new GregorianCalendar(yy1,mm1-1,dd1);
	}
	
	void print()
	{
		SimpleDateFormat dateFormat = new SimpleDateFormat("MMM dd, yyyy"); 
		System.out.println("Name : " + name);
		System.out.println("Age : " + age);
		System.out.println("Hospital No. : " + hospNum);
		System.out.println("Department Name : " + name);
		System.out.println("Room Type : " + roomType);
		System.out.println("Date of Admission : " + dateFormat.format(dateOfAdm.getTime()));
		System.out.println("Date of Discharge: " + dateFormat.format(dateOfDis.getTime()));
	}
	
	double totalAmt()
	{
		double amt=0;
		long diff=Math.abs(dateOfDis.getTimeInMillis()-dateOfAdm.getTimeInMillis());
		long d=diff/(3600*24*1000);
		
		if(roomType.equalsIgnoreCase("Special"))
			amt=d * (1000+200);
		else if(roomType.equalsIgnoreCase("SemiSpecial"))
			amt=d * (500+100);
		else if(roomType.equalsIgnoreCase("General"))
			amt=d * (100+50);
		
		return amt;
	}
}

public class oopl_6_2 
{
	public static void main(String[] args) 
	{
		Billing b=new Billing();
		b.input();
		System.out.println("Billing Ammount : Rs." + b.totalAmt());
		b.print();
	}
}