//
//  lab1.cpp
//  lab1
//
//  Created by Elizaveta Vasilieva on 07/03/2025.
//

#include <iostream>
using namespace std;

//global variables
char symbol = 'x';

//function prototypes
void drawHorizontalLine(int length, char ch = symbol);
void drawVerticalLine(int height, char ch = symbol);
void drawSquare(int length, char ch = symbol);
void drawSquareFilled(int length, char ch = symbol);
void drawRectangle(int length, int height, char ch = symbol);
void drawRectangleFilled(int length, int height, char ch = symbol);



int main() {

    int choice;
    int length = 0;
    int height = 0;
    
    do {
        cout << "\n1) Draw a horizontal line";
        cout << "\n2) Draw a vertical line";
        cout << "\n3) Draw a square";
        cout << "\n4) Draw a square filled";
        cout << "\n5) Draw a rectangle";
        cout << "\n6) Draw a rectangle filled";
        cout << "\n7) Quit";
        cout << "\n\nEnter your choice: ";

        cin >> choice;
        
        if (choice == 1){
            cout << "\nEnter the length of the line: ";
            cin >> length;
            cout << "\nEnter symbol to use: ";
            cin >> symbol;
            
            if (length <= 0){
                cout << "Length cannot be 0 or less\n";
            }else{
                drawHorizontalLine(length, symbol);
            }
        }else if (choice == 2){
            cout << "\nEnter the height of the line: ";
            cin >> height;
            
            if (height <= 0){
                cout << "Height cannot be 0 or less\n";
            }else{
                drawVerticalLine(height);
            }
        }else if (choice == 3){
            cout << "\nEnter the dimension of the square: ";
            cin >> length;
            
            if (length <= 0){
                cout << "Dimensions cannot be 0 or less\n";
            }else{
                drawSquare(length);
            }
        }else if (choice == 4){
            cout << "\nEnter the dimension of the square: ";
            cin >> length;
            drawSquareFilled(length);
        }else if (choice == 5){
            cout << "\nEnter the length of the rectangle: ";
            cin >> length;
            cout << "\nEnter the height of the rectangle: ";
            cin >> height;
            drawRectangle(length, height);
        }else if (choice == 6){
            cout << "\nEnter the length of the rectangle: ";
            cin >> length;
            cout << "\nEnter the height of the rectangle: ";
            cin >> height;
            drawRectangleFilled(length, height);
        }else if (choice == 7){
            return 0;
        }else {
            cout << "\nInvalid choice\n";
        }
        
    } while (choice != 7);
    

    cout << "Have a nice day!";


    return 0;
}

void drawHorizontalLine(int length, char ch){
    for (int i = 0; i < length; i++){
        cout << ch;
    }
    cout << "\n";
    
}

void drawVerticalLine(int height, char ch){
    for (int i = 0; i < height; i++){
        cout << ch << "\n";
    }
    
}

//draw a square with open middle
void drawSquare(int length, char ch){
    for (int i = 0; i < length; i++){
        cout << ch;
    }
    
    cout << "\n";
    
    for (int i = 0; i < length; i++){
        cout << ch;
        for (int i = 0; i < length - 2; i++){
                cout << " ";
        }
            cout << ch << endl;
    }
    for (int i = 0; i < length; i++){
        cout << ch;
    }
}

//draw a square with closed middle
void drawSquareFilled(int length, char ch){
    for (int i = 0; i < length; i++){
        cout << ch;
    }
    
    cout << "\n";
    
    for (int i = 0; i < length; i++){
        cout << ch;
        for (int i = 0; i < length - 2; i++){
                cout << " ";
        }
            cout << ch << endl;
    }
    for (int i = 0; i < length; i++){
        cout << ch;
}
}

//draw a rectangle with open middle
void drawRectangle(int length, int height, char ch){
    for (int i = 0; i < height; i++){
        for (int j = 0; j < length; j++){
            if (i == 0 || j == 0 || i == height - 1 || j == length - 1){
                cout << ch;
            }else{
                cout << " ";
            }
           
        }
        cout << endl;
    }
    
}

//draw a rectangle with closed middle
void drawRectangleFilled(int length, int height, char ch){
    for (int i = 0; i < height; i++){
        for (int j = 0; j < length; j++){
            cout << ch;
        }
        cout << endl;
    }
}


