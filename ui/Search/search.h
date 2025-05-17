//
// Created by Dell on 5/16/2025.
//

#ifndef SEARCH_H
#define SEARCH_H

#include <QWidget>
#include <unordered_map>
#include <vector>
#include <string>

#include "SearchEngine.h"
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class Search; }
QT_END_NAMESPACE

class Search : public QWidget {
    Q_OBJECT

public:
    explicit Search( unordered_map<int, string> contents, vector<int> resultsIds, QWidget *parent = nullptr);

    ~Search();

signals:
    void searchDone(vector<int> resultsIds);
private slots:
    void performSearch();

private:
    Ui::Search *ui;
    SearchEngine searchEngine;
    unordered_map<int, string> contents;
    vector<int> resultsIds;
    void handle_split();
};

#endif //SEARCH_H