module  lab7_add2(w,s,f);
input [0:15]w;
input [3:0]s;
output f;
function mux4to1;
input [0:3] w;
input [1:0]s;
begin
mux4to1=s[1]?(s[0]?w[3]:w[2]):(s[0]?w[1]:w[0]);
end
endfunction

wire [0:3]t;
assign t[0]=mux4to1 (w[0:3],s[1:0]);
assign t[1]=mux4to1 (w[4:7],s[1:0]);
assign t[2]=mux4to1 (w[8:11],s[1:0]);
assign t[3]=mux4to1 (w[12:15],s[1:0]);

assign f=mux4to1 (t[0:3],s[3:2]);
endmodule

