#include <iostream>
#include <vector>
#include <conio.h>   // _kbhit(), _getch()
#include <windows.h> // Sleep()
#include <cstdlib>   // rand(), srand()
#include <ctime>     // time()

using namespace std;

// =====================
// DATA STRUCTURES
// =====================

struct Position {
    int x;
    int y;
};

enum class Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

// =====================
// GLOBAL CONSTANTS
// =====================

const int width = 40;
const int height = 20;

// =====================
// FUNCTION DECLARATIONS
// =====================

Position getNextHead(Position currentHead, Direction dir);
void draw(const vector<Position>& snake, Position food);

// =====================
// MAIN FUNCTION
// =====================

int main() {
    srand(time(0)); // seed randomness

    // Initial snake
    vector<Position> snake = {
        {5, 5},
        {4, 5},
        {3, 5}
    };

    Direction dir = Direction::RIGHT;

    // Initial food position
    Position food;
    food.x = rand() % width;
    food.y = rand() % height;

    bool running = true;

    // =====================
    // GAME LOOP
    // =====================
    while (running) { 

        // ---------- INPUT ----------
        if (_kbhit()) {
            char ch = _getch();
            switch (ch) {
            case 'w':
                if (dir != Direction::DOWN) dir = Direction::UP;
                break;
            case 's':
                if (dir != Direction::UP) dir = Direction::DOWN;
                break;
            case 'a':
                if (dir != Direction::RIGHT) dir = Direction::LEFT;
                break;
            case 'd':
                if (dir != Direction::LEFT) dir = Direction::RIGHT;
                break;
            }
        }

       Position newHead = getNextHead(snake[0], dir);

        if (newHead.x < 0 || newHead.x >= width ||
            newHead.y < 0 || newHead.y >= height) {
            running = false;
            break;
        }

        for (size_t i = 0; i < snake.size(); i++) {
            if (newHead.x == snake[i].x &&
                newHead.y == snake[i].y) {
                running = false;
                break;
            }
        }

        bool ateFood = (newHead.x == food.x && newHead.y == food.y);

        snake.insert(snake.begin(), newHead);

        if (!ateFood) {
            snake.pop_back();
        }
        else {
            food.x = rand() % width;
            food.y = rand() % height;
        }

        // ---------- RENDER ----------
        system("cls");
        draw(snake, food);

        Sleep(100);
    }

    return 0;
}

// =====================
// FUNCTIONS
// =====================

Position getNextHead(Position currentHead, Direction dir) {
    Position newHead = currentHead;

    switch (dir) {
    case Direction::UP:
        newHead.y -= 1;
        break;
    case Direction::DOWN:
        newHead.y += 1;
        break;
    case Direction::LEFT:
        newHead.x -= 1;
        break;
    case Direction::RIGHT:
        newHead.x += 1;
        break;
    }

    return newHead;
}

void draw(const vector<Position>& snake, Position food) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {

            // Draw walls
            if (y == 0 || y == height - 1) {
                cout << '-';
                continue;
            }
            else if (x == 0 || x == width - 1) {
                cout << '|'; 
                continue;
            }

            bool printed = false;

            // Draw snake
            for (size_t i = 0; i < snake.size(); i++) {
                if (snake[i].x == x && snake[i].y == y) {
                    cout << (i == 0 ? 'O' : 'o');
                    printed = true;
                    break;
                }
            }

            // Draw food
            if (!printed && x == food.x && y == food.y) {
                cout << '*';
                printed = true;
            }

            if (!printed) {
                cout << ' ';
            }
        }
        cout << endl;
    }
}
