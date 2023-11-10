#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 512 // cambiar a 512
//Variables exercicis
float V1[N];
float V2[N];
float V3[N];
float V4[N];
float Mat[N][N];
float MatDD[N][N];

//Vectors buits
float V5[N];
float V6[N];
float V7[N];
float V8[N];
float V9[N];
float V10[N];

void InitData(){
int i,j;
srand(4422543);
for( i = 0; i < N; i++ )
 for( j = 0; j < N; j++ ){
 Mat[i][j]=(((i*j)%3)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX)));
 if ( (abs(i - j) <= 3) && (i != j))
 MatDD[i][j] = (((i*j)%3) ? -1 : 1)*(rand()/(1.0*RAND_MAX));
 else if ( i == j )
 MatDD[i][j]=(((i*j)%3)?-1:1)*(10000.0*(rand()/(1.0*RAND_MAX)));
 else MatDD[i][j] = 0.0;
 }
for( i = 0; i < N; i++ ){
 V1[i]=(i<N/2)?(((i*j)%3)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX))):0.0;
 V2[i]=(i>=N/2)?(((i*j)%3)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX))):0.0;
 V3[i]=(((i*j)%5)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX)));
}
}
void PrintVect( float vect[N], int from, int numel ){
	for (int i = from; i < from + numel; i++){
		printf("%f ", vect[i]);
	}
	printf("\n");

}
	
void PrintRow( float mat[N][N], int row, int from, int numel ){
	
	for (int i = from; i < from + numel; i++){
		printf("%f ", mat[row][i]);
	} 
	printf("\n");

}
void MultEscalar( float vect[N], float vectres[N], float alfa ){
	int i;	
	for (int i = 0; i < N; i++){
		vectres[i] = vect[i]*alfa;
	}

}


float Scalar( float vect1[N], float vect2[N] ){
	float a = 0;
	for (int i = 0; i < N; i++){
		a = vect1[i]*vect2[i]+a;
	}
return a;


}

float Magnitude( float vect[N] ){
	double b = 0;
	for (int i = 0; i < N; i++){
		b = vect[i]*vect[i]+b;
	}
	b = sqrt(b);
return b;	
}
int Ortogonal( float vect1[N], float vect2[N] ){
	float c = 0.0;
        for (int i = 0; i < N; i++){
                c = vect1[i]*vect2[i]+c;
	}
	if(c==0.0){
		printf("son Ortogonals\n");
		return c;
	}
	else{
		printf("no son ortogonals\n");
		return c;
	}

}

void Projection( float vect1[N], float vect2[N], float vectres[N] ){
	
	float alfa =(Scalar(vect1, vect2)/Magnitude(vect2));
	MultEscalar(vect2, vectres, alfa); 
}

float Infininorm( float M[N][N] ){
	float max=0.0;
	for (int i = 0; i < N; i++){
		float tmp = 0.0;
		for (int j=0; j < N; j++){
			tmp += fabs((M[i][j]));	
		}
		if (max < tmp){ max = tmp;}
	}
	return max;
}



float Onenorm( float M[N][N] ){
	float max=0.0;
        for (int i = 0; i < N; i++){
                float tmp = 0.0;
                for (int j=0; j < N; j++){
                        tmp += fabs((M[j][i]));
                }
                if (max < tmp){ max = tmp;}
        }
        return max;
}

float NormFrobenius( float M[N][N] ){
	float a = 0.0;
	for (int i = 0; i < N; i++){
                for (int j=0; j < N; j++){
                         a += ((M[i][j])*(M[i][j]));
		}
	}
	a = sqrt(a);
return a;
}


int DiagonalDom( float M[N][N] ){
	int i, j;
	for (int i = 0; i < N; i++){
		float tmp =0.0;
                for (int j=0; j < N; j++){
		}
		if (i!=j){ tmp += M[i][j]; }	
		
		if ( fabs(M[i][i]) < tmp){ return 0; }
	}
	return 1; 
		
}

int Jacobi( float M[N][N] , float vect[N], float vectres[N], unsigned int iter ){
	int j, k;
	float tmp[N];
	if (!DiagonalDom(M)) {
                return 0;
	}

	for (int i = 0; i < N; i++){
		vectres[i] = 0.0;
	}
		
        for (int i=0; i < iter; i++){
		for (j=0; j < N; j++){
			tmp[j] = vect[j];
			for ( k=0; k < N; k++){
				if (j!=k) {
					tmp[j] -= M[k][j] * vectres[j];
				}
			}
			tmp[j] /= M[j][j];
                        vectres[j] = tmp[j];
		}
	}
	return 1;

}


int main(){
	InitData();
	//EXERCICI A
	//printf("V1 del 0 al 9 i del 256 al 265:\n");
	//PrintVect(V1, 0, 10);
	//PrintVect(V1, 256, 10);
	
	//printf("V2 del 0 al 9 i del 256 al 265:\n");
	//PrintVect(V2, 0, 10);
	//PrintVect(V2, 256, 10);
	
	//printf("V3 del 0 al 9 i del 256 al 265:\n");
	//PrintVect(V3, 0, 10);
	//PrintVect(V3, 256, 10);
	

	//EXERCICI B
	//printf("Mat fila 0 i fila 100 del 0 al 9:\n");
	//PrintRow(Mat, 0, 0, 10);
	//PrintRow(Mat, 100, 0, 10);
	
	

	//EXERCICI C
	//printf("MatDD fila 0 del 0 al 9 i fila 100 del 95 al 104:\n");
	//PrintRow(MatDD, 0, 0, 9);
        //PrintRow(MatDD, 100, 95, 10);


	
	//EXERCICI D
	//D_MAT

	//float x = Infininorm(Mat);
	//printf("Infininorma de Mat = %f\n", x);
	//float y = Onenorm(Mat);
	//printf("Norma ú de Mat = %f\n", y);
	//float z = NormFrobenius(Mat);
	//printf("Norma de Frobenius de Mat = %f\n", z);
	//int a = DiagonalDom(Mat);
	//if ( a == 1 ){ printf("La matriu Mat és diagonal dominant\n"); }
	//if ( a == 0 ){  printf("La matriu Mat no és diagonal dominant\n"); }
	

	//D_MATDD

	//float r = Infininorm(MatDD);
	//printf("Infininorma de MatDD = %f\n", r);
        //float s = Onenorm(MatDD);
	//printf("Norma ú de MatDD = %f\n", s);
        //float t = NormFrobenius(MatDD);
	//printf("Norma de Frobenius de MatDD = %f\n", t);
        //int b = DiagonalDom(MatDD);
        //if ( b = 1 ){ printf("La matriu MatDD és diagonal dominant\n"); }
        //if ( b = 0 ){  printf("La matriu MatDD no és diagonal dominant\n"); }
	

	//EXERCICI E
	//float u = Scalar(V1, V2);
        //printf("Escalar <V1,V2> = %f ", u);
	//float v = Scalar(V1, V3);
        //printf("Escalar <V1,V3> =%f ", v);
	//float w = Scalar(V2, V3);
        //printf("Escalar <V2,V3> = %f \n", w);


	//EXERCICI F
	//float x = Magnitude(V1);
	//float y = Magnitude(V2);
	//float z = Magnitude(V3);
        //printf("Magnitud V1,V2 i V3 = %f %f %f\n", x, y, z);


	//EXERCICI G
	//printf("V1 i V2 ");
	//Ortogonal(V1, V2);
	//printf("V1 i V3 ");
	//Ortogonal(V1, V3);
	//printf("V2 i V3 ");
	//Ortogonal(V2, V3);

	//EXERCICI H
	//MultEscalar(V3, V5, 2);
	//printf("Els elements 0 al 9 i 256 al 265 del resultat de multiplicar V3x2.0 són:\n");
	//PrintVect(V5, 0, 10);
	//PrintVect(V5, 256, 10);
	
	
	
	//EXERCICI I
	//Projection(V2, V3, V6);
	//printf("Els elements 0 a 9 del resultat de la projecció de V2 sobre V3 són:\n");
	//PrintVect(V6, 0, 10);
	//Projection(V1, V2, V7);
	//printf("Els elements 0 a 9 del resultat de la projecció de V1 sobre V2 són:\n");
        //PrintVect(V7, 0, 10);


	//EXERCICI J
	int res = Jacobi (MatDD, V3, V8, 1);
	if ( res == 0 ){ printf("La matriu M no és diagonal dominant, no es pot aplicar Jacobi\n");}
	else{
		printf("Els elements 0 a 9 de la solució (1 iter) del sistema d'equacions són:\n");
        	PrintVect(V8, 0, 10);
	}
	
	int res2 = Jacobi (MatDD, V3, V9, 1000);
	if ( res2 == 0 ){ printf("La matriu M no és diagonal dominant, no es pot aplicar Jacobi\n"); }
	else{
		printf("Els elements 0 a 9 de la solució (1000 iters) del sistema d'equacions són:\n");
		PrintVect(V9, 0, 10);
	}
	
	int res3 = Jacobi (Mat, V3, V10, 1);
	if ( res3 == 0 ){ printf("La matriu M no és diagonal dominant, no es pot aplicar Jacobi\n"); }
	else{
		printf("Els elements 0 a 9 de la solució (1 iters) del sistema d'equacions són:\n");
        	PrintVect(V10, 0, 10);
        }
	



}
