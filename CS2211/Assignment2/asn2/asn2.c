#include <stdio.h>
//Yimin Xu
//250876566

//Converter
int main(void)
{
	int com;
	char com1;
	
	printf("Enter your command 'number' for conversion between\n");
	printf("1 Kilogram and Pound\n");
	printf("2 Litre and Gallon\n");
	printf("3 Centimetre and Inch\n");
	printf("4 Celsius and Fahrenheit\n");
	printf("5 Quit\n");

	scanf(" %d",&com);
	
	//Keep reading command until the user enter 5 
	while (com != 5)
	{

		//Kilogram and Pound
		if (com == 1)
		{
			float p,k;
			printf("Enter K 'kilogram to pound' or P 'pound to kilogram': "); 
			scanf(" %c",&com1);
			if (com1 == "K"[0])
			{
				printf("Enter kilogram: ");
				scanf(" %f",&k);
				p = 2.20462262 * k;
				printf("%f kilograms = %f pounds\n",k,p);
			}
			else if (com1 == "P"[0])
			{
				printf("Enter pounds: ");
				scanf(" %f",&p);
				k = 0.45359237 * p;
				printf("%f pounds = %f kilograms\n",p,k);	
			}		
			else
			{
				printf("\nInvalid input.\n");
			}
		}

		//Litre and Gallon
		else if (com == 2)
		{
			float l,g;
			printf("Enter L 'litre to gallon' or G 'gallon to litre': "); 
			scanf(" %c",&com1);
			if (com1 == "L"[0])
			{
				printf("Enter litre: ");
				scanf(" %f",&l);
				g = 0.264172052 * l;
				printf("%f litres = %f gallons\n",l,g);
			}
			else if (com1 == "G"[0])
			{
				printf("Enter gallon: ");
				scanf(" %f",&g);
				l = 3.78541178 * g;
				printf("%f gallons = %f litres\n",g,l);	
			}		
			else
			{
				printf("\nInvalid input.\n");
			}
		}
		
		//Centimetre and Inch
		else if (com == 3)
		{
			float c,i;
			printf("Enter C 'centimetre to inch' or I 'inch to centimetre': "); 
			scanf(" %c",&com1);
			if (com1 == "C"[0])
			{
				printf("Enter centimetre: ");
				scanf(" %f",&c);
				i = 0.393700887 * c;
				printf("%f centimetres = %f inches\n",c,i);
			}
			else if (com1 == "I"[0])
			{
				printf("Enter inch: ");
				scanf(" %f",&i);
				c = 2.54 * i;
				printf("%f inches = %f centimetres\n",i,c);	
			}		
			else
			{
				printf("\nInvalid input.\n");
			}
		}

		//Celcius and Fahrenheit
		else if (com == 4)
		{
			float c,f;
			printf("Enter C 'Celcius to Fahrenheit' or F 'Fahrenheit to Celcius': "); 
			scanf(" %c",&com1);
			if (com1 == "C"[0])
			{
				printf("Enter Celcius: ");
				scanf(" %f",&c);
				f = 1.8 * c + 32;
				printf("%f C = %f F\n",c,f);
			}
			else if (com1 == "F"[0])
			{
				printf("Enter Fahrenheit: ");
				scanf(" %f",&f);
				c = (f - 32) / 1.8;
				printf("%f F = %f C\n",f,c);	
			}		
			else
			{
				printf("\nInvalid input.\n");
			}
		}else	printf("\nInvalid input.\n");
		
		printf("--------------------------------");
		printf("\n\nEnter your command 'number' for conversion between\n");
		printf("1 Kilogram and Pound\n");
		printf("2 Litre and Gallon\n");
		printf("3 Centimetre and Inch\n");
		printf("4 Celsius and Fahrenheit\n");
		printf("5 Quit\n");

		scanf(" %d",&com);
	}

	printf("\nEnd\n");
	return 0;	
}
