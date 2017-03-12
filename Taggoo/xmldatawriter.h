#ifndef XMLDATAWRITER_H
#define XMLDATAWRITER_H

#include <vector>
#include <QIODevice>
#include <QXmlStreamWriter>
#include "data.h"

/**
 * @brief The XmlDataWriter class provides methods to write into the xml data file.
 * @author Alexis
 */
class XmlDataWriter{
public:
    /**
     * @brief Create an instance of XmlDataWriter.
     * @param data The data which have to be write in the xml document.
     */
    XmlDataWriter(Data *data);

    /**
     * @brief Write into the xml document.
     * @param device The open xml file (in WriteOnly mode) where data will be written.
     */
    void write(QIODevice *device);

private:
    /*
     * Writes xml tag "data".
     */
    void writeData();

    /*
     * Writes xml tag "homepath".
     */
    void writeHomePath();

    /*
     * Writes xml tag "tag" for each existing tag.
     */
    void writeTag();

    /*
     * Writes xml tag "file" for each file from the list of files.
     */
    void writeFileList(Tag *tag);

private:
    QXmlStreamWriter writer_;
    Data *data_;
};

#endif // XMLDATAWRITER_H
