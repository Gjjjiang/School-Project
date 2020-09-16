#include <iostream>
using namespace std;
 
static double zero[3][3]={{0,0,0},{0,0,0},{0,0,0}};
 
class Matrix{
 private:
   double arr[3][3]={0};
 
 
 public:
   Matrix(double a[3][3]=zero);
   void set_matrix(double[3][3]);
   Matrix addition(Matrix &);
   Matrix scalar_multiplication(double);
   Matrix multiplication(Matrix&);
   Matrix transpose();
   bool is_symetric();
   bool is_inverse(Matrix&);
   double determinant();
   void print();
 
   friend ostream & operator << (ostream &,  Matrix &);
   friend istream & operator >> (istream &,  Matrix &);
 
};
 
Matrix::Matrix(double a[3][3]){
 set_matrix(a);
}
 
void Matrix::set_matrix(double m[3][3]){
 for(int i=0;i<3;i++){
   for(int j=0;j<3;j++){
     arr[i][j]=m[i][j];
   }
 }
}
 
Matrix Matrix::addition(Matrix& b){
 Matrix c;
 for(int i=0;i<3;i++){
   for(int j=0;j<3;j++){
     c.arr[i][j]=arr[i][j]+b.arr[i][j];
   }
 }
 return c;
}
 
Matrix Matrix::scalar_multiplication(double k){
 Matrix c;
 for(int i=0;i<3;i++){
   for(int j=0;j<3;j++){
     c.arr[i][j]=arr[i][j]*k;
   }
 }
 
 return c;
}
 
Matrix Matrix::multiplication(Matrix& b){
 Matrix c;
 for(int i=0;i<3;i++){
   for(int j=0;j<3;j++){
     for(int counter=0;counter<3;counter++){
       c.arr[i][j]+=arr[i][counter]*b.arr[counter][j];
     }
   }
 }
 
 return c;
}
 
Matrix Matrix::transpose(){
 Matrix c;
 for(int i=0;i<3;i++){
   for(int j=0;j<3;j++){
     c.arr[i][j]=arr[j][i];
   }
 }
 
 return c;
}
 
bool Matrix::is_symetric(){
 Matrix c=transpose();
 
 for(int i=0;i<3;i++){
   for(int j=0;j<3;j++){
     if(c.arr[i][j]!=arr[i][j])return false;
   }
 }
 return true;
 
}
 
bool Matrix::is_inverse(Matrix& b){
 if(determinant()==0)return false;
 else{
   Matrix temp = transpose();
   Matrix c;
   c.arr[0][0]= temp.arr[1][1]*temp.arr[2][2]-temp.arr[2][1]*temp.arr[1][2];
   c.arr[0][1]= temp.arr[1][0]*temp.arr[2][2]-temp.arr[2][0]*temp.arr[1][2];
   c.arr[0][2]= temp.arr[1][0]*temp.arr[2][1]-temp.arr[2][0]*temp.arr[1][1];
 
   c.arr[1][0]= temp.arr[0][1]*temp.arr[2][2]-temp.arr[2][1]*temp.arr[0][2];
   c.arr[1][1]= temp.arr[0][0]*temp.arr[2][2]-temp.arr[2][0]*temp.arr[0][2];
   c.arr[1][2]= temp.arr[0][0]*temp.arr[2][1]-temp.arr[2][0]*temp.arr[0][1];
 
   c.arr[2][0]= temp.arr[0][1]*temp.arr[1][2]-temp.arr[1][1]*temp.arr[0][2];
   c.arr[2][1]= temp.arr[0][0]*temp.arr[1][2]-temp.arr[1][0]*temp.arr[0][2];
   c.arr[2][2]= temp.arr[0][0]*temp.arr[1][1]-temp.arr[1][0]*temp.arr[0][1];
  
   c=c.scalar_multiplication(1.0/determinant());
   int counter=0;
   for(int i=0;i<3;i++){
     for(int j=0;j<3;j++){
       if(counter%2==1)c.arr[i][j]*=-1;
       if(c.arr[i][j]==0)c.arr[i][j]=0;//removes -0
       counter++;
     }
   }
 
   //cout<<c<<endl;
 
   for(int i=0;i<3;i++){
     for(int j=0;j<3;j++){
       if(c.arr[i][j]!=b.arr[i][j])return false;
     }
   }
  
   return true;
  
 }
}
 
double Matrix::determinant(){
 double a,b,c, sum;
 
 a=arr[1][1]*arr[2][2]-arr[2][1]*arr[1][2];
 b=arr[1][0]*arr[2][2]-arr[1][2]*arr[2][0];
 c=arr[1][0]*arr[2][1]-arr[1][1]*arr[2][0];
  return (arr[0][0]*a) - (arr[0][1]*b) + (arr[0][2]*c);
}
void Matrix::print(){
 for(int i=0;i<3;i++){
   for(int j=0;j<3;j++){
     cout<<arr[i][j]<<" ";
   }
   cout<<endl;
 }
}
 
ostream & operator << (ostream & out,  Matrix & n){
 for(int i=0;i<3;i++){
   for(int j=0;j<3;j++){
     out<<n.arr[i][j]<<" ";
   }
   out<<"\n";
 }
 return out;
}
 
istream & operator >> (istream & in,  Matrix & n){
 for(int i=0;i<3;i++){
   for(int j=0;j<3;j++){
     in>>n.arr[i][j];
   }
 }
 return in;
}
 
 
int main() {
 //double m[3][3]={{-1,-0.25,0.5},{-0.25,0.25,0.25},{0.5,0.25,0}};
 //double n[3][3]={{1,2,3},{2,4,2},{3,2,5}};
 //Matrix a(m);
 //Matrix b(n);
 Matrix i,j;
 double c;
 cout<<"Enter 1st Matrix"<<endl;
 cin>>i;
 cout<<"Enter 2nd Matrix"<<endl;
 cin>>j;
 cout<<"Enter a constant"<<endl;
 cin>>c;
 
 cout<<"The sum of both matrices is"<<endl;
 i.addition(j).print();
 
 cout<<"Scalar multiplication of 1st matrix"<<endl;
 i.scalar_multiplication(c).print();
 
 cout<<"Scalar multiplication of 2nd matrix"<<endl;
 j.scalar_multiplication(c).print();
 
 cout<<"Product of first and second matrix"<<endl;
 i.multiplication(j).print();
 
 cout<<"transpose 1st matrix"<<endl;
 i.transpose().print();
 
 cout<<"transpose 2nd matrix"<<endl;
 j.transpose().print();
 
 if(i.is_symetric()){
   cout<<"first matrix is symetric"<<endl;
 }
 else cout<<"first matrix is not symetric"<<endl;
 
 if(j.is_symetric()){
   cout<<"second matrix is symetric"<<endl;
 }
 else cout<<"second matrix is not symetric"<<endl;
 
 if(i.is_inverse(j)){
   cout<<"second matrix is inverse of the first"<<endl;
 }
 else cout<<"second matrix is not inverse of the first"<<endl;
 
 if(j.is_inverse(i)){
   cout<<"first matrix is inverse of the second"<<endl;
 }
 else cout<<"first matrix is not inverse of the second"<<endl;
 
 cout<<"determinant of the first matrix is"<<endl;
 cout<<i.determinant()<<endl;
 
 cout<<"determinant of the second matrix is"<<endl;
 cout<<j.determinant()<<endl;
 
}
