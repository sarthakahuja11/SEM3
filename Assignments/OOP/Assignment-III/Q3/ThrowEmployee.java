class ThrowEmployee{
	public static void main(String[] args) throws EmployeeException{
		try{
			new Employee("A001",120);
			new Employee("A002",90);
		}catch(EmployeeException e)
		{
			System.out.println(e);
		}

		try{
			new Employee("A003",160);
		}catch(EmployeeException e)
		{
			System.out.println(e);
		}
	}
}