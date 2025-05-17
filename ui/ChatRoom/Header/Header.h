#ifndef HEADER_H
#define HEADER_H

#include <QWidget>
#include <QPushButton>

#include "Search/search.h"

namespace Ui {
class header;
}
class Header : public QWidget
{
    Q_OBJECT
public:
    explicit Header(int id, QWidget *parent = nullptr);
    ~Header();
    QPushButton* getName();
    Search *search;

signals:
    void searchCancel(string query);
    void searchDone(vector<int> ids);
    void searchStart();

private slots:
    void on_Name_clicked();
    void on_LastSeen_clicked();
    void on_Dots_clicked();
    void on_search_clicked();
    void on_close_search_clicked();
    void initializeSearchBar();
private:
    Ui::header *ui;
    int id;
    vector<int> searchResultsIds;
    Search *searchBar;
};
#endif // HEADER_H
