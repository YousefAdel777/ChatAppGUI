#pragma once
#include <QCoreApplication>
#include <QPainter>
#include <fstream>
#include <QPainterPath>
#include <string>
class Helper {
public:
    static std::string getPath(const std::string &FileName) {
        return QCoreApplication::applicationDirPath().toStdString()+"\\..\\..\\Resources\\"+FileName;
    }

    static std::vector<float> getPCM(std::string path) {
        std::vector<float>Amplitudes;
        std::ifstream wavFile(path, std::ios::binary);
        wavFile.seekg(0, std::ios::end);
        std::streampos fileSize = wavFile.tellg();
        wavFile.seekg(44, std::ios::beg);
        size_t dataSize = static_cast<size_t>(fileSize) - 44;
        std::vector<char> data(dataSize);
        wavFile.read(data.data(), dataSize);
        wavFile.close();
        short* samples = reinterpret_cast<short*>(data.data());
        size_t sampleCount = dataSize / sizeof(short);
        for (size_t i = 0; i < sampleCount; i += 300) {  // Sample every 300 for waveform
            Amplitudes.push_back(std::abs(samples[i]) / 32768.0f);
        }
        return Amplitudes;
    }

    static QPixmap getRoundedPixmap(const std::string &PhotoName,int width) {
        const auto src = QPixmap( getPath(PhotoName).data());
        const auto size = src.size();
        QPixmap dest(size);
        dest.fill(Qt::transparent);
        QPainter painter(&dest);
        painter.setRenderHint(QPainter::Antialiasing, true);
        QPainterPath path;
        path.addEllipse(0, 0, size.width(), size.height());
        painter.setClipPath(path);
        painter.drawPixmap(0, 0, src);
        return dest.scaled(width,width,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    }
};
