module lab11_2(t,clk,reset,q);
input t,clk,reset;
output q;
reg q;
always@(negedge clk)
if(reset==1)
q<=0;
else if(t==0)
q<=q;
else if(t==1)
q<=~q;
endmodule

