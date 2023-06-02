#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include <QMessageBox>
#include <QInputDialog>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <QFont>

using namespace std;

vector<int> depthFirstSearch(const vector<vector<int>>& graph, int startNode) {
    vector<int> visited(graph.size(), false);
    vector<int> traversalOrder;

    // Recursive depth-first search function
    function<void(int)> dfs = [&](int node) {
        visited[node] = true;
        traversalOrder.push_back(node);

        for (int neighbor = 0; neighbor < graph.size(); ++neighbor) {
            if (graph[node][neighbor] != 0 && !visited[neighbor]) {
                dfs(neighbor);
            }
        }
    };

    dfs(startNode);
    return traversalOrder;
}

vector<int> breadthFirstSearch(const vector<vector<int>>& graph, int startNode) {
    vector<int> visited(graph.size(), false);
    vector<int> traversalOrder;

    vector<int> queue;
    queue.push_back(startNode);
    visited[startNode] = true;

    while (!queue.empty()) {
        int node = queue.front();
        queue.erase(queue.begin());
        traversalOrder.push_back(node);

        for (int neighbor = 0; neighbor < graph.size(); ++neighbor) {
            if (graph[node][neighbor] != 0 && !visited[neighbor]) {
                visited[neighbor] = true;
                queue.push_back(neighbor);
            }
        }
    }

    return traversalOrder;
}

vector<int> dijkstra(const vector<vector<int>>& graph, int startNode, int endNode) {
    int numNodes = graph.size();
    vector<int> dist(numNodes, INT_MAX);
    vector<int> prev(numNodes, -1);
    vector<bool> visited(numNodes, false);

    dist[startNode] = 0;

    for (int i = 0; i < numNodes - 1; ++i) {
        int minDist = INT_MAX;
        int minNode = -1;

        for (int node = 0; node < numNodes; ++node) {
            if (!visited[node] && dist[node] < minDist) {
                minDist = dist[node];
                minNode = node;
            }
        }

        if (minNode == -1) {
            break;
        }

        visited[minNode] = true;

        for (int neighbor = 0; neighbor < numNodes; ++neighbor) {
            if (graph[minNode][neighbor] != 0 && !visited[neighbor]) {
                int newDist = dist[minNode] + graph[minNode][neighbor];

                if (newDist < dist[neighbor]) {
                    dist[neighbor] = newDist;
                    prev[neighbor] = minNode;
                }
            }
        }
    }

    vector<int> shortestPath;
    int currentNode = endNode;

    while (currentNode != -1) {
        shortestPath.push_back(currentNode);
        currentNode = prev[currentNode];
    }

    reverse(shortestPath.begin(), shortestPath.end());

    return shortestPath;
}

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Графы");

    QLabel* resultLabel = new QLabel;
    QFont font;
    font.setPointSize(24);
    resultLabel->setFont(font);

    QLabel* labelVertices = new QLabel("Введите количество вершин:");
    QLineEdit* lineEditVertices = new QLineEdit;
    QLabel* labelEdges = new QLabel("Введите количество рёбер:");
    QLineEdit* lineEditEdges = new QLineEdit;
    QPushButton* buttonSubmit = new QPushButton("Нарисовать граф");
    QPushButton* buttonDFS = new QPushButton("Обход в глубину");
    QPushButton* buttonBFS = new QPushButton("Обход в ширину");
    QPushButton* buttonDijkstra = new QPushButton("Алгоритм Дейкстры");
    QGraphicsView* graphView = new QGraphicsView;
    QGraphicsScene* graphScene = new QGraphicsScene;

    QGridLayout* layout = new QGridLayout;
    layout->addWidget(labelVertices, 0, 0);
    layout->addWidget(lineEditVertices, 0, 1);
    layout->addWidget(labelEdges, 1, 0);
    layout->addWidget(lineEditEdges, 1, 1);
    layout->addWidget(buttonSubmit, 2, 0, 1, 2);
    layout->addWidget(buttonDFS, 3, 0);
    layout->addWidget(buttonBFS, 3, 1);
    layout->addWidget(buttonDijkstra, 3, 2);
    layout->addWidget(graphView, 4, 0, 1, 3);
    layout->addWidget(resultLabel, 5, 0, 1, 3);
    window.setLayout(layout);

    graphView->setScene(graphScene);

    vector<vector<int>> graph;
    int startNode = -1;

    QObject::connect(buttonSubmit, &QPushButton::clicked, [&]() {
        int n = lineEditVertices->text().toInt();
    int numEdges = lineEditEdges->text().toInt();

    graph.clear();
    graph.resize(n, vector<int>(n, 0));

    for (int i = 0; i < numEdges; i++) {
        QString dialogText = "Введите 2 вершины и вес между ними (например 1 3 5)";
        QString inputText = QInputDialog::getText(nullptr, "Ребро " + QString::number(i + 1), dialogText);
        QStringList inputList = inputText.split(' ');

        if (inputList.size() == 3) {
            int from = inputList[0].toInt() - 1;
            int to = inputList[1].toInt() - 1;
            int weight = inputList[2].toInt();

            graph[from][to] = weight;
            graph[to][from] = weight;
        }
        else {
            QMessageBox::warning(nullptr, "Ошибка", "Неверный формат ввода.");
            return;
        }
    }

    bool ok;
    startNode = QInputDialog::getInt(nullptr, "Исходная вершина", "Введите исходную вершину:", 1, 1, n, 1, &ok);

    if (ok) {
        // Clear the previous items in the scene
        graphScene->clear();

        int radius = 200;
        int centerX = 400;
        int centerY = 400;
        double angle = 2 * M_PI / n;

        for (int i = 0; i < n; i++) {
            int x = centerX + radius * cos(i * angle);
            int y = centerY + radius * sin(i * angle);

            QGraphicsEllipseItem* ellipse = graphScene->addEllipse(x - 10, y - 10, 20, 20);
            QGraphicsTextItem* label = graphScene->addText(QString::number(i + 1), QFont("Arial", 12));

            label->setPos(x - label->boundingRect().width() / 2, y - label->boundingRect().height() / 2);

            for (int j = i + 1; j < n; j++) {
                if (graph[i][j] != 0) {
                    int x2 = centerX + radius * cos(j * angle);
                    int y2 = centerY + radius * sin(j * angle);

                    QGraphicsLineItem* line = graphScene->addLine(x, y, x2, y2);
                    int weight = graph[i][j];
                    int weightX = (x + x2) / 2;
                    int weightY = (y + y2) / 2;

                    QGraphicsTextItem* weightLabel = graphScene->addText(QString::number(weight));
                    weightLabel->setPos(weightX, weightY);

                    line->setPen(QPen(Qt::black, 2));
                }
            }
        }

        graphView->fitInView(graphScene->sceneRect(), Qt::KeepAspectRatio);
    }
        });

    QObject::connect(buttonDFS, &QPushButton::clicked, [&]() {
        if (graph.empty() || startNode == -1) {
            QMessageBox::warning(nullptr, "Ошибка", "Граф не инициализирован.");
            return;
        }

    vector<int> traversalOrder = depthFirstSearch(graph, startNode - 1);
    QString result = "Обход в глубину: ";

    for (int node : traversalOrder) {
        result += QString::number(node + 1) + " ";
    }

    resultLabel->setText(result);
        });

    QObject::connect(buttonBFS, &QPushButton::clicked, [&]() {
        if (graph.empty() || startNode == -1) {
            QMessageBox::warning(nullptr, "Ошибка", "Граф не инициализирован.");
            return;
        }

    vector<int> traversalOrder = breadthFirstSearch(graph, startNode - 1);
    QString result = "Обход в ширину: ";

    for (int node : traversalOrder) {
        result += QString::number(node + 1) + " ";
    }

    resultLabel->setText(result);
        });

    QObject::connect(buttonDijkstra, &QPushButton::clicked, [&]() {
        if (graph.empty() || startNode == -1) {
            QMessageBox::warning(nullptr, "Ошибка", "Граф не инициализирован.");
            return;
        }

    bool ok;
    int endNode = QInputDialog::getInt(nullptr, "Конечная вершина", "Введите конечную вершину:", 1, 1, graph.size(), 1, &ok);

    if (ok) {
        vector<int> shortestPath = dijkstra(graph, startNode - 1, endNode - 1);
        QString result = "Кратчайший путь: ";

        for (int node : shortestPath) {
            result += "<span style='color:red;'>" + QString::number(node + 1) + "</span> ";
        }

        resultLabel->setText(result);
    }
        });

    window.show();

    return app.exec();
}
