FILE * A,*B,*C,*D;
/*A :in
  B :ans
  C :out
  D :res
*/
#define fr fscanf
void setspj(string u = "sample")
{
     string in = u+".in";string ou = u+".out";
     string comp = u+".ans";string res = "result.txt";
     A = fopen(in.c_str(),"r");B = fopen(comp.c_str(),"r");
     C = fopen(ou.c_str(),"r");D = fopen(res.c_str(),"w");
}
void closespj()
{
     fclose(A);fclose(B);fclose(C);fclose(D);
}
