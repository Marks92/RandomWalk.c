// CS 153 PROGRAM ASSIGNMENT #5
// 
// This program is a game where a bug must
// escape from a spiders web
// 
// Mark Schuberth 
// 
// 10/13/2018

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h> /* used for srand() */

/* randDouble() is used to create a random hop for */
/* Flavia between 0-5cm */
double randDouble()
{
  return (5*(double)rand()/((double)RAND_MAX));
}

/* function that converts polar coordinates to rectangular coordinates */
void polarToRect(double radius, double theta, double *x, double *y)
{
 /* theta = a random angle from 0 - 360 degrees */
     /* theta = ( (double)rand()/((double)RAND_MAX+1) ) * 360; */
     
 /* below code is used to change polar coordinates */
 /* to rectangular coordinates */
 *x += radius*cos(theta);
 *y += radius*sin(theta);  
}

/* main function that prompts user for hops */
/* then lets user know is Flavia is free or eaten */
int main()
{
 int i, hops, limit = hops - 1;
 double webRadius = 10.00;
 double distance, x = 0.00, y = 0.00, theta, radius, location;
    
 printf("Number of times Flavia can move -->");
 scanf("%d", &hops);

 srand (time(NULL));
    
 /* bug starts at origin (0.00,0.00) until free/eaten */
 printf("Bug starts at (%0.2lf, %0.2lf)\n", x, y);
 
 /* main loop that calculates distance of Flavia from */
 /* the center of the web and prints Flavia's location */
 for(i =0; i <= hops; i++)
 {
   radius = randDouble();
   theta = ((double)rand()/((double)RAND_MAX+1)) * 360;
   
   polarToRect(radius,theta,&x,&y);
   
   distance = sqrt(x*x + y*y);
   
      
   printf("Flavia's location is: (%0.2lf, %0.2lf)", x, y);
  
   printf(" distance = %0.2lf\n", distance);
   
   if(distance >= webRadius)
   {
       printf("oh No! The bug escapes.");
       exit(EXIT_SUCCESS);
   }

 }
 
 /* if Flavia's distance is greater than 10cm */
  /* and her hops are under the alotted hops */
  /* she's free! otherwise eaten :( */
   printf("YUM YUM. Spider eats the bug.");
  
 
 
 return 0;
}
 
