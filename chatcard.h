#ifndef CHATCARD_H
#define CHATCARD_H

#include <QWidget>

namespace Ui {
class chatcard;
}

class chatcard : public QWidget
{
    Q_OBJECT

public:
    inline static chatcard* current = nullptr;
    explicit chatcard(int ChatRoom,QWidget *parent = nullptr);
    void setProfilePic(QString);
    void setName(QString);
    ~chatcard();
    void mousePressEvent(QMouseEvent *event) override;
signals:
    void clicked(int id);
private:
    Ui::chatcard *ui;
    int ChatRoomId;
    std::string defaultStyle =
        R"(background-color: #D3E8D2;
            border: none;
            border-radius: 30px;
            text-align: left;
            color: #000;)";
    std::string currentStyle =
        R"(background-color: #FFF;
            border: none;
            border-radius: 30px;
            text-align: left;
            color: #000;)";
};

#endif // CHATCARD_H
