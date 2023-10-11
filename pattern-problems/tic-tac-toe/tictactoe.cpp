#include <bits/stdc++.h>
using namespace std;

// 3x3 size board
const int BOARD_SIZE = 3;

enum class CellState {
    Empty = 0,
    X = 1,
    O = 2
};

class Observer {
   public:
    virtual void update(int row, int col, CellState state) = 0;
};

class Board {
   private:
    vector<vector<CellState>> cells;
    vector<Observer*> observers;

    void notifyObservers(int row, int col, CellState state) {
        for (Observer* observer : observers) {
            observer->update(row, col, state);
        }
    }

    bool isValidMove(int row, int col) const {
        return row >= 0 and col >= 0 and row < BOARD_SIZE and col < BOARD_SIZE;
    }

   public:
    Board() {
        cells = vector<vector<CellState>>(BOARD_SIZE, vector<CellState>(BOARD_SIZE, CellState::Empty));
    }

    void addObserver(Observer* observer) {
        observers.push_back(observer);
    }

    void makeMove(int row, int col, CellState state) {
        if (isValidMove(row, col) and cells[row][col] == CellState::Empty) {
            cells[row][col] = state;
            notifyObservers(row, col, state);
        }
    }

    CellState getCellState(int row, int col) const {
        return cells[row][col];
    }
};

class Player : public Observer {
   private:
    string name;
    CellState symbol;

   public:
    Player(string name, CellState symbol) {
        this->name = name;
        this->symbol = symbol;
    }

    void update(int row, int col, CellState state) {
        if (state == symbol) {
            cout << name << " made a move at (" << row << ", " << col << ")." << endl;
        }
    }

    CellState getSymbol() const {
        return symbol;
    }
};

class TicTacToe {
   private:
    Board* board;
    Player *currPlayer, *player1, *player2;

    bool checkGameOver(int row, int col) {
        return checkRow(row) || checkCol(col) || checkDiags(row, col);
    }

    bool checkRow(int row) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (board->getCellState(row, col) != currPlayer->getSymbol()) {
                return false;
            }
        }
        return true;
    }

    bool checkCol(int col) {
        for (int row = 0; row < BOARD_SIZE; row++) {
            if (board->getCellState(row, col) != currPlayer->getSymbol()) {
                return false;
            }
        }
        return true;
    }

    bool checkDiags(int row, int col) {
        if (row == col || row + col == BOARD_SIZE - 1) {
            return checkMainDiagonal() || checkAntiDiagonal();
        }
        return false;
    }

    bool checkMainDiagonal() {
        for (int i = 0; i < BOARD_SIZE; ++i) {
            if (board->getCellState(i, i) != currPlayer->getSymbol()) {
                return false;
            }
        }
        return true;
    }

    bool checkAntiDiagonal() {
        for (int i = 0; i < BOARD_SIZE; ++i) {
            if (board->getCellState(i, BOARD_SIZE - 1 - i) != currPlayer->getSymbol()) {
                return false;
            }
        }
        return true;
    }

   public:
    TicTacToe(Player* player1, Player* player2) {
        board = new Board();
        this->player1 = player1;
        this->player2 = player2;

        board->addObserver(player1);
        board->addObserver(player2);
    }

    void playGame() {
        bool gameOver = false;

        while (!gameOver) {
            int row, col;
            if (currPlayer->getSymbol() == CellState::X) {
                cout << "X's turn. Enter row and column (0-2): ";
            } else if (currPlayer->getSymbol() == CellState::O) {
                cout << "O's turn. Enter row and column (0-2): ";
            }

            cin >> row >> col;

            board->makeMove(row, col, currPlayer->getSymbol());

            gameOver = checkGameOver(row, col);

            currPlayer = (currPlayer == player1) ? player2 : player1;
        }

        if (currPlayer->getSymbol() == CellState::X) {
            cout << "Game over! X wins!" << endl;
        } else if (currPlayer->getSymbol() == CellState::O) {
            cout << "Game over! O wins!" << endl;
        }
    }
};

int main() {
    Player player1("Player 1", CellState::X);
    Player player2("Player 2", CellState::O);

    TicTacToe game(&player1, &player2);
    game.playGame();

    return 0;
}