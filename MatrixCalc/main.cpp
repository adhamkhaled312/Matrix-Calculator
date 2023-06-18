#include <iostream>
using namespace std;


void addition(int matA[10][10],int matB[10][10],int dimA1,int dimA2);
void subtraction(int matA[10][10],int matB[10][10],int dimA1,int dimA2);
void multiplication(int matA[10][10],int matB[10][10],int dimA1,int dimA2,int dimB1,int dimB2);
long long int determinant(int mat[10][10],int dim);


int main()
{
int dimA1,dimA2,dimB1,dimB2,choice,i,j;
cout<<"Please enter dimensions of Matrix A:\n";
cin>>dimA1>>dimA2;
cout<<"Please enter dimensions of Matrix B:\n";
cin>>dimB1>>dimB2;
int matA[10][10];
int matB[10][10];
cout<<"Please enter values of Matrix A:\n";
for(i=0;i<dimA1;i++){
    for(j=0;j<dimA2;j++){
        cin>>matA[i][j];
    }
}
cout<<"Please enter values of Matrix B:\n";
for(i=0;i<dimB1;i++){
    for(j=0;j<dimB2;j++){
        cin>>matB[i][j];
    }
}
do{
cout<<"Please choose operation type(1: A+B, 2: A-B, 3: AxB, 4: A*inverse(B), 5: |A|, 6: |B|, 7: quit):\n";
cin>>choice;
switch(choice){
case 1:
    if (dimA1!=dimB1 || dimA2!=dimB2){
        cout<<"The operation you chose is invalid for the given matrices.\n";
        break;
    }
    addition(matA,matB,dimA1,dimA2);
    break;
case 2:
    if (dimA1!=dimB1 || dimA2!=dimB2){
        cout<<"The operation you chose is invalid for the given matrices.\n";
        break;
    }
    subtraction(matA,matB,dimA1,dimA2);
    break;
case 3:
    if (dimA2!=dimB1){
       cout<<"The operation you chose is invalid for the given matrices.\n";
        break;
    }
    multiplication(matA,matB,dimA1,dimA2,dimB1,dimB2);
    break;
case 5:
    if(dimA1!=dimA2){
        cout<<"The operation you chose is invalid for the given matrices.\n";
        break;
    }
    cout<<determinant(matA,dimA1)<<endl;
    break;
case 6:
    if(dimB1!=dimB2){
        cout<<"The operation you chose is invalid for the given matrices.\n";
        break;
    }
    cout<<determinant(matB,dimB1)<<endl;
    break;

case 7:
    cout<<"Thank you!";
    break;

}
}while(choice!=7);
}


void addition(int matA[10][10],int matB[10][10],int dimA1,int dimA2){
int result [10][10];
for(int i=0;i<dimA1;i++){
    for(int j=0;j<dimA2;j++){
        result[i][j]=matA[i][j]+matB[i][j];
        cout<<result[i][j]<<" ";

    }
    cout<<endl;
    }
}


void subtraction(int matA[10][10],int matB[10][10],int dimA1,int dimA2){
int result [10][10];
for(int i=0;i<dimA1;i++){
    for(int j=0;j<dimA2;j++){
        result[i][j]=matA[i][j]-matB[i][j];
        cout<<result[i][j]<<" ";

    }
    cout<<endl;
    }
}


void multiplication(int matA[10][10],int matB[10][10],int dimA1,int dimA2,int dimB1,int dimB2){
int res=0;
int res1;
int result[dimA1][dimB2];
for(int i=0;i<dimA1;i++){
    for(int j=0;j<dimB2;j++){
        for(int k=0;k<dimB1;k++){
            res1=matA[i][k]*matB[k][j] ;
            res=res+res1;
            if (k==dimB1-1){
                result[i][j]=res;
                cout<<result[i][j]<<" ";
                res=0;
            }

            }

        }
    cout<<endl;
    }
}


long long int determinant(int mat[10][10],int dim){
void submat(int mat[10][10],int submatr[10][10],int dim,int norow,int nocol);

long long int res=0;
if (dim==1){
    return mat[0][0];
    }
else if(dim==2){
    return (mat[0][0]*mat[1][1])-(mat[0][1]*mat[1][0]);
}
else{
    int submatr[10][10];
    int sign=1;
    for (int i=0;i<dim;i++){
        submat(mat,submatr,dim,0,i);
        res+=sign*mat[0][i]*determinant(submatr,dim-1);
        sign=-sign;
    }
}
return res;
}

void submat(int mat[10][10],int submatr[10][10],int dim,int norow,int nocol){
int a=0,b=0;
for(int i=0;i<dim;i++) {
    for(int j=0;j<dim;j++){
        if (i!=norow && j!=nocol){
            submatr[a][b]=mat[i][j];
            b++;

            if (b==dim-1){
                a++;
                b=0;
            }

        }

    }
}

}
