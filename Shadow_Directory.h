
#ifndef _SHADOW_DIRECTORY_H_
#define _SHADOW_DIRECTORY_H_

#include "Directory.h"

class Shadow_Directory : public Directory
{
private:
public:
  Shadow_Directory(std::string, std::string, std::string, std::string);
  virtual Json::Value LookUp(std::string, std::string);
  virtual Json::Value UpdateFile(std::string, std::string, std::string, std::string, std::string);
  virtual Json::Value Create(std::string, std::string, std::string);
  virtual Json::Value *dumpJ();
  virtual bool Jdump(Json::Value *);
  // Adding the send shadow function
  virtual Json::Value send(std::string, std::string);
  // Adding Zip function
  virtual Json::Value Zip(std::string, std::string, std::string, std::string);
};

#endif // _SHADOW_DIRECTORY_H_
