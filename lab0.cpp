//
//  lab1.cpp
//  lab1
//
//  Created by Elizaveta Vasilieva on 07/03/2025.
//

#include <iostream>
using namespace std;

//global variables
const char SYMBOL = 'x';

//function prototypes
void drawHorizontalLine(int length, char ch = SYMBOL);
void drawVerticalLine(int height, char ch = SYMBOL);
void drawSquare(int length, char ch = SYMBOL);
void drawSquareFilled(int length);
void drawRectangle(int length, int height);
void drawRectangleFilled(int length, int height);



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
            
            if (length <= 0){
                cout << "Length cannot be 0 or less\n";
            }else{
                drawHorizontalLine(length, 'x');
            }
        }else if (choice == 2){
            cout << "\nEnter the height of the line: ";
            cin >> height;
            
            if (height <= 0){
                cout << "Height cannot be 0 or less";
            }else{
                drawVerticalLine(height);
            }
        }else if (choice == 3){
            cout << "\nEnter the dimension of the square: ";
            cin >> length;
            drawSquare(length);
        }else if (choice == 4){
            cout << "\nEnter the dimension of the square: ";
            cin >> height;
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
    cout << "\n";
}
void drawSquare(int length, char ch){
    cout << "hi";
}
void drawSquareFilled(int length){
    cout << "hi";
}
void drawRectangle(int length, int height){
    
}
void drawRectangleFilled(int length, int height){
    
}


