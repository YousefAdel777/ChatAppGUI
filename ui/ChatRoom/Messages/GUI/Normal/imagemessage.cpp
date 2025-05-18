#include "imagemessage.h"
#include <QVBoxLayout>
#include <User.h>

ImageMessage::ImageMessage(MessageModel msg,Message* Reply,QWidget *parent)
    : Message(msg,Reply,parent)
{
    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Minimum);
    Image = new HighQualityImage(msg.getContent().data(),width()-30,this);
    QVBoxLayout *bubbleLayout = new QVBoxLayout(this);
    bubbleLayout->setAlignment(Qt::AlignTop);
    bubbleLayout->setSpacing(0);
    Image->setStyleSheet("background-color:rgb(214, 240, 209)");
    if(msg.getPrompt().size())
    {
        MessageModel msg1(0,0,MessageModel::TEXT,MessageModel::RECEIVED,MessageModel::NORMAL,-1,msg.getPrompt(),msg.getStatus());
        label = new TextMessage(msg1,nullptr,this);
        bubbleLayout->addWidget(label);
    }else
        label = nullptr;
    if (msg.getUserID()==User::getCurrentUser()->getId())
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
        bubbleLayout->insertWidget(0,Reply);
    }
    setFixedWidth(std::min(width(),300));
    Image->setFixedWidth(width()-15);
    if(label!=nullptr)
        label->setFixedWidth(width()-15);
    Image->Adjust();
    if(label!=nullptr)
    {
        label->Adjust();
        setFixedHeight(label->height()+Image->height()+35);
    }
    else
        setFixedHeight(Image->height()+35);
    if(msg.type==MessageModel::SENT){
        ReadStatusContainer->setGeometry(width()-30,height()-40,30,30);
    }
    if(msg.option==MessageModel::REPLY){
        bubbleLayout->insertWidget(0,Reply);
    }
}

void ImageMessage::resizeEvent(QResizeEvent *event){
    Adjust();
}

void ImageMessage::Adjust(){
    setFixedWidth(std::min(width(),300));
    Image->setFixedWidth(width()-15);
    Image->Adjust();

    int h = 0;
    if(label!=nullptr)
        label->setFixedWidth(width()-15),label->Adjust(),h+=label->height();
    if(Content.option==MessageModel::REPLY)
    {
        if(Reply->Reply->Content.datatype==MessageModel::IMAGE){
            setFixedWidth(max(Image->width()+15,245));
        }
        h+=Reply->height();
    }else{
        setFixedWidth(Image->width()+15);
    }
    Image->Adjust();
    setFixedHeight(Image->height()+35+h);
    if (Content.getUserID()==User::getCurrentUser()->getId()){
        ReadStatusContainer->setGeometry(width()-30,height()-40,30,30);
    }
}

void ImageMessage::paintEvent(QPaintEvent* event) {
    Q_UNUSED(event);
    QPainter painter(this);

    // Enable anti-aliasing for smooth corners
    painter.setRenderHint(QPainter::Antialiasing);

    // Set background color and rounded rectangle
    QColor backgroundColor(214, 240, 209);
    QRect rect = this->rect();
    rect.setHeight(height()-15);
    painter.setBrush(backgroundColor);
    painter.setPen(Qt::NoPen);
    painter.drawRoundedRect(rect.adjusted(0, 0, -1, -1), 18, 18); // radius = 12px
}

ImageMessage::~ImageMessage(){

}
