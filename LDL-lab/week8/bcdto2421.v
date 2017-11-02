module bcdto2421(b,w);
input [3:0] b;
output [3:0] w;
wire [3:0] a,c,d;
assign a={1'b1,1'b1,b[1]|b[0],1'b0};
mux4to1 stage0(a,b[3:2],w[3]);
assign c={1'b1,1'b1,b[1]|~b[0],1'b0};
mux4to1 stage1(c,b[3:2],w[2]);
assign d={1'b1,1'b1,~b[1]&b[0],b[1]};
mux4to1 stage2(d,b[3:2],w[1]);
assign w[0]=b[0];
endmodule

module mux4to1(w,s,f);
input [3:0]w;
input [1:0]s;
output f;
reg f;
always @(w or s)
f=s[1]?((s[0]?w[3]:w[2])):((s[0]?w[1]:w[0]));
endmodule
