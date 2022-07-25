
#ifndef _DIRECTORY_H_
#define _DIRECTORY_H_

#include "Core.h"

// Directory.h
#include <iostream>

class Dirent
{
private:
public:
  std::string name;
  std::string fhandle;
  std::string filetype;
  std::string filesize;
  Dirent();
  Dirent(std::string, std::string);
  virtual Json::Value *dumpJ();
  virtual bool Jdump(Json::Value *);
};

class Directory : public Core
{
private:
public:
  std::string name;
  std::string fhandle;
  std::vector<Dirent *> *dirent_vector_ptr;
  Directory(std::string, std::string, std::string,
            std::string);
  Directory(std::string, std::string, std::string,
            std::string, std::string, std::string);
  virtual Json::Value LookUp(std::string, std::string);
  virtual Json::Value UpdateFile(std::string, std::string, std::string, std::string, std::string);
  virtual Json::Value Create(std::string, std::string, std::string);
  virtual Json::Value *dumpJ();
  virtual bool Jdump(Json::Value *);
  // Send function to send the file to the client
  virtual Json::Value send(std::string, std::string);
  // Adding Zip function
  virtual Json::Value Zip(std::string, std::string, std::string, std::string);
};

#endif /* _DIRECTORY_H_ */
