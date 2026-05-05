// CSC-134
// Daniel Kantor
// May 4, 2026
// Maze Generator with BFS Solver

#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <queue>
using namespace std;

enum Direction { NORTH = 1, SOUTH = 2, EAST = 4, WEST = 8 };

const pair<int,int> DIRECTION_OFFSETS[] = {
    {0,0}, {0,-1}, {0,1}, {0,0}, {1,0}, {0,0}, {0,0}, {0,0}, {-1,0}
};

const Direction OPPOSITES[] = {
    (Direction)0, SOUTH, NORTH, (Direction)0, WEST,
    (Direction)0, (Direction)0, (Direction)0, EAST
};

class Cell {
    int row, col, links;
public:
    Cell(int r, int c) : row(r), col(c), links(0) {}
    int getRow() const { return row; }
    int getCol() const { return col; }
    bool linked(Direction d) const { return (links & d) != 0; }
    void link(Direction d)   { links |= d; }
    void unlink(Direction d) { links &= ~d; }
};

class Grid {
    int rows, cols;
    vector<vector<Cell>> cells;
    mt19937 rng;

public:
    Grid(int rows, int cols) : rows(rows), cols(cols) {
        rng.seed((unsigned int)time(nullptr));
        cells.resize(rows);
        for (int r = 0; r < rows; r++) {
            cells[r].reserve(cols);
            for (int c = 0; c < cols; c++)
                cells[r].emplace_back(r, c);
        }
    }

    int getRows() const { return rows; }
    int getCols() const { return cols; }

    bool isValid(int r, int c) const {
        return r >= 0 && r < rows && c >= 0 && c < cols;
    }

    Cell& at(int r, int c)             { return cells[r][c]; }
    const Cell& at(int r, int c) const { return cells[r][c]; }

    int random(int lo, int hi) {
        return uniform_int_distribution<int>(lo, hi)(rng);
    }

    void linkCells(int r1, int c1, Direction dir) {
        if (!isValid(r1, c1)) return;
        int r2 = r1 + DIRECTION_OFFSETS[dir].second;
        int c2 = c1 + DIRECTION_OFFSETS[dir].first;
        if (!isValid(r2, c2)) return;
        at(r1, c1).link(dir);
        at(r2, c2).link(OPPOSITES[dir]);
    }

    void display(const vector<vector<bool>>& path) const {
        // Top border with entrance gap
        cout << "+";
        for (int c = 0; c < cols; c++)
            cout << (c == 0 ? "   +" : "---+");
        cout << "\n";

        for (int r = 0; r < rows; r++) {
            cout << "|";
            for (int c = 0; c < cols; c++) {
                cout << (path[r][c] ? " * " : "   ");
                bool openEast = (c < cols - 1) && cells[r][c].linked(EAST);
                cout << (openEast ? " " : "|");
            }
            cout << "\n";

            // Bottom border; exit gap at bottom-right
            cout << "+";
            for (int c = 0; c < cols; c++) {
                bool isExit = (r == rows - 1 && c == cols - 1);
                bool openSouth = (r < rows - 1) && cells[r][c].linked(SOUTH);
                cout << (isExit ? "   +" : openSouth ? "   +" : "---+");
            }
            cout << "\n";
        }
    }

    // Special feature: BFS solver from top-left to bottom-right
    vector<vector<bool>> solve() const {
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        vector<vector<pair<int,int>>> parent(rows, vector<pair<int,int>>(cols, {-1,-1}));

        queue<pair<int,int>> q;
        q.push({0, 0});
        visited[0][0] = true;

        Direction dirs[] = {NORTH, SOUTH, EAST, WEST};

        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            if (r == rows - 1 && c == cols - 1) break;
            for (Direction d : dirs) {
                if (!cells[r][c].linked(d)) continue;
                int nr = r + DIRECTION_OFFSETS[d].second;
                int nc = c + DIRECTION_OFFSETS[d].first;
                if (isValid(nr, nc) && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    parent[nr][nc] = {r, c};
                    q.push({nr, nc});
                }
            }
        }

        // Trace path back from exit to entrance
        vector<vector<bool>> path(rows, vector<bool>(cols, false));
        int r = rows - 1, c = cols - 1;
        while (r != -1 && c != -1) {
            path[r][c] = true;
            auto [pr, pc] = parent[r][c];
            r = pr; c = pc;
        }
        return path;
    }
};

// Binary Tree: for each cell randomly carve north or east — fast, simple, NE bias
class BinaryTreeMaze {
public:
    static void on(Grid& grid) {
        for (int r = 0; r < grid.getRows(); r++) {
            for (int c = 0; c < grid.getCols(); c++) {
                vector<Direction> neighbors;
                if (r > 0)                    neighbors.push_back(NORTH);
                if (c < grid.getCols() - 1)   neighbors.push_back(EAST);
                if (!neighbors.empty())
                    grid.linkCells(r, c, neighbors[grid.random(0, neighbors.size() - 1)]);
            }
        }
    }
};

// Sidewinder: like Binary Tree but carves runs eastward, then breaks north — less bias
class SidewinderMaze {
public:
    static void on(Grid& grid) {
        for (int r = 0; r < grid.getRows(); r++) {
            vector<int> run;
            for (int c = 0; c < grid.getCols(); c++) {
                run.push_back(c);
                bool atEast  = (c == grid.getCols() - 1);
                bool atNorth = (r == 0);
                bool closeRun = atEast || (!atNorth && grid.random(0, 1) == 0);
                if (closeRun) {
                    if (!atNorth) {
                        int member = run[grid.random(0, run.size() - 1)];
                        grid.linkCells(r, member, NORTH);
                    }
                    run.clear();
                } else {
                    grid.linkCells(r, c, EAST);
                }
            }
        }
    }
};

int main() {
    cout << "╔══════════════════════════╗\n";
    cout << "║     ASCII MAZE MAKER     ║\n";
    cout << "╚══════════════════════════╝\n\n";
    cout << "  Entrance: top-left gap\n";
    cout << "  Exit:     bottom-right gap\n";
    cout << "  Solution: marked with  *\n\n";

    bool running = true;
    while (running) {
        // --- Size ---
        int rows, cols;
        cout << "How tall should the maze be? (rows 2-50): ";
        cin >> rows;
        rows = max(2, min(50, rows));

        cout << "How wide should the maze be? (cols 2-100): ";
        cin >> cols;
        cols = max(2, min(100, cols));

        // --- Algorithm menu ---
        cout << "\nChoose a generation algorithm:\n";
        cout << "  1. Binary Tree  (fast; diagonal bias toward top-right)\n";
        cout << "  2. Sidewinder   (similar speed; bias only along top row)\n";
        cout << "Choice: ";
        int choice;
        cin >> choice;

        Grid grid(rows, cols);
        if (choice == 2)
            SidewinderMaze::on(grid);
        else
            BinaryTreeMaze::on(grid);

        string algoName = (choice == 2) ? "Sidewinder" : "Binary Tree";
        cout << "\n--- " << algoName << " maze (" << rows << " x " << cols << ") ---\n\n";

        vector<vector<bool>> empty(rows, vector<bool>(cols, false));
        grid.display(empty);

        // --- Special feature: optional BFS solution ---
        cout << "\nReveal solution path? (y/n): ";
        char show;
        cin >> show;
        if (show == 'y' || show == 'Y') {
            cout << "\n--- Solution (* = shortest path) ---\n\n";
            grid.display(grid.solve());
        }

        cout << "\nGenerate another maze? (y/n): ";
        char again;
        cin >> again;
        if (again != 'y' && again != 'Y') running = false;
        cout << "\n";
    }

    cout << "Goodbye!\n";
    return 0;
}
