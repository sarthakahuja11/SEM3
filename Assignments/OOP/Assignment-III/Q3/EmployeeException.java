public class EmployeeException extends Exception{
	String id;
	double payrate;
	@Override
	public String toString(){
		return "Invalid Payrate :"+payrate;
	}
	EmployeeException(String id,double payrate){
		this.id=id;
		this.payrate=payrate;
	}
}