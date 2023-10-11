#include <iostream>
#include <vector>

// Constants for board size
const int BOARD_SIZE = 3;

// Enum for cell state
enum class CellState { Empty,
                       X,
                       O };

// Abstract Observer interface for the Observer pattern
class Observer {
   public:
    virtual void update(int row, int col, CellState state) = 0;
};

// Concrete Subject for the Observer pattern
class Board {
   public:
    Board() : cells(BOARD_SIZE, std::vector<CellState>(BOARD_SIZE, CellState::Empty)) {}

    void addObserver(Observer* observer) {
        observers.push_back(observer);
    }

    void makeMove(int row, int col, CellState state) {
        if (isValidMove(row, col) && cells[row][col] == CellState::Empty) {
            cells[row][col] = state;
            notifyObservers(row, col, state);
        }
    }

    CellState getCellState(int row, int col) const {
        return cells[row][col];
    }

   private:
    std::vector<std::vector<CellState>> cells;
    std::vector<Observer*> observers;

    void notifyObservers(int row, int col, CellState state) {
        for (Observer* observer : observers) {
            observer->update(row, col, state);
        }
    }

    bool isValidMove(int row, int col) const {
        return row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE;
    }
};

// Concrete Observer for the Observer pattern
class Player : public Observer {
   public:
    Player(std::string name, CellState symbol) : name(name), symbol(symbol) {}

    void update(int row, int col, CellState state) override {
        if (state == symbol) {
            std::cout << name << " made a move at (" << row << ", " << col << ")." << std::endl;
        }
    }

    CellState getSymbol() const {
        return symbol;
    }

   private:
    std::string name;
    CellState symbol;
};

// Main class that manages the game
class TicTacToe {
   public:
    TicTacToe(Player* player1, Player* player2) : board(), currentPlayer(player1), player1(player1), player2(player2) {
        board.addObserver(player1);
        board.addObserver(player2);
    }

    void playGame() {
        bool gameOver = false;

        while (!gameOver) {
            int row, col;
            std::cout << currentPlayer->getSymbol() << "'s turn. Enter row and column (0-2): ";
            std::cin >> row >> col;

            board.makeMove(row, col, currentPlayer->getSymbol());

            gameOver = checkGameOver(row, col);

            // Switch players
            currentPlayer = (currentPlayer == player1) ? player2 : player1;
        }

        std::cout << "Game over! " << currentPlayer->getSymbol() << " wins!" << std::endl;
    }

   private:
    Board board;
    Player* currentPlayer;
    Player* player1;
    Player* player2;

    bool checkGameOver(int row, int col) {
        return checkRow(row) || checkColumn(col) || checkDiagonals(row, col);
    }

    bool checkRow(int row) {
        for (int col = 0; col < BOARD_SIZE; ++col) {
            if (board.getCellState(row, col) != currentPlayer->getSymbol()) {
                return false;
            }
        }
        return true;
    }

    bool checkColumn(int col) {
        for (int row = 0; row < BOARD_SIZE; ++row) {
            if (board.getCellState(row, col) != currentPlayer->getSymbol()) {
                return false;
            }
        }
        return true;
    }

    bool checkDiagonals(int row, int col) {
        if (row == col || row + col == BOARD_SIZE - 1) {
            return checkMainDiagonal() || checkAntiDiagonal();
        }
        return false;
    }

    bool checkMainDiagonal() {
        for (int i = 0; i < BOARD_SIZE; ++i) {
            if (board.getCellState(i, i) != currentPlayer->getSymbol()) {
                return false;
            }
        }
        return true;
    }

    bool checkAntiDiagonal() {
        for (int i = 0; i < BOARD_SIZE; ++i) {
            if (board.getCellState(i, BOARD_SIZE - 1 - i) != currentPlayer->getSymbol()) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Player player1("Player 1", CellState::X);
    Player player2("Player 2", CellState::O);

    TicTacToe game(&player1, &player2);
    game.playGame();

    return 0;
}
