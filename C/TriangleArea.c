#include<stdio.h>

#include<conio.h>

int main()

{

float height, base, area;

printf(“Enter height of triangle:”);

scanf(“%f”,&height);

printf(“\n Enter base of triange:”);

scanf(“%f”, &base);

area=1/2 *base*height;

printf(“\n The area of the triangle is : %.2f”, area);

getch();

}
