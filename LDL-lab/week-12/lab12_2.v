module lab12_2(clk,a);
input clk;    
output [3:0]a;
dflipflop sto(~a[0],clk,0,a[3]);
dflipflop st1(a[3],clk,0,a[2]);
dflipflop st2(a[2],clk,0,a[1]);
dflipflop st3(a[1],clk,0,a[0]);
endmodule                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
module dflipflop(d,clk,reset,q);
input d,clk,reset;
output q;
reg q;
always@(posedge reset or negedge clk)
if(reset==1)
q<=0;
else
q<=d;
endmodule

