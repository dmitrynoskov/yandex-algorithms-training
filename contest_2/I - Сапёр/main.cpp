#include <iostream>
#include <vector>

using namespace std;

/*
    основная идея: для упрощения проверок и вывода расширить исходное поле на 1 в каждую сторону
    тогда из каждой заданной клетки можно обращаться к любым соседним без выхода за пределы массива
    дополнительный плюс: не нужно будет пересчитывать индексы в массиве для мин (так как исходно они номеруются с 1)
*/

struct Coord {
    int i;
    int j;
};

struct Cell {
    int neighboring_mines = 0;
    bool isMined = false;
};

ostream& operator << (ostream& out, const Cell& cell) {
    if (cell.isMined) {
        return out << '*';
    } else {
        return out << cell.neighboring_mines;
    }
}

void addMines(vector<vector<Cell>>& field, const vector<Coord>& mines) {
    static const vector<Coord> neighboursOffset = { {-1, -1},
                                                    {-1, 0},
                                                    {-1, 1},
                                                    {0,  -1},
                                                    {0,  1},
                                                    {1,  -1},
                                                    {1,  0},
                                                    {1,  1}
                                                    };
    for (auto[i, j]: mines) {
        field[i][j].isMined = true;
        for (auto offset : neighboursOffset) {
            ++field[i + offset.i][j + offset.j].neighboring_mines;
        }
    }

}

int main() {
    int N, M;
    cin >> N >> M;
    const vector<Coord> mines = [] {
        vector<Coord> mines;
        int K;
        cin >> K;
        for (int index = 0; index < K; ++index) {
            int i, j;
            cin >> i >> j;
            mines.push_back({i, j});
        }
        return mines;
    } ();

    vector<vector<Cell>> field (N + 2);
    for (auto& column : field) {
        column.resize(M + 2);
    }

    addMines(field, mines);

    for (int i = 1; i < N + 1; ++i) {
        for (int j = 1; j < M + 1; ++j) {
            cout << field[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}