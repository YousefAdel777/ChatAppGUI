#include "TextMessage.h"
#include <QVBoxLayout>
#include <iostream>
#include <QApplication>
using namespace std;
TextMessage::TextMessage(MessageModel msg,Message* Reply,QWidget *parent) :
    Message(msg,Reply,parent) {
    textData = new QLabel();
    textData->setText(msg.getContent().data());
    setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setContentsMargins(0,0,0,0);
    layout->addWidget(textData);
    layout->setAlignment(Qt::AlignTop);
    layout->setSpacing(0);
    if(msg.type==MessageModel::SENT)
    {
        ReadStatus = new QLabel();
        ReadStatus->setFixedSize(15,15);
        ReadStatusContainer = new QWidget(this);
        QVBoxLayout *ReadStatusLayout = new QVBoxLayout();
        ReadStatusLayout->addWidget(ReadStatus,0,Qt::AlignCenter);
        ReadStatusContainer->setLayout(ReadStatusLayout);
        string s = "border-image:url(:/Resources/";
        s+=((msg.status.getSeen())?"Read.png":"3.png");
        s+=") 5 stretch stretch; border-radius:7.5;";
        ReadStatus->setStyleSheet(s.data());
        ReadStatusContainer->setStyleSheet("background-color: #D3E8D2; border-radius:15");
    }

    if(msg.option==MessageModel::REPLY){
        layout->insertWidget(0,Reply);
        textData->setStyleSheet("background-color:rgb(214, 240, 209); padding-right:10px; padding-left:10px; border-bottom-left-radius:15px; border-bottom-right-radius:15px; font-size:12; color:#424941;");
    }else{
        if(msg.type==MessageModel::SENT){
            textData->setStyleSheet("background-color:rgb(214, 240, 209); padding-right:10px; padding-left:10px; border-bottom-left-radius:15px; border-top-left-radius:15px; border-bottom-right-radius:15px; font-size:12; color:#424941;");
        }else{
            textData->setStyleSheet("background-color:rgb(214, 240, 209); padding-right:10px; padding-left:10px; border-bottom-left-radius:15px; border-top-right-radius:15px; border-bottom-right-radius:15px; font-size:12; color:#424941;");
        }
    }
    textData->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
    MessageWidth = textData->sizeHint().width();
    textData->setWordWrap(true);
}

void TextMessage::Adjust() {
    int h = (Content.option!=MessageModel::REPLY)?0:Reply->height();
    int w = std::min(width(),MessageWidth+20);
    if(Content.option==MessageModel::REPLY){
        w = std::max(w,240);
    }
    textData->setFixedWidth(w);
    QFont  font = QApplication::font("QWidget");
    QFontMetrics fm(font);
    QRect r = fm.boundingRect(0, 0, w-20,INT_MAX,Qt::TextWordWrap,textData->text());
    textData->setFixedHeight(r.height()+20);
    if(Content.type==MessageModel::SENT){
        setFixedSize(w,r.height()+h+40);
        ReadStatusContainer->setGeometry(QRect(w-30,r.height()+h,30,30));
    }else{
        setFixedSize(w,r.height()+h+20);
    }
}

void TextMessage::resizeEvent(QResizeEvent *event) {
    QWidget::resizeEvent(event);
    Adjust();
}

TextMessage::~TextMessage(){
}
