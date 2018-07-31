#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MAXIMAL_AIRLINES 10
#define DEST 6
#define DIM 2
#define HUGE_INT 1000000

char* destinations[]={"Miami", "Rio", "Moscow", "Shanghai", "Barcelona", "Melbourne"};

int fillPricesTable(double flightsPrices[][DEST],int n, double* dollarRate);

void compute(double flightsPrices[][DEST],int length,
				double* max,double* min,int* bestAirLine);

void bestPrice(double flightsPrices[][DEST],int length,
		double bestPrices[DEST][DIM],double dollarRate);

void printBestPrices(double bestPrices[DEST][DIM]);

void printMinMaxAvg(double max, double min, int bestAirLine);

void errorPrice(int row);

void errorDollar();


int main()
{
	int num_of_airlines=0, bestAirLine=0;
	double prices[MAXIMAL_AIRLINES][DEST];
    double dollarRate=0, max=0, min=0;
	double bestPrices[DEST][DIM]={{0}};
    num_of_airlines = fillPricesTable(prices, MAXIMAL_AIRLINES, &dollarRate);
    if(num_of_airlines == -1)
        return 1;
	compute(prices, num_of_airlines, &max, &min, &bestAirLine);
    printMinMaxAvg(max, min, bestAirLine);
	bestPrice(prices, num_of_airlines, bestPrices, dollarRate);
	printBestPrices(bestPrices);
    return 0;
}

int fillPricesTable(double flightsPrices[][DEST],int n, double* dollarRate)
{
    int counter = 0;

    do{
        scanf(" %lf", dollarRate );
        if(*dollarRate <= 0 )
        {
            errorDollar();
        }
    }while(*dollarRate <= 0);


    for(int counter=0; counter<n; counter++)
    {
        /*Enter price for each dest*/
        for(int i=0; i < DEST ; i++ )
        {
            if(scanf(" %lf", &flightsPrices[counter][i])==EOF) /*when to top input*/
            {
                return counter;
            }
            if(flightsPrices[counter][i]==0)
            {
                errorPrice(counter);
                return -1;
            }
        }
    }
    /*print amount of rows filled*/
    return counter;
}

void compute(double flightsPrices[][DEST],int length, double* max,double* min,int* bestAirLine)
{
    //printf("Number of rows is: %d)", length);
    int i, j, curr_price;
    /*for(j=0; j<length; j++)
    {
        for(i=0; i<DEST; i++)
        {
            printf("%.2f ", flightsPrices[j][i]);
        }
        printf("\n");
    }*/
    double curr_max = 0, curr_min = flightsPrices[0][0],price, best_sum=HUGE_INT, overall_sum=0;
    *min = curr_min;
    for(j=0; j<length; j++)
    {
        overall_sum = 0;
        for(i=0; i<DEST; i++)
        {
            /*sum first airline*/
            //printf("%.2f", flightsPrices[j][i]);
            curr_price = flightsPrices[j][i];
            overall_sum += curr_price;
        }
        //printf("%.2f\n", overall_sum);
        if(overall_sum < best_sum)
        {
            //printf("Overall sum is lower than best sum\n");
            *bestAirLine = j;
            best_sum = overall_sum;
        }
    }
    for(j=0; j< DEST; j++)
    {
        for(i=0; i<length; i++)
        {
            //printf("Initial min: %.2f\n", curr_min);
            price = flightsPrices[i][j];
            //printf("%.2f", price);
            if(price > curr_max)
            {
                //printf("Enterd max condition and is %.2f", price);
                curr_max = price;
                *max = curr_max;
            }
            if(price<=curr_min && price>0 && curr_min>0)
            {
                curr_min = price;
                *min = curr_min;
                //printf("Current min: %.2f\n", *min);
            }
        }
    }
}
void bestPrice(double flightsPrices[][DEST], int length,
               double bestPrices[DEST][DIM], double dollarRate)
{
    int company=0;
    double min;
    /*Iterate flightsPrices col*/
    for(int i=0; i<DEST; i++)
    {
        min = flightsPrices[0][i];
        //printf("Entered loop mean: %.2f ", min);
        /*Iterate flightPrices rows*/
        for(int j=0; j<length; j++)
        {
            if(flightsPrices[j][i]<= min && flightsPrices[j][i]>0)
            {
            /*keep lowest price*/
            min = flightsPrices[j][i];
            company = j;
            //printf("Entered if %.2f ", min);
            }
        }
        /*insert into bestPrices after conversion*/
        bestPrices[i][0] = company;
        bestPrices[i][1] = (double)(min*dollarRate);
    }
}
void printBestPrices(double bestPrices[DEST][DIM]){
		for(int i=0; i<DEST; i++){
		printf("Best offer for %s is ", destinations[i]);
		printf("Airline # %d price: %.2f shekels\n", (int)(bestPrices[i][0]), bestPrices[i][1]);
	}
}
void printMinMaxAvg(double max, double min, int bestAirLine){
    printf("Maximal price: %.2f\nMinimal price: %.2f\nBest Airline: %d\n", max, min, bestAirLine);
}

void errorPrice(int row){
	printf("ERROR: invalid price in airline # %d\n", row);
}

void errorDollar(){
	printf("ERROR: invalid dollar rate, try again!\n");
}
