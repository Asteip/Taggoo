#ifndef XMLDATAREADER_H
#define XMLDATAREADER_H

#include <vector>
#include <QIODevice>
#include <QXmlStreamReader>
#include "data.h"

/**
 * @brief The XmlDataReader class provides methods to read the xml data file.
 * @author Alexis
 */
class XmlDataReader{
public:
    /**
     * @brief Create an instance of XmlDataReader.
     * @param data The data which have to be read from the xml document.
     */
    XmlDataReader(Data *data);

    /**
     * @brief Read the xml document.
     * @pre If the document does not contains the "data" root, an error is raised.
     * @param device The open xml file (in ReadOnly mode) where data will be read.
     * @return False if an error occured during the parsing, true otherwise.
     */
    bool read(QIODevice *device);

    /**
     * @brief Returns an error message raised by the reader.
     * @return A string error message.
     */
    QString errorString() const;

private:
    /*
     * Reads xml tag contains by "data".
     */
    void readData();

    /*
     * Reads the text of the "homepath" xml tag.
     */
    void readHomePath();

    /*
     * Reads a the tag "tag".
     */
    void readTag();

    /*
     * Reads the property "name" in the tag "tag".
     */
    void readTagName(Tag *tag);

    /*
     * Reads the list of "file" tag contains by a "tag".
     */
    void readFileList(Tag *tag);

private:
    QXmlStreamReader reader_;
    Data *data_;
};

#endif // XMLDATAREADER_H
