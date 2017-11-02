module lab10_4(w,s,f);
input [0:3]w;
input [1:0]s;
output f;
wire [0:3]y;
lab9_1 st(s,y,1'b1);
assign f=(y[0]&w[0])|(y[1]&w[1])|(y[2]&w[2])|(y[3]&w[3]);
endmodule




module lab9_1(w,y,en);
input [1:0]w;
input en;
output [0:3]y;
reg [0:3]y;
wire [2:0]temp;
assign temp[2]=en;
assign temp[1:0]=w;
always @(w or en)
if(temp==4'b100)
y=8'b1000;
else if(temp==4'b101)
y=8'b0100;
else if(temp==4'b110)
y=8'b0010;
else if(temp==4'b111)
y=8'b0001;
else 
y=8'b0000;
endmodule

