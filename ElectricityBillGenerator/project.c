// Project Detail: Every can check there electricity bill and pay their bill using this c program.
// They only need to input their meter reading and they will get their bill amount and other information regarding bill
// They can also check their paid bill receipt after paying the bill.

#include <stdio.h>


//function Declaration
float AmountOfBill(int meterReading);
void billPerUnit(int meterReading);
float elecDuty(float amount);
float gstax(float amount);
double totalPrice(float amount, float electricityDuty, float gst);
float retrunAmount(float cash, double totalAmount);


//main
int main()
{
	FILE *fptr;
	float meterReading = 0.0, cash = 0.0, pricePerUnit = 0.0, electricityDuty = 0.0, gst = 0.0;
	int choice = 0,  year = 0;
	float amount = 0.0, amountReturn = 0;
	double totalAmount = 0.0;
	char meterNum[1000];
	char month[20];
	char traffic = 0;
	float meterRent = 0.0, tvl = 0.0, bCharges = 0.0;
	meterRent = 7.50;
	tvl = 35.00;
	bCharges = 8.0;
	char c[1000];

	printf("\n1. to pay bill");
	printf("\n2. to check your bills");
	printf("\n3. to quit");
	while(!(choice == 1 || choice == 2 || choice == 3))	// Main Menu Choice
	{
		printf("\n\nEnter your choice: ");
		scanf("%d",&choice);
	}
	system("cls");
	printf("\n");
	if(choice == 1)
	{
		printf("Enter meter no: ");
		scanf("%s",meterNum);
		printf("Enter meter reading: ");
		scanf("%f",&meterReading);
		printf("Enter month: ");
		scanf("%s",month);
		printf("Enter year: ");
		scanf("%d",&year);
		fptr = fopen(meterNum,"w");

	system("cls");
	printf("\n");

	//calling functions
	amount = AmountOfBill(meterReading);
	electricityDuty = elecDuty(amount);
	gst = gstax(amount);
	totalAmount = totalPrice(amount, electricityDuty, gst);

	//printing information on console.
	printf("*****************************************************************\n\n");
	printf("\n\nMeter Number:\t\t\t\t%s",meterNum);
	printf("\nMeter Reading:\t\t\t\t%.2f",meterReading);
	printf("\nMonth:\t\t\t\t\t%s",month);
	printf("\nyear:\t\t\t\t\t%d\n",year);
	printf("*****************************************************************\n\n");
	printf("Your bill for %s %d is: \t\t%.2f PKR",month, year ,amount);
	billPerUnit(meterReading);
	printf("\nElectricity Duty: \t\t\t%.2f",electricityDuty);
	printf("\nGeneral Sales Tax: \t\t\t%.2f",gst);
	printf("\nMeter Rent: \t\t\t\t%.2f",meterRent);
	printf("\nBank Charges: \t\t\t\t%.2f",bCharges);

	printf("\n\n*****************************************************************");

	printf("\n\nYour total payable bill amount is : \t\t%.2lf PKR",totalAmount);

	printf("\n\n*****************************************************************");

	//saving information in file
	fprintf(fptr,"*****************************************************************\n\n");
	fprintf(fptr,"\n\nMeter Number:\t\t\t\t%s",meterNum);
	fprintf(fptr,"\nMeter Reading:\t\t\t\t%.2f",meterReading);
	fprintf(fptr,"\nMonth:\t\t\t\t\t\t%s",month);
	fprintf(fptr,"\nyear:\t\t\t\t\t\t%d\n",year);
	fprintf(fptr,"*****************************************************************\n\n");
	fprintf(fptr,"Your bill for %s %d is: \t%.2f PKR",month, year ,amount);
	fprintf(fptr,"\nElectricity Duty: \t\t\t%.2f",electricityDuty);
	fprintf(fptr,"\nGeneral Sales Tax: \t\t\t%.2f",gst);
	fprintf(fptr,"\nMeter Rent: \t\t\t\t%.2f",meterRent);
	fprintf(fptr,"\nBank Charges: \t\t\t\t%.2f",bCharges);


	fprintf(fptr,"\n\n*****************************************************************");

	fprintf(fptr,"\n\nYour total payable bill amount is : \t\t%.2lf PKR",totalAmount);

	fprintf(fptr,"\n\n*****************************************************************");

	while(!(cash >= totalAmount))
	{
		//taking input on consle.
		printf("\n\n\nplease pay bill amount: ");
		scanf("%f", &cash);
	}
	amountReturn = retrunAmount(cash, totalAmount);
	
	//printing information on console.
	printf("\nYour Give: \t\t\t\t%.2f PKR ",cash);
	printf("\nYour change: \t\t\t\t%.2f PKR",amountReturn);
	printf("\n\n*****************************************************************");

	//printing information on console.
	fprintf(fptr,"\nYour Give: \t\t\t\t%.2f PKR ",cash);
	fprintf(fptr,"\nYour change: \t\t\t\t%.2f PKR",amountReturn);
	fprintf(fptr,"\n\n*****************************************************************");
	}
	else if(choice == 2)
	{
		printf("Enter meter no: ");
		scanf("%s",meterNum);
		fptr = fopen(meterNum,"r");
		if ( (fptr = fopen(meterNum,"r")) == NULL)
		{
			printf("\nBill Fill is not payed\n");
			return 0;
		}
		else if ((fptr = fopen(meterNum,"r")) != NULL)
		{
				while(!feof(fptr))
				{
					fgets(c,1000, fptr);
					printf("%s",c);
				}
			return 0;
		}

	}
	else if(choice == 3)
	{
		return 0;
	}
	fclose(fptr);
	return 0;
}

//function defination
float AmountOfBill(int meterReading)
{
	float  amount = 0, amount1 = 0, amount2 = 0, amount3 = 0;

	if(meterReading <= 50)
	{
		amount = meterReading * 2.0;
	}
	else if(meterReading > 50 && meterReading <= 100)
	{
		amount = meterReading * 5.79;
	}
	else if(meterReading > 100 && meterReading <= 200)
	{
		amount = meterReading * 8.11;
	}
	else if(meterReading > 200 && meterReading <= 300)
	{
		meterReading = meterReading - 200;
		amount1 = 200 * 8.11;
		amount = meterReading * 10.20;
		amount = amount + amount1;
	}
	else if(meterReading > 300 && meterReading <= 700)
	{
		meterReading = meterReading - 300;
		amount1 = 200 * 8.11;
		amount2 = 100 * 10.20;
		amount = meterReading * 16.0;
		amount = amount + amount1 + amount2;
	}
	else if(meterReading > 700)
	{
		meterReading = meterReading - 700;
		amount1 = 200 * 8.11;
		amount2 = 100 * 10.20;
		amount3 = 400 * 16.0;
		amount = meterReading * 18.0;
		amount = amount + amount1 + amount2 + amount3;
	}

	return amount;
}

void billPerUnit(int meterReading)
{

	if(meterReading <= 50)
	{
		printf("\nPrice per unit you have payed is:\t ");
		printf("0 - 50 units = 2.0");
	}
	else if(meterReading > 50 && meterReading <= 100)
	{
		printf("\nPrice per unit you have payed is :\t ");
		printf("0 - 100 units = 5.79");
	}
	else if(meterReading > 100 && meterReading <= 200)
	{
		printf("\nPrice per unit you have payed is:\t ");
		printf("0 - 200 units = 8.11");
	}
	else if(meterReading > 200 && meterReading <= 300)
	{
		printf("\nPrice per unit you have payed is :\t");
		printf("0 - 200 units = 8.11");
		printf("\n\t\t\t\t\t201 - 300 units = 10.20");
	}
	else if(meterReading > 300 && meterReading <= 700)
	{
		printf("\nPrice per unit you have payed is:\t");
		printf("0 - 200 units = 8.11");
		printf("\n\t\t\t\t\t201 - 300 units = 10.20");
		printf("\n\t\t\t\t\t301 - 700 units = 16.0");
	}
	else if(meterReading > 700)
	{
		printf("\nPrice per unit you have payed is:\t ");
		printf("0 - 200 units = 8.11");
		printf("\n\t\t\t\t\t201 - 300 units = 10.20");
		printf("\n\t\t\t\t\t301 - 700 units = 16.0");
		printf("\n\t\t\t\t\t700 - above units = 18.0");
	}

}

float elecDuty(float amount)
{
	float electricityDuty = 0.0;
	electricityDuty = (amount * 1.50) / 100;

	return electricityDuty;
}

float gstax(float amount)
{
	float gst = 0.0;
	gst = (amount * 17) / 100;

	return gst;
}

double totalPrice(float amount, float electricityDuty, float gst)
{

	double totalAmount = 0;
	float meterRent = 0.0, tvl = 0.0, bCharges = 0.0;
	meterRent = 7.50;
	tvl = 35.00;
	bCharges = 8.0;

	totalAmount = amount + meterRent + electricityDuty + gst + tvl + bCharges;

	return totalAmount;
}

float retrunAmount(float cash, double totalAmount)
{
	float amountReturn = 0.0;
		amountReturn = cash - totalAmount;
	return amountReturn;
}
