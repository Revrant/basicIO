/* -----------------------------------------------------------------------------
 *
 * File Name:  main.cpp
 * Author: Tristen Schwarzenberger
 * KUID: 2878034
 * Email Address: jayhawktristen@hotmail.com
 * Assignment: EECS-168 Homework 3
 * Description: This program takes a file name as a command argument and displays menu options.
 * Date: 11/1/2016
 *
 ---------------------------------------------------------------------------- */
 #include <iostream>
 #include <string>
 #include <fstream>
//---------------------------------------------------------------------------------
//Option 1, prints data from users file
//---------------------------------------------------------------------------------
 void printData(double** arr, int rows, int collums)
{
  for(int i = 0; i < rows; i++)
  {
    for(int j = 0; j < collums; j++)
    {
      if(j == collums - 1)
      {
        std::cout << arr[i][j];
      }
      else
      {
      std::cout << arr[i][j] << ", ";
      }
    }
    std::cout << std::endl;
  }
}
//---------------------------------------------------------------------------------
//Option 2 - Prints the largest row of array
//---------------------------------------------------------------------------------
void printLargestRow(double** arr, int rows, int collums)
{

  double biggestsum = 0.0;
  int index = 0;

  for(int i = 0; i < rows; i++)
  {
    double sum = 0.0;

    for(int j = 0; j < collums; j++)
    sum = sum + arr[i][j];

    if(sum > biggestsum)
    {
      biggestsum = sum;
      index = i;
    }
  }

  std::cout << "The row with the largest sum is: ";

  for(int j = 0; j < collums; j++)
  {
    if( j < collums - 1)
    {
    std::cout << arr[index][j] << ", ";
    }
    else
    {
      std::cout << arr[index][j];
    }
  }
  std::cout<<std::endl;
 }
//---------------------------------------------------------------------------------
//Option 3 - Prints largest column in array
//---------------------------------------------------------------------------------
void printLargestCollum(double** arr, int rows, int collums)
{
  double biggestsum = 0.0;
  int index = 0;

  for(int i = 0; i < collums; i++)
  {
    double sum = 0.0;

    for(int j = 0; j < rows; j++)
    {
      sum = sum + arr[j][i];

      if(sum > biggestsum)
      {
        biggestsum = sum;
        index = i;
      }
    }
  }

  std::cout << "The column with the largest sum is: ";

  for(int i = 0; i < rows; i++)
  {
    if( i < rows - 1)
    {
    std::cout << arr[i][index] << ", ";
    }
    else
    {
      std::cout << arr[i][index];
    }
  }
  std::cout<<std::endl;
}
//---------------------------------------------------------------------------------
//Option 4 - Prints the sum of the entire array
//---------------------------------------------------------------------------------
void printArraySum(double** arr, int rows, int collums)
{
  int totalsum = 0;

  for (int i = 0; i < rows; i++)
   {
       for (int j = 0; j < collums; j++)
       {
         totalsum = totalsum + arr[i][j];
       }
   }

   std::cout << "The sum of the array is " << totalsum << std::endl;
}
//---------------------------------------------------------------------------------
//Option 5 - Finds average of whole array
//---------------------------------------------------------------------------------
void printArrayAverage(double** arr, int rows, int collums)
{
  double average = 0.0;
  double totalsum = 0.0;

  for (int i = 0; i < rows; i++)
   {
       for (int j = 0; j < collums; j++)
       {
         totalsum = totalsum + arr[i][j];
       }
   }
  average = totalsum / (rows * collums);

  std::cout << "The average of the whole array is " << average <<std::endl;
}
//---------------------------------------------------------------------------------
//Option 6 - Changes specific value in array
//---------------------------------------------------------------------------------
void changeValue(double** arr, int row, int collum, int value)
{
  arr[row][collum] = value;
}
//---------------------------------------------------------------------------------
//Option 7 - Saves array into a file
//---------------------------------------------------------------------------------
void copySave(double** arr, std::string filename, int rows, int collums)
{
  std::ofstream outFile;
  outFile.open(filename);
  outFile << rows;
  outFile << " ";
  outFile << collums;
  outFile << '\n';
  for ( int i = 0; i < rows; i++)
  {
    for (int j = 0; j < collums; j++)
    {
      outFile << arr[i][j];
      outFile << " ";
    }
    outFile << '\n';
  }
  outFile.close();
}
//---------------------------------------------------------------------------------
//Option 8 - Multiplies each value in array by scalar
//---------------------------------------------------------------------------------
void printMultScalar(double** arr, int rows, int collums, int scalar)
{
  for(int i = 0; i < rows; i++)
  {
    for(int j = 0; j < collums; j++)
    {
      arr[i][j] = arr[i][j] * scalar;
    }
  }
}
//---------------------------------------------------------------------------------
//Option 9 - Divides each value in array by scalar
//---------------------------------------------------------------------------------
void printDivideScalar(double** arr, int rows, int collums, int scalar)
{
  for(int i = 0; i < rows; i++)
  {
    for(int j = 0; j < collums; j++)
    {
      arr[i][j] = arr[i][j] / scalar;
    }
  }
}
//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------


 int main(int argc, char** argv)
 {

   std::string filename = "";

   if(argc >= 2)
   {
     filename = argv[1];
   }
   else
   {
     std::cout << "Sorry, you didn't give the right number of command line arguments. 2 are required.\n";
   }

   //Variables-----------------------
   int choice = 0;
   int rows = 0;
   int collums = 0;
   int largestrow = 0;
   int totalrow = 0;
   int* temp = nullptr;
   double value = 0.0;
   int** arr = nullptr;
   int row = 0;
   int collum = 0;
   double scalar = 0.0;
   //---------------------------------

   std::ifstream inFile;
   inFile.open(filename);

   if(inFile.is_open())
   {
     //Finds Parameters and creates array
     inFile >> rows;
     inFile >> collums;
     double** arr = new double*[rows];
     int** largestrow = new int*[rows];
     int* temp = new int[0];
     //Makes a new array for each row
     for(int i = 0; i < rows; i++)
     {
       arr[i] = new double[collums];
     }

     //Inputs values into array
     for(int i = 0; i < rows; i++)
     {
       for(int j = 0; j < collums; j++)
       {
         inFile >> arr[i][j];
       }
     }
     do{
     //Choices----------------------
     std::cout << std::endl;
     std::cout << "Make a choice:" << '\n';
     std::cout << "1) Print data" << '\n';
     std::cout << "2) Print Largest row" << '\n';
     std::cout << "3) Print Largest column" << '\n';
     std::cout << "4) Print Sum" << '\n';
     std::cout << "5) Print Average" << '\n';
     std::cout << "6) Change Value" << '\n';
     std::cout << "7) Save Copy of Grid" << '\n';
     std::cout << "8) Multiply by a scalar" << '\n';
     std::cout << "9) Divide by a scalar" << '\n';
     std::cout << "10) Exit" << '\n';
     std::cout << "Input a choice: ";
     std::cin >> choice;
     //------------------------------


     //Runs option user chooses
     if (choice == 1)
     {
       printData(arr, rows, collums);
     }
     else if(choice == 2)
     {
       printLargestRow(arr, rows, collums);
     }
     else if(choice == 3)
     {
       printLargestCollum(arr, rows, collums);
     }
     else if(choice == 4)
     {
       printArraySum(arr, rows, collums);
     }
     else if(choice == 5)
     {
       printArrayAverage(arr, rows, collums);
     }
     else if(choice == 6)
     {
       std::cout << "Input a row index: ";
       std::cin >> row;
       std::cout << "Input a column index: ";
       std::cin >> collum;
       std::cout << "Input a new value to store: ";
       std::cin >> value;
       changeValue(arr, row, collum, value);
     }
     else if(choice == 7)
     {
       std::cout << "Enter a file name: ";
       std::cin >> filename;
       copySave(arr, filename, rows, collums);
     }
     else if(choice == 8)
     {
       std::cout << "Enter a number to multiply each value in array by: ";
       std::cin >> scalar;
       printMultScalar(arr, rows, collums, scalar);
     }
     else if(choice == 9)
     {
       std::cout << "Enter a number to divide each value in array by: ";
       std::cin >> scalar;
       while(scalar == 0)
       {
         std::cout << "Error. Enter a value other than 0: ";
         std::cin >> scalar;
       }
       printDivideScalar(arr, rows, collums, scalar);
     }

      }while(choice != 10);
    }
   return (0);
}
