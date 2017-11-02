class PowerFailureException extends Exception{
	
	String s="Power Failure !";
	@Override
	public String getMessage(){
		return s;
	}
	PowerFailureException(){
		getMessage();
		printStackTrace();
	}

	PowerFailureException(String s){
		this.s=s;
		getMessage();
		printStackTrace();
	}

	
}

class Q2{
	public static void main(String[] args) {
		Exception e=new PowerFailureException();
		e=new PowerFailureException("Different Exception");
	}
}