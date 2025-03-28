/** \file lab0.cpp
 * \brief this program has multiple functions to draw shapes
 * \details -
 * \author Elizaveta Vasilieva
 * \version 0.1
 * \date 03/2025
 * \copyright University of Nicosia.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>
using namespace std;

//global variables
/**
 * If no symbol specified in a drawing function, then this symbol is used as the default one to draw a shape.
 */
char symbol = 'x';

//function prototypes
void showMenu();

void initializeArrays(int shapeTy[], int shapeLen[], char shapeCh[], const int arrSize);
void drawArrays(const int shapeTy[], const int shapeLen[], const char shapeCh[], const int arrSize);

void drawHorizontalLine(const int length, char ch = symbol);
void drawVerticalLine(int height, char ch = symbol);
void drawSquare(int length, char ch = symbol);
void drawSquareFilled(int length, char ch = symbol);
void drawRectangle(int length, int height, char ch = symbol);
void drawRectangleFilled(int length, int height, char ch = symbol);

void drawShapes(const int numShapes);

/**
 * main
 * This function prints the options for drawing and then depending on user input draws the selected shape(s).
 * it is the driver function, i.e. Front-end.
 * @return zero
*/

int main() {

    const int MAX_SHAPES = 10;
    
    int choice;
    int length = 0;
    int height = 0;
    int shapeTy[MAX_SHAPES] = {1, 2, 3, 4, 5, 6, 1, 2, 3, 4};
    int shapeLen[MAX_SHAPES] = {5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    char shapeCh[MAX_SHAPES] = {'A','A','A','A','A','A','A','A','A','B'}; //@todo FIX
    
    
    srand(static_cast<unsigned int>(time(NULL)));
    
    do {
        showMenu();
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
            initializeArrays(shapeTy, shapeLen, shapeCh, MAX_SHAPES);
            drawArrays(shapeTy, shapeLen, shapeCh, MAX_SHAPES);
        }else if (choice == 9){
            return 0;
        }else {
            cerr << "\nInvalid choice\n";
        }
        
    } while (choice != 8);
    

    cout << "\nHave a nice day!\n";


    return 0;
}

/**
 * This function prints the options for drawing.
*/
void showMenu(){
    cout << "\n1) Draw a horizontal line";
    cout << "\n2) Draw a vertical line";
    cout << "\n3) Draw a square";
    cout << "\n4) Draw a square filled";
    cout << "\n5) Draw a rectangle";
    cout << "\n6) Draw a rectangle filled";
    cout << "\n7) Draw a random number of shapes";
    cout << "\n8) Draw a number of shapes defined by random arrays";
    cout << "\n9) Quit";
}

/**
* Draws shapes defined by three arrays
 @param shapeTy the type of shape, ex. rectangle, square
 @param shapeLen the length/dimension of the shape
 @param shapeCh the character used for drawing shapes
 @param arrSize the amount of shapes to be drawn
*/
void drawArrays(const int shapeTy[], const int shapeLen[], const char shapeCh[], const int arrSize){
    cout << "\nDraws " << arrSize << " shapes\n";
    
    int i;
    
    for (i = 0; i < arrSize; i++){
    switch (shapeTy[i]) {
        case 1:
            drawHorizontalLine(shapeLen[i], shapeCh[i]);
            cout << endl;
            break;
        case 2:
            drawVerticalLine(shapeLen[i], shapeCh[i]);
            cout << endl;
            break;
        case 3:
            drawSquare(shapeLen[i], shapeCh[i]);
            cout << endl;
            break;
        case 4:
            drawSquareFilled(shapeLen[i], shapeCh[i]);
            cout << endl;
            break;
        case 5:
            drawRectangle(shapeLen[i] + 3, shapeLen[i], shapeCh[i]);
            cout << endl;
            break;
        case 6:
            drawRectangleFilled(shapeLen[i] + 3, shapeLen[i], shapeCh[i]);
            cout << endl;
            break;
        default:
            cerr << "Should not happen";
            assert(false);
            break;
    }
        assert (i == arrSize);
    }
}

/**
* Randomply generates arrSize of shapes which are stored in 3 arrays
 * @param shapeTy randomly generated shape type ex. filled square
 * @param shapeLen randomply generated dimension of shape
 * @param shapeCh randomly generated chatacter used to draw the shape
 * @param arrSize total amount of shapes that will be drawn
*/
void initializeArrays(int shapeTy[], int shapeLen[], char shapeCh[], const int arrSize){
    cout << "Randomly filling arrays with " << arrSize << " shapes";
    
    for (int i = 0; i < arrSize; i++){
        shapeTy[i] = 1 + rand() % 6;
        shapeLen[i] = 5 + rand() % 16; //@todo remove the 5 and 16
        shapeCh[i] = 33 + rand() % (126 - 33); //printable ascii characters
    }
    
}

/**
* Draws a horizontal line.
 * @param length The length of the line
 * @param ch The default symbol used for drawing.
*/
void drawHorizontalLine(const int length, const char ch){
    assert(length > 0);
    
    for (int i = 0; i < length; i++){
        cout << ch;
    }
    cout << "\n";
    
}

/**
* Draws a vertical line.
 * @param height The height of the line
 * @param ch The default symbol used for drawing.
*/
void drawVerticalLine(const int height, const char ch){
    for (int i = 0; i < height; i++){
        cout << ch << "\n";
    }
    
}

/**
* Draw a square with open middle
 * @param length The dimensions for the square, which will be the same.
 * @param ch The default symbol used for drawing.
*/
void drawSquare(const int length, const char ch){
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

/**
* Draw a square with closed middle
 * @param length The dimensions for the square, which will be the same.
 * @param ch The default symbol used for drawing.
*/
void drawSquareFilled(const int length, const char ch){
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

/**
* Draw a rectangle, with open middle.
 * @param height The height of the rectangle
 * @param length The length of the rectangle
 * @param ch The default symbol used for drawing.
*/
void drawRectangle(int length, int height, const char ch){
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

/**
* Draw a rectangle, with closed middle.
 * @param height The height of the rectangle
 * @param length The length of the rectangle
 * @param ch The default symbol used for drawing.
*/
void drawRectangleFilled(const int length, const int height, const char ch){
    for (int i = 0; i < height; i++){
        for (int j = 0; j < length; j++){
            cout << ch;
        }
        cout << endl;
    }
}

/**
* Draw a random number of shapes
 * @param numShapes a constant which controls the amount of random shapes to be drawn
*/
void drawShapes(const int numShapes) {
    assert(numShapes > 0);
    
    int shapeType;
    int shapeLength;
    int shapeChar;
    
    cout << "\nDraws " << numShapes << " random shapes\n";
    
    for (int i = 0; i < numShapes; i++){
    
        shapeType = 1 + rand() % 6;
        shapeLength = 5 + rand() % 16; //@todo remove 5, 16, 33 and 94
        shapeChar = 33 + rand() % 94; //printable ascii characters
    

        switch (shapeType) {
            case 1:
                drawHorizontalLine(shapeLength, shapeChar);
                cout << endl;
                break;
            case 2:
                drawVerticalLine(shapeLength, shapeChar);
                cout << endl;
                break;
            case 3:
                drawSquare(shapeLength, shapeChar);
                cout << endl;
                break;
            case 4:
                drawSquareFilled(shapeLength, shapeChar);
                cout << endl;
                break;
            case 5:
                drawRectangle(shapeLength + 3, shapeLength, shapeChar);
                cout << endl;
                break;
            case 6:
                drawRectangleFilled(shapeLength + 3, shapeLength, shapeChar);
                cout << endl;
                break;
            default:
                cerr << "Should not happen";
                assert(false);
                break;
        }
    }
}

