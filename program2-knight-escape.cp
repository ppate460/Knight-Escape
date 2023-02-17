/*--------------------------------------------
    Program 2: Knight Escape
    The objective of this game is to get the white knight to the empty
	square in the upper right-hand corner of the board.
	
	The knight can only move in the way that it does during a traditional
	chess game. This means that a knight can only move in a valid L-shape
	(two squares in a horizontal direction, then one in a vertical direction OR 
	two squares in a vertical direction, then one in a horizontal direction).
		       
    Course: CS 141, Spring 2022
    System: Visual Studio Code, Windows 10
    Author: Ellen Kidane
    
 ---------------------------------------------*/

#include <iostream>		// for input and output
#include <cctype>		// for toupper()
using namespace std;

//--------------------------------------------------------------------------------
// Global variables

// Board pieces
string p1,p2,p3,p4,p5,
	 p6,p7,p8,p9,p10,
	 p11,p12,p13,p14,p15,
	 p16,p17,p18,p19,p20,
	 p21,p22,p23,p24,p25;

// Characters of the pieces to be used on the board
const string WhiteKnight = "\u2658";		// White knight character
const string BlackKnight = "\u265E";		// Black knight character
const string BlankPosition = " ";			// Blank position character

// Size of the board
const int BoardSideSize = 5;				// The size of one side of the board

//--------------------------------------------------------------------------------
// Display welcome message, introducing the user to the program and
// describing the instructions for the game
void displayWelcomeMessage()
{
    cout << "Program 2: Knight Escape \n"
         << "CS 141, Spring 2022, UIC \n"
         << " \n"
         << "The objective of this puzzle is to get the white knight "
		 << "up to the empty square in the top right corner of the board. "
		 << "Use standard knight moves from a traditional chess game, "
		 << "where a knight moves in an L-shape. \n"
		 << "This means that a knight can only move either "
		 << "1) two squares in a horizontal direction, then one in a vertical direction, OR "
		 << "2) two squares in a vertical direction, then one in a horizontal direction."
		 << " \n"
		 << "Your score decreases by 5 with each valid move, and by 10 with each invalid move. \n"
		 << "Try to complete the puzzle with the smallest number of valid moves!"
    	 << endl;
}//end displayWelcomeMessage()

// ----------------------------------------------------------------------
// Initialize the board
// Set the positions to the beginning board. This is called at the beginning of
// the game and also if input of 'R' to reset the board is provided.
void initializeBoard()
{
	// Set each position to have the black knight
    p1=p2=p3=p4=p5=p6=p7=p8=p9=p10=p11=p12=p13=p14=p15=p16=p17=p18=p19=p20=p21=p22=p23=p24=p25=BlackKnight;
	// Set the lower left corner (p21) to be the white knight
	p21 = WhiteKnight;
	// Set the upper right corner (p5) to be blank
	p5 = BlankPosition;
    
} //end initializeBoard()

// ----------------------------------------------------------------------
// Display the current board, along with the corresponding positions
void displayBoard()
{
    cout <<"\n"
         <<                          "    Board   " <<                               "      Position \n"
         << " " <<  p1 << " " <<  p2 << " " <<  p3 << " " <<  p4 << " " <<  p5 << "     1  2  3  4  5 \n"
         << " " <<  p6 << " " <<  p7 << " " <<  p8 << " " <<  p9 << " " << p10 << "     6  7  8  9 10 \n"
         << " " << p11 << " " << p12 << " " << p13 << " " << p14 << " " << p15 << "    11 12 13 14 15 \n"
         << " " << p16 << " " << p17 << " " << p18 << " " << p19 << " " << p20 << "    16 17 18 19 20 \n"
         << " " << p21 << " " << p22 << " " << p23 << " " << p24 << " " << p25 << "    21 22 23 24 25 \n"
         << endl;
} //end displayBoard()

// ----------------------------------------------------------------------
// This utility function takes a number 1-25 and gets the value of 
// the corresponding variable.
string getValue(int thePosition)
{
    switch(thePosition) {
        case 1: return p1;
        case 2: return p2;
        case 3: return p3;
        case 4: return p4;
        case 5: return p5;
		case 6: return p6;
        case 7: return p7;
        case 8: return p8;
        case 9: return p9;
        case 10: return p10;
        case 11: return p11;
        case 12: return p12;
        case 13: return p13;
		case 14: return p14;
		case 15: return p15;
		case 16: return p16;
		case 17: return p17;
		case 18: return p18;
		case 19: return p19;
		case 20: return p20;
		case 21: return p21;
		case 22: return p22;
		case 23: return p23;
		case 24: return p24;
		case 25: return p25;
        // Sanity check
        default: cout << "Invalid value " << thePosition << "sent to the getValue function. This should not happen! Exiting...";
			exit(-1);
			break;
    } //end switch(thePosition)
    
} //end getValue()

// ----------------------------------------------------------------------
// This utility function takes a number 1-25 and sets the corresponding
// variable to have the newValue.
void setValue(int thePosition, string newValue)
{
    switch(thePosition) {
        case 1: p1 = newValue; break;
        case 2: p2 = newValue; break;
        case 3: p3 = newValue; break;
        case 4: p4 = newValue; break;
        case 5: p5 = newValue; break;
        case 6: p6 = newValue; break;
        case 7: p7 = newValue; break;
        case 8: p8 = newValue; break;
        case 9: p9 = newValue; break;
        case 10: p10 = newValue; break;
        case 11: p11 = newValue; break;
        case 12: p12 = newValue; break;
        case 13: p13 = newValue; break;
		case 14: p14 = newValue; break;
		case 15: p15 = newValue; break;
		case 16: p16 = newValue; break;
		case 17: p17 = newValue; break;
		case 18: p18 = newValue; break;
		case 19: p19 = newValue; break;
		case 20: p20 = newValue; break;
		case 21: p21 = newValue; break;
		case 22: p22 = newValue; break;
		case 23: p23 = newValue; break;
		case 24: p24 = newValue; break;
		case 25: p25 = newValue; break;
        // Sanity check
        default: cout << "Invalid value " << thePosition << "sent to the setValue function. This should not happen! Exiting...";
			exit(-1);
			break;
    } //end switch(thePosition)
    
} //end setValue()

// ----------------------------------------------------------------------
// Check if a move is valid - return true if so, and false otherwise.
// This works by checking that moving the knight from <fromPosition> to <toPosition>
// is a valid L-shape (two horizontal and one vertical OR two vertical and one horizontal).
bool isMoveValid(int fromPosition, int toPosition) {

	// Both fromPosition and toPosition have been verified to be valid, so
	// one of the following must be true for the move itself to be valid

	// Moving 2 up first, then 1 right
	// First, check that we are in a position where we can move 2 up and 1 right
	if( (fromPosition==11 || fromPosition==12 || fromPosition==13 || fromPosition==14 || fromPosition==16 || fromPosition==17 || fromPosition==18 || fromPosition==19 || fromPosition==21 || fromPosition==22 || fromPosition==23 || fromPosition==24 )
		&& ((fromPosition - (BoardSideSize*2) + 1) == toPosition) // also check if moving 2 up and 1 right gets to the TO position
	) {
		return true;
	}

	// Moving 2 up first, then 1 left
	// First, check that we are in a position where we can move 2 up and 1 left
	if( (fromPosition==12 || fromPosition==13 || fromPosition==14 || fromPosition==15 || fromPosition==17 || fromPosition==18 || fromPosition==19 || fromPosition==20 || fromPosition==22 || fromPosition==23 || fromPosition==24 || fromPosition==25 )
		&& ((fromPosition - (BoardSideSize*2) - 1) == toPosition) // also check if moving 2 up and 1 left gets to the TO position
	) {
		return true;
	}

	// Moving 2 down first, then 1 right
	// First, check that we are in a position where we can move 2 down and 1 right
	if( (fromPosition==1 || fromPosition==2 || fromPosition==3 || fromPosition==4 || fromPosition==6 || fromPosition==7 || fromPosition==8 || fromPosition==9 || fromPosition==11 || fromPosition==12 || fromPosition==13 || fromPosition==14 )
		&& ((fromPosition + (BoardSideSize*2) + 1) == toPosition) // also check if moving 2 down and 1 right gets to the TO position
	) {
		return true;
	}

	// Moving 2 down first, then 1 left
	// First, check that we are in a position where we can move 2 down and 1 left
	if( (fromPosition==2 || fromPosition==3 || fromPosition==4 || fromPosition==5 || fromPosition==7 || fromPosition==8 || fromPosition==9 || fromPosition==10 || fromPosition==12 || fromPosition==13 || fromPosition==14 || fromPosition==15 )
		&& ((fromPosition + (BoardSideSize*2) - 1) == toPosition) // also check if moving 2 down and 1 left gets to the TO position
	) {
		return true;
	}

	// Moving 2 right, then 1 up
	// First, check that we are in a position where we can move 2 right and 1 up
	if( (fromPosition==6 || fromPosition==7 || fromPosition==8 || fromPosition==11 || fromPosition==12 || fromPosition==13 || fromPosition==16 || fromPosition==17 || fromPosition==18 || fromPosition==21 || fromPosition==22 || fromPosition==23 )
		&& ((fromPosition + 2 - (BoardSideSize*1)) == toPosition) // also check if moving 2 right and 1 up gets to the TO position
	) {
		return true;
	}

	// Moving 2 right, then 1 down
	// First, check that we are in a position where we can move 2 right and 1 down
	if( (fromPosition==1 || fromPosition==2 || fromPosition==3 || fromPosition==6 || fromPosition==7 || fromPosition==8 || fromPosition==11 || fromPosition==12 || fromPosition==13 || fromPosition==16 || fromPosition==17 || fromPosition==18 )
		&& ((fromPosition + 2 + (BoardSideSize*1)) == toPosition) // also check if moving 2 right and 1 down gets to the TO position
	) {
		return true;
	}
	
	// Moving 2 left, then 1 up
	// First, check that we are in a position where we can move 2 left and 1 up
	if( (fromPosition==8 || fromPosition==9 || fromPosition==10 || fromPosition==13 || fromPosition==14 || fromPosition==15 || fromPosition==18 || fromPosition==19 || fromPosition==20 || fromPosition==23 || fromPosition==24 || fromPosition==25 )
		&& ((fromPosition - 2 - (BoardSideSize*1)) == toPosition) // also check if moving 2 left and 1 up gets to the TO position
	) {
		return true;
	}

	// Moving 2 left, then 1 down
	// First, check that we are in a position where we can move 2 left and 1 down
	if( (fromPosition==3 || fromPosition==4 || fromPosition==5 || fromPosition==8 || fromPosition==9 || fromPosition==10 || fromPosition==13 || fromPosition==14 || fromPosition==15 || fromPosition==18 || fromPosition==19 || fromPosition==20 )
		&& ((fromPosition - 2 + (BoardSideSize*1)) == toPosition) // also check if moving 2 left and 1 down gets to the TO position
	) {
		return true;
	}

	// At this point, we have not returned true, so this move must be invalid
	return false;

} // end isMoveValid()


// ----------------------------------------------------------------------
// Main() function of the program, containing the loop that controls
// game play
int main() {
	int moveNumber = 1;
	char menuOption = '.';
	int score = 500;
	
	displayWelcomeMessage();
	initializeBoard();
	
    displayBoard();

	// Loop that controls game play
	// This loop stops when the white knight is in the upper right corner (p5)
    while( (p5 != WhiteKnight) && (score > 0) ) {
		cout << "Current score: " << score << endl << endl;

        cout << moveNumber << ". "
             << "Enter one of the following: \n"
			 << "  - M to move a knight from one position to another, \n"
			 << "  - R to reset the board back to the beginning, or \n"
			 << "  - X to exit the game. \n"
			 << "Your choice -> ";
		cin >> menuOption;
		menuOption = toupper(menuOption); // convert user input to uppercase
        
        // If the user entered 'X' to exit,
		// break out of this loop that controls game play
        if( menuOption == 'X') {
            cout << "Exiting..." << endl;
            break;
        }
        
        // If the user entered 'R' to reset,
		// reset the board back to the beginning
        if( menuOption == 'R') {
            cout << "\n"
                 << "   *** Restarting"
                 << endl;
			moveNumber = 1;
			score = 500;
            initializeBoard();
            displayBoard();
            continue;   // go back up to the top of game play loop, moving on to the next iteration
        }

		// If the user entered 'M' to move a knight,
		// ask for the position of the knight to be moved
		if(menuOption == 'M') {
			int fromPosition, toPosition = 0;
			cout << "Enter the positions from and to, separated by a space "
				 << "(e.g. 14 5 to move the knight in position 14 to position 5): ";

			cin >> fromPosition >> toPosition;
			
			cout << "You have chosen to move a knight from position " << fromPosition
				 << " to position " << toPosition << ".\n";

			// Check that FROM position is valid, i.e. within 1-25
			if(fromPosition < 1 || fromPosition > 25) {
				cout << "The source position should be a valid position on the board (1-25). Try again.\n";
				score -= 10;
				continue;
			}

			// Check that TO position is valid, i.e. within 1-25
			if(toPosition < 1 || toPosition > 25) {
				cout << "The destination position should be a valid position on the board (1-25). Try again.\n";
				score -= 10;
				continue;
			}
			
			// Check that the source position has a knight
			string sourceValue = getValue(fromPosition);
			if(sourceValue != WhiteKnight && sourceValue != BlackKnight) {
				cout << "The source position should have a knight. Try again.\n";
				score -= 10;
				continue;
			}

			// Check that the destination position is empty
			string destinationValue = getValue(toPosition);
			if(destinationValue != BlankPosition) {
				cout << "The destination position should be empty. Try again.\n";
				score -= 10;
				continue;
			}

			// Check that the move is valid - knights can only move in an L-shape
			if(!isMoveValid(fromPosition, toPosition)) {
				cout << "Invalid move. Knights can only move in an L-shape. Try again.\n";
				score -= 10;
				continue;
			}
			
			// Everything is okay! So make the move and update the score and move number
			setValue(fromPosition, BlankPosition);	// the source position becomes blank
			setValue(toPosition, sourceValue);		// the knight moves to the destination position
			moveNumber++;
			score -= 5;
		}
        
        displayBoard();
    } //end loop for game play
    
    // Check for a win by seeing if the upper right corner (p5) is the white knight.
    if(p5 == WhiteKnight) {
        cout << "\n"
             << "Congratulations, you did it!"
             << endl;
    }

	// Check if the loop ended because the user ran out of moves
	if(score <= 0) {
		cout << "Current score: " << score << endl << endl;
		cout << "\n"
			 << "You have run out of moves. Try to do better next time!"
			 << endl;
	}
    
    cout << "Thank you for playing!" << endl;

	return 0;
}