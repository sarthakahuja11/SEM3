module lab11_3(in,clk,reset,q);
input clk,reset;
input [1:0]in;
output q;
reg q;
always@(posedge clk)
if(reset==1)
q<=0;
else if(in==2'b00)
q<=q;
else if(in==2'b01)
q<=0;
else if(in==2'b10)
q<=1;
else if(in==2'b11)
q<=~q;
endmodule

