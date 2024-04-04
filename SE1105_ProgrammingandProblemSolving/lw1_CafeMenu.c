#include <stdio.h>
#include <stdbool.h> 

void menu()
{
	printf("Welcome to our cafe. Would you like to see our menu?\n");
	printf("If you want to see press(1), If you don't want press(2)\n");
	int menu;
	scanf_s("%d", &menu);
	printf("\n");
		if(menu == 1)
		{
			printf("--Coffee Menu--\n");
			printf("Espresso($5.00)\n");
			printf("Americano($6.00)\n");
			printf("Machiato($7.00)\n");
			printf("White Chocolate Mocha($8.00)\n");
			printf("\n");
			
			printf("--Dessert Menu--\n");
			printf("Cupcake($5.00)\n");
			printf("Cheesecake($5.00)\n");
			printf("Cookie($3.00)\n");
			printf("\n");
		}
}


int order_type()
{
	printf("What would you like to order?\n");
	printf("Only Coffee(1), Only Dessert(2), Coffee and Dessert(3)\n");
	int order;
	scanf_s("%d",&order);
	printf("\n");
	return order;	
}


int coffee_type()
{ 
	printf("Espresso(1), Americano(2), Machiato(3), White Chocolate Mocha(4)\n");
	int coffee;
	int easter;
	scanf_s("%d",&coffee);
	printf("\n");
	if(coffee == 4 )
		{
			printf("You have good taste in coffee! With this choice, you get a discount.\n");
			printf("If you buy a cookie, you will be able to take advantage of the discount.(Total Price-$5.00)\n");
			
			easter = easter_egg();
				if(easter == 1)
				{
					coffee = 5;
				}
			
		}
	return coffee;
}

int easter_egg()
{
	printf("Would you like to take advantage of the discount by buying a cookie?\n");
	printf("Yes(1), No(2)");
	printf("\n");
	int easter_egg;
	scanf_s("%d",&easter_egg);
	printf("\n");
	return easter_egg;
}

int coffee_size()
{
	printf("Which size do you prefer?\n");
	printf("Short(1), Tall(2), Grande(3).\n");
	int size;
	scanf_s("%d",&size);
	printf("\n");
	return size;
}

int coffee_sugar()
{
	printf("Do you want to add sugar?\n");
	printf("Add Sugar(1), No sugar(2)\n");
	int sugar;
	scanf_s("%d",&sugar);
	printf("\n");
	return sugar;
}

int coffee_heat()
{
	printf("Do you prefer your coffee hot or cold?\n");
	printf("Hot(1) or Cold(2)\n");
	int heat;
	scanf_s("%d",&heat);
	printf("\n");
	return heat;
}


int dessert_choice()
{
	printf("Cupcake(1), Cheesecake(2), Cookie(3)\n");
	int dessert;
	scanf_s("%d",&dessert);
	printf("\n");
	return dessert;
}



void cost(int coffee_type, int coffee_size, int coffee_sugar, int coffee_heat, int dessert_choice)
{   int price=0;
        if(coffee_type == 1){
        	price = 5;
        }
        
        else if(coffee_type == 2)
        {
        	price = 6;
		}
		
		else if(coffee_type == 3)
		{
			price = 7;
		}
		
		else if(coffee_type == 4 || coffee_type == 5)
		{ 
			price = 8;
		}
		
				
		if(coffee_size == 1)
		{ 
			price = price*1;
		}
		
		else if(coffee_size == 2)
		{ 
			price = price*2;
		}
		
		else if(coffee_size == 3)
		{ 
			price = price*3;
		}
				
	if(coffee_sugar == 1)
	{

		price = price+1;
	}
	
	if(coffee_heat == 1)
	{
		price = price*1;
	}
	else if(coffee_heat == 2)
	{
		price = price+2;
	}
	
	
	if(dessert_choice == 1 || dessert_choice == 2)
	{
		price = price+5;
	}
	else if (dessert_choice == 3)
	{
		if(coffee_type == 5)
		{
			price = price-2;
		}
		else
		{
			price = price+3;
		}
	}
	
	
	printf("The price of your order: %d\n",price);

}

void goodbye()
{
    printf("Thanks for choosing us. Have a good day.");
}

void main()
{
	int order;
	int coffee;
	int heat;
	int dessert;
	int size;
	int sugar;
	

	menu();
	order = order_type();
		if(order == 1)
		{ 
			coffee = coffee_type();
				if(coffee == 5)
				{
                size = coffee_size();
                sugar = coffee_sugar();
                heat = coffee_heat();
                dessert = 3;
           		}
           		
          		else
            	{
                size = coffee_size();
                sugar = coffee_sugar();
                heat = coffee_heat();
            	}
				
		}
		
		else if(order == 2)
		{
			dessert = dessert_choice();
		}
	
		else if(order == 3)		
		{
			coffee = coffee_type();
				if(coffee == 5)
				{
                size = coffee_size();
                sugar = coffee_sugar();
                heat = coffee_heat();
                dessert = 3;
           		}
           		
          		else
            	{
                size = coffee_size();
                sugar = coffee_sugar();
                heat = coffee_heat();
                dessert = dessert_choice();
            	}
            	
		}


	cost(coffee,size,sugar, heat,dessert);
	goodbye();
}
