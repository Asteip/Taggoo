#include "xmldatawriter.h"

XmlDataWriter::XmlDataWriter(Data *data){
    data_ = data;
}

void XmlDataWriter::write(QIODevice *device){
    writer_.setDevice(device);

    writer_.writeStartDocument();
    writeData();
    writer_.writeEndDocument();
}

void XmlDataWriter::writeData(){
    writer_.writeStartElement("data");
    writeHomePath();
    writeTag();
    writer_.writeEndElement();
}

void XmlDataWriter::writeHomePath(){
    if(data_->getHomePath() != NULL && data_->getHomePath() != "")
        writer_.writeTextElement("homepath", data_->getHomePath());
    else
        writer_.writeTextElement("homepath", "/home");
}

void XmlDataWriter::writeTag(){
    for(int i = 0 ; i < data_->countTag() ; ++i){
        writer_.writeStartElement("tag");
        writer_.writeAttribute("name", data_->getTag(i)->getName());
        writeFileList(data_->getTag(i));
        writer_.writeEndElement();
    }
}

void XmlDataWriter::writeFileList(Tag *tag){
    for(int i = 0 ; i < tag->countFile() ; ++i){
        writer_.writeStartElement("file");
        writer_.writeAttribute("type", tag->getFile(i)->getType() == File::TYPE_DIRECTORY ? "directory" : "file");
        writer_.writeAttribute("path", tag->getFile(i)->getPath());
        writer_.writeEndElement();
    }
}
