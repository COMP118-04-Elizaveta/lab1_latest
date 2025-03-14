//
//  lab1.cpp
//  lab1
//
//  Created by Elizaveta Vasilieva on 07/03/2025.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
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
void drawShapes(int numShapes);



int main() {

    const int MAX_SHAPES = 10;
    
    int choice;
    int length = 0;
    int height = 0;
    
    srand(static_cast<unsigned int>(time(NULL)));
    
    do {
        cout << "\n1) Draw a horizontal line";
        cout << "\n2) Draw a vertical line";
        cout << "\n3) Draw a square";
        cout << "\n4) Draw a square filled";
        cout << "\n5) Draw a rectangle";
        cout << "\n6) Draw a rectangle filled";
        cout << "\n7) Draw a random number of shapes";
        cout << "\n8) Quit";
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
            cout << "\nEnter symbol to use: ";
            cin >> symbol;
            
            if (height <= 0){
                cout << "Height cannot be 0 or less\n";
            }else{
                drawVerticalLine(height);
            }
        }else if (choice == 3){
            cout << "\nEnter the dimension of the square: ";
            cin >> length;
            
            cout << "\nEnter symbol to use: ";
            cin >> symbol;
            
            if (length <= 0){
                cout << "Dimensions cannot be 0 or less\n";
            }else{
                drawSquare(length);
            }
        }else if (choice == 4){
            cout << "\nEnter the dimension of the square: ";
            cin >> length;
            
            cout << "\nEnter symbol to use: ";
            cin >> symbol;
            
            drawSquareFilled(length);
        }else if (choice == 5){
            cout << "\nEnter the length of the rectangle: ";
            cin >> length;
            cout << "\nEnter the height of the rectangle: ";
            cin >> height;
            
            cout << "\nEnter symbol to use: ";
            cin >> symbol;
            
            drawRectangle(length, height);
        }else if (choice == 6){
            cout << "\nEnter the length of the rectangle: ";
            cin >> length;
            cout << "\nEnter the height of the rectangle: ";
            cin >> height;
            
            cout << "\nEnter symbol to use: ";
            cin >> symbol;
            
            drawRectangleFilled(length, height);
        }else if (choice == 7){
            drawShapes(MAX_SHAPES);
        }else if (choice == 8){
            return 0;
        }else {
            cerr << "\nInvalid choice\n";
        }
        
    } while (choice != 8);
    

    cout << "\n7Have a nice day!\n";


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

//draws a random number of shapes, i.e. automated testing function
void drawShapes(int numShapes) {
    int shapeType;
    int shapeLength;
    int shapeChar;
    
    cout << "\nDraws " << numShapes << " random shapes";
    
    shapeType = 1 + rand() % 6;
    shapeLength = 5 + rand() % 16; //@todo remove 5, 16, 33 and 94
    shapeChar = 33 + rand() % 127 - 33; //printable ascii characters
    
    for (int i = 0; i <= numShapes; i++){
    switch (shapeType) {
    case 1:
            drawHorizontalLine(shapeLength, shapeChar);
            break;
    case 2:
            drawVerticalLine(shapeLength, shapeChar);
            break;
    case 3:
            break;
    case 4:
            break;
    case 5:
            drawRectangle(shapeLength + 3, shapeLength, shapeChar);
            break;
    case 6:
            break;
    default:
            cerr << "Should not happen";
            break;
    }
    }
}

