#include <stdio.h> 
#include <stdlib.h> 

float x1, x2, delta, a, b, c; 


#define SQRT_MAGIC_F 0x5f3759df 
float thesqrt(const float x)
{
	const float xhalf = 0.5f*x;
 
	union
	{
		float x;
		int i;
	} u;
	
	u.x = x;
	u.i = SQRT_MAGIC_F - (u.i >> 1);  
	return x*u.x*(1.5f - xhalf*u.x*u.x);
}   

double inline __declspec (naked) __fastcall asmsqrt(double n)
{
	_asm fld qword ptr [esp+4]
	_asm fsqrt
	_asm ret 8
} 

int main(void)
{ 
	
	printf("Entrez les valeurs des: a, b, c \n"); 
	scanf("%f %f %f",&a, &b, &c); 

	delta = (b*b)-(4*a*c); 

	if (delta == 0.0) 
	{ 

		x1 = -b /(2*a); 
		printf("la solution unique est xs = %.2f \n",x1); 

	} else if (delta > 0.0) 
	{ 

		//x1 = (-b - thesqrt(delta))/(2*a); 
		//x2 = (-b + thesqrt(delta))/(2*a); 
		x1 = (-b - asmsqrt(delta))/(2*a); 
		x2 = (-b + asmsqrt(delta))/(2*a); 
		printf("les deux racines sont : x1 = %.2f et x2 = %.2f \n",x1, x2); 

	} else	
	{
		printf("l'equation n admet pas de solution\n"); 
	}

	return 0; 
}
