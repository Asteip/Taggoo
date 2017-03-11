#include "xmldatareader.h"

XmlDataReader::XmlDataReader(Data *data){
    data_ = data;
}

bool XmlDataReader::read(QIODevice *device){
    reader_.setDevice(device);

    if (reader_.readNextStartElement()) {
        if (reader_.name() == "data")
            readData();
        else
            reader_.raiseError(QObject::tr("Not a data file"));
    }

    return !reader_.error();
}

QString XmlDataReader::errorString() const{
    return reader_.errorString();
}

void XmlDataReader::readData(){
    while(reader_.readNextStartElement()){
        if(reader_.name() == "homepath")
            readHomePath();
        else if(reader_.name() == "tag")
            readTag();
        else
            reader_.skipCurrentElement();
    }
}

void XmlDataReader::readHomePath(){
    Q_ASSERT(reader_.isStartElement() &&
             reader_.name() == "homepath");

    QString homePath = reader_.readElementText();
    data_->setHomePath(homePath);
}

void XmlDataReader::readTag(){
    Q_ASSERT(reader_.isStartElement() &&
             reader_.name() == "tag");

    Tag *tag = new Tag(NULL);

    readTagName(tag);
    readFileList(tag);

    data_->addTag(tag);
}

void XmlDataReader::readTagName(Tag *tag){
    Q_ASSERT(reader_.name() == "tag" &&
             reader_.attributes().hasAttribute("name"));

    QString name = reader_.attributes().value("name").toString();
    tag->setName(name);
}

void XmlDataReader::readFileList(Tag *tag){
    Q_ASSERT(reader_.isStartElement() &&
             reader_.name() == "tag");

    while(reader_.readNextStartElement()){
        if(reader_.name() == "file" && reader_.attributes().hasAttribute("type") && reader_.attributes().hasAttribute("path")){
            File *file = NULL;
            QString type = reader_.attributes().value("type").toString();
            QString path = reader_.attributes().value("path").toString();

            if(type == "directory")
                file = new File(path, File::TYPE_DIRECTORY);
            else if(type == "file")
                file = new File(path, File::TYPE_FILE);
            else
                reader_.raiseError(QObject::tr("Error when parsing the data file : a file does not have an accepted type."));

            if(file != NULL)
                tag->addFile(file);

            reader_.skipCurrentElement();
        }
        else{
            reader_.skipCurrentElement();
        }
    }
}
