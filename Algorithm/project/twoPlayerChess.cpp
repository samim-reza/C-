#include <iostream>
#include <cmath>  // for std::abs
using namespace std;

char board[8][8] = {
    {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
};

void displayBoard() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool isValidMove(int startX, int startY, int endX, int endY, char currentPlayer) {
    char piece = board[startX][startY];
    char targetPiece = board[endX][endY];

    // Check if the destination is within the board
    if (endX < 0 || endX >= 8 || endY < 0 || endY >= 8) {
        return false;
    }

    // Move validation for the pawn
    if (toupper(piece) == 'P') { // Pawn
        int forwardDir = (currentPlayer == 'w') ? -1 : 1;
        int startRow = (currentPlayer == 'w') ? 6 : 1;

        // The pawn moves forward one square
        if (startY == endY && startX + forwardDir == endX && board[endX][endY] == ' ') {
            return true;
        }
        // The pawn moves two squares forward from the starting position
        if (startY == endY && startX + 2 * forwardDir == endX && startX == startRow && board[endX][endY] == ' ' && board[startX + forwardDir][endY] == ' ') {
            return true;
        }
        // The pawn captures diagonally
        if (abs(startY - endY) == 1 && startX + forwardDir == endX && islower(targetPiece) && currentPlayer == 'w') {
            return true;
        }
        if (abs(startY - endY) == 1 && startX + forwardDir == endX && isupper(targetPiece) && currentPlayer == 'b') {
            return true;
        }
    }

    // Move validation for the knight
    if (toupper(piece) == 'N') { // Knight
        int deltaX = abs(endX - startX);
        int deltaY = abs(endY - startY);

        // Check the L-shaped move for the knight
        if ((deltaX == 2 && deltaY == 1) || (deltaX == 1 && deltaY == 2)) {
            // Check if the destination is empty or contains an opponent's piece
            if (targetPiece == ' ' || (islower(piece) && isupper(targetPiece)) || (isupper(piece) && islower(targetPiece))) {
                return true;
            }
        }
    }

        // Move validation for the bishop
    if (toupper(piece) == 'B') { // Bishop
        int deltaX = abs(endX - startX);
        int deltaY = abs(endY - startY);

        // Check if the move is diagonally
        if (deltaX == deltaY) {
            // Check if there are no pieces in the diagonal path
            int directionX = (endX > startX) ? 1 : -1;
            int directionY = (endY > startY) ? 1 : -1;

            int x = startX + directionX;
            int y = startY + directionY;

            while (x != endX && y != endY) {
                if (board[x][y] != ' ') {
                    return false; // There's a piece in the diagonal path
                }
                x += directionX;
                y += directionY;
            }

            // Check if the destination is empty or contains an opponent's piece
            if (targetPiece == ' ' || (islower(piece) && isupper(targetPiece)) || (isupper(piece) && islower(targetPiece))) {
                return true;
            }
        }
    }

    // Move validation for the rook
    if (toupper(piece) == 'R') { // Rook
        int deltaX = abs(endX - startX);
        int deltaY = abs(endY - startY);

        // Check if the move is in a straight line (either horizontally or vertically)
        if ((deltaX == 0 && deltaY != 0) || (deltaX != 0 && deltaY == 0)) {
            // Check if there are no pieces in the path
            int directionX = (endX > startX) ? 1 : (endX < startX) ? -1 : 0;
            int directionY = (endY > startY) ? 1 : (endY < startY) ? -1 : 0;

            int x = startX + directionX;
            int y = startY + directionY;

            while (x != endX || y != endY) {
                if (board[x][y] != ' ') {
                    return false; // There's a piece in the path
                }
                x += directionX;
                y += directionY;
            }

            // Check if the destination is empty or contains an opponent's piece
            if (targetPiece == ' ' || (islower(piece) && isupper(targetPiece)) || (isupper(piece) && islower(targetPiece))) {
                return true;
            }
        }
    }

    // Move validation for the queen
    if (toupper(piece) == 'Q') { // Queen (combining bishop and rook moves)
        int deltaX = abs(endX - startX);
        int deltaY = abs(endY - startY);

        // Check if the move is diagonally
        if (deltaX == deltaY) {
            // Check if there are no pieces in the diagonal path
            int directionX = (endX > startX) ? 1 : -1;
            int directionY = (endY > startY) ? 1 : -1;

            int x = startX + directionX;
            int y = startY + directionY;

            while (x != endX && y != endY) {
                if (board[x][y] != ' ') {
                    return false; // There's a piece in the diagonal path
                }
                x += directionX;
                y += directionY;
            }

            // Check if the destination is empty or contains an opponent's piece
            if (targetPiece == ' ' || (islower(piece) && isupper(targetPiece)) || (isupper(piece) && islower(targetPiece))) {
                return true;
            }
        }
        // Check if the move is in a straight line (either horizontally or vertically)
        else if ((deltaX == 0 && deltaY != 0) || (deltaX != 0 && deltaY == 0)) {
            // Check if there are no pieces in the path
            int directionX = (endX > startX) ? 1 : (endX < startX) ? -1 : 0;
            int directionY = (endY > startY) ? 1 : (endY < startY) ? -1 : 0;

            int x = startX + directionX;
            int y = startY + directionY;

            while (x != endX || y != endY) {
                if (board[x][y] != ' ') {
                    return false; // There's a piece in the path
                }
                x += directionX;
                y += directionY;
            }

            // Check if the destination is empty or contains an opponent's piece
            if (targetPiece == ' ' || (islower(piece) && isupper(targetPiece)) || (isupper(piece) && islower(targetPiece))) {
                return true;
            }
        }
    }

    // Move validation for the king (including castling)
    if (toupper(piece) == 'K') {
        int deltaX = abs(endX - startX);
        int deltaY = abs(endY - startY);

        // Check if the move is within one square in any direction
        if ((deltaX == 1 && deltaY == 0) || (deltaX == 0 && deltaY == 1) || (deltaX == 1 && deltaY == 1)) {
            // Check if the destination is empty or contains an opponent's piece
            if (targetPiece == ' ' || (islower(piece) && isupper(targetPiece)) || (isupper(piece) && islower(targetPiece))) {
                return true;
            }
        }

        // Check for castling
        if (startY == 4 && ((startX == 0 && endX == 0 && endY == 6) || (startX == 7 && endX == 7 && endY == 6))) {
            // Check if the king and the corresponding rook have not moved
            if (startX == 0 && board[0][7] == 'r') {
                // Check if the path between the king and rook is clear
                if (board[0][5] == ' ' && board[0][6] == ' ') {
                    return true;
                }
            } else if (startX == 7 && board[7][7] == 'R') {
                if (board[7][5] == ' ' && board[7][6] == ' ') {
                    return true;
                }
            }
        }
    }




    return false;
}


void makeMove(int startX, int startY, int endX, int endY, char &currentPlayer) {
    if (isValidMove(startX, startY, endX, endY, currentPlayer)) {
        // Handle castling
        if (toupper(board[startX][startY]) == 'K' && abs(endY - startY) == 2) {
            // Perform castling
            int rookStartY = (endY == 6) ? 7 : 0;
            int rookEndY = (endY == 6) ? 5 : 3;
            board[startX][rookEndY] = board[startX][rookStartY];
            board[startX][rookStartY] = ' ';
        }

        board[endX][endY] = board[startX][startY];
        board[startX][startY] = ' ';

        // Switch to the other player's turn only if the move is valid
        currentPlayer = (currentPlayer == 'w') ? 'b' : 'w';
    } else {
        cout << "Invalid Move!" << endl;
    }
}

bool isCheckmate(char currentPlayer) {
    // Iterate through each square on the board
    for (int startX = 0; startX < 8; startX++) {
        for (int startY = 0; startY < 8; startY++) {
            // Check if the piece at the current square belongs to the current player
            if ((islower(board[startX][startY]) && currentPlayer == 'w') || (isupper(board[startX][startY]) && currentPlayer == 'b')) {
                // Try all possible moves for the piece
                for (int endX = 0; endX < 8; endX++) {
                    for (int endY = 0; endY < 8; endY++) {
                        if (isValidMove(startX, startY, endX, endY, currentPlayer)) {
                            // If there is at least one valid move, the king is not in checkmate
                            return false;
                        }
                    }
                }
            }
        }
    }

    // If no valid moves are found for any piece, it's checkmate
    return true;
}

bool isStalemate(char currentPlayer) {
    // Iterate through each square on the board
    for (int startX = 0; startX < 8; startX++) {
        for (int startY = 0; startY < 8; startY++) {
            // Check if the piece at the current square belongs to the current player
            if ((islower(board[startX][startY]) && currentPlayer == 'w') || (isupper(board[startX][startY]) && currentPlayer == 'b')) {
                // Try all possible moves for the piece
                for (int endX = 0; endX < 8; endX++) {
                    for (int endY = 0; endY < 8; endY++) {
                        if (isValidMove(startX, startY, endX, endY, currentPlayer)) {
                            // If there is at least one valid move, it's not stalemate
                            return false;
                        }
                    }
                }
            }
        }
    }

    // If no valid moves are found for any piece, it's stalemate
    return true;
}

bool isKingCaptured(char currentPlayer) {
    // Iterate through each square on the board
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            // Check if the piece at the current square is the king of the current player
            char king = (currentPlayer == 'w') ? 'K' : 'k';
            if (board[i][j] == king) {
                // If the king is found, it is not captured
                return false;
            }
        }
    }

    // If the king is not found, it is captured
    return true;
}


void endGame(char currentPlayer) {
    if (isCheckmate(currentPlayer)) {
        cout << "Checkmate! Player " << ((currentPlayer == 'w') ? "Black" : "White") << " wins!" << endl;
    } else if (isStalemate(currentPlayer)) {
        cout << "Stalemate! The game is a draw." << endl;
    } else if (isKingCaptured(currentPlayer)) {
        cout << "King captured! Player " << ((currentPlayer == 'w') ? "Black" : "White") << " wins!" << endl;
    }
}

int main() {
    char currentPlayer = 'w'; // 'w' for white, 'b' for black
    displayBoard();

    int startX, startY, endX, endY;

    while (true) {
        cout << "Enter start position for " << ((currentPlayer == 'w') ? "white" : "black") << " (row col): ";
        cin >> startX >> startY;

        cout << "Enter end position for " << ((currentPlayer == 'w') ? "white" : "black") << " (row col): ";
        cin >> endX >> endY;

        makeMove(startX, startY, endX, endY, currentPlayer);

        displayBoard();

        // Check for game-ending conditions after each move
        if (isCheckmate(currentPlayer) || isStalemate(currentPlayer) || isKingCaptured(currentPlayer)) {
            endGame(currentPlayer);
            break;
        }

        // Switch to the other player's turn only if the move is valid
        currentPlayer = (currentPlayer == 'w') ? 'b' : 'w';
    }

    return 0;
}