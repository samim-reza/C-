#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>
#include <queue> 
#include <thread>  
#include <chrono>  
#include <cstdlib> 

using namespace std;

struct ChessMove {
    int startX, startY, endX, endY;
    int evaluation; 
};

struct ChessMoveWithCost {
    int startX, startY, endX, endY;
    int cost; 
};

struct CompareMoves {
    bool operator()(const ChessMoveWithCost& move1, const ChessMoveWithCost& move2) {
        return move1.cost > move2.cost; 
    }
};

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
    cout << "   0   1   2   3   4   5   6   7\n"; 
    cout << "  +---+---+---+---+---+---+---+---+\n";
    for (int i = 0; i < 8; i++) {
        cout << i << " | "; 
        for (int j = 0; j < 8; j++) {
            cout << board[i][j] << " | ";
        }
        cout << endl;
        cout << "  +---+---+---+---+---+---+---+---+\n";
    }
}

bool isValidMove(int startX, int startY, int endX, int endY, char currentPlayer) {
    char piece = board[startX][startY];
    char targetPiece = board[endX][endY];

    if (endX < 0 || endX >= 8 || endY < 0 || endY >= 8) {
        return false;
    }

    if (toupper(piece) == 'P') { 
        int forwardDir = (currentPlayer == 'w') ? -1 : 1;
        int startRow = (currentPlayer == 'w') ? 6 : 1;

        if (startY == endY && startX + forwardDir == endX && board[endX][endY] == ' ') {
            return true;
        }

        if (startY == endY && startX + 2 * forwardDir == endX && startX == startRow && board[endX][endY] == ' ' && board[startX + forwardDir][endY] == ' ') {
            return true;
        }

        if (abs(startY - endY) == 1 && startX + forwardDir == endX && islower(targetPiece) && currentPlayer == 'w') {
            return true;
        }
        if (abs(startY - endY) == 1 && startX + forwardDir == endX && isupper(targetPiece) && currentPlayer == 'b') {
            return true;
        }
    }

    if (toupper(piece) == 'N') { 
        int deltaX = abs(endX - startX);
        int deltaY = abs(endY - startY);

        if ((deltaX == 2 && deltaY == 1) || (deltaX == 1 && deltaY == 2)) {

            if (targetPiece == ' ' || (islower(piece) && isupper(targetPiece)) || (isupper(piece) && islower(targetPiece))) {
                return true;
            }
        }
    }

    if (toupper(piece) == 'B') {
        int deltaX = abs(endX - startX);
        int deltaY = abs(endY - startY);
        if (deltaX == deltaY) {
            int directionX = (endX > startX) ? 1 : -1;
            int directionY = (endY > startY) ? 1 : -1;

            int x = startX + directionX;
            int y = startY + directionY;

            while (x != endX && y != endY) {
                if (board[x][y] != ' ') {
                    return false;
                }
                x += directionX;
                y += directionY;
            }

            if (targetPiece == ' ' || (islower(piece) && isupper(targetPiece)) || (isupper(piece) && islower(targetPiece))) {
                return true;
            }
        }
    }

    if (toupper(piece) == 'R') {
        int deltaX = abs(endX - startX);
        int deltaY = abs(endY - startY);

        if ((deltaX == 0 && deltaY != 0) || (deltaX != 0 && deltaY == 0)) {
            int directionX = (endX > startX) ? 1 : (endX < startX) ? -1 : 0;
            int directionY = (endY > startY) ? 1 : (endY < startY) ? -1 : 0;

            int x = startX + directionX;
            int y = startY + directionY;

            while (x != endX || y != endY) {
                if (board[x][y] != ' ') {
                    return false;
                }
                x += directionX;
                y += directionY;
            }

            if (targetPiece == ' ' || (islower(piece) && isupper(targetPiece)) || (isupper(piece) && islower(targetPiece))) {
                return true;
            }
        }
    }

    if (toupper(piece) == 'Q') {
        int deltaX = abs(endX - startX);
        int deltaY = abs(endY - startY);

        if (deltaX == deltaY) {
            int directionX = (endX > startX) ? 1 : -1;
            int directionY = (endY > startY) ? 1 : -1;

            int x = startX + directionX;
            int y = startY + directionY;

            while (x != endX && y != endY) {
                if (board[x][y] != ' ') {
                    return false;
                }
                x += directionX;
                y += directionY;
            }

            if (targetPiece == ' ' || (islower(piece) && isupper(targetPiece)) || (isupper(piece) && islower(targetPiece))) {
                return true;
            }
        }
        else if ((deltaX == 0 && deltaY != 0) || (deltaX != 0 && deltaY == 0)) {
            int directionX = (endX > startX) ? 1 : (endX < startX) ? -1 : 0;
            int directionY = (endY > startY) ? 1 : (endY < startY) ? -1 : 0;

            int x = startX + directionX;
            int y = startY + directionY;

            while (x != endX || y != endY) {
                if (board[x][y] != ' ') {
                    return false;
                }
                x += directionX;
                y += directionY;
            }

            if (targetPiece == ' ' || (islower(piece) && isupper(targetPiece)) || (isupper(piece) && islower(targetPiece))) {
                return true;
            }
        }
    }

    if (toupper(piece) == 'K') {
        int deltaX = abs(endX - startX);
        int deltaY = abs(endY - startY);

        if ((deltaX == 1 && deltaY == 0) || (deltaX == 0 && deltaY == 1) || (deltaX == 1 && deltaY == 1)) {
            if (targetPiece == ' ' || (islower(piece) && isupper(targetPiece)) || (isupper(piece) && islower(targetPiece))) {
                return true;
            }
        }

        // Check for castling
        if (startY == 4 && ((startX == 0 && endX == 0 && endY == 6) || (startX == 7 && endX == 7 && endY == 6))) {
            if (startX == 0 && board[0][7] == 'r') {
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
            int rookStartY = (endY == 6) ? 7 : 0;
            int rookEndY = (endY == 6) ? 5 : 3;
            board[startX][rookEndY] = board[startX][rookStartY];
            board[startX][rookStartY] = ' ';
        }

        board[endX][endY] = board[startX][startY];
        board[startX][startY] = ' ';

        //currentPlayer = (currentPlayer == 'w') ? 'b' : 'w';
    } else {
        cout << "Invalid Move!" << endl;
    }
}

int getPieceValue(char piece) {
    switch (toupper(piece)) {
        case 'P':
            return 10; // Pawn value
        case 'N':
            return 30; // Knight value
        case 'B':
            return 30; // Bishop value
        case 'R':
            return 50; // Rook value
        case 'Q':
            return 90; // Queen value
        case 'K':
            return 900; // King value
        default:
            return 0;
    }
}

int evaluateBoard(char currentPlayer) {
    int evaluation = 30;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            char piece = board[i][j];
            if (islower(piece)) {
                evaluation -= getPieceValue(piece);
            } else if (isupper(piece)) {
                evaluation += getPieceValue(piece);
            }
        }
    }

    return evaluation;
}


vector<ChessMove> generateMoves(char currentPlayer) {
    vector<ChessMove> moves;

    for (int startX = 0; startX < 8; startX++) {
        for (int startY = 0; startY < 8; startY++) {
            if ((islower(board[startX][startY]) && currentPlayer == 'b') || (isupper(board[startX][startY]) && currentPlayer == 'w')) {
                for (int endX = 0; endX < 8; endX++) {
                    for (int endY = 0; endY < 8; endY++) {
                        if (isValidMove(startX, startY, endX, endY, currentPlayer)) {
                            ChessMove move = {startX, startY, endX, endY, 0};
                            move.evaluation = evaluateBoard(currentPlayer);
                            moves.push_back(move);
                        }
                    }
                }
            }
        }
    }
    random_shuffle(moves.begin(), moves.end());


    return moves;
}


void performAIMoveAStar(char &currentPlayer) {
    vector<ChessMove> moves = generateMoves(currentPlayer);

    priority_queue<ChessMoveWithCost, vector<ChessMoveWithCost>, CompareMoves> moveQueue;

    for (const auto &move : moves) {
        ChessMoveWithCost moveWithCost = {move.startX, move.startY, move.endX, move.endY, move.evaluation};
        moveQueue.push(moveWithCost);
    }

    string messages[] = {"Thinking...", "Wait...", "Nice move...", "Well played...", "You're genius", "Perfect move"};
    string message = messages[rand() % 6];

    cout << message<<"\n";
    cout.flush();
    this_thread::sleep_for(chrono::seconds((rand() % 2) + 1));
    if (!moveQueue.empty()) {
        ChessMoveWithCost bestMove = moveQueue.top();
        makeMove(bestMove.startX, bestMove.startY, bestMove.endX, bestMove.endY, currentPlayer);
    }
}


bool isInCheck(char currentPlayer) {
    int kingX, kingY;
    char king = (currentPlayer == 'w') ? 'K' : 'k';
    bool kingFound = false;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == king) {
                kingX = i;
                kingY = j;
                kingFound = true;
                break;
            }
        }
        if (kingFound) {
            break;
        }
    }

    if (!kingFound) {
        return false;
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((islower(board[i][j]) && currentPlayer == 'w') || (isupper(board[i][j]) && currentPlayer == 'b')) {
                if (isValidMove(i, j, kingX, kingY, currentPlayer)) {
                    return true;
                }
            }
        }
    }

    return false;
}
bool isCheckmate(char currentPlayer) {
    for (int startX = 0; startX < 8; startX++) {
        for (int startY = 0; startY < 8; startY++) {
            if ((islower(board[startX][startY]) && currentPlayer == 'w') || (isupper(board[startX][startY]) && currentPlayer == 'b')) {
                for (int endX = 0; endX < 8; endX++) {
                    for (int endY = 0; endY < 8; endY++) {
                        if (isValidMove(startX, startY, endX, endY, currentPlayer)) {
                            return false;
                        }
                    }
                }
            }
        }
    }
    return true;
}

bool isStalemate(char currentPlayer) {
    for (int startX = 0; startX < 8; startX++) {
        for (int startY = 0; startY < 8; startY++) {
            if ((islower(board[startX][startY]) && currentPlayer == 'w') || (isupper(board[startX][startY]) && currentPlayer == 'b')) {
                for (int endX = 0; endX < 8; endX++) {
                    for (int endY = 0; endY < 8; endY++) {
                        if (isValidMove(startX, startY, endX, endY, currentPlayer)) {
                            return false;
                        }
                    }
                }
            }
        }
    }

    return true;
}

bool isKingCaptured(char currentPlayer) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            char king = (currentPlayer == 'w') ? 'K' : 'k';
            if (board[i][j] == king) {
                return false;
            }
        }
    }

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
    char currentPlayer = 'w';
    displayBoard();

    int startX, startY, endX, endY;


while (true) {

    if (currentPlayer == 'w') {
        cout << "Enter start position (row col): ";
        cin >> startX >> startY;
        cout << "Enter end position (row col): ";
        cin >> endX >> endY;

        if (isValidMove(startX, startY, endX, endY, currentPlayer)) {
            makeMove(startX, startY, endX, endY, currentPlayer);
            displayBoard();
        } else {
            cout << "Invalid Move! Try again." << endl;
            continue;
        }
    }
    else {
        performAIMoveAStar(currentPlayer);
        displayBoard();
    }

    // Check for game-ending conditions after each move
    if (isCheckmate(currentPlayer) || isStalemate(currentPlayer) || isKingCaptured(currentPlayer)) {
        endGame(currentPlayer);
        break;
    }
    currentPlayer = (currentPlayer == 'w') ? 'b' : 'w';
}

    return 0;
}