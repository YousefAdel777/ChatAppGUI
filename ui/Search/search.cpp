#include "search.h"
#include "ui_Search.h"
#include <sstream>
#include <unordered_set>

#include "ChatRoom.h"
#include "SearchEngine.h"

Search::Search(std::unordered_map<int, std::string> contents, std::vector<int> resultsIds, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Search),
    contents(contents),
    resultsIds(std::move(resultsIds))
{
    ui->setupUi(this);
    handle_split();
    connect(ui->searchBtn, QPushButton::clicked, this, &Search::performSearch);
}

Search::~Search() {
    delete ui;
}

void Search::performSearch() {
    std::string query = ui->searchIn->text().toStdString();
    std::string token;
    std::unordered_set<int> ids;
    std::string lowercase_query;
    lowercase_query.reserve(query.size());
    std::transform(query.begin(), query.end(), std::back_inserter(lowercase_query), [](unsigned char c){ return std::tolower(c); });
    std::istringstream ss(lowercase_query);
    while (ss >> token) {
        auto matches = searchEngine.getIds(token);
        ids.insert(matches.begin(), matches.end());
    }
    resultsIds.assign(ids.begin(), ids.end());
    emit searchDone(resultsIds);
}

void Search::addContent(int id, string content) {
    std::string lowercase_content;
    lowercase_content.reserve(content.size());
    std::transform(content.begin(), content.end(), std::back_inserter(lowercase_content), [](unsigned char c){ return std::tolower(c); });
    contents[id] = lowercase_content;
    std::istringstream ss(lowercase_content);
    std::string token;

    while (ss >> token) {
        searchEngine.addWordWithId(token, id);
    }
}

void Search::handle_split() {
    for (const auto& [id, content] : contents) {  
        std::string token;
        std::string lowercase_content;
        lowercase_content.reserve(content.size());
        std::transform(content.begin(), content.end(), std::back_inserter(lowercase_content), [](unsigned char c){ return std::tolower(c); });
        std::istringstream ss(lowercase_content);

        while (ss >> token) {
            searchEngine.addWordWithId(token, id);
        }
    }
}
