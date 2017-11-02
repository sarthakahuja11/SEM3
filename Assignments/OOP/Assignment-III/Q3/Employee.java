class Employee{
	String idNum;
	double hourlyWage;
	Employee(String idNum,double hourlyWage) throws EmployeeException{
	if(hourlyWage<100 || hourlyWage>150)
		{	System.out.println("Can't create this object");
			throw new EmployeeException(idNum,hourlyWage);}
	
	this.idNum=idNum;
	this.hourlyWage=hourlyWage;
	System.out.println("An object of the Employee class created");
}

}