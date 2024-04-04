#include <stdio.h>

int squareRoot(int n)
{
	int a = 0;

	for (; a * a < n; a++);


	if (a * a == n)
	{
		return a;
	}
	else
	{
		return  - 1;
	}
}


int main()
{
	int ilksayi=0;
	printf("Please enter an integer: ");
	scanf_s("%d",&ilksayi);
		int degisken;
		int degiskeniki;
		int toplam=0;
		int degiskenuc;
		int kare=1;
		
		for( degisken=1 ; degisken<ilksayi+1; degisken++ )
		{	
			for( degiskeniki=degisken ; degiskeniki>0 ; degiskeniki = degiskeniki/10)
			{
				toplam = toplam + degiskeniki%10;
			}	
			
			
		kare = squareRoot(toplam);
			toplam=0;
			
				if(kare != -1)
				{
					printf("%d ", degisken);
					for( degiskenuc=degisken ; degiskenuc>0 ; degiskenuc = degiskenuc/10)
					{
						if ( degiskenuc == degisken )
						{
							printf("%d",degiskenuc%10);
						}
						else
						{
							printf(":%d",degiskenuc%10);
						}
					}
					
					printf(" %d \n", kare*kare);
				}

		}
	
}
 
