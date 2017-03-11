#ifndef XMLDATAREADER_H
#define XMLDATAREADER_H

#include <vector>
#include <QIODevice>
#include <QXmlStreamReader>
#include "data.h"

/**
 * @brief The XmlDataReader class
 */
class XmlDataReader{
public:
    /**
     * @brief XmlDataReader
     * @param data
     */
    XmlDataReader(Data *data);

    /**
     * @brief read
     * @param device
     * @return
     */
    bool read(QIODevice *device);

    /**
     * @brief errorString
     * @return
     */
    QString errorString() const;

private:
    void readData();
    void readHomePath();
    void readTag();
    void readTagName(Tag *tag);
    void readFileList(Tag *tag);

private:
    QXmlStreamReader reader_;
    Data *data_;
};

#endif // XMLDATAREADER_H
