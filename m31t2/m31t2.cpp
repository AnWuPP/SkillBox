#include <iostream>
#include <string>
#include <vector>
#include <set>

class IGraph {
public:
    virtual ~IGraph() {}
    IGraph() {};
    IGraph(IGraph* _oth) {};
    virtual void AddEdge(int from, int to) = 0; // Метод принимает вершины начала и конца ребра и добавляет ребро
    virtual int VerticesCount() const = 0; // Метод должен считать текущее количество вершин
    virtual void GetNextVertices(int vertex, std::vector<int>& vertices) const = 0; // Для конкретной вершины метод выводит в вектор “вершины” все вершины, в которые можно дойти по ребру из данной
    virtual void GetPrevVertices(int vertex, std::vector<int>& vertices) const = 0; // Для конкретной вершины метод выводит в вектор “вершины” все вершины, из которых можно дойти по ребру в данную
    virtual std::vector<int> GetVertices() = 0; // Вернуть все вершины. Нужно для копирования.
};

class ListGraph final : public IGraph{
    std::vector<std::vector<int>> peeks;

    int FindEdge(int v) const {
        for (int i = 0, ie = VerticesCount(); i != ie; ++i) {
            if (peeks[i][0] == v)
                return i;
        }
        return -1;
    }
public:
    ListGraph() {}

    ListGraph(IGraph* _oth) {
        peeks.clear();
        std::vector<int> vert = _oth->GetVertices();
        std::vector<int> tmp;
        for (auto& from : vert) {
            _oth->GetNextVertices(from, tmp);
            for (auto& to : tmp) {
                AddEdge(from, to);
            }
            tmp.clear();
        }
    }

    virtual void AddEdge(int from, int to) {
        int v = FindEdge(from);
        int t = FindEdge(to);
        if (v != -1) {
            if (std::find(peeks[v].begin(), peeks[v].end(), v) == peeks[v].end())
                peeks[v].push_back(to);
        }
        else {
            peeks.push_back({ from, to });
        }
    }

    virtual int VerticesCount() const {
        return static_cast<int>(peeks.size());
    }

    virtual void GetNextVertices(int vertex, std::vector<int>& vertices) const {
        int v = FindEdge(vertex);
        if (v != -1) {
            std::vector<int> tmp(peeks[v].begin() + 1, peeks[v].end());
            vertices = tmp;
        }
    }

    virtual void GetPrevVertices(int vertex, std::vector<int>& vertices) const {
        for (int i = 0, ie = VerticesCount(); i != ie; ++i) {
            for (int j = 1, je = static_cast<int>(peeks[i].size()); j != je; ++j) {
                if (peeks[i][j] == vertex)
                    vertices.push_back(peeks[i][j]);
            }
        }
    }

    virtual std::vector<int> GetVertices() {
        std::vector<int> tmp;
        for (auto& p : peeks) {
            tmp.push_back(p[0]);
        }
        return tmp;
    }
};

class MatrixGraph final : public IGraph {
    std::vector<std::vector<int>> matrix;

public:
    MatrixGraph() {};
    MatrixGraph(IGraph* _oth) {
        matrix.clear();
        std::vector<int> vert = _oth->GetVertices();
        std::vector<int> tmp;
        for (auto& from : vert) {
            _oth->GetNextVertices(from, tmp);
            for (auto& to : tmp) {
                AddEdge(from, to);
            }
            tmp.clear();
        }
    };
    virtual void AddEdge(int from, int to) {
        int max = (from > to ? from : to) + 1;
        if (matrix.size() < max) {
            matrix.resize(max);
            for (auto& e : matrix) {
                if (e.size() < max)
                    e.resize(max, 0);
            }
            for (int i = 0, ie = max; i < max; ++i) {
                matrix[i][0] = i;
                matrix[0][i] = i;
            }
        }
        matrix[from][to] = 1;
    }
    virtual int VerticesCount() const {
        return static_cast<int>(matrix.size());
    }
    virtual void GetNextVertices(int vertex, std::vector<int>& vertices) const {
        if (vertex >= matrix.size())
            return;
        for (int j = 1, je = matrix.size(); j != je; ++j) {
            if (matrix[vertex][j]) {
                vertices.push_back(matrix[0][j]);
            }
        }
    }
    virtual void GetPrevVertices(int vertex, std::vector<int>& vertices) const {
        if (vertex >= matrix.size())
            return;
        for (int j = 1, je = matrix.size(); j != je; ++j) {
            if (matrix[j][vertex]) {
                vertices.push_back(matrix[j][0]);
            }
        }
    }
    virtual std::vector<int> GetVertices() {
        std::vector<int> tmp;
        for (int i = 1, ie = matrix.size(); i != ie; ++i) {
            for (int j = 1, je = matrix.size(); j != je; ++j) {
                if (matrix[i][j]) {
                    tmp.push_back(matrix[i][0]);
                    break;
                }
            }
        }
        return tmp;
    };

    void print() {
        int max = matrix.size();
        for (int i = 0, ie = max; i < ie; ++i)  {
            for (int j = 0, je = max; j < je; ++j) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main()
{
    ListGraph list;
    list.AddEdge(1, 2);
    list.AddEdge(2, 3);
    list.AddEdge(2, 4);
    list.AddEdge(3, 4);
    list.AddEdge(4, 1);

    MatrixGraph matrix(&list);
    matrix.AddEdge(4, 3);
    matrix.AddEdge(5, 6);
    matrix.AddEdge(5, 6);
    matrix.AddEdge(6, 4);

    matrix.print();

    std::vector<int> v = matrix.GetVertices();
    for (auto& e : v) {
        std::cout << e << " ";
    }
    v.clear();
    std::cout << std::endl;
    matrix.GetNextVertices(4, v);
    for (auto& e : v) {
        std::cout << e << " ";
    }
}