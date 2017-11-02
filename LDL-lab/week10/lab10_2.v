module lab10_2(x,f1,f2,f3);
input [2:0]x;
output f1,f2,f3;
wire [0:7]y;
lab9_1 st(x,y,1'b1);
assign f1=y[0]|y[5]|y[7];
assign f2=y[2]|y[3]|y[4];
assign f3=y[1]|y[6]|y[7];
endmodule


module lab9_1(w,y,en);
input [2:0]w;
input en;
output [0:7]y;
reg [0:7]y;
wire [3:0]temp;
temp[3]=en;
temp[2:0]=w;
always @(w or en)
if(temp==4'b1000)
y=8'b10000000;
else if(temp==4'b1001)
y=8'b01000000;
else if(temp==4'b1010)
y=8'b00100000;
else if(temp==4'b1011)
y=8'b000100000;
else if(temp==4'b1100)
y=8'b00001000;
else if(temp==4'b1101)
y=8'b00000100;
else if(temp==4'b1110)
y=8'b00000010;
else if(temp==4'b1111)
y=8'b10000001;
else 
y=8'b00000000;endmodule



