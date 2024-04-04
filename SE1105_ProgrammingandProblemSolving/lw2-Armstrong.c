#include <stdio.h>

int main()
{
	int ilksayi=0;
	int dongu;
	int donguiki;
	int bsmaksayi=0;
	int bsmakdgeri;
	int toplam=0;
	printf("Please enter an integer: \n");
	scanf_s("%d",&ilksayi);

	for ( dongu = ilksayi; dongu>0 ; dongu = dongu/10) 
	{
		bsmaksayi = bsmaksayi+1;
		//printf("bsmaksayi: %d \n",bsmaksayi);
	}
	
	for( dongu = ilksayi ; dongu>0 ; dongu = dongu/10)
	{
		bsmakdgeri = dongu%10;
		for ( donguiki = 1; bsmaksayi>donguiki ; donguiki++ )
		{ 
			bsmakdgeri = bsmakdgeri*(dongu%10);
		}
		
		//printf("bsmakdgeri: %d \n", bsmakdgeri);

		toplam = toplam + bsmakdgeri;
		//printf("toplam: %d \n", toplam);
	}	
	
	if ( ilksayi == toplam )
	printf("%d is an Armstrong number.", ilksayi);
	
	else
	printf("%d is not an Armstrong number.", ilksayi);
	
}
