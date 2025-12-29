#include <iostream>
using namespace std;
int main(){
int rows,colums;
cout << "Enter number of rows : ";
cin >>rows;
cout << "Enter number of columns : ";
cin >> colums;
int arr[rows][colums];
cout << "Enter elements of the matrix: "<<endl;
for (int i =0;i < rows;i++)
{
for (int j =0;j < colums;j++)
{
cin >> arr[i][j];
}
}
cout << "\nOriginal Matrix:\n";
for (int i =0;i < rows;i++)
{
for (int j = 0; j < colums; j++)
{
cout << arr[i][j] << "\t";
}
cout << endl;
}
int arr2[rows*colums];
int choice;
cout <<"Choose an option:"<<endl;
cout <<"1.Sort each row individually (ascending)\n";
cout<< "2.Sort each column individually (ascending)\n";
cout<< "3.Sort all elements globally (ascending)\n";
cout << "Enter choice (1/2/3): ";
cin>> choice;

if (choice==1) 
{
    for (int i= 0;i <rows; i++) 
    {
        for (int j = 0; j <colums- 1; j++) 
        {
            for (int k = j + 1; k <colums; k++) 
            {
                if (arr[i][j] > arr[i][k]) 
                {
                    int temp = arr[i][j];
                    arr[i][j] = arr[i][k];
                    arr[i][k] = temp;
                }
            }
        }
    }
    cout << "\nMatrix after sorting each row: " <<endl;
    for (int i= 0;i< rows;i++) 
    { 
        cout<<"[";
    for (int j = 0; j <colums; j++)
    {
    cout << arr[i][j] << "\t";}
    cout <<"]"<< endl;
    }
}
else if (choice == 2) 
{
    for (int j = 0; j <colums; j++) 
    {
        for (int i= 0; i <rows- 1; i++) 
        {
            for (int k = i + 1; k <rows; k++) 
            {
                if (arr[i][j]> arr[k][j]) 
                {
                    int temp= arr[i][j];
                    arr[i][j] = arr[k][j];
                    arr[k][j] = temp;
                }
            } 
        }
    }
    cout << "\nMatrix after sorting each column: " <<endl;
    for (int i= 0;i< rows;i++) 
    { 
        cout<<"[";
    for (int j = 0; j <colums; j++)
    {
    cout << arr[i][j] << "\t";}
    cout <<"]"<< endl;
    }
}
else if (choice == 3) 
{
    int total = rows * colums;
    int x = 0;
    for (int i= 0; i < rows; i++) 
    {
        for (int j =0; j< colums; j++) 
        {
            arr2[x++] =arr[i][j];
        }
    }
    for (int i =0;i <total -1;i++) 
    {
            for (int j = i+1; j <total;j++) 
            {
                if (arr2[i] > arr2[j]) 
                {
                    int temp = arr2[i];
                    arr2[i]= arr2[j];
                    arr2[j] =temp;
                }
            }
    }
    x= 0;
    for(int i = 0; i <rows; i++) 
    {
        for(int j = 0; j <colums; j++) 
        {
            arr[i][j] = arr2[x++];
        }
    }
    cout << "Matrix after sorting all elements globally:\n";
    for (int i= 0;i< rows;i++) 
    { 
        cout<<"[";
    for (int j = 0; j <colums; j++)
    {
    cout << arr[i][j] << "\t";}
    cout <<"]"<< endl;
    }
}
else
{
    cout << "Invalid choice!\n";
    return 0;
}

return 0;
}