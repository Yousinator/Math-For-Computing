
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define matrix_size 100

void flipImageVertically(int rows, int columns, char image[rows][columns]);
//draw rectangle (x1,y1) length L wedth W
void rect (int x1, int y1,int L,int W, char arr[matrix_size][matrix_size]);
//draw line (x1,y1) to (x2,y2)
void line (int x1, int y1, int x2,int y2, char arr[matrix_size][matrix_size]);
//draw circle center( a,b )  and radius=r
void circle (int a, int b,int r,  char arr[matrix_size][matrix_size]);
//drow Vertical line at x=x1 (x1,y1) to (x1,y2)
void  vertical_Line (int x1, int y1, int y2, char arr[matrix_size][matrix_size]);
int main()
{

char arr[matrix_size][matrix_size];

for(int y = 0; y < matrix_size; y++)
	for(int x = 0; x < matrix_size; x++)
			arr[y][x] = ' '; //fill the matrix with -

		//! left triangle of rectangle
		line(0,55,15,51,arr);
		line(0,55,15,59,arr);
		//! right triangle of rectangle
		line(60,51,75,55,arr);
		line(60,59,75,55,arr);
		//! rectangle
		vertical_Line(15,5,65,arr);
		vertical_Line(60,5,65,arr);
		line(15,5,60,5,arr);
		line(15,65,60,65,arr);
		//! bottom left triangle of rectangle
		line(20,0,25,5,arr);
		line(25,5,30,0,arr);
		line(20,0,30,0,arr);
		//! bottom right triangle of rectangle
		line(45,0,50,5,arr);
		line(50,5,55,0,arr);
		line(45,0,55,0,arr);
		//! top triangle of rectangle
		line(15,65,38,80,arr);
		line(38,80,61,65,arr);

		rect(25,45,10,10,arr);
		rect(40,45,10,10,arr);

		circle(38,30,5,arr);
	   circle(38,15,5,arr);

    //!plot the matrix 
	//! This function sets the image in the right position and plots it
	flipImageVertically(matrix_size,matrix_size,arr);
	
	
	return 0;
	
	
}


//draw rectangle (x1,y1) length L wedth W
void rect (int x1, int y1,int L,int W, char arr[matrix_size][matrix_size])
{
   
	for(int y = 0; y < matrix_size; y++)
	{
		for(int x = 0; x < matrix_size; x++)
		{
			// see if we're within the range of x and y
			if(x > x1 && x < x1+L && (y > y1 && y < y1+W))
			{
				arr[y][x] = '*';
			}
			
		}
	}
	
	
}

//draw circle center( a,b )  and radius=r
void circle (int a, int b,int r, char arr[matrix_size][matrix_size])
{

   double EPSILON = 8;// need to be close to the radius value
   

	for(int y = 0; y < matrix_size; y++)
	{
		for(int x = 0; x < matrix_size; x++)
		{
			
			// see if we're close to (x-a)**2 + (y-b)**2 == r**2

			if( fabs(pow((x-a),2)+pow((y-b),2)-pow(r,2)) < EPSILON)
			{
			
				arr[y][x] = '*';
			}
		}
	}
	
}

  //draw line (x1,y1) to (x2,y2)
void line (int x1, int y1, int x2,int y2, char arr[matrix_size][matrix_size])
{   
  //0=y-m*x-c  
   double EPSILON = 0.5, m, c;
   m= (double) (y2-y1)/(x2-x1);  // the slope of the line
   c=m*x1-y1;         //the y-intercept of the line
  
  
	for(int y = 0; y < matrix_size; y++)
	{
		for(int x = 0; x < matrix_size; x++)
		{
			
			// see if we're close to y = m*x + c
			
			
			 if( x >= x1 && x <= x2 && fabs(y-m*x+c) < EPSILON)
			{
				arr[y][x] = '*';
				
			}
			
		}
	}
	
}

//drow Vertical line at x=x1 (x1,y1) to (x1,y2)
void vertical_Line (int x1, int y1, int y2, char arr[matrix_size][matrix_size])
{

	for(int y = 0; y < matrix_size; y++)
	{
		for(int x = 0; x < matrix_size; x++)
		{
			
			// if x=x1 virtical Line
			 if( x == x1  && y<y2 && y>y1)
			{
				arr[y][x] = '*';
			}	
			
		}
	}
	
}

void flipImageVertically(int rows, int columns, char arr[matrix_size][matrix_size]) {
    int firstCounter = 0,secondCounter = 0;
    char newImage[matrix_size][matrix_size],aRow[matrix_size];
    char fileName[]="image.in";

    for (firstCounter = 0 ; firstCounter < rows ; firstCounter++){ // this nested loop will store the rows of the 2d array into a single array.
		secondCounter = 0;

		while (secondCounter < columns){
			aRow[secondCounter] = arr[firstCounter][secondCounter]; // Stores the rows of the 2d array into a normal array.
			secondCounter++; // after finishing each column this counter goes to the next column.
		}
		for (secondCounter = 0 ; secondCounter < columns ; secondCounter++){
			newImage[((rows - 1) - firstCounter)][secondCounter] = aRow[secondCounter]; // Puts the first row in the original array in the last row of the new array and so on.
            // (rows - 1) ==> because the index starts from zero and ends at (rows - 1) "599".
            // ((rows - 1) - firstCounter) ==> so that column (firstCounter) #0 is placed as the last row ((rows - 1) - 0) "599". and it goes on.
        }
	}
	arr = newImage;
	//! Prints the image in the right position
	for(int y = 0; y < matrix_size; y++){
	for(int x = 0; x < matrix_size; x++)
		printf("%c",	arr[y][x]);
	printf("\n");
	}
    return;
}
